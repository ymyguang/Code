import java.util.*;
public class TestHashSet {
	public static void main(String[] args) {
		HashSet h = new HashSet();
		h.add("1st");
		h.add("2nd");
		h.add("3rd");
		h.add("4th");
		h.add("5th");
		h.add(new Integer(6));
		h.add(new Double(7.0));

		h.add("2nd");          // �ظ�Ԫ��, δ������
		h.add(new Integer(6)); // �ظ�Ԫ��, δ������

		m1(h);
	}
	public static void m1(Set s){
		System.out.println(s);  // ��������toString()����,ע����ʾʱ,Ԫ����˳��
	}
}