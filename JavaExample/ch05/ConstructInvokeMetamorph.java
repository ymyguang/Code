class ConstructInvokeMetamorph 
{
	public static void main(String[] args){ 
		Person p = new Student("����", 18, "����");
	}
}

class Person
{
	String name="δ����"; 
	int age=-1;
	Person( String name, int age ){
		this.name=name; this.age=age; 
		sayHello();
	}
	void sayHello(){
		System.out.println( "����һ���ˣ������У�" + name + ",����Ϊ��"+ age );
	}
}

class Student extends Person
{
	String school="δ��ѧУ";
	Student( String name, int age, String school ){
		super( name, age );
		this.school = school;
	}
	void sayHello(){
		System.out.println( "����ѧ���������У�" + name + ",����Ϊ��"+ age + ",ѧУ�ڣ�" + school );
	}
}

