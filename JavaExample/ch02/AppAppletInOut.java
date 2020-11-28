import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class AppAppletInOut extends Applet
{
	public static void main( String args[] )
	{
		Frame frame = new Frame();
		AppAppletInOut app = new AppAppletInOut();
		app.Init();
		frame.add( app );
		frame.setSize( 400,100 );
		frame.show();
	}

	TextField in = new TextField(10);
	Button btn = new Button("��ƽ��");
	Label out = new Label("������ʾ����ı�ǩ");

	public void Init()
	{
		setLayout( new FlowLayout() );
		add( in );
		add( btn );
		add( out );
		btn.addActionListener( new BtnActionAdapter() );
	}

	class BtnActionAdapter implements ActionListener
	{
		public void actionPerformed( ActionEvent e )
		{
			String s = in.getText();
			double d = Double.parseDouble( s );
			double sq = d * d;
			out.setText( d + "��ƽ���ǣ�" + sq );
		}
	}

}
