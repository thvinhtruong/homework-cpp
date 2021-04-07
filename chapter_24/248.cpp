#include <iostream>

using namespace std;

class MyClass
{
    private:
        int x;
        double d;
    public:
        MyClass(int a, double b);
        void printdata();
};

MyClass::MyClass(int a, double b) {
    this->x = a;
    this->d = b;
}

void MyClass::printdata()
{
    cout << x << "" <<  d << endl;
}

int main() {
    MyClass c1(1, 2.231);
    MyClass c2 = c1;
    c1.printdata();
    c2.printdata();
}

