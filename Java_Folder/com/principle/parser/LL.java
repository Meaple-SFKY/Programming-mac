package com.principle.parser;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.util.Vector;

//以LL（1）分析法对任意输入的符号串进行分析的语法分析程序
public class LL extends JFrame implements ActionListener {
    private static final long serialVersionUID = 1L;
    JTextField tf1;
    JTextField tf2;
    JLabel l;
    JButton b0;
    JPanel p1, p2, p3;
    JTextArea t1, t2, t3;
    JButton b1, b2, b3;
    JLabel l0, l1, l2, l3, l4;
    JTable table;
    Statement sta;
    Connection conn;
    ResultSet rs;
    DefaultTableModel dtm;
    String Vn[] = null;
    Vector<String> P = null;

    int firstComplete[] = null;// 存储已判断过first的数据
    char first[][] = null;// 存储最后first结果
    int followComplete[] = null;// 存储已判断过follow的数据
    char follow[][] = null;// 存储最后follow结果
    char select[][] = null;// 存储最后select结果
    int LL = 0;// 标记是否为LL（1）
    String vt_tou[] = null;// 储存Vt
    Object shuju[][] = null;// 存储表达式数据
    char yn_null[] = null;// 存储能否推出空

    LL()// 基本布局
    {
        setLocation(100, 0);
        setSize(700, 780);
        tf1 = new JTextField(13);
        tf2 = new JTextField(13);
        l = new JLabel(">>");
        l0 = new JLabel("输入字符串：");
        l1 = new JLabel("输入的文法为：                                                                         ");
        l2 = new JLabel(" ");
        l3 = new JLabel("分析的结果：                                                                              ");
        l4 = new JLabel(
                "预测分析表：                                                                                                                                             ");
        // p1=new JPanel();
        p2 = new JPanel();
        p3 = new JPanel();
        t1 = new JTextArea(24, 20);
        t2 = new JTextArea(1, 30);
        t3 = new JTextArea(24, 40);
        b0 = new JButton("确定(S为开始)");
        b1 = new JButton("       判断文法                ");
        b2 = new JButton("输入");
        b3 = new JButton("清空");
        table = new JTable();
        JScrollPane jp1 = new JScrollPane(t1);
        JScrollPane jp2 = new JScrollPane(t2);
        JScrollPane jp3 = new JScrollPane(t3);
        p2.add(tf1);
        p2.add(l);
        p2.add(tf2);

        p2.add(b0);
        p2.add(b1);
        p2.add(l0);
        p2.add(l2);
        p2.add(jp2);
        p2.add(b2);
        p2.add(b3);

        p2.add(l1);
        p2.add(l3);
        p2.add(jp1);
        p2.add(jp3);

        p3.add(l4);
        p3.add(new JScrollPane(table));
        add(p2, "Center");
        add(p3, "South");

        b0.addActionListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        table.setPreferredScrollableViewportSize(new Dimension(660, 200));
        setVisible(true);

    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == b0) {
            String a = tf1.getText();
            String b = tf2.getText();
            t1.append(a + '→' + b + '\n');
        }
        if (e.getSource() == b1) {
            t3.setText("");
            int Vnnum = 0, k;
            Vn = new String[100];
            P = new Vector<String>();
            String s[] = t1.getText().split("\n");

            for (int i = 0; i < s.length; i++) {
                if (s.length < 2) {
                    t3.setText("文法输入有误，请重新输入");// 判断长度是否符合
                    return;
                }
                if (s[i].charAt(0) <= 'Z' && s[i].charAt(0) >= 'A' && s[i].charAt(1) == '→') {
                    for (k = 0; k < Vnnum; k++) {
                        if (Vn[k].equals(s[i].substring(0, 1))) {
                            break;
                        }
                    }
                    if (Vnnum == 0 || k >= Vnnum) {
                        Vn[Vnnum] = s[i].substring(0, 1);// 存入Vn数据
                        Vnnum++;
                    }
                    P.add(s[i]);
                } else {
                    t3.setText("文法输入有误，请重新输入");
                    return;
                }
            }
            yn_null = new char[100];
            first = new char[Vnnum][100];
            int flag = 0;
            String firstVn[] = null;
            firstComplete = new int[Vnnum];

            for (int i = 0; Vn[i] != null; i++) // 依次求 FIRST**
            {
                flag = 0;
                firstVn = new String[20];
                if ((flag = add_First(first[i], Vn[i], firstVn, flag)) == -1)
                    return;
                firstComplete[i] = 1;

            }
            t3.append("first集：" + "\n"); // 显示FIRST**
            for (int i = 0; Vn[i] != null; i++) {
                t3.append("first(" + Vn[i] + ")={ ");
                for (int j = 0; first[i][j] != '\0'; j++) {
                    t3.append(first[i][j] + " , ");
                }
                t3.append("}" + "\n");
            }
            follow = new char[Vnnum][100];
            String followVn[] = null;
            followComplete = new int[Vnnum];

            for (int i = 0; Vn[i] != null; i++) // 求FOLLOW**
            {
                flag = 0;
                followVn = new String[20];
                if ((flag = tianjiaFollow(follow[i], Vn[i], followVn, flag)) == -1)
                    return;
                followComplete[i] = 1;
            }
            t3.append("follow集：" + "\n"); // 显示FOLLOW**
            for (int i = 0; Vn[i] != null; i++) {
                t3.append("follow(" + Vn[i] + ")={ ");
                for (int j = 0; follow[i][j] != '\0'; j++) {
                    t3.append(follow[i][j] + " , ");
                }
                t3.append("}" + "\n");
            }
            select = new char[P.size()][100];

            for (int i = 0; i < P.size(); i++) // 求SELECT**
            {
                flag = 0;
                tianjiaSelect(select[i], (String) P.elementAt(i), flag);
            }
            t3.append("select集：" + "\n"); // 显示SELECT**
            for (int i = 0; i < P.size(); i++) {
                t3.append("select(" + (String) P.elementAt(i) + ")={ ");
                for (int j = 0; select[i][j] != '\0'; j++) {
                    t3.append(select[i][j] + " , ");
                }
                t3.append("}" + "\n");
            }

            for (int i = 0; Vn[i] != null; i++)// 判断select交集是否为空
            {
                int biaozhi = 0;
                char save[] = new char[100];
                for (int j = 0; j < P.size(); j++) {
                    String t = (String) P.elementAt(j);

                    if (t.substring(0, 1).equals(Vn[i])) {
                        for (k = 0; select[j][k] != '\0'; k++) {
                            if (puanduanChar(save, select[j][k])) {
                                save[biaozhi] = select[j][k];
                                biaozhi++;
                            } else// 当有交集时，不为LL（1）文法
                            {
                                t3.append("不是LL（1）文法！！" + "\n");
                                return;
                            }
                        }
                    }
                }
            }
            char Vt[] = new char[100];
            int biaozhi = 0;
            for (int i = 0; i < P.size(); i++) {
                String t = (String) P.elementAt(i);
                for (int j = 2; j < t.length(); j++)// 提取表达式右侧的终结符存入Vt
                {
                    if (t.charAt(j) > 'Z' || t.charAt(j) < 'A') {
                        if (puanduanChar(Vt, t.charAt(j))) {
                            Vt[biaozhi] = t.charAt(j);
                            biaozhi++;
                        }
                    }
                }
            }
            if (puanduanChar(Vt, '#'))// 若可推出空集，则将#加入Vt。
            {
                Vt[biaozhi] = '#';
                biaozhi++;
            }
            vt_tou = new String[biaozhi + 1];// 根据select和表达式生成预测分析表
            shuju = new String[Vnnum][biaozhi + 1];
            String f = "";
            vt_tou[0] = f;
            for (int i = 0; i < biaozhi; i++) {
                vt_tou[i + 1] = String.valueOf(Vt[i]);
            }
            for (int i = 0; i < Vnnum; i++) {
                shuju[i][0] = Vn[i];
            }
            for (int i = 0; i < P.size(); i++) {
                String t = (String) P.elementAt(i);
                int j;
                for (j = 0; j < Vn.length; j++) {
                    if (Vn[j].equals(t.substring(0, 1))) {
                        break;
                    }
                }
                for (k = 0; select[i][k] != '\0'; k++) {
                    int y = puanduanXulie(Vt, select[i][k]);
                    shuju[j][y + 1] = t.substring(1);
                }
            }
            dtm = new DefaultTableModel(shuju, vt_tou);// 显示预测分析表
            table.setModel(dtm);
            LL = 1;
        }
        if (e.getSource() == b3)// 清空列表
        {
            tf1.setText("");
            tf2.setText("");
            t1.setText("");
            t2.setText("");
            t3.setText("");
            Vn = null;
            P = null;
            firstComplete = null;
            first = null;
            followComplete = null;
            follow = null;
            select = null;
            dtm = new DefaultTableModel();
            table.setModel(dtm);

        }

