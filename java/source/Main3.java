public class Main3 {
    public static void main(String[] arge) {
          String s = """
             SELECT * FROM
              users
            WHERE id > 100
             ORDER BY name DESC
            """;
        System.out.println(s);
    }
}
