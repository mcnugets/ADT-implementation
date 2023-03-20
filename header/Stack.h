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
        int capacity;
        type *arr;
        initializer_list<type> *init_list;

    public:
        explicit stack();
        explicit stack(const stack<type> &input);
        explicit stack(const size_t &size);
        stack(const std::initializer_list<type> &init_list);
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
T adt::stack<type>::stack() : _size(0), capacity(1), arr(new type[capacity])
{
}

T adt::stack<type>::stack(const size_t &size) : _size(size), capacity(size * 2) ss, arr(new type[capacity]) {}

T adt::stack<type>::stack(const adt::stack<type> &input) : this(input) {}

T adt::stack<type>::stack(const std::initializer_list<type> &init_list) : init_list(&init_list)
{
}

T adt::stack<type>::~stack()
{
    delete[] this->arr;
}

#pragma endregion

//----modifiers
T constexpr void adt::stack<type>::push(const type &input)
{
    if (this->_size == this->capacity)
    {

        capacity = capacity * 2;
        type *new_alloc = new type[capacity];
        for (int x = 0; x < this->_size; x++)
        {
            new_alloc[x] = this->arr[x];
        }
        delete[] this->arr;
        this->arr = new_alloc;
    }
    this->_size++;
    int &temp = this->arr[0];
    for (int x = 1; x < this->_size; x++)
    {
        this->arr[x] = temp;
        temp = this->arr[x];
    }
    this->arr[0] = input;
}

T inline constexpr type &adt::stack<type>::top()
{
    return this->arr[0];
}

T constexpr void adt::stack<type>::pop()
{
    this->arr[0].~type();
    this->_size--;
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