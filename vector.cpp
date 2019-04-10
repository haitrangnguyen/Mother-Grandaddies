#include "vector.h"

template<class Type>
void vector<Type>::copy(const vector& source)   //helper function
{
    for (int i = 0; i < source.maxSize; ++i) element[i] = source.element[i];
}

template<class Type>
vector<Type>::vector(const vector& source) // copy constructor
    :maxSize{source.maxSize}, element{new double[maxSize]}
{
    copy(source);
}

template<class Type>
vector<Type>::vector(vector&& source) // move constructor
    : element {source.element}, maxSize{source.maxSize}
{
    source.element = nullptr;
    delete source.element;
}

template<class Type>
vector<Type>& vector<Type>::operator=(const vector& rhs) // copy assignment
{
    Type* temp = new Type[rhs.maxSize];                 // allocate new space for Type[]
    std::copy(rhs.element, rhs.elemement + rhs.maxSize, temp);	// use std::copy algorithm to copy rhs elements into temp[]
    delete[] element;								// deallocate old space
    element = temp;									// now that we've copied new, deallocated old elems, reset elem pointer
    maxSize = rhs.maxSize;							// reset vector size

    return *this;                       // return a self-reference
}

template<class Type>
vector<Type>& vector<Type>::operator=(vector&& rhs) // move assignment
{
    delete[] element;		// deallocate old space
    element = rhs.element;	// copy rhs's elements and size, move implies copying element pointer only
    maxSize = rhs.maxSize;
    rhs.element = nullptr;	// empty the rhs vector
    rhs.maxSize = 0;

    return *this;		// return a self-reference
}

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
