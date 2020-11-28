import java.util.*;
class TestQueue 
{
	public static void main(String[] args) 
	{
		Queue q = new Queue();
		for( int i=0; i<5; i++ )
			q.enqueue( ""+i );
		while( ! q.isEmpty() )
			System.out.println( q.dequeue() );
	}
}

class Queue extends LinkedList
{
	void enqueue( Object obj ){
		addLast( obj );
	}
	Object dequeue(){
		return removeFirst();
	}
	public boolean isEmpty(){
		return super.isEmpty();
	}
}
