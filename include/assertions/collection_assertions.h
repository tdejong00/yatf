#ifndef __YATF_COLLECTION_ASSERTIONS_H__
#define __YATF_COLLECTION_ASSERTIONS_H__

#include <algorithm>

#include "basic_assertions.h"

namespace assert {
    /**
     * @brief Provides collection assertions for verifying specific conditions within test cases.
     */
    namespace collection {
        /**
         * @brief Asserts that a collection is empty.
         * 
         * @tparam T The type of the collection, which has to be iterable.
         * @param container The collection to check.
         */
        template<typename T>
        typename std::enable_if<type_traits::is_iterable<T>::value>::type is_empty(const T &collection) {
            if (std::begin(collection) != std::end(collection)) {
                throw assertion_failed("expected collection to be empty, but it was not");
            }
        }

        /**
         * @brief Asserts that a collection is not empty.
         * 
         * @tparam T The type of the collection, which has to be iterable.
         * @param container The collection to check.
         */
        template<typename T>
        typename std::enable_if<type_traits::is_iterable<T>::value>::type is_not_empty(const T &collection) {
            if (std::begin(collection) == std::end(collection)) {
                throw assertion_failed("expected collection to not be empty, but it was");
            }
        }

        /**
         * @brief Asserts that a collection contains a specific value.
         * 
         * @tparam T The type of the collection, which has to be iterable.
         * @tparam U The type of the value of the items of the collection.
         * @param collection The collection to check.
         * @param value The value the collection should contain.
         */
        template<typename T, typename U>
        typename std::enable_if<type_traits::is_iterable<T>::value>::type contains(const T &collection, const U &value) {
            if (std::find(std::begin(collection), std::end(collection), value) == std::end(collection)) {
                throw assertion_failed("expected collection to contain value, but it did not");
            }
        }

        /**
         * @brief Asserts that a collection does not contain a specific value.
         * 
         * @tparam T The type of the collection, which has to be iterable.
         * @tparam U The type of the value of the items of the collection.
         * @param collection The collection to check.
         * @param value The value the collection should not contain.
         */
        template<typename T, typename U>
        typename std::enable_if<type_traits::is_iterable<T>::value>::type does_not_contain(const T &collection, const U &value) {
            if (std::find(std::begin(collection), std::end(collection), value) != std::end(collection)) {
                throw assertion_failed("expected collection to not contain value, but it did");
            }
        }

        /**
         * @brief Asserts that a collection is equal to another collection.
         * 
         * @tparam T The type of the collections, which has to be iterable.
         * @tparam U The type of the items of the collections, which has to be equality comparable.
         * @param collection1 The first collection.
         * @param collection2 The second collection.
         */
        template<typename T, typename U = typename std::remove_reference<decltype(*std::begin(std::declval<T>()))>::type>
        typename std::enable_if<type_traits::is_iterable<T>::value && type_traits::are_equality_comparable<U, U>::value>::type is_equal(const T &collection1, const T &collection2) {
            auto it1 = std::begin(collection1);
            auto it2 = std::begin(collection2);

            while (it1 != std::end(collection1) && it2 != std::end(collection2)) {
                if (!(*it1 == *it2)) {
                    throw assertion_failed("expected collections to be equal, but they were not");
                }
                ++it1;
                ++it2;
            }

            if (it1 != std::end(collection1) || it2 != std::end(collection2)) {
                throw assertion_failed("expected collections to be equal, but they were of different size");
            }
        }

        /**
         * @brief Asserts that a collection is not equal to another collection.
         * 
         * @tparam T The type of the collections, which has to be iterable.
         * @tparam U The type of the items of the collections, which has to be equality comparable.
         * @param collection1 The first collection.
         * @param collection2 The second collection.
         */
        template<typename T, typename U = typename std::remove_reference<decltype(*std::begin(std::declval<T>()))>::type>
        typename std::enable_if<type_traits::is_iterable<T>::value && type_traits::are_equality_comparable<U, U>::value>::type is_not_equal(const T &collection1, const T &collection2) {
            auto it1 = std::begin(collection1);
            auto it2 = std::begin(collection2);

            while (it1 != std::end(collection1) && it2 != std::end(collection2)) {
                if (!(*it1 == *it2)) {
                    throw assertion_passed();
                }
                ++it1;
                ++it2;
            }

            if (it1 == std::end(collection1) && it2 == std::end(collection2)) {
                throw assertion_failed("expected collections to not be equal, but they were");
            }
        }
    }
}

#endif