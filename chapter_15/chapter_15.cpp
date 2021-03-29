#include <iostream>
#include <string>


using namespace std;

void ex1() {
    float a[5]= {1.1,2.2,3.3,4.4,5.5};
    a[0]+=1;
    a[4]+=1;
    cout << "first element: " << a[0] <<endl;
    cout << "Last element: "<<a[4]<<endl;
}

void ex2() {
    float d=1.1;
    float *p=&d;
    cout << *p << endl;
}

void ex3() {
    float d2 = 1.1;
    float &ref_d = d2;
    d2+=1;
    cout << "values are: " << d2 << " and " << ref_d << endl;
    ref_d+=1;
    cout << "values are: " << d2 << " and " << ref_d << endl;
}

void ex4() {
    string s1="Res",s2="ult";
    string s3=s1+s2;
    cout<< "The resulting string is: "<<s3<<endl;
}

void ex5() {
    string fullname;
    cout << "Please enter the first and the last name: ";
    getline(cin,fullname);
    cout << "Your name is: "<< fullname << endl;
}

void ex6() {
    string fullname = "John Doe";
    string firstname= fullname.substr(0,4), lastname=fullname.substr(5,3);
    cout << "Fullname is: " << fullname << endl;
    cout << "Firstname is: " << firstname << endl;
    cout << "Lastname is: " << lastname << endl;
}

void ex7() {
    string s="Hello C++ World";
    auto found=s.find('C');
    if (found!=string::npos)
        cout<<"Character found at position: "<<found<<endl;
    else
        cout<< "Character was not found."<<endl;
}

void ex8() {
    string s="Hello C++ World";
    auto found = s.find("C++");
    if (found != string::npos)
        cout<<"Character found at position: "<<found<<endl;
    else
        cout<< "Character was not found."<<endl;
}

void ex9() {
    string c = "a";
    int x = 123;
    double d1 = 3.14;
    cout << "The type of c is deduced as char, the value is: "
              << c << endl;
    cout << "The type of x is deduced as int, the value is: "
              << x << endl;
    cout << "The type of d is deduced as double, the value is: "
              << d1 << endl;
}

int main() {
    ex1();
    ex2();
    ex3();
    ex4();
}