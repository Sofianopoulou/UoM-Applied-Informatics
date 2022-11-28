import java.awt.Dimension;
import java.awt.Color;
import java.awt.BorderLayout;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.border.Border;

import edu.uci.ics.jung.algorithms.layout.CircleLayout;
import edu.uci.ics.jung.graph.Graph;
import edu.uci.ics.jung.graph.SparseGraph;
import edu.uci.ics.jung.visualization.VisualizationImageServer;
import edu.uci.ics.jung.visualization.decorators.ToStringLabeller;
import edu.uci.ics.jung.algorithms.shortestpath.DistanceStatistics;


public class JungFrame extends JFrame{
	
	private Border grey;
	private Registry NewRegistry;
	private JTextField diameterField;
			
	public JungFrame(Registry R) {
		
		NewRegistry = R;
		double diameter=-1;
		
		Graph g = new SparseGraph();
		
		for(Suspect suspect : NewRegistry.getSuspects())
		{
			g.addVertex(suspect.getCodeName());
		}
		
		int counter=0;
		for(Suspect suspect1 : NewRegistry.getSuspects()) 
			for(Suspect suspect2 : suspect1.getPossPartners())
			{	
				g.addEdge(counter, suspect1.getCodeName(), suspect2.getCodeName());
				counter++;
			}
			
		//finding the diameter
		diameter = DistanceStatistics.diameter(g);
				
		grey=BorderFactory.createLineBorder(Color.gray,1);
		diameterField = new JTextField();
		diameterField.setEditable(false);
		diameterField.setText("Diameter = " + diameter);
		diameterField.setBorder(grey);
			
		VisualizationImageServer vs = new VisualizationImageServer(new CircleLayout(g), new Dimension(250,250));
		
		vs.getRenderContext().setVertexLabelTransformer(new ToStringLabeller());
		
		JFrame frame = new JFrame();
		frame.getContentPane().add(vs);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.pack();
		frame.setSize(340,330);
		frame.setVisible(true);
		frame.setTitle("Suspects Network");
		
		frame.setLayout(new BorderLayout ());
		frame.add(diameterField, BorderLayout.PAGE_END);
		
		ImageIcon image = new ImageIcon("logo.jpg");
		frame.setIconImage(image.getImage());
		
	}
	
	
}
