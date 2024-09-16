#include <stdio.h> 
#include <stdlib.h>


struct customer *pointerCustomer;  // pointer to struct s

// THE SIZE IS GREATER OF THE SIZE OF ITS MEMBER
struct Customer {
    char name [1][15];
    int age;
} customer;


// OCCUPY LESS MEMORY SIZE OF THE LARGEST MEMBER
union SchoolStructur
{
    struct Student {
        int id;
        char name[1][15];
    } student; // WITH THE TAG I ACCESS A THIS OBJCET
} schoolStructure};




int main (void){

union SchoolStructur unionStudent;
unionStudent.student.id = 33;
schoolStructure.student.id = 29;
union SchoolStructur secondUS;
struct Student newStudent = {25, "John"};



// ARRAY TYPE IS NOT ASSIGNABLE IN C
strcpy(customer.name,"Pippo");
printf("%s\n",customer.name[0]);
// ISTANTIATE A STRCTURE
struct Customer customerOne = {"Carlo",36};
printf("%s\n",customerOne.name[0]);

}