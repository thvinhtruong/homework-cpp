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
        double getSalary() {
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

class Company {
    private:
        vector<Employee>list;
    public:
        void getEmployee(Employee people) {
            list.push_back(people);
        }

        int getSize() {
            return list.size();
        }

        int getEmployeeSize() {
            int x = 0;
            for (int i=0; i<list.size(); i++) {
                if ((Boss)list[i].getSalary() > list[i].getSalary()) {
                    x++;
                }
            }
            return x;
        }


};

int main() {
    Employee e1("Trung", 50);
    Employee e2("Thang", 49);
    Boss b("Vinh", 200, 100);
    Company tdc;
    tdc.getEmployee(e1);
    tdc.getEmployee(e2);
    tdc.getEmployee(b);
    cout << tdc.getEmployeeSize() << endl;

    return 0;

}
