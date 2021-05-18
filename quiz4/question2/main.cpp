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

class Canvas {
    private:
        vector <Shape*> shape_list;
        vector <double> area_list;
    
    public:
        Canvas(){}
        
        void addShape(Shape *s) {
            shape_list.push_back(s);
        }

        void sortArea() {
            int i;
            for (i=0; i<shape_list.size(); i++) {
                area_list.push_back(shape_list[i]->getArea());
            }
            sort(area_list.begin(), area_list.end());
        }
        
        void PrintAreaList() {
            reverse(area_list.begin(), area_list.end());
            for (int i=0; i<area_list.size(); i++) {
                cout << area_list[i] << " ";
            }
            putchar('\n');
        }

        int countShape() {
            return shape_list.size();
        }

        int countCircle() {
            int n = 0;
            for (int i=0; i<shape_list.size(); i++) {
                Circle *c = dynamic_cast<Circle*>(shape_list[i]);
                if (c) {
                    n++;
                }
            }
            return n;
        }

        int countSquare() {
            int n = 0;
            for (int i=0; i<shape_list.size(); i++) {
                Square *s = dynamic_cast<Square*>(shape_list[i]);
                if (s) {
                    n++;
                }
            }
            return n;
        }

        int countTriangle() {
            return countShape() - countSquare() - countCircle();
        }
};

int main() {
    Shape *c = new Circle(3);
    Shape *sq = new Square(2);
    Shape *t = new Triangle(1, 2);
    Canvas list;

    c->calc_area();
    sq->calc_area();
    t->calc_area();

    list.addShape(c);
    list.addShape(sq);
    list.addShape(t);
    list.sortArea();
    list.PrintAreaList();
    
    cout << list.countSquare() << endl;
    cout << list.countCircle() << endl;
    cout << list.countTriangle() << endl;

    delete c;
    delete sq;
    delete t;
    return 0;
}