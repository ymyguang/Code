class  A
{
	int a=9;
	public void main(Object o, double p) 
	{
		final int i=a;
		class B
		{
			int b=i;
		}
		Object x = new B();
		System.out.println("Hello World!");
	}
	public void m(){
		this.a = 88;
		main( this, 3.0);
		C.b = 1;
	}
}

class B
{
	static int b;
}

class C extends B
{
	static int c;
}
