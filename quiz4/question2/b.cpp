#include <iostream>

using namespace std;

class Shape {
    public:
        virtual void draw() = 0;
        Shape() {
            draw();
            // Bug: Call to pure virtual member function 'draw' has undefined behavior; overrides of 'draw' in subclasses are not available in the constructor of 'Shape'
        }
        ~Shape() {}
};

class Circle : public Shape {
    public:
        void draw() {
            cout << "Draw circle" << endl;
        }
};

class Square : public Shape {
    public:
        void draw() {
            cout << "Draw square" << endl;
        }
};

class Triangle : public Shape {
    public:
        void draw() {
            cout << "Draw triangle" << endl;
        }
};

int main() {
    Shape sh;
    Circle c;
    Square s;
    Triangle t;
    sh.draw();
    c.draw();
    s.draw();
    t.draw();
    return 0;
}