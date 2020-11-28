import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class  AppletInOut extends Applet
{
	TextField in = new TextField(10);
	Button btn = new Button("��ƽ��");
	Label out = new Label("������ʾ����ı�ǩ");

	public void init()
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
