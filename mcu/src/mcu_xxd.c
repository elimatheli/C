#include <stdio.h>
#include "mcu_putint.h"
extern int isprint(int c);

int main(void){
  int tab[16];

  int c;
  int cpt=0;
  while ((c=getchar())!=EOF){
    int i=0; int j; int k; int l;
    tab[i]=c;
    i++;
    while (i<16 && (c=getchar())!=EOF){
      tab[i]=c;
      i++;
    }
    puthex0(cpt*16);
    putchar(':');
    for (j=0;j<i;j++){
      if (j%2==0) putchar(' ');
      puthex(tab[j]);
    }
    putchar(' ');
    for (k=0;k<16-i;k++){
      if (k%2==0) putchar(' ');
      putchar(' '); putchar(' ');
    }
    putchar(' ');
    for (l=0;l<i;l++){
      if (!isprint(tab[l])) putchar('.');
      else putchar(tab[l]);
    }
    putchar('\n');
    cpt++;
  }
  return 0;
}
