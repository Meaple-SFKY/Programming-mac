#include<iostream>

using namespace std;

int main(void) {
    return 0;
}

class Line {
private:
    double a;
    double b;
    double c;

    void set_a(double a_temp) {
        a = a_temp;
    }

    void set_b(double b_temp) {
        b = b_temp;
    }

    void set_c(double c_temp) {
        c = c_temp;
    }

public:
    Line(double a_temp, double b_temp, double c_temp) {
        set_a(a_temp);
        set_b(b_temp);
        set_c(c_temp);
    }

    double get_a(void) {
        return a;
    }

    double get_b(void) {
        return b;
    }

    double get_c(void) {
        return c;
    }
};