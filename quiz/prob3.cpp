#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(){}
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}

	Point(const Point& center)
	{
		this->x = center.x;
		this->y = center.y;
	}

	int getx() {
		return this->x;
	}

	int gety() {
		return this->y;
	}

	double computeDistance(const Point& rhs) {
		return sqrt((this->x - rhs.x)*(this->x - rhs.x) + (this->y - rhs.y)*(this->y - rhs.y));
	}

};
class Shape {
protected:
	Point anchor;
public:
	Shape(){}
	Shape(int x, int y)
	{
		Point center(x, y);
		anchor = cen;
	}
	double distance(const Shape* other)
	{
		return this->anchor.computeDistance(other->anchor);
	}
	virtual double computeArea() = 0;
	virtual double computePerimeter() = 0;
	virtual ~Shape(){};
};

class Square : public Shape {
    private:
        int side;
    public:
        Square(){}
        Square(int side, int x, int y):Shape(x,y){
            this->side = side;
        }

        double computeArea() {
            return this->side*this->side;
        }

        double computePerimeter() {
            return 4 * this->side;
        }

        double distance(Shape* other) {
            return this->anchor.computeDistance(other->anchor);
        }


};
class Rectangular : public Shape {
    private:
        int h;
        int w;
    public:
        Rectangular(){}
        Rectangular(int h,int w, int x, int y):Shape(x,y) { 
            this->h = h;
            this->w = w;
        }

        double computeArea() {
            return this->h*this->w;
        }
        double computePerimeter() {
            return (this->h+this->w)*2.0;
        }
        double distance(Shape* other) {
            return this->anchor.computeDistance(other->anchor);
        }
};

int main()
{
	Shape* o = new Rectangular(3,2,1,1);
	Shape* b = new Square(3,2,1);
	cout << o->computeArea() << endl;
	cout << o->computePerimeter() << endl;
	cout << b->computeArea() << endl;
	cout << b->computePerimeter()<< endl;
	cout <<o->distance(b);
	delete o;
	delete b;
}