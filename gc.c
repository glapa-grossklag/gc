#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 64

static void **stack = NULL;
static size_t top = 0;
static size_t capacity = 0;

void collect(void) {
	if (stack == NULL) {
		return;
	}

	for (size_t i = 0; i < top; i += 1) {
		free(stack[i]);
	}

	free(stack);
	stack = NULL;
	top = 0;
	capacity = 0;
}

void *allocate(size_t size) {
	// Only initialize the stack once.
	if (capacity == 0) {
		atexit(collect);
		top = 0;
		capacity = DEFAULT_CAPACITY;
		stack = malloc(capacity * sizeof(void *));
	}

	void *memory = malloc(size);

	if (top == capacity) {
		capacity *= 2;
		stack = realloc(stack, capacity * sizeof(void *));
		assert(stack != NULL);
	}

	stack[top] = memory;
	top += 1;

	return memory;
}

