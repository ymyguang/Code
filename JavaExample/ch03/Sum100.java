public class Sum100{
	public static void main( String args[ ] ){
		int sum,n;

		System.out.println("\n**** for statement ****");
		sum=0;
		for( int i=1; i<=100; i++){ //��ʼ��,ѭ������,ѭ���ı�
			sum+=i;		//ѭ����
		}
		System.out.println("sum is "+sum);

		System.out.println("\n**** while statement ****");
		sum=0;
		n=100;			//��ʼ��
		while( n>0 ){	//ѭ������
			sum+=n;		//ѭ����
			n--;		//ѭ���ı�
		}
		System.out.println("sum is "+sum);

		System.out.println("\n**** do_while statement ****");
		sum=0;
		n=0;			//��ʼ��
		do{
			sum+=n;		//ѭ����
			n++;		//ѭ���ı�
		}while( n<=100 );//ѭ������
		System.out.println("sum is "+sum);
	}
}
