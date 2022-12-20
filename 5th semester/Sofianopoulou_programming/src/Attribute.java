import java.util.ArrayList;

public class Attribute {
	
	private ArrayList<Double> data = new ArrayList<Double>(); 		//List of data that the attribute contains.
	private ArrayList<String> data_class = new ArrayList<String>(); //List of data's class
	
	private String name;
	
	//Constructor
	public Attribute(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
		
	public void setName(String name) {
		this.name = name;
	}
	
	public void addData(Double givenData) {
		data.add(givenData); 
	}
	
	public void addClass(String givenClass) {
		data_class.add(givenClass);
	}
	
	public ArrayList<Double> getData() {
		return data;
	}
	
	public ArrayList<String> getAllClasses() {
		return data_class;
	}
	
	public Double findMax() {
		double max = 0;
		
		for(int i=0;i<data.size();i++) {
			if(data.get(i) > max)
				max=data.get(i);
		}
		
		return max;
	}
	
	public Double findMin() {
		double min = 0;
		
		for(int i=0;i<data.size();i++) {
			if(data.get(i) < min)
				min=data.get(i);
		}
		
		return min;
	}
	
}
