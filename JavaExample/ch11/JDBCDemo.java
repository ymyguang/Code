/*
 * @(#)JDBCDemo.java	2000/06/18
 */
import java.sql.*;

/**
 * ��ʾJDBC�������ݿ�ĸ���ܣ�������Ĵ���
 * ��CREATE����ɾ����DROP������¼�Ĳ��루INSERT����
 * ѡ��SELECT���͸��ģ�UPDATE���Ȳ��� ��
 * @version	1.00 2000/06/18
 * @author TangDashi
 * @since   JDK1.2
 */
public class JDBCDemo 
{
	public static void main(String args[]) 
	{
		try {
			Statement stmt;
			PreparedStatement pstmt;
			ResultSet rs;
			
			// ���� jdbc-odbc ����������
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");

			//����JDBC URL
			String url   = "jdbc:odbc:JDBCDemo";

			//�õ������ݿ������
			Connection con = DriverManager.getConnection (url);
			
			//��ʾURL��������Ϣ
			System.out.println("URL: " + url);
			System.out.println("Connection: " + con);
			
			//�õ�һ��Statement����
			stmt = con.createStatement();
			
			//�����DemoTable�Ѿ����ڣ���ɾ��֮����������һ���쳣
			System.out.println("DROP TABLE DemoTable, if it exists.");
			try{
				stmt.executeUpdate("DROP TABLE DemoTable");
			}catch(Exception e){
				System.out.print(e);
				System.out.println("No existing table to delete");
			}

			//�����ݿ��д���һ����DemoTable
			stmt.executeUpdate("CREATE TABLE DemoTable ("
				+ "test_id int,test_val char(15) not null)");
			System.out.println("table DemoTable created!");
			
			//�ڱ��в���һЩֵ
			stmt.executeUpdate("INSERT INTO DemoTable ("
				+ "test_id, test_val) VALUES(1,'One')");
			stmt.executeUpdate("INSERT INTO DemoTable ("
				+ "test_id, test_val) VALUES(2,'Two')");
			stmt.executeUpdate("INSERT INTO DemoTable ("
				+ "test_id, test_val) VALUES(3,'Three')");
			stmt.executeUpdate("INSERT INTO DemoTable ("
				+ "test_id, test_val) VALUES(4,'Four')");
			stmt.executeUpdate("INSERT INTO DemoTable ("
				+ "test_id, test_val) VALUES(5,'Five')");

			//�õ���һ��Statement����
			stmt = con.createStatement();

			//��ѯ���ݿ��еı�DemoTable���õ���test_id���������м�¼��
			//���洢��ResultSet����rs��
			rs = stmt.executeQuery("SELECT * from DemoTable ORDER BY test_id");

			//��ʾ��DemoTable�е����м�¼
			System.out.println("Display all results:");
			while(rs.next())
			{
				int theInt= rs.getInt("test_id");
				String str = rs.getString("test_val");
				System.out.println("\ttest_id= " + theInt + "\tstr = " + str);
			}

			// ������׼���õ���䣬���¡�DemoTable������
			// ĳ����¼��test_val�ֶΡ�
			// ��׼���õ�����������������
			pstmt = con.prepareStatement(
				"UPDATE DemoTable SET test_val = ? WHERE test_id = ?");


			//���ı�DemoTable�еĵ�2����¼��test_val�ֶε�ֵ
			// ����UPDATE����еġ���������ִ��UPDATE���
			pstmt.setString(1, "Hello!");
			pstmt.setInt(2, 2);
			pstmt.executeUpdate();
			System.out.println("Update row number 2: OK.");

			//��ʾ��DemoTable�и��º�ĵ�2����¼
			stmt = con.createStatement();
			rs = stmt.executeQuery("SELECT * from DemoTable ORDER BY test_id");
			System.out.println("Display row 2:");
			if (rs.next() && rs.next())
			{
				int theInt= rs.getInt("test_id");
				String str = rs.getString("test_val");
				System.out.println("\ttest_id= " + theInt + "\tstr = " + str);
			}

			con.close();	//�ر������ݿ������
		}catch( Exception e ) {
			e.printStackTrace();
		}
	}
}
