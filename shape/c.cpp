#include <iostream>

using namespace std;

class Shape {
    public:
        Shape(){}
        virtual void draw() {
            cout << "Draw sth" << endl;
        }
        ~Shape(){}
};

class Square: public Shape {
    public:
        Square(){}
        void draw() {
            cout << "Draw square" << endl;
        }
};

class Triangle: public Shape {
    public:
        Triangle(){}
        void draw() {
            cout << "Draw triangle" << endl;
        }
};

class Circle: public Shape {
    public:
        void draw() {
            cout << "Draw circle" << endl;
        }
};

void Testing(Shape& s) {
    s.draw();
}

int main() {
    Square sq;
    Testing(sq); // not work when passing by val.
    return 0;
}