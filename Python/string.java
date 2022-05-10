public class string {
    public static void main(String[] args) {
        String s = "I've been reading books of old";
        System.out.println(s);
        System.out.println(s.replaceAll("books", "poems"));

        String s2 = "2000/12/25";
        String s3 = s2.substring(0,4);
        System.out.println(s3);
        System.out.println(s2.substring(4));
        System.out.println(s2.substring(5));
    }
}
