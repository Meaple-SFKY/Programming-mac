package com.principle.parser;

// 内部集合类
public class BasicData {
    // 非终结符集合
    public char VN[] = { 'E', 'G', 'T', 'S', 'F' };

    // 终结符集合
    public char VT[] = { '+', '-', 'ε', '*', '/', '(', ')', 'i', '#' };

    // 文法串
    public String GRAMMER[] = { "E->TG", "G->+TG|-TG", "G->ε", "T->FS", "S->*FS|/FS", "S->ε", "F->(E)", "F->i" };

    // FIRST集合
    public String[] FIRST = new String[VN.length];

    // FOLLOW集合
    public String[] FOLLOW = new String[VN.length];

    // 预测分析表
    public String[][] ANALYSISTABLE = new String[VN.length][VT.length];

    public BasicData() {
        initFirst();
        initFollow();
        initAnalyTable();
        formFirst();
        formFollow();
    }

    private void initFirst() {
        for (int i = 0; i < VN.length; i++) {
            FIRST[i] = "";
        }
    }

    private void initFollow() {
        FOLLOW[0] = "#";
        for (int i = 1; i < VN.length; i++) {
            FOLLOW[i] = "";
        }
    }

    private void initAnalyTable() {
        for (int i = 0; i < VN.length; i++) {
            for (int j = 0; j < VT.length; j++) {
                ANALYSISTABLE[i][j] = "";
            }
        }
    }

    // 删除FIRST中的重复字符
    private void delDupliChOfFir(int firstLab) {
        int len = FIRST[firstLab].length();
        if (len == 0) {
            return;
        }
        String string = "";
        for (int i = 0; i < len; i++) {
            String tempStr = Character.toString(FIRST[firstLab].charAt(i));
            if (string.contains(tempStr) == false) {
                string += tempStr;
            }
        }
        FIRST[firstLab] = string;
    }

    private void tidyFirst() {
        for (int i = 0; i < FIRST.length; i++) {
            delDupliChOfFir(i);
        }
    }

    // 删除FOLLOW中的重复字符
    private void delDupliChOfFol(int followLab) {
        int len = FOLLOW[followLab].length();
        if (len == 0) {
            return;
        }
        String string = "";
        for (int i = 0; i < len; i++) {
            String tempStr = Character.toString(FOLLOW[followLab].charAt(i));
            if (string.contains(tempStr) == false) {
                string += tempStr;
            }
        }
        FOLLOW[followLab] = string;
    }

    private void tidyFollow() {
        for (int i = 0; i < FOLLOW.length; i++) {
            delDupliChOfFol(i);
        }
    }

    // 判断字符是否在VN中
    private boolean ifIsAVn(char chVn) {
        for (int i = 0; i < VN.length; i++) {
            if (chVn == VN[i]) {
                return true;
            }
        }
        return false;
    }

    // 判断字符在VN中的位置
    private int indexOfVn(char chVn) {
        if (ifIsAVn(chVn) == true) {
            int i;
            for (i = 0; i < VN.length; i++) {
                if (chVn == VN[i]) {
                    return i;
                }
            }
            return i;
        }
        return VN.length;
    }

    // 判断字符是否在VT中
    private boolean ifIsAVt(char chVt) {
        for (int i = 0; i < VT.length; i++) {
            if (chVt == VT[i]) {
                return true;
            }
        }
        return false;
    }

    // 判断字符在VN中的位置
    private int indexOfVt(char chVt) {
        if (ifIsAVt(chVt) == true) {
            int i;
            for (i = 0; i < VT.length; i++) {
                if (chVt == VT[i]) {
                    return i;
                }
            }
            return i;
        }
        return VT.length;
    }

    // 判断字符是否在FIRST中
    private boolean ifIsInFirst(int locVn, char ch) {
        boolean index = FIRST[locVn].contains(Character.toString(ch));
        return index;
    }

    // GRAMMER最长子串
    private int lenSubStr(int lineNum) {
        int length = 0;
        int len = 0;
        for (int i = 3; i < GRAMMER[lineNum].length(); i++) {
            if (GRAMMER[lineNum].charAt(i) != '|') {
                len++;
            } else {
                if (length < len) {
                    length = len;
                }
                len = 0;
            }
        }
        return length;
    }

    // 求循环次数
    private int cycleNum() {
        int length = 0;
        for (int i = 0; i < GRAMMER.length; i++) {
            int len = lenSubStr(i);
            if (length < len) {
                length = len;
            }
        }
        return length;
    }

    // 添加终结符除空字的FIRST集合
    private void addNoEmptyToFirst(int added, int add) {
        if (FIRST[add].length() != 0) {
            for (int i = 0; i < FIRST[add].length(); i++) {
                if (FIRST[add].charAt(i) != 'ε') {
                    FIRST[added] += FIRST[add].charAt(i);
                }
            }
        }
    }

