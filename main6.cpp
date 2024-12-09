#include "iostream"
#include "string"

using namespace std;

class Animal {

public:
    Animal() {
        this->m_A = 10;
//        cout << "Animal Structure m_A:" << this->m_A << endl;
    }

    virtual void eat() {
        cout << "Animal eat" << endl;
    }

    int m_A;
};

class Dog : public Animal {
public:
    void eat() {
        cout << "Dog eat" << endl;
    }
};

class Cat : public Animal {
public:
    Cat() {
        this->m_A = 20;
//        cout << "Cat Structure m_A:" << this->m_A << endl;
    }

    void eat() {
        cout << "Cat eat" << endl;
    }

    void change(int number) {
        this->m_A = number;
    }

    int m_A;
};

void doEat(Animal *animal) {
    animal->eat();
    animal->m_A = 30;
//    cout << "Cat * m_A:" << animal->m_A << " address:" << animal << endl;
}

void doEat(Animal &animal) {
    animal.eat();
    animal.m_A = 40;
//    cout << "Cat & m_A:" << animal.m_A << " address:" << &animal << endl;
}

void test() {
    Cat cat;
//    cat.eat();
    doEat(&cat);
    cout << "Cat after change1 m_A:" << cat.m_A << " address:" << &cat << endl;
    cout << "Cat after change1 m_A:" << cat.Animal::m_A << " address:" << &cat << endl;
    doEat(cat);
    cout << "Cat after change2 m_A:" << cat.m_A << " address:" << &cat << endl;
    cout << "Cat after change2 m_A:" << cat.Animal::m_A << " address:" << &cat << endl;
    cat.change(30);
    cout << "Cat after change m_A:" << cat.m_A << endl;
//    cout << "Animal before change m_A:" << cat.Animal::m_A << endl;
//    cat.Animal::m_A = 40;
//    cout << "Animal after change m_A:" << cat.Animal::m_A << endl;
//    Animal animal;
//    doEat(animal);
}

int main() {
    test();
}
