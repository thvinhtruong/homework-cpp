#include <iostream>

using namespace std;

class MyClass
{
    public:
        void printmessage()
        {
            cout << "Hello World.";
        }
};
int main() {
    MyClass o;
        o.printmessage();
}