#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Address {
    private:
        string street;
        int house_num;
        string city_name;
    
    public:
        Address(string street, int house_num, string city_name): street(street), house_num(house_num), city_name(city_name) {}
        string getStreet() {
            return this->street;
        }

        void setStreet(string street) {
            this->street = street;
        }
};

class Dog {
    private:
        string name;
        string street;
        Address a;
        int code;

    public:
        Dog(string name, int code, string street) {
            this->name = name;
            this->code = code;
            a.setStreet(this->street);
        }
        string getName() {
            return this->name;
        }

        string getStreet() {
            return this->street;
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

        int getCountSameStreetDog() {
            int y;
            for (int i=0; i<list.size(); i++) {
                int x = 0;
                for (int j=0; j<list.size(); j++) {
                    if (list[i]->getStreet() == list[j]->getStreet()) {
                        x++;
                        if (x > 1) {
                            y++;
                        }
                    } 
                }
            }
            return y;
        }
};

int main() {
    House h("tdc", 123, "Binh Duong");
    Dog *d = new Dog("david", 456, "tdc");
    h.addDog(d);
    h.removeDog(d);
    cout << h.getNumberOfDog() << endl;
    delete d;
    return 0;
}