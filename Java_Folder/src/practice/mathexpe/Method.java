package src.practice.mathexpe;

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
        System.out.print("0:");
        for (int i = 0; i < size; i++) {
            answerNow[i] = (double)Matrix.matrix[i][size] / Matrix.matrix[i][i];
            System.out.print(" " + answerNow[i]);
        }
        System.out.println();
        for (int k = 1; k < 10; k++) {
            for (int i = 0; i < size; i++) {
                answerPast[i] = answerNow[i];
            }
            for (int i = 0; i < size; i++) {
                answerNow[i] = Matrix.matrix[i][size];
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
        }
        System.out.println();
        System.out.print("0:");
        for (int i = 0; i < size; i++) {
            answerNow[i] = (double)Matrix.matrix[i][size] / Matrix.matrix[i][i];
            System.out.print(" " + answerNow[i]);
        }
        System.out.println();
        for (int i = 0; i < size; i++) {
            answerNow[i] = Matrix.matrix[i][size];
        }
        for (int k = 1; k < 10; k++) {
            for (int i = 0; i < size; i++) {
                answerNow[i] = Matrix.matrix[i][size];
                for (int j = 0; j < size; j++) {
                    if (i != j) {
                        answerNow[i] -= answerNow[j] * Matrix.matrix[i][j] / Matrix.matrix[i][i];
                    }
                }
            }
            System.out.print(k + ":");
            for (int i = 0; i < size; i++) {
                System.out.print(" " + answerNow[i]);
            }
            System.out.println();
        }
    }
}