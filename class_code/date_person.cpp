#include <iostream>
#include <string>

using namespace std;

class Date {
    private:
        int day, month, year;

    public:
        Date(int d, int m, int y) {
            this->day = d;
            this->month = m;
            this->year = y;
        }
        void update(int d, int m, int y) {
            this->day = d;
            this->month = m;
            this->month = y;
        }

        bool checkk_date(Date d) {
            return true ? (this->day == d.day && this->month == d.month && this->year == d.year) : false;
        }
};

class Person {
    private:
        string name;
        Date date;
    
    public:
        Person(string n, int d, int m, int y) {
            this->name = n;
            this->date.update(d, m, y); //function in this class call the function in another class.
        }

        string getName() {
            return this->name;
        } 

        bool check_name(Person p) {
            return true ? (this->name == p.name) : false;
        }
        bool check_date(Person p) {
            return true ? (this->date.checkk_date() == true) : false;
        }
};


int main() {
    //testing....
    return 0;
}