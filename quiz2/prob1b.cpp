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

class Pet {
    protected:
        string name;
    
    public:
        Pet(){};
        Pet(string name): name(name) {}
        virtual string getName() = 0;
        virtual ~Pet(){}
};

class Dog: public Pet {
    public:
        Dog(){}
        Dog(string name): Pet(name) {}

        string getName() {
            return this->name;
        }
};

class Cat: public Pet {
    public:
        Cat(){}
        Cat(string name): Pet(name) {}

        string getName() {
            return this->name;
        }
};

class House {
    private:
        Address a;
        vector<Pet *> list;

    public:
        House(string street, int house, string city): a(street, house, city) {}

        void addPet(Pet* p) {
            list.push_back(p);
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
            int x = 0;
            for (int i=0; i<list.size(); i++) {
                Dog *d = dynamic_cast <Dog*>(list[i]);
                if (d) {
                    x++;
                }
            }
            return x;
        }

        int getNumberOfCat() {
            return list.size() - getNumberOfDog();
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

        int count_pets_same_street() {
            int x = 0;
            for (int i=0; i<list_of_house.size() - 1; i++) {
                if (list_of_house[i]->SameStreetForHouses(list_of_house[i+1])) {
                    int dog_num = list_of_house[i]->getNumberOfDog() + list_of_house[i+1]->getNumberOfDog();
                    int cat_num = list_of_house[i]->getNumberOfCat() + list_of_house[i+1]->getNumberOfCat();
                    x += dog_num + cat_num;
                }
            }
            return x;
        }
};

int main() {
    House *h1 = new House("tdc", 123, "Binh Duong");
    House *h2 = new House("tdc", 234, "Binh Duong");
    Pet *d1 = new Dog("david");
    Pet *d2 = new Dog("trung");
    Pet *c1 = new Cat("thang");
    Pet *c2 = new Cat("quang");
    House_Management hm;

    h1->addPet(d1);
    h2->addPet(d2);
    h1->addPet(c1);
    h2->addPet(c2);
    hm.addHouse(h1);
    hm.addHouse(h2);

    cout << hm.count_pets_same_street() << endl;
    delete h1;
    delete h2;
    delete d1;
    delete d2;
    delete c1;
    delete c2;
    return 0;
}