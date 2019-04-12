#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>

template<class Type>
class vector
{
public:
    //constructors
    vector(int s) : maxSize{ s }, element{ new Type*[s] } { initialize(); }// constructor
    vector(const vector&);              // copy constructor: defines the copy operation
    vector(vector&&);                   // move constructor: defines the move operation
    //destructor
    ~vector()
    {
        for(int i = 0; i < maxSize; i++) delete element[i];
        delete [] element;
    }

    //overloaded operators
    vector& operator=(const vector&);   // copy assignment
    vector& operator=(vector&&);        // move assignment
    Type * operator[](int n);           // returns the item at location n

    //getters
    int size() const {return maxSize;}

private:
    //helper functions
    void copy(const vector& source);
    void initialize() {for(int i = 0; i < maxSize; i++) element[i] = new Type();}

    //data members
    Type ** element; //pointer to array of pointers of Type
    int maxSize;    //maxSize of array
};

//helper function
template<class Type>
void vector<Type>::copy(const vector& source)
{
    for (int i = 0; i < source.maxSize; ++i) element[i] = source.element[i];
}

// copy constructor
template<class Type>
vector<Type>::vector(const vector& source)
    :maxSize{source.maxSize}, element{new Type[maxSize]}
{
    copy(source);
}

// move constructor
template<class Type>
vector<Type>::vector(vector&& source)
    : element {source.element}, maxSize{source.maxSize}
{
    source.element = nullptr;
    delete source.element;
}

//Overloaded Operators
//Copy assignment
template<class Type>
vector<Type>& vector<Type>::operator=(const vector& rhs)
{
    Type* temp = new Type[rhs.maxSize];                 // allocate new space for Type[]
    std::copy(rhs.element, rhs.elemement + rhs.maxSize, temp);	// use std::copy algorithm to copy rhs elements into temp[]
    delete[] element;								// deallocate old space
    element = temp;									// now that we've copied new, deallocated old elems, reset elem pointer
    maxSize = rhs.maxSize;							// reset vector size

    return *this;                       // return a self-reference
}

//Move assignment
template<class Type>
vector<Type>& vector<Type>::operator=(vector&& rhs)
{
    delete[] element;		// deallocate old space
    element = rhs.element;	// copy rhs's elements and size, move implies copying element pointer only
    maxSize = rhs.maxSize;
    rhs.element = nullptr;	// empty the rhs vector
    rhs.maxSize = 0;

    return *this;		// return a self-reference
}

//Square Bracket Operator
template<class Type>
Type * vector<Type>::operator[](int n)
{
    if (n >= maxSize)
    {
        Type * temp = new Type [maxSize * 2];
        for (int i = 0; i < maxSize; i++)
        {
            temp[i] = element[i];
            temp[i + maxSize] = Type();
        }
        maxSize *= 2;
        delete[] element;
        element = temp;
    }
    return element[n];
}

//ostream& print(ostream& os, vector& v)
//    // print vector element values to the output stream
//{
//    for (int i = 0; i < v.size(); ++i) os << v.get(i) << " ";
//    return os;
//}

//End Overloaded Operators


#endif // VECTOR_H
