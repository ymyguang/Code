public class TestEqualsString {
 	public static void main(String[] args) {
	   String name1 = new String("LiMing");
	   String name2 = new String("LiMing");
	   System.out.println( name1==name2 );  //������������ã������
	   System.out.println( name1.equals(name2) ); // ���ݣ����
	   
	   String name3 = "LiMing";
	   String name4 = "LiMing";
	   System.out.println( name3==name4 );  //��ͬ���������ã����
	   System.out.println( name3.equals(name4) ); // ���ݣ����
	}
}
