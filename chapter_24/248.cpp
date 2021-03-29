#include <iostream>

using namespace std;

class MyClass
{
    private:
        int x;
        double d;
    public:
        MyClass(int xx, double dd);
        MyClass(const MyClass& rhs);
        void printdata();
    };

MyClass::MyClass(int xx, double dd)
    : x{ xx }, d{ dd }
{}

void MyClass::printdata()
{
    cout << x << d << endl;
}

int main() {
    MyClass c1(1, 2);
    MyClass c2 = c1;
    c1.printdata();
    c2.printdata();
}

