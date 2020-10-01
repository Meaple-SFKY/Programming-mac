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
    public int tempChar = 0;
    public String tempString = "";

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
    };

    public char[] arithmeticOperators = {
        '+', '-', '*', '/', '%', '#'
    };

    public String[] relationalOperators = {
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
        for (int i = 0; i < delimiters.length; i++) {
            if (asciiCode == Integer.valueOf(delimiters[i])) {
                return true;
            }
        }
        return false;
    }

    //判断是否是算术运算符
    public boolean ifIsAArithmeticOperators(int slice) {
        int asciiCode = slice;
        for (int i = 0; i < arithmeticOperators.length; i++) {
            if (asciiCode == Integer.valueOf(arithmeticOperators[i])) {
                return true;
            }
        }
        return false;
    }

    //判断是否是关键字
    public boolean ifIsAKeyWord() {
        for (int i = 0; i < keyWords.length; i++) {
            if (tempStorString.toString().equals(keyWords[i])) {
                return true;
            }
        }
        return false;
    }

    //判断是否是标识符
    public boolean ifIsAIdentifier() {
        if (tempStorString.charAt(0) >= '0' && tempStorString.charAt(0) <= '9') {
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
        int temp = 0;
        if (tempStorString.length() != 0) {
            for (int i = 0; i < tempStorString.length(); i++) {
                if (tempStorString.charAt(i) < 48 || tempStorString.charAt(i) > 57) {
                    return false;
                }
                if (tempStorString.charAt(i) == '.') {
                    temp++;
                }
            }
            if (temp > 1) {
                return false;
            }
            return true;
        } else {
            return false;
        }
    }

    //判断是否是单个关系运算符
    public boolean ifIsARelaOperator(int slice) {
        if ((char)slice == '=' || (char)slice == '<' || (char)slice == '>') {
            return true;
        } else {
            return false;
        }
    }

    //判断是否是关系运算符
    public boolean ifIsRelaOperator() {
        for (int i = 0; i < relationalOperators.length; i++) {
            if (tempStorString.equals(relationalOperators[i]) == true) {
                return true;
            }
        }
        return false;
    }

    //连接经过处理的字符串和刚处理的字符
    public void addCharToString(int slice) {
        tempStorString.append((char)slice);
    }

    //输出关键字、标识符、常数、关系运算符有关信息
    public void printString() {
        if (tempStorString.length() != 0) {
            if (ifIsAKeyWord() == true) {
                System.out.println(tempStorString + "\t(" + 1 + ", " + tempStorString
                                + ")\t" + "关键字\t");
            } else if (ifIsASetDigitals() == true) {
                System.out.println(tempStorString + "\t(" + 3 + ", " + tempStorString
                                + ")\t" + "常数\t");
            } else if (ifIsAIdentifier() == true) {
                System.out.println(tempStorString + "\t(" + 2 + ", " + tempStorString
                                + ")\t" + "标识符\t");
            } else if (ifIsRelaOperator() == true) {
                System.out.println(tempStorString + "\t(" + 5 + ", " + tempStorString
                                + ")\t" + "关系运算符\t");
            } else {
                System.out.println(tempStorString + "\tERROR\tERROR\t");
            }
        }
    }

    //输出分界符有关信息
    public void printDelimiter(int slice) {
        System.out.println((char)slice + "\t(" + 6 + ", " + (char)slice
                            + ")\t" + "分界符\t");
    }

    //输出运算符有关信息
    public void printOperator(int slice) {
        System.out.println((char)slice + "\t(" + 4 + ", " + (char)slice
                            + ")\t" + "运算符\t");
    }

    //刷新临时字符串
    public void flushTempString() {
        tempStorString.delete(0, tempStorString.length());
    }

    public void analysis(String fileName) {
        BufferedReader bufferedReader;
        try {
            bufferedReader = new BufferedReader(new FileReader(fileName));
            while ((tempChar = bufferedReader.read()) != -1) {
                if (ifIsASpace(tempChar) == false && (char)tempChar != '\n') {
                    if (ifIsALetter(tempChar) == true || ifIsADigital(tempChar) == true ||
                        (char)tempChar == '_') {
                        addCharToString(tempChar);
                    } else if (ifIsADelimiter(tempChar)) {
                        if ((char)tempChar == '.') {
                            if (ifIsASetDigitals() == true) {
                                addCharToString(tempChar);
                            } else {
                                printString();
                                flushTempString();
                                printDelimiter(tempChar);
                            }
                        } else {
                            printString();
                            flushTempString();
                            printDelimiter(tempChar);
                        }
                    } else if (ifIsAArithmeticOperators(tempChar) == true) {
                        printString();
                        flushTempString();
                        printOperator(tempChar);
                    } else if (ifIsARelaOperator(tempChar) == true) {
                        if (tempStorString.length() > 0) {
                            if (ifIsARelaOperator(tempStorString.charAt(0)) == false) {
                                printString();
                                flushTempString();
                                addCharToString(tempChar);
                            } else {
                                addCharToString(tempChar);
                                printString();
                                flushTempString();
                            }
                        } else {
                            addCharToString(tempChar);
                        }
                    }
                } else {
                    printString();
                    flushTempString();
                }
            }
        } catch (FileNotFoundException exceptionFile) {
            exceptionFile.printStackTrace();
        } catch (IOException exceptionIO) {
            exceptionIO.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Analyzer analyzer = new Analyzer();
        String fileName = new String("/Users/sfky/Documents/Programming/Java_Folder/com/meaple/principle/example.c");
        analyzer.analysis(fileName);
    }
}