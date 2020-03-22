//此类在src.learn.exercise6包里
package src.learn.exercise6;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

//定义Demo类，此类包含主方法
public class Demo {
    public static void main(String[] args) throws IOException, FileNotFoundException{
        try {
            //将要合并的两个文件(文件1和文件2)
            File file1 = new File("Java异常处理.md");
            File file2 = new File("Java输入输出系统.md");
            //合并产生的文件(文件3)
            File file3 = new File("Java笔记.md");
            //如果文件3已经存在，将其删除
            if (file3.exists() == true) {
                file3.delete();
            }
            //创建文件3
            file3.createNewFile();
            FileInputStream file4 = new FileInputStream(file1);
            FileInputStream file5 = new FileInputStream(file2);
            FileOutputStream file6 = new FileOutputStream(file3);
            BufferedInputStream file7 = new BufferedInputStream(file4);
            BufferedInputStream file8 = new BufferedInputStream(file5);
            BufferedOutputStream file9 = new BufferedOutputStream(file6);
            int len;
            //建立数组对象，加快文件读写速度
            byte[] b = new byte[1024];
            //从文件1中复制数据道文件3
            while ((len = file7.read(b)) > 0) {
                file9.write(b, 0, len);
            }
            file9.write('\n');
            //从文件2中复制数据道文件3
            while ((len = file8.read(b)) > 0) {
                file9.write(b, 0, len);
            }
            //刷新缓冲区
            file9.flush();
            //关闭文件对象
            file7.close();
            file8.close();
            file9.close();
        }
        //若将要合并的两个文件不存在，抛出异常
        catch(FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}