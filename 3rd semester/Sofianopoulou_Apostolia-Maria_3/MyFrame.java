import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.*;

public class MyFrame extends JFrame {
	
	private JPanel panel = new JPanel();
	private JTextField nameField = new JTextField("Please enter suspect's name");
	private JButton FindButton = new JButton("Find");
	private ArrayList<Suspect> AllSuspects;
	private Registry NewReg;
	
	public MyFrame (Registry R) {
		NewReg = R;
		AllSuspects = R.AllSuspects;
		
		panel.add(nameField);
		panel.add(FindButton);
		
		this.setContentPane(panel);
		
		ButtonListener listener = new ButtonListener();
		FindButton.addActionListener(listener);
		
		this.setVisible(true);
		this.setSize(350, 200);
		this.setTitle("Find Suspect");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		ImageIcon image = new ImageIcon("search.png");
		this.setIconImage(image.getImage());
	}
	
	class ButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			
			String SuspectName = nameField.getText();
			
			boolean flag = false;
			for(int i=0; i<AllSuspects.size(); i++) {
				if(SuspectName.equals(AllSuspects.get(i).getName()))
			
				{
					new SuspectInfoFrame(NewReg, SuspectName, i);
					MyFrame.this.dispose();
					flag=true;
				}
			}
			
			if(flag==false)
				JOptionPane.showMessageDialog(null, "Suspect " +SuspectName + " Not Found");
		}
		
	}
	
}
