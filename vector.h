#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>

template<class Type>
class vector
{
public:
    //constructors
    vector(int s) : maxSize{ s }, element{ new Type[s] } { initialize(); }// constructor
    vector(const vector&);              // copy constructor: defines the copy operation
    vector(vector&&);                   // move constructor: defines the move operation
    ~vector() { delete[] element; }     // destructor

    //overloaded operators
    vector& operator=(const vector&);   // copy assignment
    vector& operator=(vector&&);        // move assignment
    Type * operator[](int n);           // returns the item at location n

    //getters
    int size() const {return maxSize;}

private:
    //helper functions
    void copy(const vector& source);
    void initialize() {for(int i = 0; i < maxSize; i++) element[i] = Type();}

    //data members
    Type * element; //pointer to array of Types
    int maxSize;    //maxSize of array
};

#endif // VECTOR_H
