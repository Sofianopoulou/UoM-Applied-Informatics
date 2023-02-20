# Programming Project 2 - iis21118, Apostolia-Maria Sofianopoulou
import tarfile
import os
import string
import nltk
import pandas as pd
from nltk.corpus import stopwords
from nltk.stem import SnowballStemmer
from sklearn.feature_extraction.text import TfidfVectorizer
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import apriori, association_rules

nltk.download("punkt")
nltk.download("stopwords")

# extract the tar.gz file
tar = tarfile.open("20news-bydate.tar.gz", "r:gz")
tar.extractall()
tar.close()

# get a list of all the directories, train and test (newsgroups)
newsgroups_train = [d for d in os.listdir("./20news-bydate-train") if not d.startswith('.')]
newsgroups_test = [d for d in os.listdir("./20news-bydate-test") if not d.startswith('.')]

# read the text file in each directory and store the data in the lists
data_train = []
data_test = []
for group in newsgroups_train:
    dir_path = os.path.join("./20news-bydate-train", group)
    for file_name in os.listdir(dir_path):
        with open(os.path.join(dir_path, file_name), 'r') as file:
            data_train.append(file.read())

for group in newsgroups_test:
    dir_path = os.path.join("./20news-bydate-test", group)
    for file_name in os.listdir(dir_path):
        with open(os.path.join(dir_path, file_name), 'r') as file:
            data_test.append(file.read())


# ------------------------- PREPROCESSING DATA OF TRAINING SET -------------------------
def remove_punctuation(text):
    # Define a table of punctuation characters to remove
    table = str.maketrans({key: None for key in string.punctuation})
    # Remove punctuation from the text
    return text.translate(table)


def preprocess_document(document):
    # Convert the document to lowercase
    doc = document.lower()

    # Tokenize the document into words
    words = nltk.word_tokenize(doc)

    # Remove stop-words
    stop_words = set(stopwords.words("english"))
    words = [token for token in words if token.lower() not in stop_words]

    # Remove punctuation characters from words
    words = [remove_punctuation(word) for word in words]

    # Perform stemming
    stemmer = SnowballStemmer("english")
    stemmed_words = [stemmer.stem(word) for word in words]

    return ' '.join(stemmed_words)


all_prepr_train_docs = []
for group in newsgroups_train:
    dir_path = os.path.join("./20news-bydate-train", group)
    for filename in os.listdir(dir_path):
        file_path = os.path.join(dir_path, filename)
        with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
            file = f.read()
            preprocessed_document = preprocess_document(file)
            all_prepr_train_docs.append(preprocessed_document)


# TF-IDF weighting scheme
vectorizer = TfidfVectorizer()

# the resulting TF-IDF weights are stored in the 'tfidf' matrix
tfidf = vectorizer.fit_transform(all_prepr_train_docs)

# get the feature names
feature_names = vectorizer.get_feature_names_out()

# access the top-k values
k = 100
top_k = []
for i in range(tfidf.shape[0]):
    row = tfidf[i].toarray()[0].argsort()[-k:]
    top_k.append(row)

# ------------------------- ASSOCIATION RULES -------------------------
# support and confidence thresholds
min_support = 0.5
min_confidence = 0.8

# convert the list of lists to a one-hot encoder transaction format
te = TransactionEncoder()
te_ary = te.fit_transform(top_k)
df = pd.DataFrame(te_ary, columns=te.columns_)

# find the frequent item-sets
frequent_item_sets = apriori(df, min_support=min_support, use_colnames=True)

# show the rules (with support and confidence greater than or equal to the thresholds we set earlier)
print("Here are the association rules: ")
for item in association_rules(frequent_item_sets, metric="confidence", min_threshold=min_confidence).itertuples():
    ante = item.antecedents
    conseq = item.consequents
    support = item.support
    conf = item.confidence
    lift = item.lift
    ante_words = [feature_names[idx] for idx in ante]
    conseq_words = [feature_names[idx] for idx in conseq]
    print("{} -> {} (Confidence: {}, Lift: {})".format(", ".join(ante_words), ", ".join(conseq_words), conf, lift))


# ------------------------- TEXT CLASSIFICATION -------------------------
def preprocess_document_with_category(document, category):
    # Convert the document to lowercase
    doc = document.lower()

    # Tokenize the document into words
    words = nltk.word_tokenize(doc)

    # Remove stop-words
    stop_words = set(stopwords.words("english"))
    words = [token for token in words if token.lower() not in stop_words]

    # Remove punctuation characters from words
    words = [remove_punctuation(word) for word in words]

    # Perform stemming
    stemmer = SnowballStemmer("english")
    stemmed_words = [stemmer.stem(word) for word in words]

    # Add the category information to the words
    stemmed_words.append(category)

    return ' '.join(stemmed_words)


all_prepr_train_docs_with_category = []
for group in newsgroups_train[:6]:
    dir_path = os.path.join("./20news-bydate-train", group)
    rank = group
    for filename in os.listdir(dir_path):
        file_path = os.path.join(dir_path, filename)
        with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
            file = f.read()
            preprocessed_document = preprocess_document_with_category(file, rank)
            all_prepr_train_docs_with_category.append(preprocessed_document)

# TF-IDF weighting scheme
vectorizer = TfidfVectorizer()

# the resulting TF-IDF weights are stored in the 'tfidf' matrix
tfidf = vectorizer.fit_transform(all_prepr_train_docs_with_category)

# get the feature names
feature_names = vectorizer.get_feature_names_out()

# access the top-k values
top_k = [row.toarray()[0].argsort()[-k:][::-1] for row in tfidf]

# extract the categories
categories = [string.split()[-1] for string in all_prepr_train_docs_with_category]

# support and confidence thresholds
min_support = 0.4
min_confidence = 0.5

# convert the list of lists to a one-hot encoder transaction format
te = TransactionEncoder()
te_ary = te.fit_transform(top_k)
df = pd.DataFrame(te_ary, columns=te.columns_)

# find the frequent item-sets
frequent_item_sets = apriori(df, min_support=min_support, use_colnames=True)

# show the rules (with support and confidence greater than or equal to the thresholds we set earlier
# that have as antecedents the categories
print("\nHere are the association rules with the category of the file being on the right side of the rule: ")
for item in association_rules(frequent_item_sets, metric="confidence", min_threshold=min_confidence).itertuples():
    ante = item.antecedents
    conseq = item.consequents
    support = item.support
    conf = item.confidence
    lift = item.lift
    ante_words = [feature_names[idx] for idx in ante]
    conseq_words = [feature_names[idx] for idx in conseq]
    if len(conseq_words) == 1 and conseq_words[0] in categories:
        print("{} -> {} (Confidence: {}, Lift: {})".format(", ".join(ante_words), ", ".join(conseq_words), conf, lift))
