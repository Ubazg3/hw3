#include <iostream>
#include "vector.h"
#define MIN_CAP 2
#define ERROR -9999
/*
    ctor
    input: capacity size and resize size
    output:none
*/
Vector::Vector(int n)
{
	this->_capacity = n;
	this->_size = 0;
    this->_resizeFactor = n;
    if (n < MIN_CAP)
    {
        this->_capacity = MIN_CAP;
        this->_resizeFactor = MIN_CAP;
    }
	this->_elements = new int[this->_capacity];
    // clean the elements
    for (int i = 0; i < this->_capacity; i++)
    {
        this->_elements[i] = 0;
    }
}
/*
    dtor
    input: none
    output:none
*/
Vector::~Vector()
{
	delete(this->_elements);
}
/*
    getter
    input: none
    output:size
*/
int Vector::size() const
{
	return this->_size;
}
/*
    getter
    input: none
    output:capacity
*/
int Vector::capacity() const
{
	return this->_capacity;
}
/*
    getter
    input: none
    output:resizeFactor
*/
int Vector::resizeFactor() const
{
	return this->_resizeFactor;
}
/*
    check if the array is empty
    input: none
    output:empty?
*/
bool Vector::empty() const
{
	return this->_size == 0;
}
/*
    adding a number to the array
    input: value to add 
    output:none
*/
void Vector::push_back(const int& val)
{
    if (this->_size == this->_capacity)
    {
        int newCapacity = this->_capacity + this->_resizeFactor;
        int* newElements = new int[newCapacity];
        for (int i = 0; i < this->_size; i++)
        {
            newElements[i] = this->_elements[i];
        }
        this->~Vector();
        this->_elements = newElements;
        this->_capacity = newCapacity;
    }
    this->_elements[this->_size] = val;
    this->_size++;
}
/*
    removing a number from the array
    input: none
    output:the number that has been popped
*/
int Vector::pop_back()
{
    if (!empty())
    {
        int lastElement = this->_elements[this->_size - 1];
        this->_size--;
        return lastElement;
    }
    else
    {
        std::cout << "Error: Attempt to pop from an empty vector." << std::endl;
        return ERROR;
    }
}
/*
    change the size of the array based on n
    input: the new size
    output:none
*/
void Vector::reserve(int n)
{
    if (n > this->_capacity)
    {
        int newCapacity = n;
        int* newElements = new int[newCapacity];
        for (int i = 0; i < this->_size; i++)
        {
            newElements[i] = this->_elements[i];
        }
        delete(this->_elements);
        this->_elements = newElements;
        this->_capacity = newCapacity;
    }
}
/*
    change the size of the array based on n
    input: the new size
    output:none
*/
void Vector::resize(int n)
{
    while (this->_capacity > n)
    {
        pop_back();
    }
    if (this->_capacity < n)
    {
        reserve(n);
    }
}
/*
    changing all of the variables of the array to the value that has been sent
    input: value
    output:none
*/
void Vector::assign(int val)
{
    for (int i = 0; i < this->_capacity; i++)
    {
        this->_elements[i] = val;
    }
}
/*
    changing the size of the array and in all of the empty spots changes it to the value
    input: new size and value
    output:none
*/
void Vector::resize(int n, const int& val)
{
    if (n > this->_size)
    {
        reserve(n);
        for (int i = this->_size; i < n; i++)
        {
            this->_elements[i] = val;
        }
    }
    else
    {
        while (this->_size > n)
        {
            pop_back();
        }
    }
    this->_size = n;
}
/*
    making it possible to equalize 2 objects
    input: other object
    output:the same vector that has been changed
*/
Vector& Vector::operator=(const Vector& other)
{
    this->_capacity = other._capacity;
    this->_size = other._size;
    this->_resizeFactor = other._resizeFactor;
    this->_elements = new int[this->_capacity];

    for (int i = 0; i < other._size; i++)
    {
        this->_elements[i] = other._elements[i];
    }
    return *this;
}
/*
    build and copy function
    input: other object
    output:none
*/
Vector::Vector(const Vector& other)
{
    *this = other;
}
/*
    making it possible to access a variable in the array by using [] 
    input: the place
    output: the element in that place
*/
int& Vector::operator[](int n) const
{
    if (n < 0)
    {
        return this->_elements[0];
    }
    return this->_elements[n % this->_size];

}
