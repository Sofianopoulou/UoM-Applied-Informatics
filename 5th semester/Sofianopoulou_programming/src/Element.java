import java.util.ArrayList;

public class Element {
	
	ArrayList<Attribute> Attributes = new ArrayList<Attribute>();
	
	Integer index;
	
	//Constructor
	public Element(Integer index) {
		this.index = index;
	}
	
	public void addAttribute(Attribute a) {
		Attributes.add(a);
	}
	
	public Integer getIndex() {
		return index;
	}
	
	public ArrayList<Attribute> getAttributes() {
		return Attributes;
	}
}
