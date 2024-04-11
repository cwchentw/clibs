/** @file       cio.h
 *  @brief      Basic input and output for C
 *  @author     ByteBard
 *  @copyright  MIT
 */
#ifndef CLIBS_CIO_H
#define CLIBS_CIO_H

#include <stdio.h>

/** @fn      char * stream_read_all(FILE *fp);
 *  @brief   Read all the content of \a fp into C string
 *  @param   fp a i/o stream
 *  @return  char *
 */
char * stream_read_all(FILE *fp);

#endif  /* CLIBS_CIO_H */
