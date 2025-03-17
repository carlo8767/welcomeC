#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// I need a way to move easily the table 
// and assign a number
/*
With the fact that is not specify if I have to count the location 
from a bigindian or lower indian
I decided to verify the position from left to right
the limit is 
int limit = location[a]+ willing_walk;

6 2 1
110011
3 5

3 1 1
001
3

*/

typedef struct PizzaChain{
  int numberLocations;
  int sizeCharacter;
  int willing_walk;
  char* character;
  int* location;
} PizzaChain;

typedef struct MapsLocation {;
  int positionIndexLocation;
}MapsLocation;

 PizzaChain addPizzaChain (int willing_walk, char* character,  int* location, int sizeCharacter, int numberLocations)  {
  PizzaChain p =  {numberLocations, sizeCharacter, willing_walk, character, location };
  return p;
}
  

void cut_array_ (char* character, int* location, int sizeCharacter, int size_location, int willing_walk){
    int memo_pizza_location = 0;
    for (int a=0; a<size_location; a++){
          int number_pizza_location = 0;
         /// SETTING THE INDEX CORRECT BECUAUSE POS 2 IT IS AN INDEX 1 BUT THE LIMIT WEST
         // IS CORRECT BECAUSE I NEED TO STOP BEFORE  THE LENGTH
         int limit_est = location[a]+ willing_walk;
         int limit_west = location[a] - willing_walk-1;
         for (int i= limit_west; i < limit_est; i++){
               int value = character[i]; 
               if (value == 49 ){
                number_pizza_location+=1;  
               } 
         }    
       if (memo_pizza_location < number_pizza_location){
          memo_pizza_location = number_pizza_location;
       }
    }
    printf("%d", memo_pizza_location);
}

void recoverInput(){
  int n=0; // LENGTH PIZZA STREET
  int m=0; // NUMBER OF POSSIBLE LOCATIONS
  int r=0; // THE DISTANCE LEA AND HER FRIEND ARE WILLING TO WORK
  
  scanf("%d %d %d",  &n, &m, &r);
  if(n >= 1 && n  <= 100000){
    char* character = malloc(sizeof(char)*n);
    scanf( "%s",  character);
    if( m>= 1 && r >= 1 ){
      int* h = malloc(sizeof(int)*m);
      for (int i = 0; i < m; i++) {
        scanf("%d", &h[i]);  // **Reads multiple values in the same line**
      }
      PizzaChain p = addPizzaChain(r, character, h, n, m);
      cut_array_(p.character, p.location, p.sizeCharacter, m, p.willing_walk);
      free(h);
      free(character);

    }
  }
 
}

int main (){
 recoverInput();
}

