#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
  int x;
  int y;
} point_t;

void print_point(point_t *p) {
  printf("%d %d", p->x , p->y );
}

point_t *create_point(int x, int y) {
  point_t *points = malloc(sizeof(point_t)); 
  points->x = x;
  points->y = y;
  return points;
}

void euclidian (point_t *p){
  int xOne;
  int yTwo;
  printf("Insert two point \n");
  scanf("%d %d", &xOne, &yTwo);
  int point_one = (xOne += xOne)+(yTwo *=yTwo);
  int point_two = (p->x*=p->x)+(p->y*p->y);
  double distance = (double)(point_two + point_one);
  double dist = sqrt(distance);
  printf("The distance is %lf\n", distance);
 
}


point_t *read_point() {
  // TASK: Read a point from the user
  int x_cordinate;
  int y_cordinate;
  scanf("%d %d" , &x_cordinate, &y_cordinate );
  point_t  *point = create_point(x_cordinate , y_cordinate);
  return point;
}


// Do not modify below
int main() {
  int a = 5;
  int *pointerss = &a;
  pointerss += 5;
  


  srand(0);
  for (int i = 0; i < 1000; i++) {
    int x = rand();
    int y = rand();
    point_t *p = create_point(x, y);
    if (p->x != x || p->y != y) {
      printf("Create is wrong");
      exit(1);
    }
    free(p);
  }

  printf("Please enter two coordinates: ");
  point_t *read = read_point();
  printf("You entered: ");
  print_point(read);
  printf("\n");
  euclidian(read);
}
