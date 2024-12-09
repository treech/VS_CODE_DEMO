#include "iostream"
#include "string"

using namespace std;

class Person {

public:
    Person() {}

    Person(int a, int b) {
        this->m_numA = a;
        this->m_numB = b;
    }

    //成员函数加号运算符重载
//    Person operator+(Person &p) {
//        Person tp;
//        tp.m_numA = this->m_numA + p.m_numA;
//        tp.m_numB = this->m_numB + p.m_numB;
//        return tp;
//    }

    int m_numA;
    int m_numB;
private:
    int m_numC;
};

//全局函数加号运算符重载
Person operator+(Person &left, Person &right) {
    Person tp(0, 0);
    cout << "地址1：" << &tp << endl;
    tp.m_numA = left.m_numA + right.m_numA;
    tp.m_numB = left.m_numB + right.m_numB;
    return tp;
}

void test() {
    Person person1(10, 20);

    Person person2(40, 50);
    Person person = person1 + person2;
    cout << "加号运算符重载：m_numA=" << person.m_numA << ",m_numB=" << person.m_numB << "地址2：" << &person << endl;
}

int main5() {
    test();
}
