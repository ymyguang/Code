package p2;

class Derived extends p1.Original{
	void Access( ){
		System.out.println("**** ��ͬ���е����� ****");
		// System.out.println("friendly member "+n_friendly);//���ܷ���
		// System.out.println("private member "+n_private);//���ܷ���
		System.out.println("protected member "+n_protected);//������Է��ʸ���
		System.out.println("public member "+n_public);
		
		p1.Original o = new p1.Original( );
		System.out.println("**** �����ڲ�ͬ���еĸ��� ****");
		// System.out.println("friendly member "+o.n_friendly);//���ܷ���
		// System.out.println("private member "+o.n_private);//���ܷ���
		// System.out.println("protected member "+o.n_protected);//���ܷ���
		System.out.println("public member "+o.n_public);
	}
}

class AnotherPackageClass{
	void Access( ){
		p1.Original o = new p1.Original( );
		System.out.println("**** ��һ���е������� ****");
		// System.out.println("friendly member "+o.n_friendly);//���ܷ���
		// System.out.println("private member "+o.n_private);//���ܷ���
		// System.out.println("protected member "+o.n_protected);//���ܷ���
		System.out.println("public member "+o.n_public);
	}
}

public class AccessControl{
	public static void main( String args[ ] ){
		Derived d = new Derived( );
		d.Access( );
		AnotherPackageClass a = new AnotherPackageClass( );
		a.Access( );
	}
}
