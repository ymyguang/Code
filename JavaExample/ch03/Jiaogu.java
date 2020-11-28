import java.io.*;
class Jiaogu 
{
	public static void main(String[] args) 
	{
		System.out.print("\n请输入一个数:");
		try{
			BufferedReader br = new BufferedReader ( new InputStreamReader( System.in ) );
			String s = br.readLine();
			int a = Integer.parseInt( s );

			while( a != 1 )
			{
				System.out.print( " " +a );
				if( a%2==1 ) a = a*3+1; else a /= 2;
			}
			System.out.println(" " +a);
		}
		catch(Exception e){}
	}
}
