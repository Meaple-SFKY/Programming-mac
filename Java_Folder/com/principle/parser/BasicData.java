package com.principle.parser;

// 内部集合类
public class BasicData {
    // 非终结符集合
    private char VN[] = { 'E', 'G', 'T', 'S', 'F' };

    // 终结符集合
    private char VT[] = { '+', '-', 'ε', '*', '/', '(', ')', 'i', '#' };

    // 文法串
    private String GRAMMER[] = { "E->TG", "G->+TG|-TG", "G->ε", "T->FS", "S->*FS|/FS", "S->ε", "F->(E)", "F->i" };

    // FIRST集合
    private String[] FIRST = new String[VN.length];

    // FOLLOW集合
    private String[] FOLLOW = new String[VN.length];

    // 预测分析表
    private String[][] ANALYSISTABLE = new String[VN.length][VT.length];

    public char[] getVn() {
        return VN;
    }

    public char[] getVt() {
        return VT;
    }

    public String[] getFirst() {
        return FIRST;
    }

    public String[] getFollow() {
        return FOLLOW;
    }

    public String[][] getTable() {
        return ANALYSISTABLE;
    }

    public BasicData() {
        initFirst();
        initFollow();
        initAnalyTable();
        formFirst();
        formFollow();
        formTable();
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

    private void delDupliCh(String str) {
        int len = str.length();
        if (len == 0) {
            return;
        }
        String string = "";
        for (int i = 0; i < len; i++) {
            String tempStr = Character.toString(str.charAt(i));
            if (string.contains(tempStr) == false) {
                string += tempStr;
            }
        }
        str = string;
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
    public boolean ifIsAVn(char chVn) {
        for (int i = 0; i < VN.length; i++) {
            if (chVn == VN[i]) {
                return true;
            }
        }
        return false;
    }

    // 判断字符在VN中的位置
    public int indexOfVn(char chVn) {
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
    public boolean ifIsAVt(char chVt) {
        for (int i = 0; i < VT.length; i++) {
            if (chVt == VT[i]) {
                return true;
            }
        }
        return false;
    }

    // 判断字符在VT中的位置
    public int indexOfVt(char chVt) {
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
                                if (temp == 3) {
                                    addNoEmptyToFirst(i, index);
                                } else {
                                    if (ifIsInFirst(index, 'ε') == true) {
                                        addNoEmptyToFirst(i, index);
                                    } else {
                                        for (int k = temp; k < GRAMMER[j].length(); j++) {
                                            if (GRAMMER[j].charAt(k) == '|') {
                                                temp = k;
                                                break;
                                            }
                                        }
                                        continue;
                                    }
                                }
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

    /* // 把除空字的FIRST集合加到FOLLOW
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
    } */

    // 生成串的FIRST集合
    private String getStrFirst(String setOfChar) {
        if (setOfChar.length() > 0) {
            if (ifIsAVt(setOfChar.charAt(0)) == true) {
                return Character.toString(setOfChar.charAt(0));
            } else {
                String tempString = "";
                for (int i = 0; i < setOfChar.length(); i++) {
                    char ch = setOfChar.charAt(i);
                    if (i == 0) {
                        tempString += FIRST[indexOfVn(ch)];
                        if(ifIsInFirst(indexOfVn(ch), 'ε') == false) {
                            break;
                        }
                    } else {
                        if (ifIsAVn(ch) == true) {
                            if(ifIsInFirst(indexOfVn(ch), 'ε')) {
                                if (FIRST[indexOfVn(ch)].length() != 0) {
                                    for (int j = 0; j < FIRST[indexOfVn(ch)].length(); j++) {
                                        if (FIRST[indexOfVn(ch)].charAt(j) != 'ε') {
                                            tempString += FIRST[indexOfVn(ch)].charAt(j);
                                        }
                                    }
                                }
                            } else {
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                }
                return tempString;
            }
        } else {
            return "";
        }
    }

    // 删除FIRST集合中的空字
    private String deleteEmpty(String strFirst) {
        String str = "";
        if (strFirst.length() == 0) {
            return "";
        }
        for (int i = 0; i < strFirst.length(); i++) {
            if (strFirst.charAt(i) != 'ε') {
                str += strFirst.charAt(i);
            }
        }
        return str;
    }

    // 取串的不含空字的FIRST集合
    private String strCharFirst(String str) {
        String strTemp = "";
        String string = getStrFirst(str);
        delDupliCh(getStrFirst(str));
        strTemp = deleteEmpty(string);
        return strTemp;
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
                                    if (ifIsAVt(GRAMMER[j].charAt(temp)) == true) {;
                                        FOLLOW[i] += GRAMMER[j].charAt(temp);
                                    } else if (ifIsAVn(GRAMMER[j].charAt(temp)) == true) {
                                        String tempString = "";
                                        for (int t = temp; t < GRAMMER[j].length(); t++) {
                                            if (GRAMMER[j].charAt(t) != '|') {
                                                tempString += GRAMMER[j].charAt(t);
                                            } else {
                                                break;
                                            }
                                        }
                                        String strFirst = strCharFirst(tempString);
                                        FOLLOW[i] += strFirst;
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

    private void formTableCell(int tempGra) {
        String headString = GRAMMER[tempGra].substring(0, 3);
        int locVnHead = indexOfVn(GRAMMER[tempGra].charAt(0));
        for (int i = 0; i < GRAMMER[tempGra].length(); i++) {
            if ((GRAMMER[tempGra].charAt(i) == '|') || (GRAMMER[tempGra].charAt(i) == '>')) {
                i++;
                String tempStorString = "";
                for (int j = i; j < GRAMMER[tempGra].length(); j++) {
                    if (GRAMMER[tempGra].charAt(j) == '|') {
                        break;
                    } else {
                        tempStorString += GRAMMER[tempGra].charAt(j);
                    }
                }
                if (ifIsAVt(GRAMMER[tempGra].charAt(i)) == true) {
                    if (GRAMMER[tempGra].charAt(i) == 'ε') {
                        if (FOLLOW[locVnHead].length() != 0) {
                            for (int j = 0; j < FOLLOW[locVnHead].length(); j++) {
                                int locVtFo = indexOfVt(FOLLOW[locVnHead].charAt(j));
                                ANALYSISTABLE[locVnHead][locVtFo] = headString + tempStorString;
                            }
                        }
                    }
                    int locVt = indexOfVt(GRAMMER[tempGra].charAt(i));
                    ANALYSISTABLE[locVnHead][locVt] = headString + tempStorString;
                } else if (ifIsAVn(GRAMMER[tempGra].charAt(i)) == true) {
                    String setOfChar = "";
                    String strFirst = "";
                    boolean ifInFisrt = false;
                    for (int t = i; t < GRAMMER[tempGra].length(); t++) {
                        if (GRAMMER[tempGra].charAt(t) != '|') {
                            setOfChar += GRAMMER[tempGra].charAt(t);
                        } else {
                            break;
                        }
                    }
                    strFirst = strCharFirst(setOfChar);
                    int locVnTail = indexOfVn(GRAMMER[tempGra].charAt(i));
                    if (strFirst.length() != 0) {
                        for (int j = 0; j < strFirst.length(); j++) {
                            int locVtFo = indexOfVt(strFirst.charAt(j));
                            ANALYSISTABLE[locVnHead][locVtFo] = headString + tempStorString;
                        }
                    }
                    for (int t = 0; t < strFirst.length(); t++) {
                        if (strFirst.charAt(t) == 'ε') {
                            ifInFisrt = true;
                            break;
                        }
                    }
                    if (ifInFisrt == true) {
                        if (FOLLOW[locVnTail].length() != 0) {
                            for (int j = 0; j < FOLLOW[locVnHead].length(); j++) {
                                int locVtFo = indexOfVt(FOLLOW[locVnHead].charAt(j));
                                ANALYSISTABLE[locVnHead][locVtFo] = headString + tempStorString;
                            }
                        }
                    }
                }
            }
        }
    }
    
    // 构造预测分析表
    private void formTable() {
        for (int i = 0; i < GRAMMER.length; i++) {
            formTableCell(i);
        }
    }
}