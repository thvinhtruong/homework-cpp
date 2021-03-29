#include <iostream>
#include <cmath>

using namespace std;

class Point {
    private:
        int x, y;
    public:
        void SetCenter(int a, int b) {
            this->x = a;
            this->y = b;
        }
};

class Shape {
    private:
        // coordinate of center point
        Point p;

    public:
        void setPoint(int x, int y) {
            p.SetCenter(x, y);
        }
        virtual double ComputeArea() = 0;
        virtual double Circumstance() = 0;
        void setRec(int height, int width) {
            h = height;
            w = width;
        }
        void setCir(int radius) {
            r = radius;
        }
        void setSquare(int side) {
            s = side;
        }
        protected:
            int h, w, r, s;

};

class Circle: public Shape {
    public:
        double ComputeArea() {
            return M_PI * r * r;
        }    
        double Circumstance() {
            return M_PI * 2 * r;
        }
};

class Square: public Shape {
    public:
        double ComputeArea() {
            return pow(s, 2);
        }
        double Circumstance() {
            return 4*this->s;
        }
};

class Rectangular: public Shape {
    public:
        double ComputeArea() {
            return h * w;
        }
        double Circumstance() {
            return (h + w) * 2;
        }
};

int main() {
    Rectangular r;
    r.setRec(2, 3);
    Circle c;
    c.setCir(5);
    Square s;
    s.setSquare(6);
    cout << r.ComputeArea() << endl;
    cout << c.ComputeArea() << endl;
    cout << s.ComputeArea() << endl;
    return 0;
}