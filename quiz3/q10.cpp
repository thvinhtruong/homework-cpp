#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
    private:
        int day, month, year;
    
    public:
        Date(int d, int m, int y): day(d), month(m), year(y) {}
        void showDate() {
            cout << this->day << "/" << this->month << "/" << this->year << endl;
        }

        int getDay() {
            return this->day;
        }

        int getMonth() {
            return this->month;
        }

        int getYear() {
            return this->year;
        }

};

class Patient {
    private:
        string name, issues;
        Date birth, admission, discharge;

    public:
        Patient(string name, string issues, Date birth, Date admission, Date discharge): birth(birth), admission(admission), discharge(discharge) {
            this->name = name;
            this->issues = issues;
        }

        string getName() {
            return this->name;
        }

        string getIssues() {
            return this->issues;
        }

        Date getDateOfBirth() {
            return this->birth;
        }

        Date getAdmission() {
            return this->admission;
        }

        Date getDischarge() {
            return this->discharge;
        }

        void PrintMe() {
            cout << "Name: " << this->name << endl;
            cout << "Issues: " << this->issues << endl;
            cout << "Date of birth: ";
            this->birth.showDate();
            cout << "Date of admission: ";
            this->admission.showDate();
            cout << "Date of discharge: ";
            this->discharge.showDate();
        }
};

class Hospital {
    private:
        vector <Patient *> list;
    
    public:
        void addPatient(Patient *p) {
            list.push_back(p);
        }

        void deletePatient(Patient *p) {
            int i, x = 0;
            for (i=0; i<list.size(); i++) {
                if (p->getName() == list[i]->getName()) {
                    x += i;
                }
            }
            list.erase(list.begin() + x);
        }

        void displayAll() {
            for (int i=0; i<list.size(); i++) {
                cout << "Patient " << i+1 << ": " << endl;
                list[i]->PrintMe();
            }
        }

        void display_under_12() {
            cout << "Patients whose ages are less than 12: " << endl;
            for (int i=0; i<list.size(); i++) {
                if (2021 - list[i]->getDateOfBirth().getYear() <= 12) {
                    list[i]->PrintMe();
                }
            }
        }
};



int main() {
    Date b1(1, 1, 2015);
    Date b2(2, 2, 2016);
    Date b3(3, 3, 2001);
    Date a1(2, 1, 2021);
    Date a2(3, 2, 2021);
    Date a3(3, 5, 2020);
    Date d1(6, 5, 2022);
    Date d2(5, 6, 2023);
    Date d3(9, 5, 2024);

    Patient* p1 = new Patient("Trung", "Xam", b1, a1, d1);
    Patient* p2 = new Patient("Thang", "Map", b2, a2, d3);
    Patient* p3 = new Patient("Quang", "Yeu sinh ly", b3, a3, d3);

    Hospital h;
    h.addPatient(p1);
    h.addPatient(p2);
    h.addPatient(p3);
    //h.deletePatient(p1);
    //h.displayAll();
    h.display_under_12();
    delete p1;
    delete p2;
    delete p3;
    return 0;
}