package com.principle.defined;

public class DefinitedCells {
    //关键字
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

    //分界符
    public char[] delimiters = {
        '.', ',', '(', ')', '[', ']', '{', '}', ':', '#', ';', '&'
    };

    //运算符
    public String[] arithmeticOperators = {
        "+", "-", "*", "/", "%", "++", "--", "|"
    };


    public String[] relationalOperators = {
        "<", "<=", "=", ">=", ">", "==", "<>"
    };
}
