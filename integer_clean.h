#if _WIN32 && _MSC_VER
    typedef  signed __int8     int8_t;
    typedef  unsigned __int8   uint8_t;
    typedef  signed __int16    int16_t;
    typedef  unsigned __int16  uint16_t;
    typedef  signed __int32    int32_t;
    typedef  unsigned __int32  uint32_t;
    typedef  signed __int64    int64_t;
    typedef  unsigned __int64  uint64_t;
#elif __STDC_VERSION__ >= 199901L
    #include <stdint.h>
#else
    #include "_sizeof_data_type.h"
    #if _SIZEOF_CHAR >= 32
        typedef signed char    int32_t;
        typedef unsigned char  uint32_t;
        #define INT32_IS_DEFINED
        #define UINT32_IS_DEFINED
    #elif _SIZEOF_CHAR >= 16
        typedef signed char    int16_t;
        typedef unsigned char  uint16_t;
        #define INT16_IS_DEFINED
        #define UINT16_IS_DEFINED
    #else
        typedef signed char    int8_t;
        typedef unsigned char  uint8_t;
        #define INT8_IS_DEFINED
        #define UINT8_IS_DEFINED
    #endif

    #if _SIZEOF_SHORT >= 32
        typedef signed short    int32_t;
        typedef unsigned short  uint32_t;
        #define INT32_IS_DEFINED
        #define UINT32_IS_DEFINED
    #else
        #ifndef INT16_IS_DEFINED
            typedef signed short    int16_t;
            typedef unsigned short  uint16_t;
            #define INT16_IS_DEFINED
            #define UINT16_IS_DEFINED
        #endif
    #endif

    #if _SIZEOF_INT >= 64
        #if __APPLE__
            typedef  unsigned long  uint64_t;
            #define INT64_IS_DEFINED
            #define UINT64_IS_DEFINED
        #else
            typedef  signed int    int64_t;
            typedef  unsigned int  uint64_t;
            #define  INT64_IS_DEFINED
            #define  UINT64_is_DEFINED
        #endif
    #elif _SIZEOF_INT >= 32
       #ifndef INT32_IS_DEFINED
           typedef  signed int    int32_t;
           typedef  unsigned int  uint32_t;
           #define INT32_IS_DEFINED
           #define UINT32_IS_DEFINED
       #endif
    #else
        #ifndef INT16_IS_DEFINED
            typedef signed int    int16_t;
            typedef unsigned int  int16_t;
            #define INT16_IS_DEFINED
            #define UINT16_IS_DEFINED
        #endif
    #endif

    #if _SIZEOF_LONG >= 64
        #if __APPLE__
            typedef  unsigned long  uint64_t;
            #define INT64_IS_DEFINED
            #define UINT64_IS_DEFINED
        #else
            typedef  signed long    int64_t;
            typedef  unsigned long  uint64_t;
            #define INT64_IS_DEFINED
            #define UINT64_IS_DEFINED
        #endif
    #else
        #ifndef INT32_IS_DEFINED
            typedef  signed long    int32_t;
            typedef  unsigned long  uint32_t;
            #define INT32_IS_DEFINED
            #define UINT32_IS_DEFINED
        #endif
    #endif

    /* `long long int` in C89 is defined as a compiler extension
        in either GCC or Clang. */
    #if __GNUC__ || __clang__
        #if __APPLE__
            #if !defined(INT64_IS_DEFINED) && _SIZEOF_LONG_LONG <= 64
                typedef  unsigned long long  uint64_t;
                #define INT64_IS_DEFINED
                #define UINT64_IS_DEFINED
            #endif
        #else
            #if !defined(INT64_IS_DEFINED) && _SIZEOF_LONG_LONG <= 64
                typedef  signed long long    int64_t;
                typedef  unsigned long long  uint64_t;
                #define INT64_IS_DEFINED
                #define UINT64_IS_DEFINED
            #endif
        #endif
    #endif
#endif
