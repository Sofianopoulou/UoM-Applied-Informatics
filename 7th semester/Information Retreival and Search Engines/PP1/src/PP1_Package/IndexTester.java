package PP1_Package;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.Map;

import jodd.json.JsonParser;

import org.apache.lucene.analysis.en.EnglishAnalyzer; 
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.document.TextField;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.index.LeafReader;
import org.apache.lucene.index.Terms;
import org.apache.lucene.index.TermsEnum;
import org.apache.lucene.queryparser.classic.MultiFieldQueryParser;
import org.apache.lucene.queryparser.classic.ParseException;
import org.apache.lucene.queryparser.simple.SimpleQueryParser;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.ScoreDoc;
import org.apache.lucene.search.TopDocs;
import org.apache.lucene.store.Directory;
import org.apache.lucene.store.FSDirectory;

//Extra imports
import java.util.Scanner;
import java.util.HashMap;

public class IndexTester {

	public static void main(String[] args) throws IOException, ParseException {
		
        if (args.length != 3) {
            System.err.println("Incorrect number of arguments! Usage:");
            System.err.println("");
            System.err.println("java IndexTester should_clear_index path_to_data path_to_index ");
            System.err.println("\tif should_clear_index is \"1\", the index will be rebuilt. Otherwise, it will try and use an existing index.");
            System.err.println("\tpath_to_index should point to an empty directory somewhere.");
            System.exit(-1);
        }
		
        String shouldClearIndex = args[0];
		String inputPath = args[1]; // where to find the file containing the JSON to index
		String idxDirPath = args[2]; // where to put/find the Lucene index we want to search
        
        
		File inputFile = new File(inputPath);
		
		// set up analyzer:
		//StandardAnalyzer analyzer = new StandardAnalyzer();
		EnglishAnalyzer analyzer = new EnglishAnalyzer();
		
		// set up the index
		File idxDir = new File(idxDirPath);
	
		Directory dir = FSDirectory.open(idxDir.toPath());
		
        if (shouldClearIndex.compareTo("1") == 0) {
            System.out.println("Rebuilding index...");
        
            IndexWriterConfig idxConfig = new IndexWriterConfig(analyzer);
            idxConfig.setOpenMode(IndexWriterConfig.OpenMode.CREATE);
            IndexWriter idxWriter = new IndexWriter(dir, idxConfig);

            // Now, populate the index:
            int idx = 0;
            JsonParser jParser = new JsonParser();
            
            for (String line : Files.readAllLines(inputFile.toPath(), StandardCharsets.UTF_8)) {
                // On large amounts of data, this can take a while
                if (idx % 10000 == 0) {
                    System.out.println(idx);
                }
                idx++;
                
                // each line of the input file is a serialized JSON object
                Map j = jParser.parse(line);
                // simple types (strings, numbers, etc.) are handled like so:
                String title = (String)j.get("title");
                // complex types (lists or dicts) get turned into instances of
                // java.util.Map and java.util.List.
                String ab = (String)j.get("abstract");

                // Look at the docs for TextField to see about other types- Lucene can index numbers, dates, etc.
                Field tiField = new Field("title", title, TextField.TYPE_STORED); 
                // The TYPE_STORED directive tells Lucene to actually store the original token in the index. This is handy 
                // for all sorts of reasons!
                
                // set up any additional fields here
                // To index the abstract of the articles 
                Field abField = new Field("abstract", ab, TextField.TYPE_STORED);

                Document thisDoc = new Document();
                thisDoc.add(tiField);
                thisDoc.add(abField);

                // add our document to the index
                idxWriter.addDocument(thisDoc);

            }

            System.out.println("Done!");

            System.out.println(idx + " documents indexed.");

            idxWriter.close();

        }

		do {
			// Open up the index for querying:
			DirectoryReader reader = DirectoryReader.open(dir);

		
			// Tell me about the index (comment in/out as needed- this may be useful for debugging):
//			LeafReader slowC = SlowCompositeReaderWrapper.wrap(reader);	
//			Terms idxTerms = slowC.terms("title"); // change to a different field as needed
//			TermsEnum tEnum = idxTerms.iterator(null);
//			System.out.println("Terms in the index for the title field:");
//			while (tEnum.next() != null) {
//				String s = tEnum.term().utf8ToString();			
//				System.out.println(s + "\t" + tEnum.docFreq());
//			}
		
		
			// Now search
			IndexSearcher searcher = new IndexSearcher(reader);
		
			// Things to note re: QueryParser:
			// 1. 	The first argument is the "default" field to search- 
			//		if nothing else is specified, in the query, this is what
			//		will be searched.
			// 2.	You always want to make sure to use the same Analyzer for your
			//		query as you did when you built the index!
			//
			// Other query parser classes will behave similarly, but may have different argument ordering.
			
			//Specify boost values for each field
			Map<String, Float> boosts = new HashMap<>();
			boosts.put("title", 1.0f);
			boosts.put("abstract", 0.5f);
			
			//QueryParser qParser = new QueryParser("title", analyzer);
			//Changing QueryParser to SimpleQueryParser
			SimpleQueryParser qParser = new SimpleQueryParser(analyzer, boosts); 
		
			System.out.print("Query: ");
			//String queryText = System.console().readLine();
			Scanner scanner = new Scanner(System.in);
			String queryText = scanner.nextLine();

		
			if (queryText.compareTo("") != 0) {
		
				Query q = qParser.parse(queryText);
				TopDocs results = searcher.search(q,  10);
				System.out.println("Got " + results.totalHits + "!");
				for (ScoreDoc d : results.scoreDocs) {
					System.out.println(d.doc + "\t" + d.score);
					Document res = reader.document(d.doc);
					System.out.println("Title: " + res.getField("title").stringValue());
					System.out.println("Abstract: " + res.getField("abstract").stringValue() + "\n\n");
				}
			}
			
		} while (true); // keep querying until user hits ctrl-C
		
	}

}

