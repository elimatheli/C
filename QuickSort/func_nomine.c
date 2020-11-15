#include <stdio.h>
#include "Nomine_s.h"


void get_string(char tab[]){
  int c; int i = 0;
  while ((c=getchar())!='"'){}
  while ((c=getchar())!='"'){
    tab[i]=(char) c;
    i++;
  }
  tab[i]=0;
}

void new_line(){
  while(getchar()!='\n');
}

int ConstruireTableaux(struct Nomine_s *t){
  int nb_cell = 0;
  struct Nomine_s Nomine;
  int c; int date; int j;
  while ((c=getchar())!=EOF){
    date = 0;
    date=(date+c-48)*10;
    for (j=0;j<3;j++){
      date=(date+getchar()-48)*10;
    }
    Nomine.year = date/10;

    get_string(Nomine.domain);
    get_string(Nomine.name);

    while ((c=getchar())!='"'){}
    date = 0;
    while ((c=getchar())!='-'){
      date=(date+c-48)*10;
    }
    Nomine.birthday.year = date/10;
    date = 0;
    while ((c=getchar())!='-'){
      date=(date+c-48)*10;
    }
    Nomine.birthday.month = date/10;
    date = 0;
    while ((c=getchar())!='"'){
      date=(date+c-48)*10;
    }
    Nomine.birthday.day = date/10;

    get_string(Nomine.nationality);
    get_string(Nomine.gender);
    new_line();
    t[nb_cell]=Nomine;
    nb_cell++;
  }
  return nb_cell;
}

int CompareNomineParAgeDObtention(struct Nomine_s *nom1, struct Nomine_s *nom2){
  int age1=(*nom1).year-(*nom1).birthday.year;
  int age2=(*nom2).year-(*nom2).birthday.year;
  if (age1<age2) return -1;
  if (age1>age2) return 1;
  else return 0;
}

int CompareNomineParAgeDObtentionVoid(const void *nom1, const void *nom2){
  const struct Nomine_s *p_struct1 = nom1;
  const struct Nomine_s *p_struct2 = nom2;
  int age1=(*p_struct1).year-(*p_struct1).birthday.year;
  int age2=(*p_struct2).year-(*p_struct2).birthday.year;
  if (age1<age2) return -1;
  if (age1>age2) return 1;
  else return 0;
}
