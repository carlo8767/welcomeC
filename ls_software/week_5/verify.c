#include<stdio.h>
#include<string.h>


int main(){

char str[1024];
  fgets(str, 1024, stdin);
  char other[1024];

  int j = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if ('a' <= str[i]) {
      other[j] = str[i];
      j++;
    }
  }
  other[j] = '\0';
  printf("%s", other);

}