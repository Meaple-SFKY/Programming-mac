package src.temporary.magic;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Demo extends JFrame implements MouseListener {

    /**
     *
     */
    private static final long serialVersionUID = 1L;

    public static void main(String[] args) {
        Demo demo = new Demo();
    }

    public int x, y, sign, width, height;

    public int getX() {
        return this.x;
    }

    public int getY() {
        return this.y;
    }

    public void setX(int X) {
        this.x = X;
    }

    public void setY(int Y) {
        this.y = Y;
    }

    public void setFlag(int flag) {
        sign = flag;
    }

    public int getFlag() {
        return this.sign;
    }

    public Demo() {
        addMouseListener(this);
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