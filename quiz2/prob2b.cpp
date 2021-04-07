#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Campus {
    private:
        string name;
        string address;
        int distance;
    
    public:
        Campus(string name, string address, int distance): name(name), address(address), distance(distance) {}
        string getName() {
            return this->name;
        }

        string getAddress() {
            return this->address;
        }
        
        int getDis() {
            return this->distance;
        }
};

class Club {
    private:
        string name;
        string building;
        int phone;
    
    public:
        Club(Campus c, string building, int phone) {
            this->name = name;
            this->building = building;
            this->phone = phone;
        }
};

class Teacher {
    private:
        int id;
        string name, title, office;

    public:
        Teacher(Campus c, int id, string name, string title, string office) {
            this->id = id;
            this->name = name;
            this->title = title;
            this->office = office;
        }
};

int main() {
    //testing
}