public class Prime100Continue{
	public static void main( String args[ ] ){
		System.out.println(" **** 100--200������ ****");
		int n=0;
		outer: for(int i=101;i<200;i+=2){ //���ѭ��
			for(int j=2; j<i; j++){ //�ڲ�ѭ��
				if( i%j==0 )		//������������������ѭ��
					continue outer;
			}
			System.out.print(" "+i);//��ʾ����
			n++;					//������� 
			if( n<10 )				//δ��10�������򲻻���
				continue;	
			System.out.println( );
			n=0;
		}
		System.out.println( );
	}
}
