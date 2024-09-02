 // ESSENTIAL LIBRARY 
 
  #include <stdio.h> 
  #include <stdlib.h>

// THIS FUCTION DO NOT TAKE ANY ARGUMENTS AND IT IS VOID
int main(void) {
  //  EOF STANDS FOR END OF FILE 
  if(puts("Hello, world!")==EOF){
    return EXIT_FAILURE;
  }
  else{
      // PRINT FORMATTED OUTPUT 
      // %READ SECOND ARGUMENT N new line
    printf("%s,\n","Hello, print format");
    return EXIT_SUCCESS;
  }
}