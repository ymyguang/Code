import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.sql.*;
import java.util.*;
import javax.swing.table.*;

class JDBCJTable extends Frame
{
	AbstractTableModel tm;		//����һ����AbstractTableModel����
	JTable table;				//����һ����JTable����
	JScrollPane scrollpane;		//����һ������������
	String titles[];			//��ά������
	Vector records;				//����һ����������

	public void init(){
		records = new Vector();	//ʵ��������
		tm = new AbstractTableModel(){
			public int getColumnCount(){
				return titles.length;	//ȡ�ñ������
			}
			public int getRowCount(){
				return records.size();		//ȡ�ñ������
			}
			public Object getValueAt(int row,int column){
				if(!records.isEmpty())		//ȡ�õ�Ԫ���е�����ֵ
					return ((Vector)records.elementAt(row)).elementAt(column);
				else
					return null;
			}
			public String getColumnName(int column){
				return titles[column];	//���ñ������
			}
			public void setValueAt(Object value,int row,int column){
					//����ģ�Ͳ��ɱ༭���÷�������Ϊ��
			}
			public Class getColumnClass(int c){
				return getValueAt(0,c).getClass();	//ȡ��������������
			}
			public boolean isCellEditable(int row,int column){
				return false;//���õ�Ԫ�񲻿ɱ༭��Ϊȱʡʵ��
			}
		};
	}

	public void start() throws SQLException, ClassNotFoundException{
		//String driver="com.sybase.jdbc.SybDriver";
		//SybDriver sybdriver=(SybDriver)
		//Class.forName(driver).newInstance();
		//DriverManager.registerDriver(sybdriver);
		//String user="sa";
		//String password="";
		//String url="jdbc:sybase:Tds:202.117.203.114:5000/WORKER";
		//SybConnection connection=(SybConnection)
		//	DriverManager.getConnection(url,user,password);

		// ���� jdbc-odbc ����������
		Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");

		//����JDBC URL
		String url   = "jdbc:odbc:pubs";

		//�õ������ݿ������
		Connection connection = DriverManager.getConnection (url);

		//��ʾ��ѯ����� 
		Statement stmt = connection.createStatement();
		ResultSet rs = stmt.executeQuery("select * from authors");
		ResultSetMetaData meta = rs. getMetaData();	//�õ�Ԫ����

		int cols = meta.getColumnCount();
		System.out.println( cols );
		titles = new String[ cols ];
		for( int i=0; i<cols; i++){
			titles[i] = meta.getColumnName(i+1);	//�õ�����
		}

		records.removeAllElements();//��ʼ����������
		while(rs.next()){
			Vector rec_vector=new Vector();
			//�ӽ������ȡ���ݷ�������rec_vector��
			for ( int i=0; i<titles.length; i++ ){
				rec_vector.addElement(rs.getObject(i+1).toString());
			}
			records.addElement(rec_vector);
		}

		//���Ʊ�� 
		table=new JTable(tm);	//�����Լ�������ģ��
		table.setToolTipText("��ʾȫ����ѯ���");	//���ð�����ʾ
		table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);	//���ñ������ߴ�ģʽ
		table.setCellSelectionEnabled(false);	//���õ�Ԫ��ѡ��ʽ
		table.setShowVerticalLines(true);
		table.setShowHorizontalLines(true);
		scrollpane=new JScrollPane(table);		//�������Ϲ�����
		add( scrollpane );

		tm.fireTableStructureChanged();//���±��
	}

	public static void main( String [] args ){
		JDBCJTable f = new JDBCJTable();
		f.init();
		try{
			f.start();
		}catch( Exception e){ e.printStackTrace(); }
		f.setSize( 400,300);
		f.setTitle( "Show Database in JTable" );
		f.show();
		f.addWindowListener( new WindowAdapter(){
			public void windowClosing( WindowEvent e){System.exit(0);}
		});
	}

}



