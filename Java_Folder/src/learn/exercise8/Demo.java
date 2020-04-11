//在src.learn.exercise8包中
package src.learn.exercise8;

import java.lang.Thread;

//定义Demo类，此类包含主方法
public class Demo {
    public static void main(String[] args) {
        MyThread little = new MyThread(1, 1000000);
        MyThread large = new MyThread(1000001, 2000000);
        //启动线程
        little.start();
        large.start();
        //分别输出两部分质数的个数
        System.out.println("1 ~ 1000000 间的质数个数是：" + little.getNum());
        System.out.println("1000000 ~ 2000000 间的质数个数是：" + large.getNum());
    }
}

//定义MyThread类，继承Thread类
class MyThread extends Thread {
    private int tempHead, tempEnd;
    private int num;

    //构造函数，传入起始和末尾数字
    MyThread(int temp1, int temp2) {
        tempHead = temp1;
        tempEnd = temp2;
    }

    //返回质数的个数
    public int getNum() {
        return num;
    }

    //重写run函数
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
                num++;
                System.out.print(temp + "  ");
            }
        }
    }
}