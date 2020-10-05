package com.principle.lexical;

public class LexicalAnalyzer {
    public static void main(String[] args) {
        String fileName = "/Users/sfky/Documents/Programming/Java_Folder/com/principle/example.c";
        AnalysisLexical analysisLexical = new AnalysisLexical(fileName);
        analysisLexical.analysis();
    }
}
