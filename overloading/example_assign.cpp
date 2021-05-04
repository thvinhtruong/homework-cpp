#include <iostream>

using namespace std;

class Person {
    private:
        int age;
    
    public:
        Person(){}
        Person(int age): age(age) {}
        void operator = (Person& p) {
            p.age = this->age;
            cout << p.age << endl;
        }
};

int main() {
    Person p1(10);
    Person p2;
    p1 = p2;
    return 0;
}