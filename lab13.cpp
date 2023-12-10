#include <iostream>
using namespace std;

class Parent{
public:
    void print() {
        cout << "이곳은 Parent입니다." << endl;
    }
};

class Child : public Parent{
public:
    void print() {
        cout << "이곳은 Child입니다." << endl;
    }
};

void main() {
    Parent* p = new Parent;
    Child* c = new Child;
    
    p->print();
    p = c;
    p->print();
}
