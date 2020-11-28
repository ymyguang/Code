import java.awt.*;
import java.awt.event.*;
import java.applet.*;
class ButtonBlockMove extends Applet
{
	final int RC = 4;	// ������
	final int N = RC*RC;	// ��ĸ���
	int []num = new int[N];   //����num���ڼ�¼ÿ����ť�ϵ�����-1
	Button [] btn = new Button[N];
	Button btnStart = new Button("��ʼ��Ϸ");

	public void init(){ //����ʼ,�����鸳ֵ,����ʾ��ť����
		setLayout( new BorderLayout() );
		Panel p1 = new Panel();
		Panel p2 = new Panel();
		p1.setLayout( new GridLayout( RC, RC ));
		p2.add( btnStart );
		add(p1);
		add(p2, BorderLayout.SOUTH );

		for( int i=0; i<N; i++ ){
			num[i] = i;
			btn[i] = new Button(""+ ( num[i] + 1 ));
			p1.add(btn[i]);
			btn[i].setVisible( true );
		}
		btn[N-1].setVisible( false ); //����ΪN-1�İ�ť����ʾ

		btnStart.addActionListener( new ActionListener(){
			public void actionPerformed( ActionEvent e){
				btnStart_Click();
			}
		});
		for( int i=0; i<N; i++ ){
			btn[i].addActionListener( new ActionListener(){
				public void actionPerformed( ActionEvent e){
					for( int j=0; j<N; j++ )
						if( (Button)e.getSource() == btn[j] )
							btn_Click(j);
				}
			});
		}
	}

	public void btnStart_Click(){
		//����˳�򣬿�ʼ��Ϸ
		int i,j,k,t;    
		for( i = 1; i<500; i++){ 
			j = (int)(Math.random()* N);  //����������±�,�������Ӧ������Ԫ��
			k = (int)(Math.random()* N);
			t = num[j]; num[j] = num[k]; num[k] = t;
		}
		
		for( i=0; i<N; i++ ){//��ʾ����
			btn[i].setLabel(""+ (num[i] + 1));
			btn[i].setVisible( true );
		}
		i = findBlank();       //������һ����ť��Ҫ����
		btn[i].setVisible(false);
	}

	int findBlank(){  //����: �ҵ���һ��Ϊ��λ
		int i;
		for( i=0; i<N; i++ ){        //����
			if( num[i] == N-1 ) break; //�ҵ�ֵΪN-1�����Ԫ��
		}
		return i;         //��������ֵΪ�ҵ����±�
	}

	void btn_Click(int index){  //��Index����ť���¼�����
		int blank, t;
		blank = findBlank();                    //�ҵ��հװ�ť(���ص�)
		if( isNeighbor(blank, index)){       //�������
			btn[index].setVisible( false );         //һ������,һ����ʾ
			btn[blank].setVisible( true );          //���������ϵ�����
			t = num[blank]; num[blank] = num[index]; num[index] = t;
			btn[blank].setLabel( ""+ (num[blank] + 1));
			btn[index].setLabel( ""+ (num[index] + 1));
		}
		checkResult();                       //���ù���,����Ƿ����
	}

	boolean isNeighbor(int a, int b){  //�ж��Ƿ�����
		boolean r; //��ע�����е���������/��ϵ����/�߼�����
		r = false;
		if( a == b - RC || a == b + RC ) r = true;  //��������
		if( (a == b - 1 || a == b + 1) && a / RC == b / RC ) r = true; //��������,ע��Ҫ��ͬһ��
		return r;
	}

	void checkResult(){  //�����
		int i;
		for( i=0; i<N; i++ ){     //���ÿ������
			if( num[i] != i ) return;  //�����δ��ȫ��λ,�˳����ӳ���
		}
		new Dialog(new Frame(), "��Ӯ��!���� [��ʼ] ����һ��.",true).show();
	}

	public static void main(String args[]) {
		Frame f = new Frame("�ſ���Ϸ");
		Applet p = new ButtonBlockMove();
		p.init();
		p.start();
		f.add(p);
		f.setSize(300, 300);
		f.addWindowListener( new WindowAdapter(){
			public void windowClosing(WindowEvent e){ System.exit(0);}
		});
		f.show();
    }
}


