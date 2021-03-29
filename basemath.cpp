#include <iostream>

using namespace std;

class Basemath {
    
    public:
        bool isEven(int num) {
            return true ? num % 2 == 0 : false;
        }

        int factorial(int num) {
            if (num == 0) {
                return 1;
            }
            else {
                return num * factorial(num - 1); 
            }
        }

};

class Advancemath: public Basemath {
    public:
        double estimateEuler(int loops) {
            double x = 0;
            loops = 10;
            for (int i=0; i<loops; i++) {
                x += (float)1/factorial(i);
            }
            return x;
        }
};

int main() {
    Advancemath res;
    cout << res.estimateEuler(3) << endl;
    return 0;
    
}
