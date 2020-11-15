#include <stdio.h>
#include "macros.h"
#include "fonctions_ext.h"

void affiche(int t[], int size){
  int i;
  for (i=0;i<size;i++){
    printf("%d ",t[i]);
  }
}

int main(void){
  int tab[6]={4,2,3,1,5,4};
  /*init_rand(tab,6);*/
  printf("Avant tri :");
  affiche(tab,6);
  putchar('\n');
  printf("Après tri :");
  quicksort_int(tab,6);
  affiche(tab,6);
  putchar('\n');
  return 1;
}
