#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
    protected:
        string name;
        double salary;
    
    public:
        Employee(string name, double salary) {
            this->name = name;
            this->salary = salary;      
        }
        
        virtual double getSalary() {
            return this->salary;
        }
    
};

class Boss: public Employee {
    protected:
        double bonus;
    public:
        Boss(string name, double salary, double bonus): Employee(name, salary) {
            this->bonus = bonus;
        }

        double getBonus() {
            return this->bonus;
        }

        double getSalary() {
            return salary + this->bonus;
        }
};

int main() {
    //testing
    Employee e1("Trung", 50);
    Employee e2("Thang", 49);
    Employee e3("Quang", 58);
    Boss b("Vinh", 200, 100);
    cout << e1.getSalary() << endl;
    cout << e2.getSalary() << endl;
    cout << e3.getSalary() << endl;
    cout << b.getSalary() << endl;
    cout << b.getBonus() << endl;
    return 0;

}
