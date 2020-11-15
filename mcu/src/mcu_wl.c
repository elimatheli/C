#include <stdio.h>
#include "mcu_putint.h"
#include "mcu_readl.h"

int main(void){
  int cpt=0;
  int line[MAXLINE];
  int c;
  while ((c=readl(line))!=EOF){
    cpt++;
  }
  putdec(cpt);
  putchar('\n');
  return 0;
}
