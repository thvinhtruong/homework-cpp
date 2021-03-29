#include <iostream>
#include <string>

using namespace std;

class MyClass
{
    private:
        double d;
        string s;
    public:
        MyClass(double dd, string ss): d{ dd }, s{ ss }
    {}
    MyClass(MyClass&& otherobject): d{ std::move(otherobject.d) }, s{ std::move(otherobject.s) }
    {
        cout << "Move constructor invoked." << '\n';
    }
    void printdata()
    {
        cout << d << s << endl;
    }
};

int main() {
    MyClass c1{ 3.14, "pi" };
    MyClass c2 = move(c1); //move constructor
    c2.printdata();
}