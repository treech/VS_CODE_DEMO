#include "iostream"
#include "string"

using namespace std;

class Building;

class Person {
public:
    Person();

    void visit();

    void visit2();

private:
    Building *building;
};

class Building {

    friend void Person::visit();

public:
    Building();

    string m_SittingRoom;
private:
    string m_BedRoom;
};

Person::Person() {
    this->building = new Building;
}

void Person::visit() {
    cout << "visit--正在访问" << building->m_SittingRoom << endl;
    cout << "visit--正在访问" << building->m_BedRoom << endl;
}

void Person::visit2() {
    cout << "visit2--正在访问" << building->m_SittingRoom << endl;
}

Building::Building() {
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

void test() {
    Person person;
    person.visit();
    person.visit2();
}


int main4() {
    test();
    return 0;
}