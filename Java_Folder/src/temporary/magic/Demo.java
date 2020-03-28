package src.temporary.magic;

import java.awt.*;
import javax.swing.*;

public class Demo {
    public static void main(String[] args) {
        JFrame jFrame = new JFrame();
        JMenuBar jMenuBar = new JMenuBar();
        jFrame.setJMenuBar(jMenuBar);
        JMenu jMenuOne = new JMenu("开始");
        JMenu jMenuTwo = new JMenu("文件");
        JMenu jMenuThree = new JMenu("编辑");
        JMenu jMenuFour = new JMenu("选择");
        JMenu jMenuFive = new JMenu("查看");
        jMenuBar.add(jMenuOne);
        jMenuBar.add(jMenuTwo);
        jMenuBar.add(jMenuThree);
        jMenuBar.add(jMenuFour);
        jMenuBar.add(jMenuFive);
        JMenuItem jMenuItem1 = new JMenuItem("关于");
        JMenuItem jMenuItem2 = new JMenuItem("个性化");
        JMenuItem jMenuItem3 = new JMenuItem("外观");
        JMenuItem jMenuItem4 = new JMenuItem("新建文件");
        JMenuItem jMenuItem5 = new JMenuItem("打开文件");
        JMenuItem jMenuItem6 = new JMenuItem("打开文件夹");
        JMenuItem jMenuItem7 = new JMenuItem("剪切");
        JMenuItem jMenuItem8 = new JMenuItem("复制");
        JMenuItem jMenuItem9 = new JMenuItem("粘贴");
        JMenuItem jMenuItem10 = new JMenuItem("全选");
        JMenuItem jMenuItem11 = new JMenuItem("反选");
        JMenuItem jMenuItem12 = new JMenuItem("取消选择");
        JMenuItem jMenuItem13 = new JMenuItem("错误");
        JMenuItem jMenuItem14 = new JMenuItem("终端");
        JMenuItem jMenuItem15 = new JMenuItem("输出");
        jMenuOne.add(jMenuItem1);
        jMenuOne.add(jMenuItem2);
        jMenuOne.add(jMenuItem3);
        jMenuTwo.add(jMenuItem4);
        jMenuTwo.add(jMenuItem5);
        jMenuTwo.add(jMenuItem6);
        jMenuThree.add(jMenuItem7);
        jMenuThree.add(jMenuItem8);
        jMenuThree.add(jMenuItem9);
        jMenuFour.add(jMenuItem10);
        jMenuFour.add(jMenuItem11);
        jMenuFour.add(jMenuItem12);
        jMenuFive.add(jMenuItem13);
        jMenuFive.add(jMenuItem14);
        jMenuFive.add(jMenuItem15);
        jFrame.setBounds(300, 300, 500, 400);
        JTextField jTextField = new JTextField(10);
        jTextField.setText("Hello");
        jFrame.add(jTextField);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jFrame.setVisible(true);
    }
}