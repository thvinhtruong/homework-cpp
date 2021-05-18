#include<iostream>
#include<string.h>

using namespace std;
class Person {
    protected:
        string name;
	public:
        Person(string name) {
            this->name = name;
        }
        string getName() {
            return this->name;
        }
};

class Employee: public Person {
    private:
            int year;
            double salary;
            string insurance;
    public:
        Employee(string name, int year, double salary, string insurance): Person(name) {
            this->year = year;
            this->salary = salary;
            this->insurance = insurance;
        }
        void printMe()
        {
            cout<<"Employee Name = "<< name <<endl;
            cout<<"Joining Year = "<< year <<endl;
            cout<<"Annual Salary = "<< salary <<endl;
            cout<<"National Insurance Number = "<< insurance << endl;
        }

        bool isEqualSalary(Employee e1, Employee e2) {
            return true ? e1.salary == e2.salary : false;
        }
};

int main()
{
    Person p1("Vinh");
    string name = p1.getName();
    Employee e1(name, 2020 , 324230, "2ffafnajnf");
    e1.printMe();
    return 0;
}
