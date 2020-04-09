/** @file       clibs_math.h
 *  @brief      Common math operations.
 *  @author     Michael Chen
 *  @copyright  MIT
 */
#ifndef CLIBS_CMATH_H
#define CLIBS_CMATH_H

/** @def MAX(a, b)
 *  @brief Get the maximal value between \a a and \a b
 */
#ifndef MAX
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

/** @def MIN(a, b)
 *  @brief Get the minimal value between \a a and \a b
 */
#ifndef MIN
    #define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

/** @def ABS(a)
 *  @brief Get the absolute value of \a a
 */
#ifndef ABS
    #define ABS(a) ((a) > 0.0 ? (a) : -(a))
#endif

/** @def IS_EQUAL(a, b, epsilon)
 *  @brief Check the equality between two floating-point numbers
 *
 *  <b>EQUAL(a, b)</b> compares two floating-point numbers by the absolute value
 *  of the difference between \a a and \a b. The value should be smaller than
 *  \b epsilon
 */
#ifndef IS_EQUAL
    #define IS_EQUAL(a, b, epsilon) (ABS((a) - (b)) <= epsilon)
#endif

/** @def COMPARE(a, b, flag)
 *  @brief Compare two numeric data
 * 
 *  \a flag should be an integer-compatible variable to hold the status of
 *  the comparison between \a a and \a b
 */
#ifndef COMPARE
    #define COMPARE(a, b, flag) { \
        if ((a) > (b)) \
            flag = 1; \
        else if ((a) < (b)) \
            flag = -1; \
        else \
            flag = 0; \
    }
#endif

/** @def IS_EVEN(n)
 *  @brief Check whether \a n is even
 */
#ifndef IS_EVEN
    #define IS_EVEN(n) (0 == ((n) & 1))
#endif

/** @def IS_ODD(n)
 *  @brief Check whether \a n is odd
 */
#ifndef IS_ODD
    #define IS_ODD(n) (1 == ((n) & 1))
#endif

/** @def SWAP(a, b)
 *  @brief Swap between \a a and \a b
 * 
 *  \a a and \a b are integers
 */
#ifndef SWAP
    #define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
#endif

#endif  /* CLIBS_CMATH_H */
