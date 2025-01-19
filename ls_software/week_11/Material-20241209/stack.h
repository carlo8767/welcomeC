typedef struct stack stack_t;

stack_t *make_stack();
void free_stack(stack_t *s);
void print_stack(stack_t *s);
void push(stack_t *s, int v);
int pop(stack_t *s);
