#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char *argv[]) {
  int buffer_size, c, not_endofline, i, lus, ecrits, not_end;
  assert( argc>=2 );
  assert( (buffer_size=atoi(argv[1]))>0 );
  char buffer[buffer_size];
  FILE * stream;

  // pas de fichier en argument
  int nb_arg=argc;
  if (argc==2) nb_arg++ ;
  for (i=2;i<nb_arg;i++){
    // ouverture du flux du fichier
    if (argc==2){
      // cas oÃ¹ il n'y a pas de fichier donc entrÃ©e standard
      stream=stdin;
    }else{
      // cas oÃ¹ il y a au moins un fichier en argument
      if ((stream=fopen(argv[i],"r"))==NULL) perror(argv[i]);
    }
    // boucle pour chaque fichier
    not_end = 1;
    while (not_end) {

      // copie dans le tampon
      lus=0;
      not_endofline = 1;
      while (lus < buffer_size && not_end && not_endofline){
        if ( (buffer[lus]=fgetc(stream))!=EOF ) {
          // pour le cas ou on n'a pas de fichier
          if (buffer[lus]=='\n') not_endofline=0;
          lus++;
        }else{
          not_end=0;
        }
      }

      // ecriture dans la sortie standard
      ecrits=0;
      not_endofline = 1;
      while (ecrits < buffer_size && buffer[ecrits]!=EOF && not_endofline){
        if ((c=fputc(buffer[ecrits],stdout)) == EOF) perror("fputc");
        ecrits++;
        // pour le cas oÃ¹ on n'a pas de fichier
        if (c == '\n') not_endofline=0;
      }
      assert(lus==ecrits);
    }
    if (fclose(stream)==EOF) perror("fclose");
  }
  return 0;
}
