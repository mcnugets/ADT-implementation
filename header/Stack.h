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

    public:
        explicit stack();
        explicit stack(const stack<type> &input);
        explicit stack(const size_t &size);
        ~stack();

        // modifiers
        constexpr void push(const type &input);
        constexpr void pop();
        inline constexpr type &top();
        constexpr bool find(const type &input);
        size_t &size();

        //---------------operators
        int &operator[](const size_t i);
        type &operator=(type &assign_to);
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

T adt::stack<type>::~stack()
{
    delete[] this->arr;
}

#pragma endregion

//----modifiers
T constexpr void adt::stack<type>::push(const type &input)
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

T inline constexpr type &adt::stack<type>::top()
{
    return this->arr[0];
}

T constexpr void adt::stack<type>::pop()
{
    size_t old_size = this->_size; // modify this later, we want to avoid copy assignment for the effective perfomance
    this->_size--;
    type *new_arr = new type[this->_size];
    type popped_value = this->arr[0]; // modify this also this is essentially a copyy assignment
    for (int x = 1; x < old_size; x++)
    {
        new_arr[x - 1] = this->arr[x];
    }
    delete[] this->arr;

    this->arr = new_arr;
    return popped_value;
}

T constexpr bool adt::stack<type>::find(const type &input)
{
    for (int x = 0; x < this->_size; x++)
    {
        if (input == this->arr[x])
            return true;
    }
    return false;
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

T type &adt::stack<type>::operator=(type &assign_to)
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
