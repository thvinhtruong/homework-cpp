#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Address {
    private:
        string street;
        int house;
        string city;
    
    public:
        Address(){}
        Address(string street, int house, string city): street(street), house(house), city(city) {}
        
        string getStreet() {
            return this->street;
        }

        int getHouse() {
            return this->house;
        }

        string getCity() {
            return this->city;
        }

        bool isTheSameStreet(const Address& another) {
            return (this->street == another.street) ? true: false;
        }
};

class Dog {
    private:
        string name;
        int code;

    public:
        Dog(){}
        Dog(string name, int code) {
            this->name = name;
            this->code = code;
        }

        string getName() {
            return this->name;
        }

        int getCode() {
            return this->code;
        }
};

class House {
    private:
        Address a;
        vector<Dog *> list;

    public:
        House(string street, int house, string city): a(street, house, city) {}

        void addDog(Dog *d) {
            list.push_back(d);
        }

        void removeDog(Dog *d) {
            int x = 0;
            for (int i=0; i<list.size(); i++) {
                if (this->list[i]->getName() == d->getName()) {
                    x+=i;
                }
            }
            list.erase(list.begin() + x);
        }

        int getNumberOfDog() {
            return list.size();
        }

        Address getAddress() {
            return this->a;
        }

        bool SameStreetForHouses(House* another) {
            return (this->a.getStreet() == another->getAddress().getStreet());
        }        
};

class House_Management {
    private:
        vector <House *> list_of_house;

    public:
        House_Management(){}
        void addHouse(House *h) {
            list_of_house.push_back(h);
        }

        int HouseNum() {
            return list_of_house.size();
        }

        int count_dogs_same_street() {
            int x = 0;
            for (int i=0; i<list_of_house.size() - 1; i++) {
                if (list_of_house[i]->SameStreetForHouses(list_of_house[i+1])) {
                    x += (list_of_house[i]->getNumberOfDog() + list_of_house[i+1]->getNumberOfDog());
                }
            }
            return x;
        }
};

int main() {
    House *h1 = new House("tdc", 123, "Binh Duong");
    House *h2 = new House("tdc", 234, "Binh Duong");
    Dog *d1 = new Dog("david", 456);
    Dog *d2 = new Dog("trung", 212);
    House_Management hm;

    h1->addDog(d1);
    h2->addDog(d2);
    hm.addHouse(h1);
    hm.addHouse(h2);

    cout << hm.count_dogs_same_street() << endl;
    delete h1;
    delete h2;
    delete d1;
    delete d2;
    return 0;
}