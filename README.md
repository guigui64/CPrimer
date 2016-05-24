# C++ Primer - Chapters summaries and notes

## Getting started

Example of a program that uses the IO library:

    #include <iostream>
    /*
     * Simple main function:
     * read two numbers and write their sum
     */
    int main()
    {
      // prompt user to enter two numbers
      std::cout << "Enter two numbers:" << std::endl;
      int v1 = 0, v2 = 0; // variables to hold the input we read
      std::cin >> v1 >> v2; // read input
      std::cout << "The sum of " << v1 << " and " << v2
                << " is " << v1 + v2 << std::endl;
      return 0;
    }
(ignore this : .*)

## Variables and Basic Types

### References

A **reference** defines an alternative name for an object. A reference type “refers to” another type. We define a reference type by writing a declarator of the form `&d`, where `d` is the name being declared:

    int ival = 1024;
    int &refVal = ival; // refVal refers to (is another name for) ival
    int &refVal2 = ival // error: a reference must be initialized

### Pointers

A **pointer** is a compound type that “points to” another type. Like references, pointers are used for indirect access to other objects. Unlike a reference, a pointer is an object in its own right. Pointers can be assigned and copied; a single pointer can point to several different objects over its lifetime. Unlike a reference, a pointer need not be initialized at the time it is defined. Like other built-in types, pointers defined at block scope have undefined value if they are not initialized.

    int ival = 42;
    int *p = &ival; // p holds the address of ival; p is a pointer to ival
    cout << *p;     // * yields the object to which p points; prints 42
(ignore this : .*)

### Summary

Types are fundamental to all programming in C++.

Each type defines the storage requirements and the operations that may be performed on objects of that type. The language provides a set of fundamental built-in types such as `int` and `char`, which are closely tied to their representation on the machine’s hardware. Types can be non`const` or `const`; a `const` object must be initialized and, once initialized, its value may not be changed. In addition, we can define compound types, such as pointers or references. A compound type is one that is defined in terms of another type.

The language lets us define our own types by defining classes. The library uses the class facility to provide a set of higher-level abstractions such as the IO and `string` types.

## Strings, Vectors, and Arrays

Among the most important library types are `vector` and `string`. A `string` is a variable-length sequence of characters, and a `vector` is a container of objects of a single type.

Iterators allow indirect access to objects stored in a container. Iterators are used to access and navigate between the elements in `string`s and `vector`s.

Arrays and pointers to array elements provide low-level analogs to the `vector` and `string` libraries. In general, the library classes should be used in preference to low-level array and pointer alternatives built into the language.

## Functions

Functions are named units of computation and are essential to structuring even modest programs. Every function has a return type, a name, a (possibly empty) list of parameters, and a function body. The function body is a block that is executed when the function is called. When a function is called, the arguments passed to the function must be compatible with the types of the corresponding parameters.

In C++, functions may be overloaded: The same name may be used to define different functions as long as the number or types of the parameters in the functions differ. The compiler automatically figures out which function to call based on the arguments in a call. The process of selecting the right function from a set of overloaded functions is referred to as function matching.

## Classes

Classes are the most fundamental feature in C++. Classes let us define new types for our applications, making our programs shorter and easier to modify.

Data abstraction—the ability to define both data and function members—and encapsulation—the ability to protect class members from general access—are fundamental to classes. We encapsulate a class by defining its implementation members as `private`. Classes may grant access to their non`public` member by designating another class or function as a friend.

Classes may define constructors, which are special member functions that control how objects are initialized. Constructors may be overloaded. Constructors should use a constructor initializer list to initialize all the data members.

Classes may also define `mutable` or `static` members. A `mutable` member is a data member that is never `const`; its value may be changed inside a `const` member function. A `static` member can be either function or data; `static` members exist independently of the objects of the class type.

## The IO Library

3 headers : `iostream` for streams, `fstream` for files and `sstream` for `string`s
