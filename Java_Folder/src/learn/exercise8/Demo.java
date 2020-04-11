package src.learn.exercise8;

import java.net.*;
import java.io.*;

public class Demo {
    public static void main(String[] args) throws Exception {
        //URL数据-> InputStreamReader对象 -> BufferedReader对象  -> 程序处理
        URL hfut = new URL("http://www.baidu.com");
        BufferedReader in = new BufferedReader(new InputStreamReader( hfut.openStream()));
        String inputLine;
        //打印输出HTML
        while ( (inputLine = in.readLine() ) != null )
        System.out.println(inputLine);
        //关闭缓冲区
        in.close();
    }
}