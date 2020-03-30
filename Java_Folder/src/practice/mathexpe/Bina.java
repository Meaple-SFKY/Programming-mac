package src.practice.mathexpe;

public class Bina {
    public static void main(String[] args) {
        double num = 0.472;
        double sum;
        for (int i = 0; i < 50; i++) {
            sum = (-0.4255) * Math.pow(num, 2) + 1.304685 * num - 0.0254638;
            if (sum < 0.5) {
                num = (num + 0.48) / 2;
            }
            else {
                num = (num + 0.472) / 2;
            }
            System.out.println(num + "  " + sum);
        }
    }
}