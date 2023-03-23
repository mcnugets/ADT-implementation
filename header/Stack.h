#define T template <typename type>
#define conc const noexcept
#include <iostream>

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

        // typedef initialization for initializer list
        typedef std::initializer_list<type> in_list;

    public:
        // constructors
        explicit stack();
        explicit stack(const stack<type> &input);
        explicit stack(const size_t &size);
        stack(const in_list &init_list);
        ~stack();

        /// write-only cannot be used withc const
        // modifiers
        constexpr void push(const type &input);
        constexpr void pop();

        /// read-only can be const
        // access
        constexpr type &top() conc;
        constexpr bool find(const type &input) conc;

        // capacity
        constexpr size_t size() conc;
        constexpr size_t capacity() conc;
        constexpr bool empty() conc;

        // operators
        int &operator[](const size_t i);
        type &operator=(type &assign_to);
    };
};
#endif stack_header

#pragma region constructors
T adt::stack<type>::stack() : _size(0), _capacity(1)
{
    arr = new type[_capacity];
}

// constructor that defines the size of the stack
T adt::stack<type>::stack(const size_t &size) : _size(size), _capacity(size * 2)
{
    arr = new type[_capacity];
}
// copy constructor
T adt::stack<type>::stack(const adt::stack<type> &input) : _size(input._size), _capacity(input._capacity)
{
    this->arr = new type[this->_capacity];
    for (int i = 0; i < this->_size; i++)
    {
        this->arr[i] = input.arr[i];
    }
}

// init list constructor
T adt::stack<type>::stack(const in_list &init_list) : _size(init_list.size()), _capacity(_size * 2)
{

    this->arr = new type[this->_capacity];
    for (int i = 0; i < this->_size; i++)
    {
        this->arr[i] = *init_list.begin() + i;
    }
}

T adt::stack<type>::~stack()
{
    delete[] this->arr;
}

#pragma endregion

//----modifiers
T constexpr void adt::stack<type>::push(const type &input)
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
    this->_size++;
    int &temp = this->arr[0];
    for (int x = 1; x < this->_size; x++)
    {
        this->arr[x] = temp;
        temp = this->arr[x];
    }
    this->arr[0] = input;
}
T constexpr void adt::stack<type>::pop()
{
    this->arr[0].~type();
    this->_size--;
}

// access
T inline constexpr type &adt::stack<type>::top() conc
{
    return this->arr[0];
}

T constexpr bool adt::stack<type>::find(const type &input) conc
{
    for (int x = 0; x < this->_size; x++)
    {
        if (input == this->arr[x])
            return true;
    }
    return false;
}

// capacity
T constexpr size_t adt::stack<type>::size() conc
{
    return this->_size;
}
T constexpr size_t adt::stack<type>::capacity() conc
{
    return this->_capacity;
}
T constexpr bool adt::stack<type>::empty() conc
{
    if (this._size == 0)
    {
        return true;
    }
    return false;
}

// operator
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