    // 添加终结符到FIRST集合
    private void addVtToFirst() {
        for (int i = 0; i < VN.length; i++) {
            for (int j = 0; j < GRAMMER.length; j++) {
                if (VN[i] == GRAMMER[j].charAt(0)) {
                    if (ifIsAVt(GRAMMER[j].charAt(3)) == true) {
                        FIRST[i] += GRAMMER[j].charAt(3);
                    }
                    for (int temp = 4; temp < GRAMMER[j].length(); temp++) {
                        if (GRAMMER[j].charAt(temp) == '|') {
                            temp++;
                            FIRST[i] += GRAMMER[j].charAt(temp);
                        }
                    }
                }
            }
        }
    }

    // 添加非终结符的FIRST集合
    private void addVtOfVnToFirst() {
        for (int cycleNum = 0; cycleNum < cycleNum(); cycleNum++) {
            for (int i = 0; i < VN.length; i++) {
                for (int j = 0; j < GRAMMER.length; j++) {
                    if (VN[i] == GRAMMER[j].charAt(0)) {
                        for (int temp = 3; temp < GRAMMER[j].length(); temp++) {
                            if (ifIsAVn(GRAMMER[j].charAt(temp)) == true) {
                                int index = indexOfVn(GRAMMER[j].charAt(temp));
                                addNoEmptyToFirst(i, index);
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    // 生成FIRST集合
    private void formFirst() {
        addVtToFirst();
        addVtOfVnToFirst();
        tidyFirst();
    }

    // 把除空字的FIRST集合加到FOLLOW
    private void addNoEmptyFirToFollow(int added, char add) {
        int index = indexOfVn(add);
        if (FIRST[index].length() == 0) {
            return;
        }
        for (int i = 0; i < FIRST[index].length(); i++) {
            if (FIRST[index].charAt(i) != 'ε') {
                FOLLOW[added] += FIRST[index].charAt(i);
            }
        }
    }

    // 把FIRST集合加到FOLLOW
    private void addFirstToFollow() {
        for (int i = 0; i < VN.length; i++) {
            for (int j = 0; j < GRAMMER.length; j++) {
                if (GRAMMER[j].substring(3).contains(Character.toString(VN[i])) == true) {
                    for (int temp = 3; temp < GRAMMER[j].length(); temp++) {
                        if (VN[i] == GRAMMER[j].charAt(temp)) {
                            temp++;
                            if (temp < GRAMMER[j].length()) {
                                if (GRAMMER[j].charAt(temp) != '|') {
                                    if (ifIsAVt(GRAMMER[j].charAt(temp)) == true) {
                                        FOLLOW[i] += GRAMMER[j].charAt(temp);
                                    } else if (ifIsAVn(GRAMMER[j].charAt(temp)) == true) {
                                        addNoEmptyFirToFollow(i, GRAMMER[j].charAt(temp));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    // 把FOLLOW集合添加到FOLLOW
    private void addFolToFol() {
        for (int cycleNum = 0; cycleNum < cycleNum(); cycleNum++) {
            for (int i = 0; i < VN.length; i++) {
                for (int j = 0; j < GRAMMER.length; j++) {
                    if (GRAMMER[j].substring(3).contains(Character.toString(VN[i])) == true) {
                        for (int temp = 3; temp < GRAMMER[j].length(); temp++) {
                            if (VN[i] == GRAMMER[j].charAt(temp)) {
                                temp++;
                                if (temp >= GRAMMER[j].length()) {
                                    FOLLOW[i] += FOLLOW[indexOfVn(GRAMMER[j].charAt(0))];
                                } else {
                                    if (GRAMMER[j].charAt(temp) == '|') {
                                        FOLLOW[i] += FOLLOW[indexOfVn(GRAMMER[j].charAt(0))];
                                    } else {
                                        if (ifIsAVt(GRAMMER[j].charAt(temp)) == true) {
                                            if (GRAMMER[j].charAt(temp) == 'ε') {
                                                FOLLOW[i] += FOLLOW[indexOfVn(GRAMMER[j].charAt(0))];
                                            }
                                        } else if (ifIsAVn(GRAMMER[j].charAt(temp)) == true) {
                                            if (ifIsInFirst(indexOfVn(GRAMMER[j].charAt(temp)), 'ε') == true) {
                                                FOLLOW[i] += FOLLOW[indexOfVn(GRAMMER[j].charAt(0))];
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // 生成FOLLOW集合
    private void formFollow() {
        addFirstToFollow();
        tidyFollow();
        addFolToFol();
        tidyFollow();
    }

    // 对于终结符构造预测分析表
    private void formTableForVt() {
        String tempFirstStr = "";
    }

    public static void main(String[] args) {
        BasicData basicData = new BasicData();
        for (int i = 0; i < basicData.FOLLOW.length; i++) {
            System.out.println(basicData.FIRST[i]);
            System.out.println(basicData.FOLLOW[i]);
        }
    }
}