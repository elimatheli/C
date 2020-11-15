#include <stdio.h>
#include "macros.h"

void affiche(int t[], int TABSIZE){
  int i;
  for (i=0;i<TABSIZE;i++){
    printf("%d ",t[i]);
  }
}

void main(void){
  int tab[TABSIZE];
  init_rand(tab);
  affiche(tab,TABSIZE);
  quicksort_int(tab,TABSIZE);
  affiche(tab,TABSIZE);
}
