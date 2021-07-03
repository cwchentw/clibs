/** @file       clibs_math.h
 *  @brief      Common math operations.
 *  @author     Michelle Chen
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
 *  <b>IS_EQUAL(a, b, epsilon)</b> compares two floating-point numbers by the absolute value
 *  of the difference between \a a and \a b. The value should be smaller than
 *  \b epsilon
 */
#ifndef IS_EQUAL
    #define IS_EQUAL(a, b, epsilon) (ABS((a) - (b)) <= (epsilon))
#endif

/** @def COMPARE(a, b)
 *  @brief Compare two numeric data
 */
#ifndef COMPARE
    #define COMPARE(a, b) ((a) > (b) ? 1 : (a) == (b) ? 0 : -1)
#endif

/** @def IS_EVEN(n)
 *  @brief Check whether \a n is even
 */
#ifndef IS_EVEN
    #define IS_EVEN(n) (!((n) & 1))
#endif

/** @def IS_ODD(n)
 *  @brief Check whether \a n is odd
 */
#ifndef IS_ODD
    #define IS_ODD(n) ((n) & 1)
#endif

/** @def SWAP(a, b)
 *  @brief Swap between \a a and \a b
 * 
 *  \a a and \a b are integers
 */
#ifndef SWAP
    #define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
#endif

/** @def RANDINT(min, max)
 *  @brief Get a random integer bewteen \a min and \a max
 * 
 *  Set a random seed by yourself.
 */
#ifndef RANDINT
    #define RANDINT(min, max) ((min) + rand() % ((max) - (min) + 1)) 
#endif

/** @def INF
 *  @brief An infinity number
 */
#ifndef INF
    #ifdef _MSC_VER
        #include <math.h>
        #define INF (-logf(0.0))
    #else
        #define INF (1.0 / 0.0)
    #endif
#endif

/** @def IS_INF(n)
 *  @brief Check whether \a n is an infinity number
 */
#ifndef IS_INF
    #ifdef _MSC_VER
        #include <math.h>
        #define IS_INF(n) (!_finite(n))
    #else
        #define IS_INF(n) ((n) > FLT_MAX)
    #endif
#endif

/** @def NEG_INF
 *  @brief A negative infinity number
 */
#ifndef NEG_INF
    #ifdef _MSC_VER
        #include <math.h>
        #define NEG_INF (logf(0.0))
    #else
        #define NEG_INF (-1.0 / 0.0)
    #endif
#endif

/** @def IS_NEG_INF(n)
 *  @brief Check whether \a n is a negative infinity number
 */
#ifndef IS_NEG_INF
    #ifdef _MSC_VER
        #include <math.h>
        #define IS_NEG_INF(n) (!_finite(n) && (n) < 0)
    #else
        #define IS_NEG_INF(n) (-(n) > FLT_MAX)
    #endif
#endif

/** @def NaN
 *  @brief A NaN (not a number)
 */
#ifndef NaN
    #ifdef _MSC_VER
        #include <math.h>
        #define NaN (logf(0.0) - logf(0.0))
    #else
        #define NaN (0.0 / 0.0)
    #endif
#endif

/** @def IS_NaN(n)
 *  @brief Check whether \a n is NaN (not a number)
 */
#ifndef IS_NaN
    #define IS_NaN(n) \
        ((n) > (n)  ? 0 : \
         (n) == (n) ? 0 : \
         (n) < (n)  ? 0 : 1)
#endif

#endif  /* CLIBS_CMATH_H */
