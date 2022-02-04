#ifndef GC_H
#define GC_H

#include <stddef.h>

/**
 * Allocate some memory and mark it for collection.
 */
void *allocate(size_t);

/**
 * Collect the garbage.
 */
void collect(void);

#endif
