#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

// CREATE A POINTER
struct student {
    int *id;
};

struct PointLInes {
    int x;
};
typedef struct  PointLInes PointLInes;


struct fraction {
  int numerator;
  int denominator;
} fra;

double approximate(struct fraction *f) {
  return (double) f->numerator/ f->denominator;
}










typedef struct pointPulcino {
  double x;
  double y;
} pointPulcino;


void add( pointPulcino  *p, int a) {
   p->x;
}

// CONSTRUCTOR

struct student *construct_student (int size){
    // INSTANTIATE A POINTER WITH DYNAMIC SIZE 
    struct student *students = malloc(sizeof(struct student));  
    students->id = malloc(sizeof(int[size]));
    return students;
}

void freeStudent (struct student *student){
    free(student->id);
}

// modify a structure
void setPoint (struct  point *points, int x_value, int y_value){
    points -> x = x_value;
    points -> y = y_value;
}

int sum (int *a, int *b){
    return *a + *b;
}

int count_same_age (int ages_people [], int count_people, int age_people){
    int same_age =0;
    for(int i=0; i< count_people; i++){
        if(ages_people [i] == age_people){
            same_age+=1;
        }
    }
    return same_age;
}
    




int main(){

        int value = 5;
        int *point = &value;
        int n = *point;
        printf("The value of my first levele of inderection is %d\n", n+5);
        int **dereference = &point;
        int ** pointers = (int **) malloc (5* sizeof (int *));
        // ACCESS AT THE VALUE OF MY POINTER
        printf("The value of my first levele of inderection is %d\n", *point+5);
        printf("The value of my pointer is %p\n", point);
        printf("The value of my dereference is %p\n", *dereference);

        PointLInes p = {1};

        struct point array [2];
        for (int i = 0; i< 2; i++){
            array[i].x = 3+i;
            array[i].y = 4+i;
        }
    for (int i = 0; i< 2; i++){
        printf("The content of array struct is for x  %d\n and y %d\n", array[i].x, array[i].y);
    }
    
    array [0].x = 9;
    array [0].y = 8;

    struct point points = {1,2};
    printf("The value of x is %d\n", points.x);
    struct point q = {.y = 1, .x = 1};
    p.x = 3;
    printf("Coordinates: %d %d\n", q.x, q.y);
    setPoint( &points, 2,9);
    printf("Coordinates: %d %d\n", points.x, points.y);


}