#include <iostream>
using namespace std;

template <typename F, typename... A>
struct ReturnTypeDefaultConstructible
{
    typedef typename std::result_of <F (A...)>::type R;
    typedef typename std::is_default_constructible <R>::value value;
};

template <typename F, typename... A>
struct EnableIfReturnIsDefaultConstructible :
    public std::enable_if <ReturnTypeDefaultConstructible <F (A...)>::value>::type
{
};

template <typename F, 
          typename... Args,
          typename = EnableIfReturnIsDefaultConstructible <F (int, Args...)>>
typename std::result_of <F (int, Args...)>::type
CallAndReturn (F const &f, bool call, Args&&... args)
{
	if (call)
	    return f (1, std::forward <Args> (args)...);
	
	return typename std::result_of <F (int, Args...)>::type ();
}

void foo (int a)
{
}

void bar (bool call)
{
	return CallAndReturn (&foo, call);
}

int baz (bool call)
{
	return CallAndReturn ([](int j) {
		return (int) j;
	}, call);
}

int main() {
	bar (true);
	bar (false);

	std::cout << baz (true) << " " << baz (false) << std::endl;
	// your code goes here
	return 0;
}
