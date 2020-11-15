#include <stdio.h>
#include "mcu_putint.h"

int main(void){
  int i=0;
  while (getchar()!=EOF){
    i++;
  }
  putdec(i);
  putchar('\n');
  return 0;
}
