#include <iostream>

using namespace std;
int main() {
    char c = 'a';
    char* p = &c;
    cout << "The value of the dereferenced pointer is: " << *p<<endl;
    int x = 123;
    int* p1 = &x;
    cout << "The value of the dereferenced pointer is: " << *p<<endl;
    int* p2 = &x;
    *p = 456; // change the value of pointed-to object
    cout << "The value of x is: " << x;
}
