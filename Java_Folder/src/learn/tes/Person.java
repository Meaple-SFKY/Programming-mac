package src.learn.tes;

import java.util.Random;
import java.lang.Thread;

public class Person implements Runnable {
    private Racing racing;
    private int speed;
    private String name;

    /**
     * 
     */
    public Person(Racing racing, int maxSpeed, String name) {
        Random random = new Random();
        this.racing = racing;
        this.speed = random.nextInt(maxSpeed) + 5;
        this.name = name;
    }

    @Override
    public void run() {
        int position = 0;// 赛道中的位置
        int time = 0;// 已经比赛时间，秒为单位
        while (position < racing.getLineLength()) {
            // 跑步动态信息，每隔1秒输出比赛时间已经所处的位置
            // 补写代码区
            try {
                Thread.sleep(1000);
                System.out.println(position);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
        System.out.print(name+"结束，用时"+time+"秒");
        //调用racing的结束函数，告诉其本人比赛结束 racing.end(this);
       //补写代码区
        racing.end(this);
    }
}