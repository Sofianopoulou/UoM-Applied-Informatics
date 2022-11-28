
public class PhoneCall extends Communication{
	
	private int seconds;
	
	//Constructor
	public PhoneCall(String num1, String num2, int day, int month, int year, int seconds){
		super(num1,num2,day,month,year);
		this.seconds = seconds;
	}
	
	public void printInfo() {
		System.out.println("This phone call has the following info");
		super.printInfo();
		System.out.println("Duration: " +seconds);
	}
	
	public int getCallDuration()
		{return seconds;}
}
