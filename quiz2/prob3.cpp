#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Member {
    protected:
        string name;
        string address;
        int fee;
    public:
        Member(){}
        Member(string name, string address): name(name), address(address) {
            this->fee = 0;
        }
        ~Member(){}
        string getName() {
            return this->name;
        }

        string getAddr() {
            return this->address;
        }

        virtual int getFee();
};

class Standard_Member: public Member {
    public:
        Standard_Member(){
            this->fee = 0;
        }
        int getFee() {
            return 0;
        }
};

class Senior: public Member {
    public:
        Senior(int fee): fee(fee) {}
        int getFee() {
            return this->fee;
        }
};

class Society {
    private:
        string name;
    public:
        Society(string name, string address): m(name, address) {}
        virtual void addMember(string name, string address);
        virtual void addSenior(string name, string address, int fee);
        virtual void addCtteeMember(Senior s);
        virtual int getTotalFee();
};

class Management: public Society {
    private:
        vector<Member*> list;

    public:
        void addCtteeMember(Senior s);
        void removeCtteeMember(string name);
}

int main() {
    // testing.
}