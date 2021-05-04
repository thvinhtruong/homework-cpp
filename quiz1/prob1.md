# What is overloading and give an example to illustrate the concept?

- Overloading is when two function have the same name but different in parameters.
- Ex:

class PrintMe {
   public:
      void print(int i) {
        cout << i << endl;
      }
      void print(float f) {
        cout << f << endl;
      }
      void print(string a) {
        cout << a << endl;
    }
};

int main() {
    PrintMe p;
    p.PrintMe();
    return 0;
}

#  What is overriding and give an example to illustrate the concept?

- Overriding is when we have two class: base class and child class which inherited from the base. It means that the function in base class can be redefine in the child class --> called OVERRIDING A FUNCTION.

Ex: 
class Father
{
    public:
    void show()
    {
        cout << "I am your dad" << endl;
    }
};

class Derived: public Base
{
    public:
    void show()
    {
        cout << "i am your children" << endl;
    }
}

# What is inheritance and give an example to illustrate the concep?

- The child class inherited from the father, things like function, variables, .... For example: "Tiger" is a class inherited from a base class "Animal".

- We use inheritance only if an is-a relationship is present between the two classes.

- Ex:

class Animal {
    public:
        eat();
        speak();
};

class Dog : public Animal {
    public:
        eat();
        speak();
};


    