#include <iostream>
#include <string>

using namespace std;

class EmBe {
    private:
        string action;
        int num;
    
    public:
        EmBe(string a, int n): action(a), num(n) {}
        
        void operator++ (int) // postfix
        {
            this->num++;
        }

        void operator++ () //prefix;
        {
            ++this->num;
        }

        void count_step() {
            cout << "Em bé bò " << this->num << " " << "bước" << endl;
        }
};

int main() {
    EmBe e("Bò", 0);
    for (int i=1; i<=10; i++) {
        e++; 
        // ++e++ --> error: cannot increment value of type 'void'
        e.count_step();
    }
    return 0;
}