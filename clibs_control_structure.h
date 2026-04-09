/** @file       clibs_control_structure.h
 *  @brief      Common control structures.
 *  @author     ByteBard
 *  @copyright  MIT
 *
 *  @note
 *  This header demonstrates that language-like control structures can
 *  technically be implemented using macros in C.
 *
 *  However, this pattern can easily lead to code that is difficult to
 *  read, debug, and maintain. Because of this risk, we will NOT introduce
 *  any additional "language block" style macros in this project.
 *
 *  This macro exists purely as a technical demonstration of what is
 *  possible in C, not as a recommended pattern for general use.
 *
 *  @warning
 *  Avoid using this macro in production code. Control-flow macros can
 *  easily evolve into a macro-based DSL and make the codebase harder to
 *  understand.
 */

#ifndef CLIBS_CONTROL_STRUCTURE_H
#define CLIBS_CONTROL_STRUCTURE_H

#include <stddef.h>

/** @def     TIMES(count, block)
 *  @brief   Repeat a block of code a given number of times
 *  @param   count Number of repetitions
 *  @param   block Code block to execute
 */
#define TIMES(count, block)                     \
    do {                                        \
        for (size_t _clibs_times_i = 0;         \
             _clibs_times_i < (count);          \
             ++_clibs_times_i)                  \
        {                                       \
            block;                              \
        }                                       \
    } while (0)

#endif  /* CLIBS_CONTROL_STRUCTURE_H */
