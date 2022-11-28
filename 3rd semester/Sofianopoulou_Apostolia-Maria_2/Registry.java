import java.util.ArrayList;

public class Registry {
	
	//ArrayList with all the Communications (it can rather be PhoneCall or SMS.
	private ArrayList<Communication> AllCommunications = new ArrayList<Communication>(); 
	
	//ArrayList with all the Suspects. 
	private ArrayList<Suspect> AllSuspects = new ArrayList<Suspect>(); 
	
	public void addSuspect(Suspect aSuspect) {
		AllSuspects.add(aSuspect); 
	}
	
	public void addCommunication(Communication aCommunication) {
		AllCommunications.add(aCommunication);
		
		for(int i=0;i<AllSuspects.size();i++)
		{
			if(AllSuspects.get(i).numbers.contains(aCommunication.num1)) 
			{
				for(int j=0;j<AllSuspects.size();j++)
				{
					if(AllSuspects.get(j).numbers.contains(aCommunication.num2))
					{
						AllSuspects.get(j).possible_partners.add(AllSuspects.get(i)); 
						AllSuspects.get(i).possible_partners.add(AllSuspects.get(j));
					}
				}
			}
		}
	}
	
	public Suspect getSuspectWithMostPartners() {
		int max=0;
		int index=0;
		
		for(int i=0;i<AllSuspects.size();i++)
			for(int j=0;j<AllSuspects.get(i).possible_partners.size();j++) 
				{
					if(AllSuspects.get(i).possible_partners.size() > max)
					{
						max = AllSuspects.get(i).possible_partners.size();
						index=i;
					}
				}
		return AllSuspects.get(index); 
	}
	
	public PhoneCall getLongestPhoneCallBetween(String number1, String number2) {
		
		int max=0;
		PhoneCall index = null;
		
		for(Communication i : AllCommunications)
		{
			if(i instanceof PhoneCall)
			{
				PhoneCall phoneCall = (PhoneCall) i;
				if(phoneCall.num1.equals(number1) && phoneCall.num2.equals(number2)) {
					if(phoneCall.getCallDuration() > max)
					{
						max = phoneCall.getCallDuration();
						index = phoneCall;
					}
				}
			}
		}
		
		return index;
	}
	
	public ArrayList<SMS> getMessagesBetween(String number1, String number2) {
		
		String message = "";
		ArrayList<SMS> sms = new ArrayList<SMS>();
		
		for(Communication i : AllCommunications)
		{
			if(i instanceof SMS)
			{
				SMS Sms = (SMS) i;
				if(Sms.num1.equals(number1) && Sms.num2.equals(number2))
					if(Sms.getSMS().contains("Bomb") || Sms.getSMS().contains("Attack") || 
							Sms.getSMS().contains("Explosives") || Sms.getSMS().contains("Gun"))
					{
						message = Sms.getSMS();
						sms.add(Sms);
					}
			}
		}
		
		return sms;
	}
	
	
}
