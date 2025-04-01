#include <stdio.h>
#include <stdlib.h>

int main(){
  char c;
  float f;

  while(1) {
     scanf("%c", &c);
     scanf("%f", &f);
     printf("Set breakpoint here.\n");
     printf("Testing if doesnt overwrite");
     scanf("Testing if doesnt overwrite");
  }
}

