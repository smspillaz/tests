#include <functional>
#include <memory>

template <typename Function, typename... Args>
int forward_function (Function const &f, Args&&... args)
{
    return f (std::forward <Args...> (args...));
}

int main (void)
{
    int i = 1;
    return forward_function ([&i](int j) -> int {
        return i + j;
    }, 2);
}
