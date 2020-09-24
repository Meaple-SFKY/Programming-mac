package src.learn;

public class test {
    public static void main(String[] args) {
        switch (args.length == 0 ? "" : args[1]) {
            case "lower": {
                System.out.println("yes");
                break;
            }
            case "upper": {
                System.out.println("no");
                break;
            }
            default: {
                System.out.println("one");
                break;
            }
        }
    }
}