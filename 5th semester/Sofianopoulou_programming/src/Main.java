/*Apostolia Maria Sofianopoulou, iis21118*/

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		
		/*Implement program NormalizeValues that takes as input a csv file and normalizes the values of
		all its attributes (i.e., transforms them in the [0, 1] range). Obviously, the class attribute should 
		be excluded. The normalized file should be written to disk.*/
		
		try {
			
			String file="letter-recognition.csv";
			FileReader filereader = new FileReader(file);
			BufferedReader br = new BufferedReader(filereader);
			
			ArrayList<Attribute> allAttributes = new ArrayList<Attribute>(); 		//��� �� ���� ��� �� attributes ��� csv �������
			
			String line = br.readLine();											// ������� ��� 1� ������
			String[] words = line.split(",");										//split ��� 1� ������ ��� �� ���� �� attributes
			
			//��������� objects ����� attribute
			for(String s : words) {
				allAttributes.add(new Attribute(s));
			}		
			
			//�������� �� �������� ���� ������ ��� attribute ��� �������	
			line = br.readLine(); 													//��� �� ��������� ��� 1� ������
			while(line != null)  													//����� �� ����� ���� ��������� ������ ��� �������
			{
				words = line.split(","); 											//����� String ��� �� ������������ �� ����������� ���� �������
				for(int i=0; i<allAttributes.size()-1; i++) 
				{						
					try 
						{ allAttributes.get(i).addData(Double.parseDouble(words[i]));}
					catch (Exception e) {}
				}
				
				//���������� ��� �������
				try 
					{ allAttributes.get(allAttributes.size()-1).addClass(words[allAttributes.size()-1]); }
				catch (Exception e) {}
				line = br.readLine();
			}
			
			//�������� �� �������� ��� attributes ��� allAttributes ArrayList
			System.out.println("The given dataset is: ");
			for(int i=0; i<allAttributes.size()-1; i++)
				System.out.println(allAttributes.get(i).getName() + ": " + allAttributes.get(i).getData());
			System.out.println(allAttributes.get(allAttributes.size()-1).getName() + ": " + allAttributes.get(allAttributes.size()-1).getAllClasses());
			System.out.println();
			
			//���� ��������������
			double max,min,num;
			for(int i=0; i<allAttributes.size()-1; i++)
				{
					//���� max ��� min ��������� ��� attribute
					max = allAttributes.get(i).findMax();
					min = allAttributes.get(i).findMin();
					
					//���� ��������������
					for(int x=0; x<allAttributes.get(i).getData().size(); x++) 
					{
						//num = allAttributes.get(i).getData().get(x);
						num = ( (allAttributes.get(i).getData().get(x) - min)	/ (max-min) );	
						allAttributes.get(i).getData().set(x, num);
					}
				}
			
			System.out.println("The normalized dataset is: ");
			for(int i=0; i<allAttributes.size()-1; i++)
				System.out.println(allAttributes.get(i).getName() + ": " + allAttributes.get(i).getData());
			System.out.println(allAttributes.get(allAttributes.size()-1).getName() + ": " + allAttributes.get(allAttributes.size()-1).getAllClasses());
			System.out.println("\nYou can find the normalized dataset at: newNormalizedDataset.csv that was just created\n\n\n");
			

			//������ ��� normalized ����� �� ��� csv ������, �������� ��� String			
			try
			{
				File f = new File("newNormalizedDataset.csv");
				FileWriter writer = new FileWriter(f);
				
				//����� ����� �� ������� ��� attributes (����� ��� �����)
				for(int i=0; i<allAttributes.size()-1; i++) {
					writer.write(allAttributes.get(i).getName() + ", ");
				}
				writer.write(allAttributes.get(allAttributes.size()-1).getName());
				writer.write(System.lineSeparator());
				
				for(int i=0; i<allAttributes.get(0).getData().size(); i++) 							//��� ��� ������ ��������� �����
				{
					for(int x=0; x<allAttributes.size()-1; x++)										//��� ���� ����� 
					{
						writer.write(allAttributes.get(x).getData().get(i).toString() + ", ");		//����� �� i'���� �������� ��� attribute �� ����� x 
					}
					writer.write(allAttributes.get(allAttributes.size()-1).getAllClasses().get(i));	//����� ��� i'��� �����
					writer.write(System.lineSeparator());
				}
				
				writer.close();
			}
			catch(IOException e) 
			{
				e.printStackTrace();
			}
			
			filereader.close();
			
			
			
			/*Implement program ENN that takes as input a normalized csv file and applies the editing algorithm ENN on it. 
			The edited file should be written to disk.*/	
			try 
			{
				String newFile="newNormalizedDataset.csv";
				FileReader newFileReader = new FileReader(newFile);
				BufferedReader newBr = new BufferedReader(newFileReader);
				
				//� ������� �������� �� k ��� ��� ENN
				int k;
				Scanner scanner = new Scanner(System.in);	
				System.out.print("Choose k for ENN algorithm: ");
				k = scanner.nextInt();
				scanner.close();
				
				ArrayList<Element> allElements = new ArrayList<Element>();							//��� �� ������
				String newLine=newBr.readLine();
				String[] attributes = newLine.split(",");
				 
				//��� ���� element ��������� �� ��� ��� Attributes
				for(int i=0; i<allAttributes.get(0).getData().size(); i++)
				{
					allElements.add(new Element(i));
					for(String s : attributes) {
						allElements.get(i).addAttribute(new Attribute(s));
					}
				}
				
				//�������� ��� ������� ��� newNormalizedDataset 
				newLine = newBr.readLine(); 													//��� �� ��������� ��� 1� ������
				Integer lineCount=0;
				
				while(newLine != null)  														//����� �� ����� ���� ��������� ������ ��� �������
				{
					words = newLine.split(",");
					
					//������ �� ArrayList allElements
					for(int i=0; i<allAttributes.size()-1; i++)
					{
						try
							{ allElements.get(lineCount).getAttributes().get(i).addData(Double.parseDouble(words[i])); }
						catch (Exception e) {}
					}
					try 
						{ allElements.get(lineCount).getAttributes().get(allAttributes.size()-1).addClass(words[allAttributes.size()-1]); }
					catch (Exception e) {}
						
					newLine = newBr.readLine();
					lineCount++;	
				}
				
				
				//����������� ���������� ��������� ���� ��� ������� allElements 
				ArrayList<Double> distances = new ArrayList<Double>();
				ArrayList<String> classes = new ArrayList<String>();				
				Map<String, Integer> hshmap = new HashMap<String, Integer>();
				
				double min_distance;
				double distance;
				int index;
				int maxVal;
				String maxStr;
				
				ArrayList<Element> ES = allElements;
				
				for(int i=0; i<allElements.size(); i++) 
				{
					distance=0;
					min_distance=100;
					index=0;
					maxStr = "";
					maxVal = 0;
					
					//������ ���� ��� ����������
					for(int j=0; j<allElements.size(); j++)
					{
						distance=0;
						for(int y=0; y<allAttributes.size()-1; y++)
						{
							distance += Math.pow(allElements.get(j).getAttributes().get(y).getData().get(0) - allElements.get(i).getAttributes().get(y).getData().get(0), 2);
						}
						distances.add(distance);
					}
					
					//������ k ������������ ���������
					for(int x=0; x<k; x++)
					{
						min_distance = 100;
						for(int z=0; z<distances.size(); z++) 	
						{
							if(distances.get(z)!=0.0 && distances.get(z) < min_distance)
							{
								min_distance = distances.get(z);
								index=z;
							}
						}
						
						classes.add(allElements.get(index+x).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0)); 			//�� k ������������ �������
						distances.remove(index);
					}
					
					//� �������� �����
					for(String s : classes)
					{
						if(hshmap.keySet().contains(s))
							hshmap.put(s, hshmap.get(s) +1);
						else
							hshmap.put(s, 1);
					}
					for(Map.Entry<String, Integer> entry : hshmap.entrySet())
					{
						String key = entry.getKey();
						Integer count = entry.getValue();
						if(count > maxVal)
						{
							maxVal = count;
							maxStr = key;
						}
						else if (count == maxVal)
						{
							if(key.length() < maxStr.length())
								maxStr = key;
						}
						/*System.out.println("Most frequent class: " + maxStr);
						System.out.println("Count: "+ maxVal); */
					}
					
					
					if(!allElements.get(i).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0).equals(maxStr))
					{
						ES.remove(index);
					}
						
					distances.clear();
					classes.clear();
					hshmap.clear();
				
				}
				
				System.out.println("\n\n\nAfter applying the ENN algorithm at the normalized dataset, these are the results:\n");
				System.out.println("------------------------ES (" + ES.size() + " elements)------------------------");
				for(int x=0;x<ES.size();x++)
				{
					for(int i=0; i<allAttributes.size()-1; i++)
						System.out.print(ES.get(x).getAttributes().get(i).getData().get(0) + ", ");
					System.out.print(ES.get(x).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0));
					System.out.println();
				}

				//������ ��� ������������������ ����� �� ��� csv ������, �������� ��� String			
				try
				{
					File f = new File("newENNDataset.csv");
					FileWriter writer = new FileWriter(f);
					
					for(int i=0; i<allAttributes.size()-1; i++) {
						writer.write(allAttributes.get(i).getName() + ", ");
					}
					writer.write(allAttributes.get(allAttributes.size()-1).getName());
					writer.write(System.lineSeparator());
					
					for(int i=0; i<ES.size(); i++)
					{
						for(int y=0; y<allAttributes.size()-1; y++)
							writer.write(ES.get(i).getAttributes().get(y).getData().get(0).toString() + ", ");
						
						writer.write(ES.get(i).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0));
						writer.write(System.lineSeparator());
					}
					
					writer.close();

				}
				catch(IOException e) 
				{
					e.printStackTrace();
				}
				
				System.out.println("\nYou can find the edited dataset at: newENNDataset.csv that was just created\n\n\n");
				
				newFileReader.close();
				
				
				/*Implement program IB2 that takes as input a normalized csv file and applies the instance 
				reduction algorithm IB2 on it. The reduced file should be written to disk.*/
				
				ArrayList<Element> CS = new ArrayList<Element>();
				ArrayList<Element> TS = allElements;
				

				//������� �� ����� �������� ��� TS ��� �� �������� ���� CS
				CS.add(new Element(0));
				for(int i=0; i<allAttributes.size()-1; i++)	
				{
					CS.get(0).addAttribute(new Attribute(allAttributes.get(i).getName()));
					CS.get(0).getAttributes().get(i).addData(TS.get(0).getAttributes().get(i).getData().get(0));
				}
				CS.get(0).addAttribute(new Attribute(allAttributes.get(allAttributes.size()-1).getName()));
				CS.get(0).getAttributes().get(allAttributes.size()-1).getAllClasses().add(TS.get(0).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0));
				TS.remove(0);
				
				
				//��� ��� �� elements ��� TS ������ �� ����������� ���� CS
				ArrayList<Double> distancesIB2 = new ArrayList<Double>();
				double min_distanceIB2;
				double distanceIB2;
				int indexIB2;
				int indexCS=0;
				
				while(!TS.isEmpty())
				{
					distanceIB2=0;
					min_distanceIB2=100;
					indexIB2=0;
					
					/*
					System.out.println(TS.get(0).getAttributes().get(allAttributes.size()-1).getAllClasses());
					System.out.println(CS.get(0).getAttributes().get(allAttributes.size()-1).getAllClasses());
					System.out.println(TS.get(0).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0).equals(CS.get(0).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0)));
					*/
					
					//1� ���������: o CS ���� 1 �������� ��� �� ������� ����� ������������ 
					if(CS.size()==1 && (!TS.get(0).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0).equals(CS.get(0).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0))))																	//�� � CS ���� ���� ��� �������� �������� ���������� ��� �������
					{
						//�������� �� �������� ��� TS ���� CS
						indexCS++;
						CS.add(new Element(indexCS));
						for(int x=0; x<allAttributes.size()-1; x++)
						{
							CS.get(indexCS).addAttribute(new Attribute(allAttributes.get(x).getName()));
							CS.get(indexCS).getAttributes().get(x).addData(TS.get(0).getAttributes().get(x).getData().get(0));
						}
						CS.get(indexCS).addAttribute(new Attribute(allAttributes.get(allAttributes.size()-1).getName()));
						CS.get(indexCS).getAttributes().get(allAttributes.size()-1).getAllClasses().add(TS.get(0).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0));
						
					}

					//2� ���������: � CS ���� ����� �������� 
					if(CS.size()>1)
					{
						for(int y=0; y<CS.size(); y++)													//��� ��� �� elements ��� CS 
						{
							distanceIB2 = 0;
							for(int m=0; m<allAttributes.size()-1; m++)									//��� ���� attribute ��� element
							{
								distanceIB2 += Math.pow(TS.get(0).getAttributes().get(m).getData().get(0) - CS.get(y).getAttributes().get(m).getData().get(0),2);
							}
							distancesIB2.add(distanceIB2);
						}
					
						//������ ���������� ���������
						for(int z=0; z<distancesIB2.size(); z++) 	
						{
							if(distancesIB2.get(z) <= min_distanceIB2)
							{
								min_distanceIB2 = distancesIB2.get(z);
								indexIB2=z;																//� index ������� ���� ������ ��� CS ����� ��� ����� 
							}	
						}
						
						//System.out.println(min_distanceIB2 + " at " + indexIB2);
					
						//�������� �������
						if(!TS.get(0).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0).equals(CS.get(indexIB2).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0)));	
						{
							indexCS++;
							CS.add(new Element(indexCS));
							for(int x=0; x<allAttributes.size()-1; x++)
							{
								CS.get(indexCS).addAttribute(new Attribute(allAttributes.get(x).getName()));
								CS.get(indexCS).getAttributes().get(x).addData(TS.get(0).getAttributes().get(x).getData().get(0));
							}
							CS.get(indexCS).addAttribute(new Attribute(allAttributes.get(allAttributes.size()-1).getName()));
							CS.get(indexCS).getAttributes().get(allAttributes.size()-1).getAllClasses().add(TS.get(0).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0));
						}
					}
					
					TS.remove(0);
					distancesIB2.clear();
					
				}
				
				System.out.println("After applying the IB2 algorithm at the normalized dataset, these are the results: \n");
				System.out.println("------------------------CS (" + CS.size() + " elements)------------------------");
				for(int x=0;x<CS.size();x++)
					{
						for(int i=0; i<allAttributes.size()-1; i++)
							System.out.print(CS.get(x).getAttributes().get(i).getData().get(0) + ", ");
						System.out.print(CS.get(x).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0));
						System.out.println();
					}
				System.out.println();
				System.out.println("------------------------TS (" + TS.size() + " elements)------------------------");
				for(int x=0;x<TS.size();x++)
				{
					for(int i=0; i<allAttributes.size()-1; i++)
						System.out.print(TS.get(x).getAttributes().get(i).getData().get(0) + ", ");
					System.out.print(TS.get(x).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0));
					System.out.println();
				}
				if(TS.isEmpty()) System.out.println("TS is empty :)");
				
				
				//������ ��� reduced ����� �� ��� csv ������, �������� ��� String			
				try
				{
					File f = new File("reducedDatasetIB2.csv");
					FileWriter writer = new FileWriter(f);
					
					for(int i=0; i<allAttributes.size()-1; i++) {
						writer.write(allAttributes.get(i).getName() + ", ");
					}
					writer.write(allAttributes.get(allAttributes.size()-1).getName());
					writer.write(System.lineSeparator());
					
					for(int i=0; i<CS.size(); i++)
					{
						for(int y=0; y<allAttributes.size()-1; y++)
							writer.write(CS.get(i).getAttributes().get(y).getData().get(0).toString() + ", ");
						
						writer.write(CS.get(i).getAttributes().get(allAttributes.size()-1).getAllClasses().get(0));
						writer.write(System.lineSeparator());
					}
					
					writer.close();
				}
				catch(IOException e) 
				{
					e.printStackTrace();
				}
				
				System.out.println("\nYou can find the reduced dataset at: reducedDatasetIB2.csv that was just created\n\n\n");
			}
			catch (Exception e)
			{
				
			}
			
		}
		catch (Exception e) 
		{
			e.printStackTrace();
		}
		
	}
}
