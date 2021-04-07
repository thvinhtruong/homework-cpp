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
        string setStreet(string s) {
            this->street = s;
        }
};

class Pet {
    protected:
        string name;
        string street;
        Address a;
    
    public:
        Pet(){}
        Pet(string name, string street): name(name) {
            a.setStreet(street);
        }
        virtual ~Pet(){}
        bool operator==(Pet other)
        {
            if (other.name!=this->name) return false;
            return true;
        }

        string getName() {
            return this->name;
        }

        string getStreet() {
            return this->street;
        }
};

class Dog: public Pet {
    public:
        Dog(string name){
            this->name = name;
        }
};

class Cat: public Pet {
    public:
        Cat(string name) {
            this->name = name;
        }
};

class House {
    private:
        Address a;
        vector<Pet*>list;

    public:
        House(string street, int house, string city): a(street, house, city) {}

        void addDog(Pet *d) {
            list.push_back(d);
        }

        void addCat(Pet *c) {
            list.push_back(c);
        }

        void removeDog(Pet *d) {
            for (int i=0; i<list.size(); i++) {
                if (this->list[i]->getName()==d->getName()) {
                    list.erase(list.begin()+i);
                }
            }
        }

        int getNumberOfPet() {
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
    Dog *d = new Dog("David");
    Cat *c = new Cat("Thang");
    h.addDog(d);
    h.addCat(c);
    cout << h.getNumberOfPet() << endl;
    delete d;
    delete c;
}