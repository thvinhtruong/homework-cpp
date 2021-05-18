#include <iostream>
#include <vector>
#include <algorithm>
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

class List {
    private:
        vector <Complex *> num_list;
    
    public:
        List(){}
        void addNum(Complex *n) {
            num_list.push_back(n);
        }

        void sortNum() {
            sort(num_list.begin(), num_list.end());
            reverse(num_list.begin(), num_list.end());
        }

        void printNum() {
            int i;
            for (i=0; i<num_list.size(); i++) {
                num_list[i]->PrintMe();
            }
        }
};

int main() {
    Complex *n1 = new Complex(2, 2);
    Complex *n2 = new Complex(2, 3);
    Complex *n3 = new Complex(1, 4);
    List ls;

    cout << n1->getAbs() << endl;
    cout << n2->getAbs() << endl;
    cout << n3->getAbs() << endl;

    ls.addNum(n1);
    ls.addNum(n2);
    ls.addNum(n3);
    ls.sortNum();
    ls.printNum();
    
//   if (n1 > n2) {
//      cout << "true" << endl;
//    } else {
//        cout << "false" << endl;
//    }
//    Complex *n3;
//    Complex summ;
//    summ = *n1 + *n2;
//    summ.PrintMe();
//    n3 = n1;
//    n3->PrintMe();
//    n3 = n2;
//    n3->PrintMe();
    
    delete n1;
    delete n2;
    delete n3;
    return 0;
}