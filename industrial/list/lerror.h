#include <stdio.h>
#include <string.h>

/** \file */

typedef enum
{
    LERR_NO_ERROR = 0,
    LERR_LIST_VALIDATION
} lerror_t;

#define MAX_LERR_MSG_LEN 100

extern lerror_t __lerrno;
extern char __lerr_str[];
extern char __lerr_func_name[];
#define LERR_RETURN_NULL(err, err_string) { LERR(err, err_string); return NULL; }
#define LERR_RETURN_MINUS_ONE(err, err_string) { LERR(err, err_string); return -1; }
#define LERR(err, err_string, ...) { LERRNO(err); LERRSTR(err_string, ##__VA_ARGS__); }
#define LERRNO(err) { __lerrno = (err); strcpy(__lerr_func_name,  __func__); }
#define LERRSTR(err_str, ...)                       \
{                                                   \
    char tmp_buf[MAX_LERR_MSG_LEN + 1];             \
    sprintf(tmp_buf, err_str, ##__VA_ARGS__);       \
    strncpy(__lerr_str, tmp_buf, MAX_LERR_MSG_LEN); \
}
#define LERRPRINT() fprintf(stderr, "An error occured in function %s: %s\n", \
                                        __lerr_func_name, __lerr_str)