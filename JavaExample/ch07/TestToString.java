class MyDate {
    int day,month,year;
    public MyDate(int i,int j,int k) {
    	day = i;
    	month = j;
    	year = k;
    }
}

class MyOkDate extends MyDate{
	public MyOkDate(int i,int j,int k ){
		super(i,j,k);
	}
	public String toString(){
		return year + "-" + month + "-" + day;
	}
}

public class TestToString{
	public static void main(String[] args) {
 	   MyDate m1 = new MyDate(24, 3, 2001);
 	   MyDate m2 = new MyOkDate(24, 3, 2001);
	   System.out.println( m1 ); //œ‘ æMyDate@132f0db
	   System.out.println( m2 ); //œ‘ æ2001-3-24
   }
}
