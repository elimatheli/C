/* Lit une ligne sur l'entrée standard - via getchar() ou fgets().
   Lit au plus MAXLINE-1 caractères.
   Les caractères lus sont renvoyés dans le paramètre line,
     y compris un '\0' final.
   Le tableau line est assez grand pour contenir MAXLINE caractères.
   Renvoie
   - le nombre de caractères lus
   - EOF si la fin de fichier est atteinte
   Termine sur une erreur fatale, en utilisant fatal(), si la ligne
     contient plus de MAXLINE caractères.
*/
#include <stdio.h>
#include "mcu_fatal.h"

int readl(int line[]){
  int tape;
  int cpt=0;
  while ((tape=getchar())!=EOF && tape!='\n'){
    fatal(cpt<MAXLINE-1,"There are more than MAXLINE caracters in a line",1);
    line[cpt]=tape;
    cpt++;
  }
  line[cpt]=0;
  if (tape==EOF){
    return EOF;
  }
  return cpt;
}
