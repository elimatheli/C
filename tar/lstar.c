
/* Auteur : Eliot Viseux */

#include <stdio.h>
#include <tar.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Fonction qui arrondi l'entier en paramètre au plus proche multiple de 512. */
long arrondi512(long n){

    if(n%512 == 0){   /* si l'entier a pour reste 0 de la division par 512 il est déjà multiple de 512 */
	
	return n;
    }else{            /* sinon on ajoute 512 et on retire l'excès */
    
	int rest = n -((n / 512)*512);
	return (n+512 - rest);

     }
}


/* Structure du posix_header dans la commande tar */
struct posix_header
{                    /* Byte offset    Field type                 */
  char name[100];            /*   0    NUL-terminated if NUL fits */
  char mode[8];              /* 100                               */
  char uid[8];               /* 108                               */
  char gid[8];               /* 116                               */
  char size[12];             /* 124                               */
  char mtime[12];            /* 136                               */
  char chksum[8];            /* 148                               */
  char typeflag;             /* 156    see below                  */
  char linkname[100];        /* 157    NUL-terminated if NUL fits */
  char magic[6];             /* 257    must be TMAGIC (NUL term.) */
  char version[2];           /* 263    must be TVERSION           */
  char uname[32];            /* 265    NUL-terminated             */
  char gname[32];            /* 297    NUL-terminated             */
  char devmajor[8];          /* 329                               */
  char devminor[8];          /* 337                               */
  char prefix[155];          /* 345    NUL-terminated if NUL fits */
 			     /* 500                               */
/* If the first character of prefix is '\0', the file name is name;
   otherwise, it is prefix/name.  Files whose pathnames don't fit in
   that length can not be stored in a tar archive.  */
};

#define TMAGIC   "ustar"        /* ustar and a null */
#define TMAGLEN  6
#define TVERSION "00"           /* 00 and no null */
#define TVERSLEN 2


int main(int argc, char *argv[]) {

  /* On initialise la structure qui prend 512 octets */
  struct posix_header *structTamp = malloc(512);

  /* pointer pour la fonction strtol */
  char *ptr;

  /* pointeur du fichier */
  int fd;
  
  char *valueperm = valueperm = malloc(sizeof(char) * 9 + 1);


/* ---------------------------------------- */
/* VERSION POUR PIPE */
/* ---------------------------------------- */

  if(argc==1){
  /* le pointeur est mis sur 0 */
        fd=0;
        int r;     /*resultat de read()*/
        int l;     /*longeur lu dans le fichier*/
        int t;     /*la size récupérée dans l'entête*/
        r = 1;
        
        /* tant que read() renvoie un entier positif */
        while(r > 0){
        
        r = read(fd, structTamp, 512);   /* on lit le bloc de 512 qui représente l'entête */
        l = 0;
        
        t = strtol(structTamp->size,&ptr,8);  /* on récupère la taille du fichier */
        
        /* si la taille est de 0 et que le magic et le version est NULL alors on ne fait rien */
        if(t == 0 && strlen(structTamp->magic) == 0 && strlen(structTamp->version) == 0){
        }
        else{        /* sinon on affiche les différentes informations du fichier */
        
        /* masque pour les permissions */
         mode_t perm = structTamp->mode;
         valueperm[0] = (perm & S_IRUSR) ? 'r' : '-';
         valueperm[1] = (perm & S_IWUSR) ? 'w' : '-';
         valueperm[2] = (perm & S_IXUSR) ? 'x' : '-';
         valueperm[3] = (perm & S_IRGRP) ? 'r' : '-';
         valueperm[4] = (perm & S_IWGRP) ? 'w' : '-';
         valueperm[5] = (perm & S_IXGRP) ? 'x' : '-';
         valueperm[6] = (perm & S_IROTH) ? 'r' : '-';
         valueperm[7] = (perm & S_IWOTH) ? 'w' : '-';
         valueperm[8] = (perm & S_IXOTH) ? 'x' : '-';
         valueperm[9] = '\0';
        
        /* Formatage de la date de modification */
         long timestamp = strtol(structTamp->mtime,NULL,8);
         time_t ti;
         ti = timestamp;
    	 struct tm *pTime = localtime( &ti );
    	 char buffer[80];
    	 strftime( buffer, 80, "%d/%m/%Y %H:%M:%S", pTime );
    	
    	/* On affiche les informations */
  	 printf("%s %s/%s %ld %s %s\n",valueperm,structTamp->uname,structTamp->gname,strtol(structTamp->size,&ptr,8),buffer,structTamp->name);
        /* On lit l'équivalent de la taille pour aller jusqu'à la prochaine entête */
         while(l != (arrondi512(t)) && r > 0){
          l += read(fd, structTamp, 512);
         }
        }
        }
        
        }
        
/* ---------------------------------------- */
/* VERSION POUR AUTRE QUE PIPE */
/* ---------------------------------------- */

 if(argc > 1){
 
 mode_t perm = structTamp->mode;
 
 /* On ouvre le fichier */
  fd = open(argv[1],O_RDONLY);
  
 /* Si le résultat est error alors on exit() */
  if(fd <0){
  exit(3);
  }
  
  /* On lit l'entête pour la mettre dans la structure */
  read(fd, structTamp, 512);
  
  /* Tant que la structure n'est pas null (magic et version) */
  while(strlen(structTamp->magic) != 0 && strlen(structTamp->version) != 0){

  /* Masque pour les permissions */
        valueperm[0] = (perm & S_IRUSR) ? 'r' : '-';
        valueperm[1] = (perm & S_IWUSR) ? 'w' : '-';
        valueperm[2] = (perm & S_IXUSR) ? 'x' : '-';
        valueperm[3] = (perm & S_IRGRP) ? 'r' : '-';
        valueperm[4] = (perm & S_IWGRP) ? 'w' : '-';
        valueperm[5] = (perm & S_IXGRP) ? 'x' : '-';
        valueperm[6] = (perm & S_IROTH) ? 'r' : '-';
        valueperm[7] = (perm & S_IWOTH) ? 'w' : '-';
        valueperm[8] = (perm & S_IXOTH) ? 'x' : '-';
        valueperm[9] = '\0';

  /* Formatage de la date de modifications */
        long timestamp = strtol(structTamp->mtime,NULL,8);
        time_t ti;
        ti = timestamp;
    	struct tm *pTime = localtime( &ti );
    	char buffer[80];
    	strftime( buffer, 80, "%d/%m/%Y %H:%M:%S", pTime );
    	
  /* Affichage des informations */
  printf("%s %s/%s %ld %s %s\n",valueperm,structTamp->uname,structTamp->gname,strtol(structTamp->size,&ptr,8),buffer,structTamp->name);
  
  /* On déplace la position du curseur dans le fichier avec lseek() pour aller à l'entête suivante*/
  lseek(fd,strtol(structTamp->size,&ptr,8),SEEK_CUR);
  
  /* On lit le prochain bloc de 512 qui représente l'entête du fichier suivant*/
  read(fd, structTamp, 512);
  }
  }
  free(valueperm);
  free(structTamp);
return 0;
}

