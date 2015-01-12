#include <functional>

int main (void)
{
    std::function <int (int)> f ([](int a) -> int {
        return a;
    });

    return f(1);
}
