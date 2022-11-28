import java.util.ArrayList;

public class Suspect {
	
	//Suspect's characteristics 
	private String name;
	private String coded_name;
	private String town;
	ArrayList<String> numbers = new ArrayList<String>(); //List of phone numbers that the suspects uses.
	ArrayList<Suspect> possible_partners = new ArrayList<Suspect>();
	ArrayList<Suspect> common_partners = new ArrayList<Suspect>();
	ArrayList<Suspect> suggested_partners = new ArrayList<Suspect>();
	
	//Constructor
	public Suspect(String name, String coded_name, String town){
		this.name = name;
		this.coded_name = coded_name;
		this.town = town;
	}
	
	//Methods
	//Adds a number to suspect's list of phone numbers.
	public void addNumber(String number) {
		numbers.add(number); 
	}
	
	//Adds a suspect to another suspect's list of possible partners.
	public void addSuspect(Suspect aSuspect) {
		
		if(!possible_partners.contains(aSuspect))
			possible_partners.add(aSuspect);
	} 
	
	//Checks if two suspects are connected.
	public boolean isConnectedTo(Suspect aSuspect) { 
		
		return possible_partners.contains(aSuspect);
	}
	
	//Returns a list with all common partners of the two suspects.
	public ArrayList<Suspect> getCommonPartners(Suspect aSuspect) {
		
		for(int i=0;i<possible_partners.size();i++)
			{
				if(possible_partners.get(i).isConnectedTo(aSuspect) && !common_partners.contains(possible_partners.get(i)))
				{
					common_partners.add(possible_partners.get(i));
				}
			}
		
		return common_partners;
	}
	
	public ArrayList<Suspect> getSuggestedPartners() {
		
		Suspect someone = null;
		
		for(int i=0;i<possible_partners.size();i++)
		{
			if(possible_partners.get(i).isConnectedTo(someone) && !possible_partners.contains(someone))
				{
					suggested_partners.add(someone);
				}
		}
		
		return suggested_partners;
	}
	
	public void printInfo(Suspect aSuspect){
		for(int i=0; i<possible_partners.size();i++) 
			System.out.println(possible_partners.get(i).name + ", " +possible_partners.get(i).coded_name);
	}
	
	public String getName()
		{return name;}
	
	public String getCodeName()
		{return coded_name;}
	
	
	
}
