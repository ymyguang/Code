class ExceptionSimple 
{
	int a = 10;
	public static void main(String[] args) 
	{
		int a = 0;
		try
		{ 
			a= Integer.parseInt( "2" );
			a /= 0;  
			// ע��: ��������0,������쳣  ��  0.0/0=NaN  FPN/0=������,-FPN/0=������, 
		}
		catch(ArithmeticException ea ){ System.out.println("ea:" +ea); }
		catch(NumberFormatException en ) { System.out.println("en:" +en); }
		catch(NullPointerException ep ){ System.out.println("ep:" +ep); }
		catch(IndexOutOfBoundsException eb ){ System.out.println("eb:" +eb); }
		catch(Exception e) { System.out.println("e:" + e); }  //��catch����Exception,��catch����
		finally{ System.out.println("finally executed.");}
		System.out.println("Hello World!"+a );
	}
}
