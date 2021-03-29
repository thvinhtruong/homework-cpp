#include <iostream>

using namespace std;

class myclass {
    private:
        int x, y;

    public:
        myclass(int x, int y) {
            this->x = x;
            this->y = y;
        }
        void printme();
};

void myclass::printme() {
    cout << x << endl;
    cout << y << endl;
}

int main () {
    myclass c(1, 2);
    c.printme();
    return 0;
}