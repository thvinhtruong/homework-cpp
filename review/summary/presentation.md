# Constructors & Deconstructors

Constructors: appear whenever a new object is created
ClassName(arguments) {}

Destructors: appear/execute whenever an object is deleted. Especially, after it goes out of scope.
~ClassName(arguments) {}

Copy Constructor: 2 kinds of them.

- Copy Constructor: when copy happens immediately after variable.
    ClassName obj = obj2;

- Copy Operator: when copy happens after initializing variable:
    ClassName obj;
    obj = obj2;

User-defined copy constructor:
	ClassName (const ClassName& obj) {}


# Upcasting & Downcasting

Casting: coverting from one data type to another data type

Upcasting: casting Child -> Parent. Always possible and implicitly done by offsetting the pointer.

Downcasting: casting Parent -> Child. Only possible when the object is actually a child object (i.e was upcasted). Explicitly done through static_cast (unsafe) or dynamic_cast (safer).  

# Void Keyword
- void as function type: function returns nothing
- void as function argument: function needs nothing as argument
- void as a pointer type: universal pointer, needs to be converted to a specific type.

# Multiple Inheritance

- Multiple inheritance is when a class can inherits from multiple class: class Child: public Parent1, public Parent2 {};

- Problem: B and C have their own instances of what they inherit from A, and D inherits both those implementations.

- Solution: implement virtual inheritance

# Const Keyword

- Const is just simply a promise to the program that we will not change the value of that variables.
- Syntax: const int a = 1;



