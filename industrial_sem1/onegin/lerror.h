#include <stdio.h>
#include <string.h>

/** \file */

typedef enum
{
    LERR_NO_ERROR = 0,
    LERR_FILE_IO,
    LERR_ALLOC
} lerror_t;

extern lerror_t __lerrno;
extern char __lerr_str[];
extern char __lerr_func_name[];
#define LERR_RETURN_NULL(err, err_string) { LERR(err, err_string); return NULL; }
#define LERR_RETURN_MINUS_ONE(err, err_string) { LERR(err, err_string); return -1; }
#define LERR(err, err_string) LERRNO(err); LERRSTR(err_string)
#define LERRNO(err) __lerrno = (err); strcpy(__lerr_func_name,  __func__)
#define LERRSTR(err_str) strcpy(__lerr_str, err_str)
#define LERRPRINT(string) fprintf(stderr, "%s: %s, in function %s\n", (string), __lerr_str, __lerr_func_name)