#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
    protected:
        string name;
        double salary;
    
    public:
        Employee(){}
        Employee(string name, double salary) {
            this->name = name;
            this->salary = salary;      
        }
        double getSalary() {
            return this->salary;
        }
        virtual ~Employee(){}
    
};

class Boss: public Employee {
    private:
        double bonus;
    public:
        Boss(){}
        Boss(string name, double salary, double bonus): Employee(name, salary) {
            this->bonus = bonus;
        }

        string getName() {
            return this->name;
        }

        double getBonus() {
            return this->bonus;
        }

        double getSalary() {
            return salary + this->bonus;
        }
};

class Company {
    private:
        vector<Employee*>list;
    public:
        void getPeople(Employee *people) {
            list.push_back(people);
        }

        int getSize() {
            return list.size();
        }

        int getBoss() {
            int boss = 0;
            for (int i=0; i<list.size(); i++) {
                Boss *num = dynamic_cast<Boss*>(list[i]);
                if (num) {
                    boss++;
                    //num->getName();
                    //num->getSalary();
                    //num->getBonus()
                }
            }
            return boss;
        }

        int getEmployee() {
            return list.size() - getBoss();
        }
};

int main() {
    Employee *e1 = new Employee("Trung", 50);
    Employee *e2 = new Employee("Thang", 49);
    Boss *b = new Boss("Vinh", 200, 100);
    Company tdc;
    tdc.getPeople(e1);
    tdc.getPeople(e2);
    tdc.getPeople(b);
    cout << tdc.getSize() << endl;
    cout << tdc.getBoss() << endl;
    cout << tdc.getEmployee() << endl;
    delete e1;
    delete e2;
    delete b;
    return 0;
}
