#include <iostream>

using namespace std;


class Euler {
    private:
        float num;
    
    public:
        // if we input factorial function inside private scope, we cant see the complex of the program --> encapsulation.
        int factorial(int n) {
            if (n == 0) {
                return 1;
            }
            else if (n == 1) {
                return 1;
            }
            else  {
                return n * factorial(n-1);
            }
        }

        void euler() {
            float x = 0;
            num = 10;
            for (int i=0; i<num; i++) {
                x += (float)1/factorial(i);
            }
            cout << x << endl;
        }
};

int main() {
    Euler e;
    e.euler();
    return 0;
}
        
        