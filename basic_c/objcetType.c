#include <stdbool.h>
#include <limits.h>
#include <stdio.h>


// BOOLEAN TYPE
 _Bool flag1 = 0;
bool flag2 = true;

// CHAR ARRAY OF TWO ARRAY WIHT AN
// ARRAY FO TEN ELEMENT
char names [2][10] = {"First","Second"};
char singleCharacter = 'C';

// LONG SHOR INT
long longeValue = 3000000000;
short shorValue = 15;
//ENUM INCREASE  CODE READABILITY
enum weekDays  {Monday=1, Tuesday,Wednesday,Thursday, Friday, Saturday,Sunday};
static int sumValue = 1;

int returnValue (int number){
    return number;
}


int main (void){
    enum weekDays findDay;
    findDay = Tuesday;
    switch (findDay)
    {
    case 1:
        printf("%s\n","This is Monday");
        break;
    case 2:
            printf("%s\n","This is Tuesday");
        break;
    default:
        break;
    }
    printf("%d\n", sizeof(names)); 
    for(int i =0; i<2;i++){
        printf("%s\n", names[i]);
    }
   printf("%s""\n", flag2 ? "true": "false");
   int value = 99;
   printf("The return value is %d\n",returnValue(value));
   int *Addressvalue = &value;
   printf("The address value is %d\n", *Addressvalue);
   printf("The static value is %d\n", ++sumValue);
   char arrayValue [2][5] = {"Fives" ,"Three"};
   int sizeColumns = sizeof(arrayValue)/sizeof(arrayValue[0]);
   int sizeRows = sizeof(arrayValue[0]);
   for (int c = 0; c<sizeColumns; c++){
    printf("The array element at %d is %s\n",c, arrayValue[c]);
   }
}

