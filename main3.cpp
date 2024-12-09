#include <iostream>

using namespace std;

int funC(int a, int b = 2, int c = 3);

int funB(int a, int b = 10, int c = 20) {
    return a + b + c;
}

int funC(int a, int b, int c) {
    return a + b + c;
}

int funD(int a, int &b) {
    b = 20;
    return a + b;
}

int funE(int a, const int &b) {
    return a + b;
}

int funF(int a, int *b) {
    *b = 3;
    return a + *b;
}

class Circle {
public:
    int m_r = 2;

    double getLength(double pi) {
        return 2 * pi * m_r;
    }
};

int main3() {
    int a = 1;
    int b = 2;
    cout << "step 1 result:" << funB(50) << endl;
    cout << "step 2 result:" << funC(50) << endl;
    cout << "step 3 result:" << funD(a, b) << endl;
    cout << "step 4 result:" << funE(a, b) << endl;
    cout << "step 5 result:" << funF(a, &b) << endl;

    Circle circle;
    cout << "circle length:" << circle.getLength(3.14159) << endl;

    int c = 10;
    unsigned int d = -100;
    cout << "c+d=" << c + d << endl;
    return 0;
}
