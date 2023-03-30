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
        constexpr void enqueue(const type &input) noexcept;
        constexpr void dequeue(const type &input) noexcept;
        constexpr type &front() const noexcept;
        constexpr type &rear() const noexcept;
    };
}