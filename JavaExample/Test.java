import java.io.*;
class Test 
{
	public static void main(String[] args) 
	{
		A a = new A();
	}
}


class A
{
	int a;
	static class B 
	{

	}
	Object o = new Object() { int a=5; };
	void m(){
		final int b=5;
		int y;
		y=6;
		class C
		{
			void m(){int x=b;}
		}
	}
}


