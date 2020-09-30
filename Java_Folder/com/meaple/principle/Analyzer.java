package com.meaple.principle;

/**
 *  1   关键字
 *  2   标识符
 *  3   常数
 *  4   运算符
 *  5   关系运算符
 *  6   分界符
 * */

import java.io.*;

public class Analyzer {
    public int tempChar;
    public int tempSlice;

    public StringBuffer tempStorString = new StringBuffer();

    public int[] stateCodes = {
        1, 2, 3, 4, 5, 6
    };

    public String[] keyWords = new String[] {
        "auto"     ,"short"    ,"int"      ,"long"      ,
        "float"    ,"double"   ,"char"     ,"struct"    ,
        "union"    ,"enum"     ,"typedef"  ,"cosnt"     ,
        "unsigned" ,"signed"   ,"extern"   ,"register"  ,
        "static"   ,"volatle"  ,"void"     ,"if"        ,
        "else"     ,"switch"   ,"case"     ,"for"       ,
        "do"       ,"while"    ,"goto"     ,"continue"  ,
        "break"    ,"default"  ,"sizeof"   ,"return"
    };

    public char[] delimiters = {
        '.', ',', '(', ')', '[', ']', '{', '}'
        //46, 44, 41, 40, 91, 93, 123, 125
    };

    public char[] arithmeticOperators = {
        '+', '-', '*', '/', '%'
        //43, 45, 42, 47
    };

    public String[] ralationalOperators = {
        "<", "<=", "=", ">=", ">", "==", "<>"
    };

    //判断是否是空格
    public boolean ifIsASpace(int slice) {
        int asciiCode = slice;
        if (asciiCode == 32) {
            return true;
        } else {
            return false;
        }
    }
    
    //判断是否是字母
    public boolean ifIsALetter(int slice) {
        int asciiCode = slice;
        if ((asciiCode >= 65 && asciiCode <= 90) ||
            (asciiCode >= 97 && asciiCode <= 122)) {
            return true;
        } else {
            return false;
        }
    }

    //判断是否是数字
    public boolean ifIsADigital(int slice) {
        int asciiCode = slice;
        if (asciiCode >= 48 && asciiCode <= 57) {
            return true;
        } else {
            return false;
        }
    }

    //判断是否是分界符
    public boolean ifIsADelimiter(int slice) {
        int asciiCode = slice;
        switch (asciiCode) {
            case 46:
            case 44:
            case 41:
            case 40:
            case 91:
            case 93:
            case 123:
            case 125: {
                return true;
            } default: {
                return false;
            }
        }
    }

    //判断是否是算术运算符
    public boolean ifIsAArithmeticOperators(int slice) {
        int asciiCode = slice;
        switch (asciiCode) {
            case 43:
            case 45:
            case 42:
            case 47: {
                return true;
            } default: {
                return false;
            }
        }
    }

    //判断是否是关键字
    public boolean ifIsAKeayWord() {
        for (int i = 0; i < keyWords.length; i++) {
            if (tempStorString.toString().equals(keyWords[i])) {
                return true;
            }
        }
        return false;
    }

    //判断是否是标识符
    public boolean ifIsAIdentifier() {
        if (tempStorString.charAt(0) >= 48 || tempStorString.charAt(0) <= 57) {
            return false;
        } else {
            for (int i = 0; i < tempStorString.length(); i++) {
                int asciiCode = Integer.valueOf(tempStorString.charAt(i));
                if (((asciiCode >= 65 && asciiCode <= 90) ||
                    (asciiCode >= 97 && asciiCode <= 122) ||
                    (asciiCode == 95)) == false) {
                    return false;
                }
            }
            return true;
        }
    }

    //判断是否是常数
    public boolean ifIsASetDigitals() {
        if (tempStorString.length() != 0) {
            for (int i = 0; i < tempStorString.length(); i++) {
                if (tempStorString.charAt(i) < 48 || tempStorString.charAt(i) > 57) {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }

    //连接经过处理的字符串和刚处理的字符
    public void addCharToString(char slice) {
        tempStorString.append(slice);
    }

    //刷新临时存储字符串
    public void flushString() {
        if (ifIsAKeayWord() == true) {
            System.out.println(tempStorString + "\t" + "(" + 1 + ", " + tempStorString
                + ")\t" + "关键字\t");
        } else if (ifIsASetDigitals() == true) {
            System.out.println(tempStorString + "\t" + "(" + 3 + ", " + tempStorString
                + ")\t" + "常数\t");
        } else if (ifIsAIdentifier() == true) {
            System.out.println(tempStorString + "\t" + "(" + 2 + ", " + tempStorString
                + ")\t" + "标识符\t");
        } else {
            System.out.println(tempStorString + "\t" + "ERROR\t" + "ERROR\t");
        }
        tempStorString.delete(0, tempStorString.length());
    }

    public void analysis(String fileName) {
        BufferedReader bufferedReader;
        try {
            bufferedReader = new BufferedReader(new FileReader(fileName));
            while ((tempChar = bufferedReader.read()) != -1) {
                if (ifIsASpace(tempChar) == false) {
                    if(ifIsALetter(tempChar) == true || ifIsADigital(tempChar) == true) {
                        addCharToString((char)tempChar);
                    } else if (ifIsAArithmeticOperators(tempChar) == true) {
                        System.out.println((char)tempChar + "\t" + "(" + 4 + ", " + (char)tempChar
                        + ")\t" + "运算符\t");
                    }
                    //
                    //处理关系运算符
                }
            }
        } catch (FileNotFoundException exceptionFile) {
            exceptionFile.printStackTrace();
        } catch (IOException exceptionIO) {
            exceptionIO.printStackTrace();
        }
    }
}