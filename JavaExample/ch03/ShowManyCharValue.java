import java.io.*;
class  ShowManyCharValue
{
	public static void main(String[] args) 
	{
		try{
			
			char c;
			do
			{
				System.out.println("�����ַ������س�����#����");
				c = (char)System.in.read();
				System.in.skip(2);  //���Իس�����
				System.out.println( c + "��AsciiֵΪ:" + (int)c );
			}
			while ( c != '#' );
		}catch(Exception e){}
	}
}
