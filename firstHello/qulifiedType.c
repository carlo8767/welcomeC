 
  #include <stdio.h> 
  #include <stdlib.h>
  #include <stdbool.h>

bool volatile wait = true;
static int count = 0;

void  verifySignedUnsigend (int signed firstNum , int unsigned secondNum){

  if(secondNum < firstNum){
     printf("%d"" is greater than %d\n",firstNum, secondNum);
  }
  else {
    printf("%d is greater than " "%d\n", secondNum, firstNum);
  }

}

int QualifiedSum (int  *a,  int * restrict c){
    while(a-- >   0)
    *c += 10;
    *a += *c;
    return 0;
}

// WAIT CAN BE CHANGE FOR
// FACTOR
int changeWait (){
  wait = false;
}

int main (void){

 printf("%s\n","WAITING...");
 while(wait){
   changeWait();
 }

 int a = 10;
 int c = 9;
 QualifiedSum(&a,&c);
 printf("%d", c);

  verifySignedUnsigend(10, 9);
}

