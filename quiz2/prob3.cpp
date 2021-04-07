#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Member {
    private:
        string name;
        string address;
    public:
        Member(string name, string address): name(name), address(address) {}
        string getName() {
            return this->name;
        }

        string getAddr() {
            return this->address;
        }

        virtual int getFee();
};

class Standard: public Member {
    public:
        int getFee() {
            return 0;
        }
};

class Senior: public Member {
    private:
        int fee;
    
    public:
        Senior(int fee): fee(fee) {}
        int getFee() {
            return this->fee;
        }
};

class Society {
    private:
        Member m;
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