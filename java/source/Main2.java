public class Main2 {
    public static void main(String[] arge) {
        double r1 = 0;
        double r2 = 0;
        double a = 1.0;
        double b = 3.0;
        double c = -4.0;
        r1 = (-b+Math.sqrt(b*b-4*a*c))/2*a;
        r2 = (-b-Math.sqrt(b*b-4*a*c))/2*a;
        System.out.println(r1);
        System.out.println(r2);
        System.out.println(r1 == 1 && r2 == -4 ? "通过" : "失败");
    }
}