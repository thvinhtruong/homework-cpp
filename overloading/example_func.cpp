// The function call operator () can be overloaded for objects of class type. When you overload ( )
// you are not creating a new way to call a function
// Rather, you are creating an operator function that can be passed an arbitrary number of parameters.

#include <iostream>

using namespace std;

class Number {
    private:
        int num;
    
    public:
        Number(){}
        Number(int num): num(num) {}
        Number operator()(int a) {
            Number x;
            x.num = this->num + a;
            return x;
        }
        
        int getNum() {
            return this->num;
        }

};

int main() {
    Number a;
    Number temp(1);
    a = temp(1);
    cout << a.getNum() << endl;
}

