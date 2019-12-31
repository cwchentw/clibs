/** @file       cmath.h
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

/** @def EQUAL(a, b)
 *  @brief Check the equality between two floating-point numbers
 */
#ifndef EQUAL
    #define EQUAL(a, b) \
        (sizeof((a)) == 16 ? ABS((a) - (b)) <= 0.000000000000000000000001 : \
         (sizeof((a)) == 8 ? ABS((a) - (b)) <= 0.000000000000001 : \
                             ABS((a) - (b)) <= 0.0000001))
#endif

#endif  /* CLIBS_CMATH_H */
