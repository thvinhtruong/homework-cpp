## C++ OOP

# Chapter 10: Arrays

- To create an array: --like C
              <type> <name>[number-of-elements];  
- We can access individual array elements through a subscript operator [] and an index. 

# Chapter 11: Pointers

- use POINTERS like C.
- To create a pointer that points to nowhere.
    int *x = nullptr;
- Print out Ptr.
    cout << *p << endl;
- Print the value of address pointer points to, use cout << p << endl;

# Chapter 12: References

- A reference type is an alias to an object in memory, we describe a reference type as type followed by an &  
      int x = 123;
      int& y = x;
- Passing by value and passing by reference.
--> passing by value
for ex: void swap(int a, int b) --> passing by value --> in main(), int a, b, swap(a, b) will not be changed
void swap(int *a, int *b) --> passing by reference --> in main(), int a, b, swap(a, b) will be changed

# Chapter 13: Strings

- include the <string> header
  #include<string>
- declare a string: string s = "a"
- add character to string by the += operator
  s += " bc"
  --> s = "abc"
- concatenate 2 strings together or using strcat like c.
    string s1 = "hello"
    string s2 = " world"
    string s3 = s1 + s2; --> "hello world".
- know a string character using .at(index)
    string s = "hello";
    cout << s.at(0) (h)

- Use getline(cin,s) --> include the whitespace.

#include <iostream>
#include <string>
int main() {
    std::string fullname;
    std::cout << "Please enter the first and the last name: ";
    std::getline(std::cin, fullname);
    std::cout << "Your name is: " << fullname;
}

- A string has a member function .c_str() which returns a pointer to it first element --> use it to find substring.
- the .find() member function --> returns the position of the first found substring
- This position is the position of a character where the substring starts in the main string. If the substring is not found, the function returns a value that is std::string::npos
int main() {
    std::string s1 = "Hello";
    std::string s2 = " World!";
    std::string s3 = s1 + s2;
    std::cout << "The resulting string is: " << s3;
}

Copy from chapter 15.
		

# Chapter 14

- automatically deduce the type of an object using the auto specifier.
		auto a = '123'; // int type
		auto c = 'a'; // char type
- use auto as part of the reference type or const type
		auto& x = a;
		const auto y = 123;

#include <iostream>
int main() {
    auto c = 'a';
    auto x = 123;
    auto d = 3.14;
    std::cout << "The type of c is deduced as char, the value is: "
    << c << '\n';
    std::cout << "The type of x is deduced as int, the value is: "
    << x << '\n';
    std::cout << "The type of d is deduced as double, the value is: "
<< d << '\n'; 
}
	
Chapter 19 Functions 
	Definition and declaration
	We can break our C++ code into smaller chunks called functions. 
	A function = return type + a name + a list of parameters in a declaration, and additional function body.
	Ex:
		type function_name(arguments) {
			Statement;
			Statement;
			return something;
		}

	Return statement
	Functions are of a certain type, also referred to as a return type, and they must return a value. Functions ‘void’ do not return a value.








