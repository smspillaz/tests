#include <boost/concept.hpp>
#include <type_traits>

namespace polysquare
{
    namespace concept
    {
        namespace internal
        {
            template <typename Concept>
            using req = boost::concepts::requirement <Concept>;
            namespace dt = boost::concepts::detail;

            template <class Concept, class Void = void>
            struct is_type
            {
                using type = Void;
            };


            template <class Concept, class Enable = void>
            struct check :
                std::false_type
            {
            };

            template <typename T>
            struct check <T,
                          is_type <dt::instantiate <&req <T>::failed>>::type> :
                public std::true_type
            {
            };
        }

        template <typename Concept>
        using check = internal::check <Concept>;
    }
}