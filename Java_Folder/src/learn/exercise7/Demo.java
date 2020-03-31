//此类在src.learn.exercise6包里
package src.learn.exercise7;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;


//定义Demo类，包含主方法，继承JFrame父方法，实现MouseListener接口
public class Demo extends JFrame implements MouseListener {

    //默认添加
    /**
     *
     */
    private static final long serialVersionUID = 1L;

    //定义main方法
    public static void main(String[] args) {
        Demo demo = new Demo();
    }

    //x,y分别表示鼠标点击位置
    //sign表示右键或者左键，点击一次将对其值重新设定
    //width,height分别表示显示器尺寸的三分之一，使得显示效果更佳
    public int x, y, sign, width, height;

    //获取x,y的值
    public int getX() {
        return this.x;
    }

    public int getY() {
        return this.y;
    }

    //设定x,y的值
    public void setX(int X) {
        this.x = X;
    }

    public void setY(int Y) {
        this.y = Y;
    }

    //设定sign的值
    public void setFlag(int flag) {
        sign = flag;
    }

    //获取sign的值
    public int getFlag() {
        return this.sign;
    }

    //构造函数
    public Demo() {
        //绑定监听器
        addMouseListener(this);
        //获取屏幕尺寸
        Toolkit kit = Toolkit.getDefaultToolkit();
        Dimension screenSize = kit.getScreenSize();
        width = (int)screenSize.getWidth() / 3;
        height = (int)screenSize.getHeight() / 3;
        setBounds(width, height, width, height);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void paint(Graphics g) {
        int flag = getFlag();
        if (flag == 1) {
            g.setColor(Color.GREEN);
            g.drawOval(x, y, 20, 20);
        }
        else if (flag == 2) {
            g.setColor(Color.RED);
            g.drawRect(x, y, 20, 20);
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        setX(e.getX());
        setY(e.getY());
        if (e.getButton() == MouseEvent.BUTTON1) {
            setFlag(1);
            repaint();
        }
        else if (e.getButton() == MouseEvent.BUTTON3) {
            setFlag(2);
            repaint();
        }
    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }
    
}