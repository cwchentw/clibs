/** @file       clibs_control_structure.h
 *  @brief      Common control structures.
 *  @author     Michelle Chen
 *  @copyright  MIT
 */
#ifndef CLIBS_CONTROL_STRUCTURE_H
#define CLIBS_CONTROL_STRUCTURE_H

/** @def     TIMES(count, block)
 *  @brief   Repeat a block of code some time(s)
 *  @param   count Counter
 *  @param   block A block of code
 */
#define TIMES(count, block) { \
    size_t i; \
    for (i = 0; i < (count); ++i) { \
        (block); \
    } \
}

#endif  /* CLIBS_CONTROL_STRUCTURE_H */