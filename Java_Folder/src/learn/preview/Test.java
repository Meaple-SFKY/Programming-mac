package src.learn.preview;

public class Test
{
    public static void main(String[] args)
    {
        String greeting = "Hello";
        int index = greeting.offsetByCodePoints(0, 1);
        int cp = greeting.codePointAt(index);
        System.out.println(index);
        System.out.println(cp);
        System.out.println("你好");
    }
}
