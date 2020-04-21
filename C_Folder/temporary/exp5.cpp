#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    const int arrSize = 6 * 6;
    int value8 = 0, value9 = 0;
    vector<int> sum;
    vector<int>::iterator Location_index;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            sum.push_back(i + j + 2);
        }
    }
    value8 = count(sum.begin(), sum.end(), 8);
    value8 = count(sum.begin(), sum.end(), 9);
    if (value8 > value9) {
        cout << "小王赢的可能性更大" << endl;
    }
    else if (value8 == value9) {
        cout << "两人赢的可能性一样大" << endl;
    }
    else {
        cout << "小刘赢的可能性更大" << endl;
    }
    
    return 0;
}