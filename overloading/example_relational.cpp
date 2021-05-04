//There are various relational operators supported by C++ language like (<, >, <=, >=, ==, etc.) which can be used to compare C++ built-in data types.

#include <iostream>

using namespace std;

class Person {
    private:
        int age;
    
    public:
        Person(int age): age(age) {}
        bool operator == (const Person& p) {
            return (p.age == this->age) ? true: false;
        }
};

int main() {
    Person p1(10);
    Person p2(10);
    if (p1 == p2) {
        cout << "Person 1 has the same age as Person 2" << endl;
    }
    return 0;
}