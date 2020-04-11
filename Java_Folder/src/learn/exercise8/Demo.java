package src.learn.exercise8;

import java.lang.Thread;

public class Demo {
    public static void main(String[] args) {
        MyThread little = new MyThread(1, 1000000);
        MyThread large = new MyThread(1000001, 2000000);
        little.start();
        large.start();
    }
}

class MyThread extends Thread {
    private int tempHead, tempEnd;

    MyThread(int temp1, int temp2) {
        tempHead = temp1;
        tempEnd = temp2;
    }

    public void run() {
        for (int temp = tempHead; temp <= tempEnd; temp++) {
            boolean flag = true;
            for (int i = 2; i < temp / 2; i++) {
                if (temp % i == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                System.out.print(temp + "  ");
            }
        }
    }
}