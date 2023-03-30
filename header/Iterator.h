#include <iostream>
#define T template <typename type>

namespace adt
{
    T class iterator
    {
    private:
        type *ptr;

    public:
        ///
        /// Iterator constructor

        iterator();
        iterator(type *ptr);
        ~iterator();
        iterator &operator++(int);
        iterator &operator+(const int value);
        iterator &operator-(const int value);
        iterator &operator--();
        bool &operator==(type &other);
        bool &operator!=(type &other);
        type &operator*() const;
    };
};

//---------ITERATOR IMPLEMENTAITON-----------
T adt::iterator<type>::iterator() {}

T adt::iterator<type>::iterator(type *ptr) : ptr(ptr) {}

T adt::iterator<type>::~iterator() {}

T adt::iterator<type> &adt::iterator<type>::operator++(int)
{
    ptr++;
    return *this;
}
T adt::iterator<type> &adt::iterator<type>::operator+(const int value)
{
    ptr = ptr + value;
    return *this;
}
T adt::iterator<type> &adt::iterator<type>::operator-(const int value)
{
    ptr = ptr - value;
    return *this;
}
T adt::iterator<type> &adt::iterator<type>::operator--()
{
    ptr--;
    return *this;
}

T bool &adt::iterator<type>::operator==(type &other)
{
    return *this->ptr == other;
}

T bool &adt::iterator<type>::operator!=(type &other)
{
    return *this->ptr != other;
}

T type &adt::iterator<type>::operator*() const
{
    return *this->ptr;
}