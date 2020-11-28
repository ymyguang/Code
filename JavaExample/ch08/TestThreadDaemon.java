import java.util.*;
public class TestThreadDaemon {
	public static void main(String args[]) {
		Thread t1 = new Daemon();
		System.out.println("Main End");
	}
}

class Daemon extends Thread {
	static int id = 0;
	Daemon(){
		id ++;
		setDaemon(true);
		start();
		if( id <5 ) new Daemon();
	}
	public void run() {
		System.out.println("Start");
		for(int i=0; i<10; i++ ){
			System.out.print( "\n-----" + i + "------" + new Date() +"\n");
			//try{ Thread.sleep(1000); } catch( InterruptedException e ){}
			//yield();
		}
	}
}

/*
9.2.4 Daemon�߳�
	�߳������֣�һ����Daemon�̣߳�һ���Ƿ�Daemon�̡߳���Java�����У������з�Demon�̣߳�����������Ͳ����������Daemon�̣߳��������������������������У�����Demon�߳̿������ں�̨�������
	ͨ������isDaemon()���ɼ��һ���߳��ǲ���һ��Daemon����setDaemon (boolean flg)�������Խ�һ���߳���ΪDaemon�̡߳���һ��Daemon�߳��д��������̣߳�Ҳ�Զ���Daemon�̡߳�

*/