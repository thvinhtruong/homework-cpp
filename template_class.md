# Template class
A method for creating typename that is used for all types and we just have to specify the data type we want when we use the code.
syntax: template <typename T>
        template <class T>

when we declare an object of class T, we have to specify it to be in used: class_name<class_type> obj_name;

# Friend functions and classes:
- Functions that are able to access all the protected and private properties of a class
- Friend function must be declared inside the class and defined outside
- Syntax: declaration: friend return_type function_name(class_name);
        definition: return_type function_name(class_name object_name)
        {
            //.....
        }

- Classes that are able to access all the protected and private properties of a class
- Syntax: friend class class_name; :declaration
         class class_name{
         type function_name (original_class obj)
         {
         //codes
                }
         };

# Binding: 
The method of converting identifiers (such as variable and function names) into addresses is known as binding. 
Static binding vs. early binding: 

# Direct function call: 
The compiler can connect directly to the identifiers' addresses. When the compiler (or linker) comes across a function call, it replaces it with a machine language instruction telling the CPU to hop to the function's address.

# Late binding
Late binding, also known as dynamic binding, is the use of a pointer to refer to the address of a method rather than calling it explicitly.