#include <stdio.h>
#include "macros.h"
#include "Nomine_s.h"
#include "fonctions_ext.h"

int main(void){
  struct Nomine_s tab_nomine[MAXTAB];
  int nb; int i;
  nb = ConstruireTableaux(tab_nomine);
  quicksort(tab_nomine,MAXTAB,sizeof(*tab_nomine),CompareNomineParAgeDObtentionVoid);
  for (i=0;i<MAXTAB;i++){
    printf("%d\n",tab_nomine[i].year-tab_nomine[i].birthday.year);
  }
  printf("%d",nb);
  return nb;
}
