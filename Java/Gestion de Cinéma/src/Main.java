public class Main {
    public static void main(String[] args) {

        Cinema c = new Cinema(2);

        Spectateur s1 = new Spectateur("Ali");
        Spectateur s2 = new Spectateur("Karim");
        Spectateur s3 = new Spectateur("Sara");
        Spectateur s4 =  new Spectateur("Nada");

        System.out.println(c.placer(s1));
        System.out.println(c.placer(s2));
        System.out.println(c.placer(s3));
        System.out.println(c.placer(s4));

        System.out.println(c);
    }
}
