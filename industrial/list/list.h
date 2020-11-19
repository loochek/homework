#include <stdlib.h>
#include <stdbool.h>

typedef int    elem_t;

// as "iterator" i mean index in physical buffer
// 0 is an invalid iterator
typedef size_t list_iter_t;

typedef struct
{
    size_t       canary1;

    elem_t      *data;
    list_iter_t *next;
    list_iter_t *prev;

    list_iter_t  head;
    list_iter_t  tail;
    list_iter_t  head_free;

    size_t       buffer_size;
    size_t       used_size;
    
    bool         linear;

    size_t       canary2;
} list_t;

typedef enum
{
    LIST_OK,
    LIST_EMPTY,
    LIST_ERROR
} list_status_t;

// fast methods
// basic
list_status_t  list_construct      (list_t *list, size_t capacity);
void           list_destruct       (list_t *list);
list_status_t  list_push_front     (list_t *list, elem_t elem);
list_status_t  list_push_back      (list_t *list, elem_t elem);
list_status_t  list_pop_front      (list_t *list);
list_status_t  list_pop_back       (list_t *list);
// returns -1 if failed
int            list_size           (list_t *list);

// iterators
list_iter_t    list_next           (list_t *list, list_iter_t iter);
list_iter_t    list_prev           (list_t *list, list_iter_t iter);
list_iter_t    list_begin          (list_t *list);
list_iter_t    list_end            (list_t *list);

// iteration methods
elem_t        *list_data           (list_t *list, list_iter_t iter);
list_status_t  list_insert_after   (list_t *list, list_iter_t iter, elem_t elem);
list_status_t  list_insert_before  (list_t *list, list_iter_t iter, elem_t elem);
list_status_t  list_remove         (list_t *list, list_iter_t iter);

// linear methods (slow!)
list_status_t  list_linearize      (list_t *list);
list_iter_t    list_iter_lookup    (list_t *list, size_t position);

// debugging methods
void           list_visualize_phys (list_t *list, const char *img_file_name);
list_status_t  list_visualize_fancy(list_t *list, const char *img_file_name);
// returns Dump ID
int            list_html_dump      (list_t *list);