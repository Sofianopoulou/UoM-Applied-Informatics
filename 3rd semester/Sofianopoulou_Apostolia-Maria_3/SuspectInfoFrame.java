import javax.swing.border.Border;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Color;
import java.awt.Dimension;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.TreeSet;

import javax.swing.*;

public class SuspectInfoFrame extends JFrame {
	
	private Border grey;
	private JPanel BigPanel, InfoPanel, SMSPanel, PartnersPanel, SuggPartnPanel;
	private JButton FindSMSButton;
	private JButton BackButton;
	private JTextField SuspectName, CodedName, aNumber;
	private JTextArea PartnersArea, SuggPartnersArea, SMSArea, Numbers;
	private JLabel PartnersLabel;
	private JLabel SuggPartnersLabel;
	private Registry NewRegistry;
	
	private int index;
	
	public SuspectInfoFrame(Registry R, String Name, int index) {
		
		NewRegistry = R;
		this.index = index;
		BigPanel = new JPanel();
		
		
		//Suspect's Info Panel
		InfoPanel = new JPanel();
		SuspectName = new JTextField(Name);
		SuspectName.setEditable(false);
		SuspectName.setPreferredSize(new Dimension(100,20));
		CodedName = new JTextField(NewRegistry.AllSuspects.get(index).getCodeName());
		CodedName.setEditable(false);
		CodedName.setPreferredSize(new Dimension(100,20));
		Numbers = new JTextArea(); 
		
		String NumbersS = "";
		for(int i=0; i<NewRegistry.AllSuspects.get(index).numbers.size(); i++) {
			NumbersS += NewRegistry.AllSuspects.get(index).numbers.get(i).toString() + "\n" ;
		}
		
		Numbers.append(NumbersS);		
		Numbers.setEditable(false);
		Numbers.setPreferredSize(new Dimension(100,70));
		InfoPanel.add(SuspectName);
		InfoPanel.add(CodedName);
		InfoPanel.add(Numbers);
		grey=BorderFactory.createLineBorder(Color.gray,1);
		InfoPanel.setBorder(grey);
		
		
		//Messages Panel
		SMSPanel = new JPanel();
		aNumber = new JTextField(10);
		SMSArea = new JTextArea();
		SMSArea.setEditable(false);
		SMSArea.setPreferredSize(new Dimension(225,150));
		SMSArea.setBorder(grey);
		FindSMSButton = new JButton("Find SMS");
		SMSPanel.setBorder(grey);
		SMSPanel.add(aNumber);
		SMSPanel.add(SMSArea);
		SMSPanel.add(FindSMSButton);
		FindSMSButtonListener FindSMSListener = new FindSMSButtonListener();
		FindSMSButton.addActionListener(FindSMSListener);
		
		
		//Possible Partners Panel
		PartnersPanel = new JPanel();
		PartnersLabel = new JLabel("Partners");
		PartnersArea = new JTextArea();
		
		Collection <String> PossiblePartners = new TreeSet <String>();
		for(int i=0; i <NewRegistry.AllSuspects.get(index).possible_partners.size(); i++)
		{
			PossiblePartners.add(NewRegistry.AllSuspects.get(index).possible_partners.get(i).getName() 
					+ ", " + NewRegistry.AllSuspects.get(index).possible_partners.get(i).getCodeName() + "\n");
		}
		
		Collection <String> Clear = new HashSet <String> (PossiblePartners);
		for(String pos : Clear)
		{
			PartnersArea.append(pos);
		}
		
		PartnersArea.setEditable(false);
		PartnersArea.setPreferredSize(new Dimension(200,150));
		PartnersArea.setBorder(grey);
		PartnersPanel.add(PartnersLabel);
		PartnersPanel.add(PartnersArea);
		PartnersPanel.setBorder(grey);
		
		
		//Suggested Possible Partners Panel
		SuggPartnPanel = new JPanel();
		SuggPartnersLabel = new JLabel("Suggested Partners ----->");
		SuggPartnersArea = new JTextArea();
		SuggPartnersArea.setBorder(grey);
		
		Collection <String> SuggestedPartners = new TreeSet <String>();
		for(int i=0; i<NewRegistry.AllSuspects.get(index).getSuggestedPartners().size(); i++)
		{
			SuggestedPartners.add(NewRegistry.AllSuspects.get(index).getSuggestedPartners().get(i).getName() 
					+ ", " + NewRegistry.AllSuspects.get(index).getSuggestedPartners().get(i).getCodeName() + "\n ");
		}
		
		Collection<String> Clear2 = new HashSet<String> (SuggestedPartners);
		for(String pos : Clear2)
		{
			SuggPartnersArea.append(pos);
		}
		
		SuggPartnersArea.setEditable(false);
		SuggPartnersArea.setPreferredSize(new Dimension(250,140));
		SuggPartnPanel.add(SuggPartnersLabel);
		SuggPartnPanel.add(SuggPartnersArea);
		SuggPartnPanel.setBorder(grey);
		
		
		//Full Window Panel
		BigPanel.add(InfoPanel);
		BigPanel.add(SMSPanel);
		BigPanel.add(PartnersPanel);
		BigPanel.add(SuggPartnPanel);
		
		BackButton = new JButton("Back to Search Screen");
		BigPanel.add(BackButton);
		
		BackButtonListener listener = new BackButtonListener();
		BackButton.addActionListener(listener);
		
		this.setContentPane(BigPanel);
		this.setTitle("Suspect Page");
		this.setSize(485,730);
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		ImageIcon image = new ImageIcon("logo.jpg");
		this.setIconImage(image.getImage());
		
	}
	
	//Back to Search Screen Action
	class BackButtonListener implements ActionListener {
		
		public void actionPerformed(ActionEvent e) {
			
			new MyFrame(NewRegistry);
			SuspectInfoFrame.this.dispose();
		}
	}
	
	
	//Find SMS Action
	class FindSMSButtonListener implements ActionListener {
		
		public void actionPerformed(ActionEvent e) {
			
			String number = aNumber.getText();
			
			ArrayList<SMS> messages = new ArrayList<SMS>(); 
			   
			for(int i=0; i<NewRegistry.AllSuspects.get(index).numbers.size(); i++){
				messages.addAll(NewRegistry.getMessagesBetween(NewRegistry.AllSuspects.get(index).numbers.get(i).toString(), number));
			 }
		
			String allSMS = "";
			for(int i=0; i<messages.size(); i++)
				allSMS += messages.get(i).getSMS() + "\n";
		
			SMSArea.setText(allSMS);
		
		}

	}
}
