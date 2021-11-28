#ifndef STACK_H
#define STACK_H

struct Stack {
	int capacity;
	int index;
	void **arrdata;
};

int stack_create(struct Stack *stack);
int stack_destroy(struct Stack *stack);
int stack_push(struct Stack *stack, void *pdata);
int stack_pop(struct Stack *stack, void **ppdata);
int stack_peek(struct Stack *stack, void **ppdata);

#endif // STACK_H
