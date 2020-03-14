package src.practice.mathexpe;

import java.util.Scanner;

public class Matrix {
    public static int matrix[][];
    private int line[];
    private static int size;
    public Matrix(int temp) {
        size = temp;
        matrix = new int[size][size + 1];
        line = new int[size * (size + 1)];
    }
    private void setMatrix() {
        int temp = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size + 1; j++) {
                matrix[i][j] = line[temp++];
            }
        }
    }
    public void getElements() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Please enter elements separated by 'Space': ");
        for (int i = 0; i < size * (size + 1); i++) {
            line[i] = scan.nextInt();
        }
        setMatrix();
        System.out.println("Matrix initialized!");
        scan.close();
    }
}