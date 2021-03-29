#include <iostream>

using namespace std;

class MyClass
{
    private:
        int x;
        double d;
    public:
        MyClass(int xx, double dd): x{ xx }, d{ dd } {}
        void printme() {
            cout << x << d << endl;
        }

        MyClass& operator-=(const MyClass& rhs)
        {
            this->x -= rhs.x;
            this->d -= rhs.d;
            return *this;
        }
        
        friend MyClass operator-(MyClass lhs, const MyClass& rhs)
        {
                lhs -= rhs;
                return lhs; 
            
        }
};

int main () {
    //testing
}
        