#include <iostream>

using namespace std;

class JackPot {
    private:
        int num;

    public:
        JackPot(){}
        JackPot(int num): num(num) {}
        friend ostream &operator<<(ostream &output, const JackPot& j) { 
            output << j.num << "";
            return output;            
        }

        friend istream &operator>>( istream  &input, JackPot& j) { 
            input >> j.num;
            return input;            
        }
};  

int main() {
    JackPot j(2131312);
    JackPot test;
    cout << "Enter value: ";
    cin >> test;
    cout << test << endl;
    cout << j << endl;
}