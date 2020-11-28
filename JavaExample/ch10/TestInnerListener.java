import java.awt.*;
import java.awt.event.*;
public class TestInnerListener {
	Frame f = new Frame("�ڲ������");
	TextField tf = new TextField(30);
	
	public TestInnerListener(){
		f.add(new Label("�밴�����������϶�"), "North");
		f.add(tf, "South");
		
		f.setBackground(new Color(120,175,175));
		f.addMouseMotionListener(new InnerMonitor());
		f.addMouseListener(new InnerMonitor());
		f.setSize(300, 200);	    	
		f.setVisible(true);
	}
	
	public static void main(String args[]) {   	
		Object t = new TestInnerListener();
	}
	
	private class InnerMonitor implements MouseMotionListener,MouseListener {
		public void mouseDragged(MouseEvent e) {
		    String s = "����϶���λ�ã�" + e.getX() + "," + e.getY() + ")";
		    tf.setText(s);
		}
		
		public void mouseEntered(MouseEvent e) {
		    String s = "����ѽ��봰��";
		    tf.setText(s);
		}
		
		public void mouseExited(MouseEvent e) {
		    String s = "������Ƴ�����";
		    tf.setText(s);
		}
		public void mouseMoved(MouseEvent e) { }
		public void mousePressed(MouseEvent e) { }
		public void mouseClicked(MouseEvent e) { }
		public void mouseReleased(MouseEvent e) { }
	}
} 
