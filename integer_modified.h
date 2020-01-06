#if _WIN32 && _MSC_VER                                                 /*   1 */
    typedef  signed __int8     int8_t;                                 /*   2 */
    typedef  unsigned __int8   uint8_t;                                /*   3 */
    typedef  signed __int16    int16_t;                                /*   4 */
    typedef  unsigned __int16  uint16_t;                               /*   5 */
    typedef  signed __int32    int32_t;                                /*   6 */
    typedef  unsigned __int32  uint32_t;                               /*   7 */
    typedef  signed __int64    int64_t;                                /*   8 */
    typedef  unsigned __int64  uint64_t;                               /*   9 */
#elif __STDC_VERSION__ >= 199901L                                      /*  10 */
    #include <stdint.h>                                                /*  11 */
#else                                                                  /*  12 */
    #include "_sizeof_data_type.h"                                     /*  13 */
    #if _SIZEOF_CHAR >= 32                                             /*  14 */
        typedef signed char    int32_t;                                /*  15 */
        typedef unsigned char  uint32_t;                               /*  16 */
        #define INT32_IS_DEFINED                                       /*  17 */
        #define UINT32_IS_DEFINED                                      /*  18 */
    #elif _SIZEOF_CHAR >= 16                                           /*  19 */
        typedef signed char    int16_t;                                /*  20 */
        typedef unsigned char  uint16_t;                               /*  21 */
        #define INT16_IS_DEFINED                                       /*  22 */
        #define UINT16_IS_DEFINED                                      /*  23 */
    #else                                                              /*  24 */
        typedef signed char    int8_t;                                 /*  25 */
        typedef unsigned char  uint8_t;                                /*  26 */
        #define INT8_IS_DEFINED                                        /*  27 */
        #define UINT8_IS_DEFINED                                       /*  28 */
    #endif                                                             /*  29 */

    #if _SIZEOF_SHORT >= 32                                            /*  30 */
        typedef signed short    int32_t;                               /*  31 */
        typedef unsigned short  uint32_t;                              /*  32 */
        #define INT32_IS_DEFINED                                       /*  33 */
        #define UINT32_IS_DEFINED                                      /*  34 */
    #else                                                              /*  35 */
        #ifndef INT16_IS_DEFINED                                       /*  36 */
            typedef signed short    int16_t;                           /*  37 */
            typedef unsigned short  uint16_t;                          /*  38 */
            #define INT16_IS_DEFINED                                   /*  39 */
            #define UINT16_IS_DEFINED                                  /*  40 */
        #endif                                                         /*  41 */
    #endif                                                             /*  42 */

    #if _SIZEOF_INT >= 64                                              /*  43 */
        #if __APPLE__                                                  /*  44 */
            typedef  unsigned long  uint64_t;                          /*  45 */
            #define INT64_IS_DEFINED                                   /*  46 */
            #define UINT64_IS_DEFINED                                  /*  47 */
        #else                                                          /*  48 */
            typedef  signed int    int64_t;                            /*  49 */
            typedef  unsigned int  uint64_t;                           /*  50 */
            #define  INT64_IS_DEFINED                                  /*  51 */
            #define  UINT64_is_DEFINED                                 /*  52 */
        #endif                                                         /*  53 */
    #elif _SIZEOF_INT >= 32                                            /*  54 */
       #ifndef INT32_IS_DEFINED                                        /*  55 */
           typedef  signed int    int32_t;                             /*  56 */
           typedef  unsigned int  uint32_t;                            /*  57 */
           #define INT32_IS_DEFINED                                    /*  58 */
           #define UINT32_IS_DEFINED                                   /*  59 */
       #endif                                                          /*  60 */
    #else                                                              /*  61 */
        #ifndef INT16_IS_DEFINED                                       /*  62 */
            typedef signed int    int16_t;                             /*  63 */
            typedef unsigned int  int16_t;                             /*  64 */
            #define INT16_IS_DEFINED                                   /*  65 */
            #define UINT16_IS_DEFINED                                  /*  66 */
        #endif                                                         /*  67 */
    #endif                                                             /*  68 */

    #if _SIZEOF_LONG >= 64                                             /*  69 */
        #if __APPLE__                                                  /*  70 */
            typedef  unsigned long  uint64_t;                          /*  71 */
            #define INT64_IS_DEFINED                                   /*  72 */
            #define UINT64_IS_DEFINED                                  /*  73 */
        #else                                                          /*  74 */
            typedef  signed long    int64_t;                           /*  75 */
            typedef  unsigned long  uint64_t;                          /*  76 */
            #define INT64_IS_DEFINED                                   /*  77 */
            #define UINT64_IS_DEFINED                                  /*  78 */
        #endif                                                         /*  79 */
    #else                                                              /*  80 */
        #ifndef INT32_IS_DEFINED                                       /*  81 */
            typedef  signed long    int32_t;                           /*  82 */
            typedef  unsigned long  uint32_t;                          /*  83 */
            #define INT32_IS_DEFINED                                   /*  84 */
            #define UINT32_IS_DEFINED                                  /*  85 */
        #endif                                                         /*  86 */
    #endif                                                             /*  87 */

    /* `long long int` in C89 is defined as a compiler extension
        in either GCC or Clang. */
    #if __GNUC__ || __clang__                                          /*  88 */
        #if __APPLE__                                                  /*  89 */
            #if !defined(INT64_IS_DEFINED) && _SIZEOF_LONG_LONG <= 64  /*  90 */
                typedef  unsigned long long  uint64_t;                 /*  91 */
                #define INT64_IS_DEFINED                               /*  92 */
                #define UINT64_IS_DEFINED                              /*  93 */
            #endif                                                     /*  94 */
        #else                                                          /*  95 */
            #if !defined(INT64_IS_DEFINED) && _SIZEOF_LONG_LONG <= 64  /*  96 */
                typedef  signed long long    int64_t;                  /*  97 */
                typedef  unsigned long long  uint64_t;                 /*  98 */
                #define INT64_IS_DEFINED                               /*  99 */
                #define UINT64_IS_DEFINED                              /* 100 */
            #endif                                                     /* 101 */
        #endif                                                         /* 102 */
    #endif                                                             /* 103 */
#endif                                                                 /* 104 */
