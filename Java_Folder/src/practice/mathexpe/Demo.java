package src.practice.mathexpe;

public class Demo {
    public static void main(String[] args) {
        System.out.println("The number of rows in the matrix is '4'");
        int row = 4;
        Method method = new Method(row);
        method.iterate();
    }
}