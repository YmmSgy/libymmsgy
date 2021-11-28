#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main(void) {
	char *pchar = "abcde";
	int ret;

	struct Stack stack1;			// struct Stack *pstack;
	ret = stack_create(&stack1);		// stack_create(&pstack);
	if (ret != 0) return ret;

	stack_push(&stack1, pchar);	// a	// stack_push(pstack, pchar);
	stack_push(&stack1, pchar + 1);	// b
	stack_push(&stack1, pchar + 4);	// e
	stack_push(&stack1, pchar + 3);	// d
	stack_push(&stack1, pchar + 1);	// b

	char buf[6] = "12345";
	for (int i = 0; i < 5; ++i) {
		void *pv;
		stack_pop(&stack1, &pv);
		buf[i] = *((char *)pv);
	}
	puts(buf);

	stack_destroy(&stack1);

	puts("");

	struct Stack stack2;
	stack_create(&stack2);

	stack_push(&stack2, "hello");
	stack_push(&stack2, "world!");

	void *pv2;
	stack_peek(&stack2, &pv2);
	puts((char *)pv2);		// "world!"
	stack_peek(&stack2, &pv2);
	puts((char *)pv2);		// "world!"
	stack_pop(&stack2, &pv2);
	puts((char *)pv2);		// "world!"
	stack_peek(&stack2, &pv2);
	puts((char *)pv2);		// "hello"

	stack_destroy(&stack2);

	return EXIT_SUCCESS;
}
