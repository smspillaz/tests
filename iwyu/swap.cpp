#include <array>
#include <memory>
#include <vector>

namespace foo
{
    struct A
    {
        int member;
        std::vector <int> vec;
        std::array <int, 2> arr;
        std::unique_ptr <int> uptr;

        friend void swap (A &first, A &second) noexcept
        {
            using std::swap;

            swap (first.member, second.member);
            swap (first.vec, second.vec);
            swap (first.arr, second.arr);
            swap (first.uptr, second.uptr);
        }
    };
}

int main (void)
{
    foo::A a = { 1 };
    foo::A b = { 2 };

    using std::swap;
    swap (a, b);

    return b.member;
}
