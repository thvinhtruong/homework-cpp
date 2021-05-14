#include <iostream>

using namespace std;

class Shape {
    public:
        Shape(){}
        virtual void draw() {
            cout << "Draw sth" << endl;
        }
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
        Circle(){}
        void draw() {
            cout << "Draw circle" << endl;
        }
};

int main() {
    Shape *s1 = new Square();
    Shape *s2 = new Triangle();
    Shape *s3 = new Circle();
    s1->draw();
    s2->draw();
    s3->draw();
    delete s1;
    delete s2;
    delete s3;
    return 0;
}