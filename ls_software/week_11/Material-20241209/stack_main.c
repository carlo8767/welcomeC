// TASK: Add the correct includes (stack and util)

int main() {
	stack_t *s = make_stack();

	int n;
	scanf("%d", &n);
	int *array = malloc(sizeof(int[n]));
	for (int i = 0; i < n; i++) { // Read n numbers and push them on the stack
		int in;
		scanf("%d", &in);
		push_stack(s, in);
	}
	print_stack(s);
	for (int i = 0; i < n; i++) {
		printf("%d", pop_stack(s));
	}
}
