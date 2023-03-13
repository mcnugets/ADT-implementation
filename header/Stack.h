#pragma once
#define T template <typename type>
#include <iostream>
#include <vector>

namespace adt
{

    T class stack
    {
    private:
        size_t _size;
        type *arr;

        //-----iterators----
        // std::iterator begin;
        // std::iterator end;

    public:
        stack();
        stack(const stack<type> &input);
        stack(const size_t &size);
        ~stack();

        // modifiers
        void push(const type &input);
        type pop();
        //--------
        bool &find(const type &input);
        size_t &size();
        // iterators
        // std::iterator begin();
        // std::iterator end();

        //---------------operators
        int &operator[](const size_t i);
        type operator=(type &assign_to);
    };
};

#pragma region constructors
T adt::stack<type>::stack() : _size(0), arr(new type[_size])
{
}
T adt::stack<type>::stack(const size_t &size) : arr(new type[size]), _size(size){};

T adt::stack<type>::stack(const adt::stack<type> &input)
{
    this->vec_stack = input.vec_stack;
}

T adt::stack<type>::~stack() {}

#pragma endregion

//----modifiers
T inline void adt::stack<type>::push(const type &input)
{
    this->_size++;
    type *new_arr = new type[this->_size];

    for (int x = 1; x < this->_size; x++)
    {
        new_arr[x] = this->arr[x - 1];
    }
    new_arr[0] = input;
    delete[] this->arr;
    this->arr = new_arr;
}

T type adt::stack<type>::pop()
{
    type copy_ = *this;
    this->_size--;
    type *popped_value = this->arr[0];
    delete[] this->arr;
    this->arr = new type[this->_size];
    for (int x = 1; x < copy_._size; x++)
    {
        this->arr[x - 1] = copy_.arr[x];
    }
    return *popped_value;
}
//----
T size_t &adt::stack<type>::size()
{
    return this->_size;
}

//--operator
T int &adt::stack<type>::operator[](const std::size_t i)
{
    return this->arr[i];
}
T type adt::stack<type>::operator=(type &assign_to)
{
    if (this == &assign_to)
        return *this;
    if (this->_size != assign_to._size)
    {
        delete[] this->arr;
        this->_size = 0;
        this->arr = new type[assign_to._size];
        this->arr = assign_to.arr;
        this->_size = assign_to._size;
    }
    else
    {
        this->arr = assign_to.arr;
    }
    return *this;
}
