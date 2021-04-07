## How to exlain oop to a child?

# 4 principles of OOP:
    Encapsulation
    Abstraction
    Inheritance
    Polymorphism

# Encapsulation:
    Objects have states, which are PRIVATE and can not be changed externally.
    Though we can not change the states, we can affect them by the public methods.
    Ex: -A cat class has its private states: hungry, mood and energy and private method meow() which will be called whenever it wants
    - We cannot change the cats' states, such as deciding when the cat is hungry; this is a private matter.
    - However, we can communicate with its states through public methods such as feed() and play(), which provide a connection to the states.

# Abstraction:
    Can be considered as an exension of Encapsulation.
    Provide a codebase for the objects, which is hidden and just some operations are revealed.

# Inheritance:
  Provide the ability of a child class to derived states from a parent class.
  Further, the child class can not only derived states and method from parent class but also implement its own.

# Polymorphism:
    Many shape, things different in a function, used for different class, but under 1 function name.
    To use this mechanism, a virtual function should be declared in the base class to make it to be an abstract class.