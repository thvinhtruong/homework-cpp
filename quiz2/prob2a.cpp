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
};

class Club {
    private:
        string name;
        string building;
        int phone;
    
    public:
        Club(string name, string building, int phone): name(name), building(building), phone(phone) {}

};

int main() {
    //testing
}