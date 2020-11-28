import java.awt.*;
import java.awt.event.*;
import java.applet.*;
class ButtonBlockMove extends Applet
{
	final int RC = 4;	// 行列数
	final int N = RC*RC;	// 块的个数
	int []num = new int[N];   //数组num用于记录每个按钮上的数字-1
	Button [] btn = new Button[N];
	Button btnStart = new Button("开始游戏");

	public void init(){ //程序开始,对数组赋值,并显示按钮文字
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
		btn[N-1].setVisible( false ); //数字为N-1的按钮不显示

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
		//打乱顺序，开始游戏
		int i,j,k,t;    
		for( i = 1; i<500; i++){ 
			j = (int)(Math.random()* N);  //随机找两个下标,交换其对应的数组元素
			k = (int)(Math.random()* N);
			t = num[j]; num[j] = num[k]; num[k] = t;
		}
		
		for( i=0; i<N; i++ ){//显示它们
			btn[i].setLabel(""+ (num[i] + 1));
			btn[i].setVisible( true );
		}
		i = findBlank();       //其中有一个按钮需要隐藏
		btn[i].setVisible(false);
	}

	int findBlank(){  //函数: 找到哪一个为空位
		int i;
		for( i=0; i<N; i++ ){        //遍试
			if( num[i] == N-1 ) break; //找到值为N-1的这个元素
		}
		return i;         //函数返回值为找到的下标
	}

	void btn_Click(int index){  //第Index个按钮的事件处理
		int blank, t;
		blank = findBlank();                    //找到空白按钮(隐藏的)
		if( isNeighbor(blank, index)){       //如果相邻
			btn[index].setVisible( false );         //一个隐藏,一个显示
			btn[blank].setVisible( true );          //并交换其上的数字
			t = num[blank]; num[blank] = num[index]; num[index] = t;
			btn[blank].setLabel( ""+ (num[blank] + 1));
			btn[index].setLabel( ""+ (num[index] + 1));
		}
		checkResult();                       //调用过程,检查是否完成
	}

	boolean isNeighbor(int a, int b){  //判断是否相邻
		boolean r; //请注意其中的算术运算/关系运算/逻辑运算
		r = false;
		if( a == b - RC || a == b + RC ) r = true;  //上下相邻
		if( (a == b - 1 || a == b + 1) && a / RC == b / RC ) r = true; //左右相邻,注意要在同一排
		return r;
	}

	void checkResult(){  //检查结果
		int i;
		for( i=0; i<N; i++ ){     //检查每个数据
			if( num[i] != i ) return;  //如果尚未完全到位,退出该子程序
		}
		new Dialog(new Frame(), "你赢了!请点击 [开始] 再来一次.",true).show();
	}

	public static void main(String args[]) {
		Frame f = new Frame("排块游戏");
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


