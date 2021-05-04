// The unary operators operate on a single operand and following are the examples of Unary operators:
// The increment (++) and decrement (--) operators.
// The unary minus (-) operator.
// The logical not (!) operator.

#include <iostream>
#include <string>

using namespace std;

class EmBe {
    private:
        string action;
        int num;
    
    public:
        EmBe(string a, int n): action(a), num(n) {}
        void operator++(int) 
        {
            this->num++;
            cout << "Em bé bò " << this->num << " " << "bước" << endl;
        }

};

int main() {
    EmBe e("Bò", 1);
    e++;
    return 0;
}