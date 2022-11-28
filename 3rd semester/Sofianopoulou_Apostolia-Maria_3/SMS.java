
public class SMS extends Communication{
	
	private String message;
	
	//Constructor
	public SMS(String num1, String num2, int day, int month, int year, String message){
		super(num1,num2,day,month,year);
		this.message = message;	
	}
		
	public void printInfo() {
		System.out.println("This SMS has the following info");
		super.printInfo();
		System.out.println("Text: " +message);
	}
		
	public String getSMS()
		{return message;}

}
