#ifndef __MATH_H__
#define __MATH_H__

#include <string>
#include <ostream>

/**
 * @brief Adds two numbers.
 * 
 * @param first The first number.
 * @param second The second number.
 * 
 * @return The result of the addition of the two numbers.
 * 
 * @exception `std::overflow_error` when the addition would result in an overflow
 * @exception `std::underflow_error` when the addition would result in an underflow
 */
int add(int first, int second);

#endif
