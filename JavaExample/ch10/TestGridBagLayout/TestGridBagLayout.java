import java.awt.*;
import javax.swing.*;

class TestGridBagLayout
{
	public static void main( String [] args )
	{
		JFrame f = new JFrame( "GridBag Example" );
		Container c = f.getContentPane();
		c.setLayout( new GridBagLayout());
		
		GridBagAdder.add( c, new Canvas(), 3, 2, 1, 1, 1, 0,
			GridBagConstraints.NONE, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("1"), 0, 0, 5, 1, 0, 0,
			GridBagConstraints.HORIZONTAL, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("2"), 0, 1, 1, 1, 0, 0,
			GridBagConstraints.BOTH, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("3"), 1, 1, 1, 1, 1, 0,
			GridBagConstraints.HORIZONTAL, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("4"), 2, 1, 1, 1, 0, 0,
			GridBagConstraints.BOTH, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("5"), 3, 1, 2, 1, 0, 0,
			GridBagConstraints.HORIZONTAL, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("6"), 0, 2, 1, 4, 0, 0,
			GridBagConstraints.HORIZONTAL, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("7"), 1, 2, 3, 4, 0, 0,
			GridBagConstraints.BOTH, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("8"), 4, 2, 1, 1, 0, 1,
			GridBagConstraints.BOTH, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("9"), 4, 3, 1, 1, 0, 1,
			GridBagConstraints.BOTH, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("10"), 4, 4, 1, 1, 0, 1,
			GridBagConstraints.BOTH, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("11"), 4, 5, 1, 1, 0, 1,
			GridBagConstraints.BOTH, GridBagConstraints.CENTER );
		GridBagAdder.add( c, new JButton("12"), 0, 6, 5, 1, 0, 0,
			GridBagConstraints.HORIZONTAL, GridBagConstraints.CENTER );
		f.pack();
		f.setVisible(true);
	}


	static class GridBagAdder
	{
		static GridBagConstraints cons = new GridBagConstraints();  // Ok to reuse
		public static void add( Container container, Component comp, 
			int x, int y, int width, int height, int weightx, int weighty,
			int fill, int anchor )
		{
			cons.gridx = x;
			cons.gridy = y;
			cons.gridwidth = width;
			cons.gridheight = height;
			cons.weightx = weightx;
			cons.weighty = weighty;
			cons.fill = fill;
			cons.anchor = anchor;
			container.add( comp, cons );
		}
	}
}

