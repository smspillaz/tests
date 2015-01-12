#include <memory>
#include <iostream>

class A
{
    public:

        class Priv
        {
        public:
            int a;
        };

        A () :
            priv (new Priv ())
        {
        }

        void set_a (int a) { priv->a = a; }
        int get_a () { return priv->a; }

    private:

        std::unique_ptr <Priv> priv;

};

struct AWrapper {
    A a;
};

int main (void)
{
    struct AWrapper *a_wrapper = (AWrapper *) calloc (1, sizeof (AWrapper));
    a_wrapper->a.set_a (3);
    int a = a_wrapper->a.get_a ();

    std::cout << a << std::endl;
    return 0;
}
