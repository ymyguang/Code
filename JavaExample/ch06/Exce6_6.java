class MyException extends Exception {
   	private int idnumber;
 	public MyException(String message, int id) {
		super(message);
		this.idnumber = id;
 	} 
	public int getId() {
		return idnumber;
 	}
}

public class Exce6_6{
    public void regist(int num) throws MyException {
 	    if(num < 0) {
   			  System.out.println("�ǼǺ���" + num );
 	          throw new MyException("����Ϊ��ֵ��������",3);
 	    }
    }
    
	public void manager() {
 	    try {
	        regist(-100);
 	    } catch (MyException e) {
 	        System.out.println("�Ǽ�ʧ�ܣ���������" + e.getId());
	    }
	    System.out.println("���εǼǲ�������");
    }
    
	public static void main(String args[]){
	    Exce6_6 t = new Exce6_6();
	    t.manager();
    }
}
