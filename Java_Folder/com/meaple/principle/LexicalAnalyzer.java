package com.meaple.principle;

public class LexicalAnalyzer {
    public static void main(String[] args) {
        String fileName = "/Users/sfky/Documents/Programming/Java_Folder/com/meaple/principle/example.c";
        Analyzer analyzer = new Analyzer(fileName);
        analyzer.analysis();
    }
}
