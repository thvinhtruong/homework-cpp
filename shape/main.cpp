#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Shape {
    protected:
        double side, area;
    public:
        Shape(){}
        Shape(double side): side(side) {}
        virtual void draw() = 0;
        virtual void calc_area() = 0;
        virtual void printA() = 0;
        virtual double getArea() = 0;
        virtual ~Shape(){}
};

class Circle: public Shape {
    public:
        Circle(){}
        Circle(double radius): Shape(radius) {}
        void draw() {
            cout << "Drawing Circle" << endl;
        }  

        void calc_area() {
            this->area = M_PI * this->side * this->side;
        }

        void printA() {
            cout << this->area << endl;
        }

        double getArea() {
            return this->area;
        }
};

class Square: public Shape {
    public:
        Square(){}
        Square(double side): Shape(side) {} 
        void draw() {
            cout << "Drawing Squre" << endl;
        }

        void calc_area() {
            this->area = this->side * this->side;
        }

        void printA() {
            cout << this->area << endl;
        }

        double getArea() {
            return this->area;
        }

};

class Triangle: public Shape {
    private:
        double height;
    public:
        Triangle(){}
        Triangle(double side, double height): Shape(side) {
            this->height = height;
        }
        void draw() {
            cout << "Drawing Triangle" << endl;
        }

        void calc_area() {
            this->area = this->height * 1/2 * this->side;
        }

        void printA() {
            cout << this->area << endl;
        }

        double getArea() {
            return this->area;
        }
};

int main() {
    Shape *c = new Circle(3);
    Shape *sq = new Square(2);
    Shape *t = new Triangle(1, 2);
    c->calc_area();
    c->printA();
    sq->calc_area();
    sq->printA();
    t->calc_area();
    t->printA();
    vector <Shape*> list;
    vector <double> area_list;
    list.push_back(c);
    list.push_back(sq);
    list.push_back(t);
    for (int i=0; i<list.size(); i++) {
        list[i]->draw();
        area_list.push_back(list[i]->getArea());
    }
    sort(area_list.begin(), area_list.end());
    reverse(area_list.begin(), area_list.end());
    for (int i=0; i<area_list.size(); i++) {
        cout << area_list[i] << endl;
    }
    delete c;
    delete sq;
    delete t;
    return 0;
}