#include <iostream>

using namespace std;

int main() {
    cout<<"CHAPTER 13: STRINGS"<<endl;
    string s = "Hello world";
    cout<<s<<endl;
    char c='!';
    s+=c;
    cout<<s<<endl;
    cout<<s[0]<<' '<<s.at(0)<<endl;
    cout<<s.c_str()<<endl;

    string s1="Hello",s2="World";
    if (s1==s2)
        cout<<"The strings are equal"<<endl;
    else
        cout<<"The strings are not equal"<<endl;

    string s3;
    cout<<"Input text: ";
    cin>>s3;
    cout<<"Your text: "<<s3<<endl;

    string s4="Hello world";
    string s5=s4.substr(3,4);
    cout<<s4<<"||"<<s5<<endl;

    string s6="Hello world";
    string::size_type found=s.find("world");
    if (found!=string::npos)
        cout<<"Substring found at position: " << found;
    else
        cout << "The substring is not found.";
}