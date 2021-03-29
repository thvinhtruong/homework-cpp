#include <iostream>

using namespace std;

int main() {
    int x = 123;
    int &y = x; //y is an alias for x
    cout<<"x: "<<x<<' '<<endl;
    x = 456;
    cout<<"y: "<<y<<' '<<endl;
    y = 789;
    cout<<"x: "<<x<<' '<<endl;

    int a = 123;
    const int& b = a; // const reference
    a = 456;
    cout<<"b: "<<b<<endl;
}