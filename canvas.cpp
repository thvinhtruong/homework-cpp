#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Point
{
    private:
        int x;
        int y;
    public:
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }

};

class Shape {
    protected:
        Point center;
    public:
        Shape(int x, int y): center(x, y) { }
};

class Circle : public Shape
{
private:
    int radius;
public:
    Circle(int x, int y, int radius): Shape(x, y) {
        this->radius = radius;
    }

    double computeArea() {
        return this->radius * this->radius * 3.14;
    }

    double computeCir() {
        return this->radius * 2.0 * 3.14;
    }

};

class Square : public Shape
{
    private:
        int side;
    public:
        Square(){};
        Square(int x, int y, int side) {
            this->side = side;
        }
        double computeArea()
        {
            return this->side*this->side;
        }
        double computeCir()
        {

            return this->side*4.0;
        }

};

class Rectangle : public Shape
{
private:
    int height;
    int width;
public:
    Rectangle(){}
    Rectangle(int x, int y,int h, int w) {
        this->height = h;
        this->width = w;
    }
    double computeArea()
    {
        return this->height*this->width;
    }
    double computeCir()
    {

        return (this->height + this->width)*2.0;
    }


};

class Canvas {
    private:
        vector<Shape>list;
    public:
        void getShape(Shape *s) {
            list.push_back(*s);
        }
        double calcSum() {
            int x = 0;
            for (int i=0; i<list.size(); i++) {
                x += list[i].computeArea();
            }
            return x;
        }
};

int main()
{
    Shape* c = new Circle(1,1,2);
    Shape* s = new Square(1,1,4);
    Canvas hinh;
    hinh.getShape(c);
    hinh.getShape(s);
    return 0;
}
