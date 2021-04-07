#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Books {
    private:
        string name;
        string author;
        int year;

    public:
        Books(string name, string author, int year) {
            this->name = name;
            this->author = author;
            this->year = year;
        }
        string getName() {
            return this->name;
        }
};

class Newspaper {
    private:
        string name;
        int id;
    
    public:
        Newspaper(string name, int id): name(name), id(id) {}
        string getName() {
            return this->name;
        }
};

class Library {
    private:
        string name;
        string location;
        vector <Books*> b;
        vector <Newspaper*> n;
    public:
        void addBook(Books* bok) {
            b.push_back(bok);
        }
        void removeNewspaper(Newspaper* newss) {
            int x = 0;
            for (int i=0; i<n.size(); i++) {
                if (n[i]->getName() == newss->getName()) {
                    x+=i;
                }
            }
            // can use dynamic cast for library data types.
            n.erase(n.begin() + x);

        }

        int countBooks() {
            return b.size();
        }

        int countNewspaper() {
            return n.size();
        }
};

int main() {
    Books *a = new Books("AI", "Vinh", 2020);
    Newspaper *b = new Newspaper("Eigen", 1234);
    Library c;
    c.addBook(a);
    cout << c.countBooks() << endl;
    delete a;
    delete b;
    return 0;

}