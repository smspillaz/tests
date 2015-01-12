#include <library.h>

extern int otherfunction ();

int main ()
{
    return otherfunction () + special ();
}
