import java.io.*;

class A {
	public void methodA() throws IOException {
		  //����
	}
}

class B1 extends A {
	public void methodA() throws FileNotFoundException {
		  //����
	}
}

class B2 extends A {
	public void methodA() throws Exception {  // Error!
		  // ����
	}
}
