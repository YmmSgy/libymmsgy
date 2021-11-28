#include "stack.h"

#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define STACK_CAPACITY_MAX (INT_MAX)

extern int stack_create(struct Stack *stack) {
	// initialize the structure
	stack->capacity = 2;
	stack->index = -1;
	errno = 0;
	stack->arrdata = malloc(sizeof (void *) * stack->capacity);
	if (stack->arrdata == NULL) return errno ? errno : 1;
	return 0;
}

extern int stack_destroy(struct Stack *stack) {
	free(stack->arrdata);
	return 0;
}

extern int stack_push(struct Stack *stack, void *pdata) {
	if (stack->index + 1 == STACK_CAPACITY_MAX) return 1;

	// on overflow, double the array size
	if (stack->index + 1 == stack->capacity) {
		stack->capacity = stack->capacity > STACK_CAPACITY_MAX / 2
			? STACK_CAPACITY_MAX
			: stack->capacity * 2;

		errno = 0;
		void **newarr = realloc(stack->arrdata, sizeof (void *) * stack->capacity);
		if (newarr == NULL) return errno ? errno : 1;
		stack->arrdata = newarr;
	}

	// set the data
	stack->arrdata[++(stack->index)] = pdata;
	return 0;
}

extern int stack_pop(struct Stack *stack, void **ppdata) {
	// prevent underflow
	if (stack->index == -1) return 1;

	*ppdata = stack->arrdata[(stack->index)--];
	return 0;
}

extern int stack_peek(struct Stack *stack, void **ppdata) {
	if (stack->index == -1) return 1;

	*ppdata = stack->arrdata[stack->index];
	return 0;
}
