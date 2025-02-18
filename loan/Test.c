# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>



typedef  struct Name{
    char name [10];
    char lastName [20];
  } Name [20];
  
  struct Name* createName(char name [10],char lastName [20] ){
      Name nm = malloc(sizeof(Name));
      nm->name[0] = name;
      nm->lastName[0] = lastName;
      return nm;
  }


  
  int main (){
    struct Name arr [2];
    arr[0].name[0] = "d";
    arr[0].lastName[0] = "c";
    arr[1].name[0] = "d";
    arr[1].lastName[0] = "c";
    
    Name* name = malloc(sizeof(Name)*20);
    name[0]->name[0] = "a";
    

  }