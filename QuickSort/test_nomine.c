#include <stdio.h>
#include "macros.h"
#include "Nomine_s.h"
#include "fonctions_ext.h"

int main(void){
  struct Nomine_s tab_nomine[MAXTAB];
  int nb; int i;
  nb = ConstruireTableaux(tab_nomine);
  for (i=0;i<MAXTAB;i++){
    printf("%d %s %s %d-%d-%d %s %s\n",
	   tab_nomine[i].year,
	   tab_nomine[i].domain,
	   tab_nomine[i].name,
	   tab_nomine[i].birthday.year,
	   tab_nomine[i].birthday.month,
	   tab_nomine[i].birthday.day,
	   tab_nomine[i].nationality,
	   tab_nomine[i].gender);
  }
  printf("%d",nb);
  return nb;
}
