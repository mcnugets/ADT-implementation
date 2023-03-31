#ifndef queue_h
#define queue_h
#include <iostream>
#include "template.h"
#include "Iterator.h"

namespace adt
{
    T class queue
    {
    private:
        size_t _capacity;
        size_t _size;
        type *arr;

    public:
        // typedef
        typedef iterator<type> iter;
        // constructors
        explicit queue();
        explicit queue(const queue<type> &input);
        explicit queue(const size_t &size);
        queue(const std::initializer_list<type> &init_list) noexcept;
        ~queue();
        // modifiers
        constexpr void enqueue(const type &input) noexcept;
        constexpr void dequeue() noexcept;
        // access
        constexpr type &front() const noexcept;
        constexpr type &rear() const noexcept;
        constexpr bool find(const type &input) const noexcept;

        // capacity
        constexpr size_t size() const noexcept;
        constexpr size_t capacity() const noexcept;
        constexpr bool empty() const noexcept;

        // operators
        constexpr type &operator[](const size_t &i) const noexcept;
        constexpr type &operator=(type &assign_to);

        // iterators
        constexpr iter begin() const;
        constexpr iter end() const;

        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const iter &it);
    };
};

using namespace std;
using namespace adt;
// constructor implementation
T queue<type>::queue() : _size(0), _capacity(1), arr(new type[capacity])
{
}
T queue<type>::queue(const queue<type> &input) : _size(input._size), _capacity(input._capacity), arr(new type[capacity])
{
    for (int x = 0; x < this->_size; x++)
    {
        arr[x] = input.arr[x];
    }
}
T queue<type>::queue(const size_t &size) : _size(size), _capacity(_size * 2), arr(new type[_capacity])
{
}
T queue<type>::queue(const initializer_list<type> &init_list) noexcept : _size(init_list.size()),
                                                                         _capacity(_size),
                                                                         arr(new type[_capacity])
{
    typename initializer_list<type>::iterator it = init_list.begin();
    for (int x = 0; x < this->_size; x++)
    {
        this->arr[x] = *it;
        it++;
    }
}
T queue<type>::~queue()
{
    delete[] this->arr;
}
// modifiers implementation
T constexpr void queue<type>::enqueue(const type &input) noexcept
{
    if (_size == _capacity)
    {
        _capacity = _capacity * 2;
        type *new_arr = new type[_capacity];
        for (int x = 0; x < _size; x++)
        {
            new_arr[x] = arr[x];
        }
        delete[] arr;
        arr = new_arr;
    }
    arr[_size] = input;
    _size++;
}
T constexpr void queue<type>::dequeue() noexcept
{
    arr[_size - 1].~type();
    _size--;
}
// access implementation
T constexpr type &queue<type>::front() const noexcept
{
    return arr[0];
}
T constexpr type &queue<type>::rear() const noexcept
{
    return arr[_size - 1];
}
T constexpr bool queue<type>::find(const type &input) const noexcept
{
    for (int x = 0; x < _size; x++)
    {
        if (input == arr[x])
        {
            return true;
        }
    }
    return false;
}
// capacity implementation
T constexpr size_t queue<type>::size() const noexcept
{
    return _size;
}
T constexpr size_t queue<type>::capacity() const noexcept
{
    return _capacity;
}
T constexpr bool queue<type>::empty() const noexcept
{
    if (_size == 0)
    {
        return true;
    }
    return false;
}
// operator implementation
T constexpr type &queue<type>::operator[](const size_t &i) const noexcept
{
    return arr[i];
}
T constexpr type &queue<type>::operator=(type &other)
{
    if (this == &other)
    {
        return *this;
    }
    if (_size != other._size)
    {
        _size = other._size;
        _capacity = other._capacity;
        delete[] arr;
        arr = new type[_capacity];
        arr = other.arr;
    }
    else
    {
        arr = other.arr;
    }

    return *this;
}
T ostream &operator<<(ostream &os, typename queue<type>::iter &it)
{
    os << it;
    return os;
}

// iterator implementation
T constexpr typename queue<type>::iter queue<type>::begin() const
{
    return iter(arr);
}
T constexpr typename queue<type>::iter queue<type>::end() const
{
    return iter(arr) + _size - 1;
}

#endif
