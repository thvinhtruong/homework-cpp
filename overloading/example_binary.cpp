// The binary operators take two arguments and following are the examples of Binary operators. 
// You use binary operators very frequently like addition (+) operator, subtraction (-) operator and division (/) operator.

#include <iostream>

using namespace std;

class Square {
    private:
        double side;

    public:
        Square(){}
        Square(double side): side(side) {}
        double Area() {
            return side * side;
        }
        double operator+(const Square& s) {
            double a = s.side*s.side + this->side*this->side;
            return a;
        }
};

int main() {
    Square s(2);
    Square x(4);
    double res = s + x;
    cout << res << endl;
    return 0;
}