#include "allocator.h"

#define MAX_NODE_NAME_LENGTH 100

typedef struct tree_node_t
{
    char *node_name;
    
    struct tree_node_t *yes_branch;
    struct tree_node_t *no_branch;
} tree_node_t;

// Throws LERR
// Method messes passed buffer. Created tree depends on the buffer. 
// So keep buffer while using the tree
tree_node_t *tree_create_from_buffer(char *buf, size_t buf_size, memory_pool_t *pool);

// Throws LERR
void tree_dump(tree_node_t *tree_root, const char *file_name);
// Throws LERR
int tree_validate(tree_node_t *tree_root);

#define TREE_CHECK(tree, to_ret) \
{                                \
    tree_validate(tree);         \
    if (LERR_PRESENT())          \
        return to_ret;           \
}