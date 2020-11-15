#include <stdio.h>
#include "mcu_putint.h"

#define INT 0
#define EXT 1

int main(void){
  int etat=EXT;
  int i = 0;
  int c;
  while ((c=getchar())!=EOF){
    if (etat==INT){
      if (c==' ' || c==',' || c=='\n'){
	etat=EXT;
      }
    }else if (c!=' ' && c!=',' && c!='\n'){
      etat=INT;
      i++;
    }
  }
  putdec(i);
  putchar('\n');
  return 0;
}

