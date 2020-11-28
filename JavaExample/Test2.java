import java.util.regex.*; 
import java.io.*;
public class Test2 { 
  public static void main(String args[]) { 
    String str = "a?? ??Test for it.????Just a test.?????? Maybe.????"; 
    str = Pattern.compile("\\?").matcher(str).replaceAll("*"); 
    System.out.println(str);
	try{
	A a=new B();
	a.m();
	a.i=4;
	}
	catch(Throwable b ){b.printStackTrace();}
	finally{}
	String s="aaa";
	System.out.println( +-+-3 );
	char c=1234;
	lbl: c=9;
		while(args.length==0);
  } 
}
class A
{
	A() throws Exception {  }
	int m(){ System.out.println("A"); return 1;}
	static int i;
	//static RandomAccessFile f = new RandomAccessFile("aa","r");
	static {  i=3;  }
}

class B extends A
{
	B() throws Exception {  }
	synchronized int m() { System.out.println("B");return 0;}
}

interface IA{
	void m() throws Exception;
}

interface IB{
	void m(int i);
}

abstract class C implements IA,IB
{
	public void m(){}
};

class D extends C
{
	final public void m(){}
	public void m(int i){}
	synchronized static void p(){}
};