class StringAssign 
{
	public static void main(String[] args) 
	{
		// ���ֳ������ַ�����ֵ�ķ���
		String s;

		// ֱ�Ӹ�ֵ
		s = "Hello";
		s = new String( "Hello" );
		
		// ʹ��StringBuilder
		s = new String( new StringBuffer( "Hello" ) );
		s = new StringBuffer( "Hello").toString();

		// ����תΪ�ַ���
		s = new Object().toString();
		s = "" + new Object();
	}
}
