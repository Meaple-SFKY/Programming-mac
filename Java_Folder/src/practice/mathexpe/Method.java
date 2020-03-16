package src.practice.mathexpe;

import java.lang.Math;

public class Method {
    private int size;
    private double answerPast[];
    private double answerNow[];
    public Method(int temp) {
        size = temp;
    }
    public void iterate() {
        Matrix matrix = new Matrix(size);
        matrix.getElements();
        answerPast = new double[size];
        answerNow = new double[size];
        System.out.println();
        System.out.println("-------------Jacobi--------------");
        System.out.print("0:");
        for (int i = 0; i < size; i++) {
            answerNow[i] = (double)Matrix.matrix[i][size] / Matrix.matrix[i][i];
            System.out.print(" " + answerNow[i]);
        }
        System.out.println();
        for (int k = 1; ; k++) {
            for (int i = 0; i < size; i++) {
                answerPast[i] = answerNow[i];
            }
            for (int i = 0; i < size; i++) {
                answerNow[i] = Matrix.matrix[i][size] / Matrix.matrix[i][i];
                for (int j = 0; j < size; j++) {
                    if (i != j)
                        answerNow[i] -= answerPast[j] * Matrix.matrix[i][j] / Matrix.matrix[i][i];
                }
            }
            System.out.print(k + ":");
            for (int i = 0; i < size; i++) {
                System.out.print(" " + answerNow[i]);
            }
            System.out.println();
            if (Math.abs(answerNow[0] - answerPast[0]) < Math.pow(10, -3)) {
                break;
            }
        }
        System.out.println();
        System.out.println("-----------------GS----------------");
        System.out.print("0:");
        for (int i = 0; i < size; i++) {
            answerNow[i] = (double)Matrix.matrix[i][size] / Matrix.matrix[i][i];
            System.out.print(" " + answerNow[i]);
        }
        System.out.println();
        for (int k = 1; ; k++) {
            for (int i = 0; i < size; i++) {
                answerPast[i] = answerNow[i];
            }
            for (int i = 0; i < size; i++) {
                answerNow[i] = Matrix.matrix[i][size] / Matrix.matrix[i][i];
                for (int j = 0; j < size; j++) {
                    if (i < j) {
                        answerNow[i] -= answerPast[j] * Matrix.matrix[i][j] / Matrix.matrix[i][i];
                    }
                    else if (i > j) {
                        answerNow[i] -= answerNow[j] * Matrix.matrix[i][j] / Matrix.matrix[i][i];
                    }
                }
            }
            System.out.print(k + ":");
            for (int i = 0; i < size; i++) {
                System.out.print(" " + answerNow[i]);
            }
            System.out.println();
            if (Math.abs(answerNow[0] - answerPast[0]) < Math.pow(10, -3)) {
                break;
            }
        }
        System.out.println();
        System.out.println("------------------SOR----------------");
        System.out.print("0:");
        for (int i = 0; i < size; i++) {
            answerNow[i] = 1.25 * (double)Matrix.matrix[i][size] / Matrix.matrix[i][i];
            System.out.print(" " + answerNow[i]);
        }
        System.out.println();
        for (int k = 1; ; k++) {
            for (int i = 0; i < size; i++) {
                answerPast[i] = answerNow[i];
            }
            for (int i = 0; i < size; i++) {
                answerNow[i] = 1.25 * Matrix.matrix[i][size] / Matrix.matrix[i][i];
                for (int j = 0; j < size; j++) {
                    if (i < j) {
                        answerNow[i] -= 1.25 * answerPast[j] * Matrix.matrix[i][j] / Matrix.matrix[i][i];
                    }
                    else if (i == j) {
                        answerNow[i] -= 1.25 * answerPast[j] / Matrix.matrix[i][i];
                    }
                    else {
                        answerNow[i] -= 1.25 * answerNow[j] * Matrix.matrix[i][j] / Matrix.matrix[i][i];
                    }
                }
            }
            System.out.print(k + ":");
            for (int i = 0; i < size; i++) {
                System.out.print(" " + answerNow[i]);
            }
            System.out.println();
            if (Math.abs(answerNow[0] - answerPast[0]) < Math.pow(10, -3)) {
                break;
            }
        }
    }
}