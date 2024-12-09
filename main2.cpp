#include <iostream>

using namespace std;

void funA(int param) {
    param = 20;
    cout << "funA param address:" << &param << endl;
}

void funB(int *param) {
    *param = 30;
    cout << "funB param address1:" << static_cast<void *>(param) << endl;
    cout << "funB param address2:" << &param << endl;
    cout << "funB param address3:" << param << endl;
}

void funC(int &param) {
    param = 40;
    cout << "funC param address1:" << &param << endl;
    cout << "funC param address2:" << param << endl;
}

int main2() {
    int a = 10;
    cout << "main2 param address:" << &a << endl;
//    cout << "step 1 a:" << a << endl;
    funA(a);
//    cout << "step 2 a:" << a << endl;
    funB(&a);
//    cout << "step 3 a:" << a << endl;
    funC(a);
//    cout << "step 4 a:" << a << endl;
    return 0;
}
