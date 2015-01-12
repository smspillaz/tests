#include <vector>
#include <list>
#include <string>
#include <map>
#include <iostream>
#include <iterator>

namespace foo {

int main (void)
{
    std::string str {"string"};
    std::list <std::string> list;
    for (size_t i = 0; i < 20; ++i)
        list.push_back (str);

    std::vector <std::string> vec;

    for (auto const &s : list)
        vec.push_back (s);

    std::map <int, std::string> map;

    for (auto it = std::begin (vec); it != std::end (vec); ++it)
        map[std::distance (std::begin (vec), it)] = *it;

    int *i = 0;
    *i = 3;
    std::cout << *i;

    return vec.size ();
}

}
        
