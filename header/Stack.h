#include <iostream>
#include "Iterator.h"
#define T template <typename type>
#ifndef stack_header
#define stack_header

namespace adt
{

    T class stack
    {

    private:
        // member variables
        size_t _size;
        size_t _capacity;
        type *arr;

    public:
        // typedefs
        typedef iterator<type> iter;
        // constructors
        explicit stack();

        explicit stack(const stack<type> &input);
        explicit stack(const size_t &size);
        stack(const std::initializer_list<type> &init_list);
        ~stack();

        /// write-only cannot be used withc const
        // modifiers
        constexpr void push(const type &input);
        constexpr void pop() noexcept;
        constexpr void assign(iter &begin, iter *end, const type &input);

        /// read-only can be const
        // access
        constexpr type &top() const noexcept;
        constexpr bool find(const type &input) const noexcept;

        // capacity
        constexpr size_t size() const noexcept;
        constexpr size_t capacity() const noexcept;
        constexpr bool empty() const noexcept;

        // operators
        type &operator[](const size_t i);
        type &operator=(type &assign_to);

        // iterators
        const iter begin() const;
        const iter end() const;

        friend std::ostream &operator<<(std::ostream &os, const iter &it)
        {
            os << it;
            return os;
        }
    };
};

#endif

using namespace adt;
using namespace std;

#pragma region constructors
T stack<type>::stack() : _size(0),
                         _capacity(1)
{
    arr = new type[_capacity];
}

// constructor that defines the size of the stack
T stack<type>::stack(const size_t &size) : _size(size), _capacity(size * 2)
{
    arr = new type[_capacity];
}
// copy constructor
T stack<type>::stack(const stack<type> &input) : _size(input._size), _capacity(input._capacity)
{
    this->arr = new type[this->_capacity];
    for (int i = 0; i < this->_size; i++)
    {
        this->arr[i] = input.arr[i];
    }
}

// init list constructor
T stack<type>::stack(const initializer_list<type> &init_list) : _size(init_list.size()),
                                                                _capacity(_size * 2)
{

    this->arr = new type[this->_capacity];
    typename initializer_list<type>::iterator it = init_list.begin();
    for (int i = 0; i < this->_size; i++)
    {

        this->arr[i] = *it;
        it++;
    }
}

T stack<type>::~stack()
{
    delete[] this->arr;
}

#pragma endregion

//----modifiers
T constexpr void stack<type>::push(const type &input)
{
    if (this->_size == this->_capacity)
    {

        _capacity = _capacity * 2;
        type *new_alloc = new type[_capacity];
        for (int x = 0; x < this->_size; x++)
        {
            new_alloc[x] = this->arr[x];
        }
        delete[] this->arr;
        this->arr = new_alloc;
    }

    for (int x = this->_size; x >= 0; x--)
    {
        this->arr[x] = this->arr[x - 1];
    }
    this->arr[0] = input;
    this->_size++;
}
T constexpr void stack<type>::pop() noexcept
{
    arr[_size] = arr[0];
    for (int x = 1; x < _size; x++)
    {
        arr[x - 1] = arr[x];
    }
    arr[0].~type();
    this->_size--;
}

// access
T inline constexpr type &stack<type>::top() const noexcept
{
    return this->arr[0];
}

T constexpr bool stack<type>::find(const type &input) const noexcept
{
    for (int x = 0; x < this->_size; x++)
    {
        if (input == this->arr[x])
            return true;
    }
    return false;
}

// capacity
T constexpr size_t stack<type>::size() const noexcept
{
    return this->_size;
}
T constexpr size_t stack<type>::capacity() const noexcept
{
    return this->_capacity;
}
T constexpr bool stack<type>::empty() const noexcept
{
    if (this._size == 0)
    {
        return true;
    }
    return false;
}

// operator
T type &stack<type>::operator[](const std::size_t i)
{
    return this->arr[i];
}

T type &stack<type>::operator=(type &assign_to)
{
    if (this == &assign_to)
        return *this;
    if (this->_size != assign_to._size)
    {
        delete[] this->arr;
        this->_capacity = assign_to._capacity;
        this->arr = new type[this->_capacity];
        this->arr = assign_to.arr;
        this->_size = assign_to._size;
    }
    else
    {
        this->arr = assign_to.arr;
    }
    return *this;
}
// there is typedef, uisng, and there is #define
// stack iterator

T const typename stack<type>::iter stack<type>::begin() const
{
    return iter(this->arr);
}
T const typename stack<type>::iter stack<type>::end() const
{
    return iter(this->arr) + (this->_size - 1);
}
