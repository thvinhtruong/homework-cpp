#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Complex {
    private:
        double real, imag;

    public:
        Complex(){}
        Complex(double real, double imag): real(real), imag(imag) {}

        double getReal() const {
            return this->real;
        }

        double getImag() const {
            return this->imag;
        }

        void setReal(double real) {
            this->real = real;
        }

        double getAbs() const {
            return sqrt(this->real * this->real + this->imag * this->imag);
        }

        void setImag(double imag) {
            this->imag = imag;
        }

        void PrintMe() {
            string temp;
            if (this->imag > 0) {
                temp = "+";
            } else {
                temp = "-";
            }
            cout << this->real << " " << temp << " " << this->imag << "i" << endl;
        }
        
        void operator= (const Complex& another) {
            this->real = another.real;
            this->imag = another.imag;
        }

        bool operator== (const Complex& another) {
            return (this->real == another.real && this->imag == another.imag) ? true: false;
        }

        bool operator> (const Complex& another) {
            return (this->getAbs() > another.getAbs()) ?  true: false;
        }

        bool operator< (const Complex& another) {
            return (this->getAbs() < another.getAbs()) ? true: false;
        }

        Complex operator+ (const Complex& another) {
            return Complex(this->real + another.real, this->imag + another.imag);
        }

        Complex operator- (const Complex& another) {
            return Complex(this->real - another.real, this->imag - another.imag);
        }
};

int main() {
    Complex n1(1, 2);
    Complex n2(2, 3);
    Complex n3;
    Complex summ;
    cout << n1.getAbs() << endl;

    if (n1 > n2) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    summ = n1 + n2;
    summ.PrintMe();

    n3 = n1;
    n3.PrintMe();
    n3 = n2;
    n3.PrintMe();
    return 0;
}