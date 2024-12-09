#include <iostream>

using namespace std;

void funA(int param) {
    param = 20;
}

void funB(int *param) {
    *param = 30;
}

void funC(int &param) {
    param = 40;
}

int main0() {
    int a = 10;
    cout << "step 1 a:" << a << endl;
    funA(a);
    cout << "step 2 a:" << a << endl;
    funB(&a);
    cout << "step 3 a:" << a << endl;
    funC(a);
    cout << "step 4 a:" << a << endl;
    return 0;
}
