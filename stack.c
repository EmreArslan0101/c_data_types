#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int size;
	int *data;
} stack_t;

stack_t createStack() {
	stack_t stack;
	stack.data = (int *)malloc(sizeof(int));
	stack.size = 0;
	return stack;
}

void pushf(stack_t *stack, int value) {
    stack->size++;
    stack->data = (int *)realloc(stack->data, (stack->size) * sizeof(int));
    if (stack->data == NULL) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }
    stack->data[stack->size - 1] = value;
}

int popf(stack_t *stack) {
	
	int returnval = stack->data[stack->size - 1];
	
	stack->data[stack->size - 1] = 0;
	
	stack->size--;
	
    stack->data = (int *)realloc(stack->data, (stack->size) * sizeof(int));
    if (stack->data == NULL) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }

    return returnval;
};

int main(int argc, char** argv) {
	
	stack_t stack = createStack();
	pushf(&stack,1);
	pushf(&stack,2);
	pushf(&stack,3);
	pushf(&stack,4);
	pushf(&stack,5);

	for (int i = 0; i < stack.size; i++) {
        printf("%d%c", stack.data[i],i<stack.size-1 ? '>' : '\0');
    };
    
	free(stack.data);

	return 0;
}