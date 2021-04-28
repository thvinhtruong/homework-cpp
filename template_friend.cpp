#include <iostream>

using namespace std;

//ex1
int add(int a, int b){
    return a + b;
}

//ex2
class A {
    private:
        int a;
    
    public:
        A(int a): a(a) {}
    
    friend class B
};

class B {
    public:
        void getA(A x) {
            cout << x.a << endl;
        }
};

int main {
    //testing
    //ex3
    int (*ptr) (int, int) = add;
    cout << ptr(1, 2);
}


