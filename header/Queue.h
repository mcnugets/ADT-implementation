#include <iostream>
#define T template <typename type>

namespace adt
{
    T class queue
    {
    private:
        size_t capacity;
        size_t size;
        type *arr;

    public:
        queue();
        ~queue();
    };
}