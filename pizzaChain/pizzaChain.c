#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// I need a way to move easily the table 
// and assign a number


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


// https://isocpp.org/wiki/faq/const-correctness
int verifyNumberOfManyGoopPizza( int indexLocation, const char* character, int willingWalk, int sizeCharacter){
  // I TAKE THE INDEX LOCATION
  // I ADD THE WILLING WALK TO STEP THE BOUNDARY OF MY CHARACTER
  int size = indexLocation+1 +willingWalk; // 5
  int count = 0; 
  // NUMBER OF LEFT OCCURENCE
  for(int i=indexLocation; i <size; i++){ // i is 2 SIZE IS
    if (i < sizeCharacter ){
      int value = character[i];
      if (value == 49){
         count++;
      }
    }
  }
  // NUMBER OF RIGHT OCCURENCE
  // I SKIPPED THE FIRST LOCATION OTHERWISE OVERLOAP
  indexLocation -= 1;
  size = indexLocation - willingWalk;
  for(int i=indexLocation; i > size; i--){
    if (i >= 0 ){
      int value = character[i];
      if (value == 49){
         count++;
      }
    }
  }
   return count;

  }
  

void verifyPizzaLocation( char* character, int* location,  int willing_walk, int size_location ,int sizeCharacter){
   int index = 0;
   int maximalNumberPizzaPlaces= 0;
   int memo [1];
   memo[0] = 0;
   
  // EXTRACT LOCATION VALUE
  for(int i=0; i<size_location; i++){
      int valueLocation = location[i] ;
      // verify that the location index 
      maximalNumberPizzaPlaces = verifyNumberOfManyGoopPizza (valueLocation-1, character, willing_walk, sizeCharacter);
      if (maximalNumberPizzaPlaces > memo[0]){
          memo [0] = maximalNumberPizzaPlaces;
      }

  }

  printf("%d\n", memo[0] );
  // VERIFY THAT THE INDEX LOCATION PLUS WILLING
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
      verifyPizzaLocation(p.character, p.location, p.willing_walk, m , p.sizeCharacter);
      free(h);
      free(character);

    }
  }
 
}


int main (){
 recoverInput();
}