        if (e.getSource() == b2)// 输入字符串并预测分析
        {
            t3.setText("");
            if (LL == 1) {
                String s = t2.getText();
                for (int i = 0; i < s.length(); i++) {
                    if (s.charAt(i) == '\0') {
                        t3.setText("字符串中请不要加入空格" + "\n");

                        return;
                    }
                }
                char zifu[] = new char[100];// 剩余输入串
                char fenxi[] = new char[100];// 分析栈
                zifu[0] = '#';
                fenxi[1] = 'S';
                fenxi[0] = '#';
                int fzifu = 1;
                int ffenxi = 2;
                for (int i = s.length() - 1; i >= 0; i--) {
                    zifu[fzifu] = s.charAt(i);
                    fzifu++;
                }
                int buzhou = 2;
                char n[] = new char[65];// 存储要显示的内容
                t3.append("步骤                   分析栈                      剩余输入串              所用产生式或匹配" + "\n");
                n[0] = '1';
                n[15] = '#';
                n[14] = 'S';
                int u = 29;
                for (int i = fzifu - 1; i >= 0; i--) {
                    n[u] = zifu[i];
                    u++;
                }
                while (!(fenxi[ffenxi - 1] == '#' && zifu[fzifu - 1] == '#'))// 剩余输入串不为#则分析
                {
                    int i, j;
                    char t = zifu[fzifu - 1];
                    char k = fenxi[ffenxi - 1];
                    if (t == k)// 产生式匹配
                    {
                        n[49] = k;
                        n[50] = '匹';
                        n[51] = '配';
                        t3.append(String.copyValueOf(n) + "\n");
                        n = new char[65];
                        fzifu--;
                        ffenxi--;
                        if (buzhou < 10)
                            n[0] = (char) ('0' + buzhou);// 显示步骤数
                        else {
                            n[0] = (char) ('0' + buzhou / 10);
                            n[1] = (char) ('0' + buzhou % 10);
                        }
                        u = 14;
                        for (int y = ffenxi - 1; y >= 0; y--)// 处理分析栈，出栈
                        {
                            n[u] = fenxi[y];
                            u++;
                        }
                        u = 29;
                        for (int y = fzifu - 1; y >= 0; y--)// 处理剩余字符串，消除一个字符
                        {
                            n[u] = zifu[y];
                            u++;
                        }
                        buzhou++;
                        continue;
                    }

                    for (i = 0; Vn[i] != null; i++)// 搜寻所用产生式的左部
                    {
                        if (Vn[i].equals(String.valueOf(k)))
                            break;
                    }
                    for (j = 0; j < vt_tou.length; j++)// 判断是否匹配
                    {
                        if (vt_tou[j].equals(String.valueOf(t)))
                            break;
                    }
                    if (j >= vt_tou.length)// 全部产生式都不能符合则报错
                    {
                        t3.append(String.copyValueOf(n));
                        t3.append("\n" + "该串不是该文法的句型" + "\n");
                        return;
                    }

                    Object result1 = shuju[i][j];
                    if (result1 == null) {
                        t3.append(String.copyValueOf(n));
                        t3.append("\n" + "该串不是该文法的句型" + "\n");
                        return;
                    } else// 找到所用产生式
                    {
                        n[49] = Vn[i].charAt(0);
                        u = 50;
                        String result = (String) result1;
                        for (int y = 0; y < result.length(); y++) {
                            n[u] = result.charAt(y);
                            u++;
                        }
                        t3.append(String.copyValueOf(n) + "\n");
                        n = new char[65];

                        ffenxi--;
                        for (i = result.length() - 1; i > 0; i--)// 将分析栈内非终结符换为右边表达式
                        {
                            if (result.charAt(i) != '#')

                            {
                                fenxi[ffenxi] = result.charAt(i);
                                ffenxi++;
                            }
                        }
                    }
                    if (buzhou < 10)// 显示“步骤”
                        n[0] = (char) ('0' + buzhou);
                    else {
                        n[0] = (char) ('0' + buzhou / 10);
                        n[1] = (char) ('0' + buzhou % 10);
                    }
                    u = 14;
                    for (int y = ffenxi - 1; y >= 0; y--) {
                        n[u] = fenxi[y];
                        u++;
                    }
                    u = 29;
                    for (int y = fzifu - 1; y >= 0; y--) {
                        n[u] = zifu[y];
                        u++;
                    }
                    buzhou++;
                }
                n = new char[65];
                n[0] = '1';
                n[14] = '#';
                n[29] = '#';
                n[49] = '分';
                n[50] = '析';
                n[51] = '成';
                n[52] = '功';
                t3.append(String.copyValueOf(n));
                t3.append("\n" + "该串是此文法的句型" + "\n");
                return;
            } else {
                t3.setText("请先依次输入LL（1）文法，并点击 文法判断 按钮" + "\n");
                return;
            }

        }
    }

    private int add_First(char a[], String b, String firstVn[], int flag) // 计算FIRST**（递归）
    {
        if (puanduanString(firstVn, b.charAt(0))) {
            addString(firstVn, b);
        } else {
            return flag;
        }
        for (int i = 0; i < P.size(); i++) {

            String t = (String) P.elementAt(i);
            for (int k = 2; k < t.length(); k++) {
                if (t.substring(0, 1).equals(b)) {
                    if (t.charAt(k) > 'Z' || t.charAt(k) < 'A')// 表达式右端第i个不是非终结符
                    {
                        if (flag == 0 || puanduanChar(a, t.charAt(k))) {

                            if (t.charAt(k) == '#')// #时直接加入first
                            {
                                if (k + 1 == t.length()) {
                                    a[flag] = t.charAt(k);
                                    flag++;
                                }
                                int flag1 = 0;
                                for (int j = 0; yn_null[j] != '\0'; j++)// 所求非终结符进入yn_null**
                                {
                                    if (yn_null[j] == b.charAt(0))// 判断能否推出空
                                    {
                                        flag1 = 1;
                                        break;
                                    }
                                }
                                if (flag1 == 0) {
                                    int j;
                                    for (j = 0; yn_null[j] != '\0'; j++) {

                                    }
                                    yn_null[j] = b.charAt(0);
                                }
                                continue;
                            } else// 终结符直接加入first**
                            {
                                a[flag] = t.charAt(k);
                                flag++;
                                break;
                            }
                        }
                        break;
                    } else// 非终结符
                    {
                        if (!puanduanString(Vn, t.charAt(k))) {
                            int p = firstComplete(t.charAt(k));// 当该非终结符的first已经求出
                            if (p != -1) {
                                flag = addElementFirst(a, p, flag);// 直接加入所求first
                            } else if ((flag = add_First(a, String.valueOf(t.charAt(k)), firstVn, flag)) == -1)
                                return -1;
                            int flag1 = 0;
                            for (int j = 0; yn_null[j] != '\0'; j++)// 当非终结符的first有空
                            {
                                if (yn_null[j] == t.charAt(k)) {
                                    flag1 = 1;
                                    break;
                                }
                            }
                            if (flag1 == 1)// 当非终结符的first能推出空
                            {
                                if (k + 1 == t.length() && puanduanChar(a, '#'))// 之后无符号，且所求first无#
                                {
                                    a[flag] = '#';// first中加入#
                                    flag++;
                                }
                                continue;// 判断下一个字符
                            } else {
                                break;
                            }
                        } else// 错误
                        {
                            t3.setText("文法输入有误" + "\n");
                            return -1;
                        }
                    }
                }
            }
        }
        return flag;
    }

    private int tianjiaFollow(char a[], String b, String followVn[], int flag) // 计算FOLLOW**（递归）
    {
        if (puanduanString(followVn, b.charAt(0))) {
            addString(followVn, b);
        } else {
            return flag;
        }
        if (b.equals("S"))// 当为S时#存入follow
        {
            a[flag] = '#';
            flag++;
        }
        for (int i = 0; i < P.size(); i++) {
            String t = (String) P.elementAt(i);
            for (int j = 2; j < t.length(); j++) {
                if (t.charAt(j) == b.charAt(0) && j + 1 < t.length()) {
                    if (t.charAt(j + 1) != '\0') {
                        if ((t.charAt(j + 1) > 'Z' || t.charAt(j + 1) < 'A'))// 所求为终结符
                        {
                            if (flag == 0 || puanduanChar(a, t.charAt(2)))// 自身
                            {
                                a[flag] = t.charAt(j + 1);
                                flag++;
                            }
                        }

                        else// 所求为非终结符
                        {
                            int k;
                            for (k = 0; Vn[k] != null; k++) {
                                if (Vn[k].equals(String.valueOf(t.charAt(j + 1)))) {
                                    break;// 找寻下一个非终结符的Vn位置
                                }

                            }
                            flag = addElementFirst(a, k, flag);// 把下一个非终结符first加入所求follow集
                            for (k = j + 1; k < t.length(); k++) {
                                if ((t.charAt(j + 1) > 'Z' || t.charAt(j + 1) < 'A'))
                                    break;
                                else {
                                    if (panduan_kong(t.charAt(k))) {
                                    } else {
                                        break;
                                    }
                                }
                            }
                            if (k >= t.length())// 下一个非终结符可推出空，把表达式左边非终结符的follow集加入所求follow集
                            {
                                int p = followComplete(t.charAt(0));
                                if (p != -1) {
                                    flag = addElementFollow(a, p, flag);
                                } else if ((flag = tianjiaFollow(a, String.valueOf(t.charAt(0)), followVn, flag)) == -1)
                                    return -1;
                            }
                        }
                    } else// 错误
                    {
                        t3.setText("文法输入有误,请重新输入" + "\n");
                        return -1;
                    }

                }
                if (t.charAt(j) == b.charAt(0) && j + 1 == t.length())// 下一个字符为空，把表达式左边非终结符的follow集加入所求follow集
                {
                    int p = followComplete(t.charAt(0));
                    if (p != -1) {
                        flag = addElementFollow(a, p, flag);
                    } else if ((flag = tianjiaFollow(a, String.valueOf(t.charAt(0)), followVn, flag)) == -1)
                        return -1;
                }
            }
        }
        return flag;
    }

    private void tianjiaSelect(char a[], String b, int flag) // 计算SELECT**
    {
        int i = 2;
        int biaozhi = 0;
        while (i < b.length()) {
            if ((b.charAt(i) > 'Z' || b.charAt(i) < 'A') && b.charAt(i) != '#')// 是终结符
            {
                a[flag] = b.charAt(i);// 将这个字符加入到Select**，结束Select**的计算
                break;
            } else if (b.charAt(i) == '#')// 是空
            {
                int j;
                for (j = 0; Vn[i] != null; j++)// 将表达式左侧的非终结符的follow加入select
                {
                    if (Vn[j].equals(b.substring(0, 1))) {
                        break;
                    }
                }
                for (int k = 0; follow[j][k] != '\0'; k++) {
                    if (puanduanChar(a, follow[j][k])) {
                        a[flag] = follow[j][k];
                        flag++;
                    }
                }
                break;
            } else if (b.charAt(i) >= 'A' && b.charAt(i) <= 'Z' && i + 1 < b.length())// 是非终结符且有下一个字符
            {
                int j;
                for (j = 0; Vn[i] != null; j++) {
                    if (Vn[j].equals(String.valueOf(b.charAt(i)))) {
                        break;
                    }
                }
                for (int k = 0; first[j][k] != '\0'; k++) {
                    if (puanduanChar(a, first[j][k]))// 把表达式右侧所有非终结符的first集加入。
                    {
                        if (first[j][k] == '#')// first中存在空
                        {
                            biaozhi = 1;
                        } else {
                            a[flag] = first[j][k];
                            flag++;
                        }
                    }
                }
                if (biaozhi == 1)// 把右侧所有非终结符的first中的#去除
                {
                    i++;
                    biaozhi = 0;
                    continue;
                } else {
                    biaozhi = 0;
                    break;
                }
            } else if (b.charAt(i) >= 'A' && b.charAt(i) <= 'Z' && i + 1 >= b.length())// 是非终结符且没有下一个字符
            {
                int j;
                for (j = 0; Vn[i] != null; j++) {
                    if (Vn[j].equals(String.valueOf(b.charAt(i)))) {
                        break;
                    }
                }
                for (int k = 0; first[j][k] != '\0'; k++) {
                    if (puanduanChar(a, first[j][k])) {
                        if (first[j][k] == '#') {
                            biaozhi = 1;// 表达式右侧能推出空，标记
                        } else {
                            a[flag] = first[j][k];// 不能推出空，直接将first集加入select集
                            flag++;
                        }

                    }
                }
                if (biaozhi == 1)// 表达式右侧能推出空
                {
                    for (j = 0; Vn[i] != null; j++) {
                        if (Vn[j].equals(b.substring(0, 1))) {
                            break;
                        }
                    }
                    for (int k = 0; follow[j][k] != '\0'; k++) {
                        if (puanduanChar(a, follow[j][k])) {
                            a[flag] = follow[j][k];// 将将表达式左侧的非终结符的follow加入select
                            flag++;
                        }
                    }
                    break;
                } else {
                    biaozhi = 0;
                    break;
                }
            }
        }
    }

    // 返回b在Vt[]的位置
    private int puanduanXulie(char Vt[], char b) {
        int i;
        for (i = 0; Vt[i] != '\0'; i++) {
            if (Vt[i] == b)
                break;
        }
        return i;
    }

    // 判断b是否在a中，在返回false，不在返回true
    private boolean puanduanChar(char a[], char b) {

        for (int i = 0; a[i] != '\0'; i++) {
            if (a[i] == b)
                return false;

        }
        return true;
    }

    // 判断b是否在a中，在返回false，不在返回true
    private boolean puanduanString(String a[], char b) {
        for (int i = 0; a[i] != null; i++) {
            if (a[i].equals(String.valueOf(b)))
                return false;

        }
        return true;
    }

    // 把b加入字符串组firstVn[]
    private void addString(String firstVn[], String b) {
        int i;
        for (i = 0; firstVn[i] != null; i++) {
        }
        firstVn[i] = b;
    }

    // 判断b是否已完成first判断
    private int firstComplete(char b) {
        int i;
        for (i = 0; Vn[i] != null; i++) {
            if (Vn[i].equals(String.valueOf(b))) {
                if (firstComplete[i] == 1)
                    return i;
                else
                    return -1;
            }

        }
        return -1;
    }

    // 判断b是否已完成follow判断
    private int followComplete(char b) {
        for (int i = 0; Vn[i] != null; i++) {
            if (Vn[i].equals(String.valueOf(b))) {
                if (followComplete[i] == 1)
                    return i;
                else
                    return -1;
            }

        }
        return -1;
    }

    // 把相应终结符添加到first**中
    private int addElementFirst(char a[], int p, int flag) {
        for (int i = 0; first[p][i] != '\0'; i++) {
            if (puanduanChar(a, first[p][i]) && first[p][i] != '#') {
                a[flag] = first[p][i];
                flag++;
            }
        }
        return flag;
    }

    // 把相应终结符添加到follow**中
    private int addElementFollow(char a[], int p, int flag) {
        for (int i = 0; follow[p][i] != '\0'; i++) {
            if (puanduanChar(a, follow[p][i])) {
                a[flag] = follow[p][i];
                flag++;
            }
        }
        return flag;
    }

    // 判断a能是否包含空
    private boolean panduan_kong(char a) {
        int i;
        for (i = 0; Vn[i] != null; i++) {
            if (Vn[i].equals(String.valueOf(a))) {
                break;
            }

        }
        for (int j = 0; first[i][j] != '\0'; j++) {
            if (first[i][j] == '#')
                return true;
        }

        return false;
    }

    public static void main(String[] args) {
        new LL();
    }
}
