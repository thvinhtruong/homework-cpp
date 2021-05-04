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
	
# Chapter 19 Functions 
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


# Chapter 25: Classes - Inheritance and Polymorphism //

1. Inheritance

-Inheritance: We can build a class by deriving from a base class, which can access everthing in public and protected access level of the base class.
  --Syntax: class DerivedClass : public baseClass{};

Ex: class myClass{};
    
    class derivedClass : public myClass{}; // class derivedClass inherites class myClass // 
    
The derived class can access to public or protected members of the original class, but cannot access the private class.
We can also create new members inside the derived class.
The member which is created inside derived class can only be accessed by the derived class, while the inherited members can be accessed by both the base class and the derived one.

Ex: class myClass{
    private:
       int myNum;
    protected:
       char myChar;
    public:
       double myDouble;
    };
    
    
    class derivedClass{
    // myDouble and myChar can be accessed here, but not myNum //
    public:
         float myFloat;
    };
    
    int main(){
        derivedClass a;
        a.myNum = 12;   // Error: No 'myNum' member //
        a.myChar = 'x'; // Error here: not accessible to object //
        a.myDouble = 10.23;
        a.myFloat = 3.14;
        return 0;
    }
    
2. Polymorphism

A pointer to the derived class is compatible with the pointer to the base class since the derived class is also the base class. 
Polymorphism means the object can morph into different types. It can be archived in C++ by virtual function.
Virtual means the function can be overridden/redefined in subsequent derived classes.

Ex1 : 
class baseClass{
    public:
    virtual void dowork(){
        cout << "Hello from base class \n";
    }
};

class derivedClass : public baseClass{
};

int main(){
    baseClass* o = new derivedClass;
    o->dowork(); // If in the derived class there is no dowork function, the pointer o will point into the base class //
    //Print out "Hello from base class" //
    return 0;
}

- Hierachy: when derived a class from a base class, it will include everything from the base class, and further include its own properties, wich can also be inherited when a new class is derived base on it.


# Chapter 27: The static specifier
- The static specifier: the object with that spec has a static storage duration.
- The memory space for a static object is allocated when the program begins and deallocated when the program ends.*
- The value stored in a static object will not disappear when the function that holds it is recalled
- Only one instance of a static object can be exist in program.
  ex:
    #include <iostream>
     using namespace std;
     class MyClass
     {
      public:
	    void Hello()
	    {
		    static int x = 0;
		    x++;
		    cout <<x <<endl;
	    }
     };
    int main()
    {
	  MyClass a;
	  a.Hello();//x=1
	  a.Hello();//x=2
	  a.Hello();//x=3
	  return 0;
    }

# Chapter 28: Template
- A mechanism that supports generic programming --> create a function or class that we dont have to consider what types of the parameters are. Like vector.
- Syntax: template<typename T>
	//function definition goes here
	//e.g: void FuncName(T param)
	{
	cout << "THe value of parameter is: << param;//parameter is of type T
	}
	int main()
	{
	FuncName<int>(40);//print out 40
	}
- typename T: T can be consider as a placeholder of a specific data type, which can be replaced when the function is called.
- Template can have more than 1 parameter: template<typename T, typename U, typename ....>
					  void Function(T t, U u)
- Template can be used for class:
	#include <iostream>
	using namespace std;
	template<typename T>
	class MyClass
	{
	private:
	T x;
	public:
	MyClass(T x)
	{
	this->x = x;
	}
	void getX()
	{
	cout << this->x<<endl;
	}
	};
	int main()
	{
	MyClass<int> o(100);
	o.getX();
	}
- A function can be specialized as an exception using template<> type funcName(data_type(int, double,...)){codes go here}
	- This type of function will be called when the argument is matched with the type of paramenter of the function.
	ex: #include <iostream>
		using namespace std;

		template<typename T>
		void myfunction(T arg)
		{
		std::cout << "The value of an argument is: " << arg << '\n';
		}
		template <>
		// the rest of our code
		void myfunction(int arg)
		{
		std::cout << "This is a specialization int. The value is: " << arg <<
		'\n';
		}
		int main()
		{
		myfunction<char>('A');//invokes non_specialization
		myfunction<double>(345.678);
		myfunction<int>(123); // invokes specialization b'cause argument is int.
		}

# Chapter 29: Enumerate

- A way to define constants
- There are 2 types: unscoped and scoped.

# Chapter 33: Conversion

- Types can be converted to other types.

int main() {
    char mychar = 64;
    int myint = 123;
    double mydouble = 456.789;
    bool myboolean = true;
    myint = mychar;
    mydouble = myint;
    mychar = myboolean;
}

--> convert int to double, bool, char, ....

- While we can convert any data pointer to a void pointer, we can not dereference the void pointer. To be able to access the object pointed to by a void pointer, we need to cast the void pointer to some other pointer type first.
--> using static_cast

Otherwise, array is much easier.

- In this case, we have an implicit conversion of type int[] to type int

- When used as function arguments, the array gets converted to a pointer. More precisely, it gets converted to a pointer to the first element in an array.

- Explicit Conversion: 
static_cast<type_to_convert_to>(value_to_convert_from)

- The following explicit conversion functions should be used rarely and carefully. They are dynamic_cast and reintepret_cast. The dynamic_cast function converts pointers of base class to pointers to derived class and vice versa up the inheritance chain.

(Rarely use but be careful when using it)