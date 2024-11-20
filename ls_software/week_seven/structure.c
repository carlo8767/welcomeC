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


int main(){

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
    struct point p = {0, 0};
    struct point q = {.y = 1, .x = 1};
    q = p;
    p.x = 3;
    printf("Coordinates: %d %d\n", q.x, q.y);
    setPoint( &points, 2,9);
    printf("Coordinates: %d %d\n", points.x, points.y);


}