// TASK: Add the correct includes

typedef struct safe_array {
  // TASK: Define the struct content
} array_t;

array_t *make_array(int size) {
  // TASK: Create an array
}

void destroy_array(array_t *arr) {
  // TASK: Free all data
}

int size(array_t *a) {
  // TASK: Return the size of the array
}

int get(array_t *a, int i) {
  // TASK: Get the i-th element
}

void set(array_t *a, int i, int v) {
  // TASK: Set the i-th element
}

// Do not modify below
int main() {
  printf("Test empty ... ");
  array_t *empty = make_array(0);
  if (empty == NULL) {
    printf("Create is wrong!\n");
    exit(1);
  }
  if (size(empty) != 0) {
    printf("Size is wrong!\n");
    exit(1);
  }
  destroy_array(empty);
  empty = NULL;
  printf("ok!\n");

  printf("Test small array ... ");
  array_t *array = make_array(10);
  if (array == NULL) {
    printf("Create is wrong!\n");
    exit(1);
  }
  if (size(array) != 10) {
    printf("Size is wrong!\n");
    exit(1);
  }
  for (int i = 0; i < size(array); i++) {
    set(array, i, 10 * i);
  }
  for (int i = 0; i < size(array); i++) {
    if (get(array, i) != 10 * i) {
      printf("Set/Get is wrong!\n");
      exit(1);
    }
  }
  destroy_array(array);
  array = NULL;
  printf("ok!\n");

  printf("Test large allocate ... ");
  for (int i = 0; i < 100000; i++) {
    array_t *large = make_array(10000000);
    if (large == NULL) {
      printf("Destroy is wrong (probably)!\n");
      exit(1);
    }
    destroy_array(large);
    large = NULL;
  }
  printf("ok!\n");
}
