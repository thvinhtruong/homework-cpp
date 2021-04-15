#include <iostream>
#include <vector>

using namespace std;


class Car {
    protected:
        double price;
        int year;
    
    public:
        Car(double price, int year): price(price), year(year){}
        double getPrice() {
            return this->price;
        }
        double calculateSalePrice();
};

class SportCar: public Car {
    public:
        SportCar(double price, int year): Car(price, year) {}
        double calculateSalePrice() {
            return this->price;
        }
        
        int getYear() {
            return this->year;
        }
};

class ClassicCar: public Car {
    public:
        ClassicCar(double price, int year): Car(price, year) {}
        double calculateSalePrice() {
            return this->price;
        }

        int getYear() {
            return this->year;
        }
};

class CarExhibition {
    private:
        vector<Car*>list;
    public:
        void addCar(Car* c) {
            list.push_back(c);
        }

        void addSportCar(SportCar* c) {
            list.push_back(c);
        }

        int getTotalPrice() {
            double x = 0;
            for (double i=0; i<list.size(); i++) {
                x += list[i]->getPrice();
            }
            return (int)x;
        }
};

int main() {
    SportCar *c1 = new SportCar(100, 2000);
    ClassicCar *c2 = new ClassicCar(200, 2001);
    Car *c = new Car(10, 2002);
    CarExhibition e;
    e.addCar(c);
    e.addSportCar(c1);
    e.addCar(c2);
    cout << e.getTotalPrice() << endl;
    delete c1;
    delete c2;
    delete c;
    return 0;
}