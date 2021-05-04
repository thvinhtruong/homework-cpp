# Function Overloading.

- Def: Having multiple definition for same function (same name and scope).
- Example:
    class printData {
    public:
        void print(int i) {
            cout << "Printing int: " << i << endl;
        }
        void print(double  f) {
            cout << "Printing float: " << f << endl;
        }
        void print(char* c) {
            cout << "Printing character: " << c << endl;
        }
    };

    int main(void) {
    printData pd;
    
    // Call print to print integer
    pd.print(5);
    
    // Call print to print float
    pd.print(500.263);
    
    // Call print to print character
    pd.print("Hello C++");
    
    return 0;
    }

# Operator Overloading

- Define built-in operators available in C++.
- Use a special key called "Operator".

Example:
    Car operator+ (const Car&);
    Box operator+ (const Box&, const Box&)
