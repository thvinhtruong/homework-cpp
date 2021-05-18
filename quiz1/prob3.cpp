#include <iostream>
#include <cmath>

using namespace std;

class Point {
	private:
		int x;
		int y;
	public:
		Point(){}
		Point(int x, int y): x(x), y(y) {}

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
		Shape(int x, int y): anchor(x, y) {}

		virtual double distance(Shape* other) = 0;

		Point getAnchor() {
			return this->anchor;
		}

		virtual double computeArea() = 0;
		virtual double computePerimeter() = 0;

		virtual ~Shape(){}

};

class Square : public Shape {
	private:
		int side;
	public:
		Square(){}
		Square(int side, int x, int y): Shape(x, y){
			this->side = side;
		}

		double computeArea() {
			return this->side*this->side;
		}

		double computePerimeter() {
			return 4 * this->side;
		}

		double distance(Shape* other) {
			return this->anchor.computeDistance(other->getAnchor());
		}
};

class Rectangular : public Shape {
    private:
        int h;
        int w;
    public:
        Rectangular(){}
        Rectangular(int h,int w, int x, int y): Shape(x, y) { 
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
            return this->anchor.computeDistance(other->getAnchor());
        }
};

int main()
{
	Shape* r = new Rectangular(3,2,1,1);
	Shape* s = new Square(3,2,1);
	cout << r->computeArea() << endl;
	cout << r->computePerimeter() << endl;
	cout << s->computeArea() << endl;
	cout << s->computePerimeter()<< endl;
	cout << r->distance(s) << endl;
	cout << s->distance(r) << endl;
	delete r;
	delete s;
	return 0;
}