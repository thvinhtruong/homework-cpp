#include <iostream>

using namespace std;

class myclass {
    public:
        void printme();
};

void myclass::printme() {
    cout << "Hello world" << endl;
}

int main() {
    myclass a;
    a.printme();
    return 0;
}