#ifndef __YATF_TYPE_TRAITS_H__
#define __YATF_TYPE_TRAITS_H__

#include <type_traits>

/**
 * Contains type traits for checking various properties of types used in assertions.
 */
namespace type_traits {
    template<typename T, typename U>
    struct are_equality_comparable_helper {
        template<typename V, typename W>
        static auto test(int) -> decltype(std::declval<V>() == std::declval<W>());

        template<typename, typename>
        static auto test(...) -> std::false_type;

        using type = typename std::is_same<bool, decltype(test<T, U>(0))>::type;
    };

    /**
     * Type trait for checking if two types are equality comparable.
     */
    template<typename T, typename U>
    struct are_equality_comparable : are_equality_comparable_helper<T, U>::type {};

    template<typename T>
    struct is_iterable_helper {
        template<typename V>
        static auto test(int) -> decltype(
            std::begin(std::declval<V&>()), // has begin
            std::end(std::declval<V&>()), // has end
            std::declval<V&>() != std::declval<V&>(), // has not equal
            std::declval<V&>() == std::declval<V&>(), // has equal
            void(), // handle overloaded ','
            ++std::declval<decltype(std::begin(std::declval<V&>()))&>(), // has increment
            void(*std::begin(std::declval<V&>())), // has dereference
            std::true_type{}
        );

        template<typename>
        static auto test(...) -> std::false_type;

        using type = decltype(test<T>(0));
    };

    /**
     * Type trait for checking if a type is iterable.
     */
    template<typename T>
    struct is_iterable : is_iterable_helper<T>::type {};
}

#endif