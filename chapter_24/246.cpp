#include <iostream>

using namespace std;

class myclass {
    public:
        myclass();
        ~myclass();
};

myclass::myclass()
{
    std::cout << "Constructor invoked." << '\n';
}
myclass::~myclass()
{
    std::cout << "Destructor invoked." << '\n';
}

int main() {
    myclass c;
    return 0;
}
