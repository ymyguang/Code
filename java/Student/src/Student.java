import com.sun.jdi.InconsistentDebugInfoException;
import org.xml.sax.SAXNotRecognizedException;
import java.util.*;

public class Student {
    int ID;
    String name;
    float grade;

    public Student(int ID, String name, float grade) {
        this.ID=ID;
        this.name=name;
        this.grade=grade;
    }

    public float getGrade(int ID,Map<Integer, Float> map) {
        return map.get(ID);
    }
    public static void main(String[] args) {
        Student stu=new Student(1901080214,"刘赵淳",100);
        Map<Integer,Float> map = new HashMap<>();
        map.put(stu.ID,stu.grade);
        Scanner in = new Scanner(System.in);
        System.out.println("输入查询的学号");
        int t_id = in.nextInt();
        System.out.println("学号:" + t_id + "  成绩：" + stu.getGrade(t_id,map));
    }
}
