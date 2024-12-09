#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Person {
public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

public:
    string m_Name;
    int m_Age;
};

void test() {
    vector<Person> v;
    Person p1("Tom", 10);
    Person p2("Jason", 11);
    Person p3("Ruby", 12);
    Person p4("Kotlin", 13);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "name:" << it->m_Name << ",age:" << it->m_Age << endl;
    }
}

void test2() {
    vector<Person *> v;
    Person p1("Tom", 10);
    Person p2("Jason", 11);
    Person p3("Ruby", 12);
    Person p4("Kotlin", 13);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "name:" << (*it)->m_Name << ",age:" << (*it)->m_Age << endl;
    }
}

int main() {
    test();
    test2();
    return 0;
}
