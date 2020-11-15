#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <pwd.h>

 /*Auteur : Eliot Viseux*/

/*Fonction principale*/
int main(int argc, char *argv[]){

	/*si il y a trop d'arguments déclanche exit()*/
        if (argc != 2){
                exit(1);
        }
 
 	/* on ouvre le fichier avec l'appel système open() en lecture seulement*/
        int fd = open(argv[1], O_RDONLY);

    /* si la fonction renvoie 0 le fichier n'est pas ouvert*/
        if (fd < 0){
                printf("[%d] open file error!\n", fd);
        }

    /* sinon on construit la structure stat*/
        struct stat *resStat = malloc(sizeof(struct stat));

    /* on utilise fstat pour avoir les informations dans la structure*/
        int result = fstat(fd, resStat);
    /*si la fonction renvoie 0 alors le node n'existe pas*/
        if (result < 0){
                printf("[%d] fstat error!\n", result);
                exit(3);
        }

    /*sinon on affiche les différentes informations sur le node*/

    /* Le nom du fichier passé en agument*/
        printf("Fichier : '%s' \n",argv[1]);

    /* une variable isdi pour le type du node*/
        char *isdi;

     /* si c'est un repertoire ou un fichier en utilisant la macro S_ISDIR*/
        if(S_ISDIR(resStat->st_mode)){

        isdi = "Repertoire";
        }
        else{
        isdi = "Fichier";
        }

        /*la mise en forme des différentes informations de la structure*/
        printf("Taille :  %ld     Blocs : '%ld'      Blocs d'E/S : '%ld'  '%s'", resStat->st_size,resStat->st_blocks,resStat->st_blksize,isdi);
        printf("\nPériphérique : %ld      Inœud : '%ld'  Liens : '%ld'", resStat->st_dev,resStat->st_ino,resStat->st_nlink);


        /* valueperm stock une chaine de caractères représentant les permissions, on utilise st_mode et les différentes macro pour faire un AND, si la valeur booleénne est vrai on met le caractère correspondant dans la chaîne sinon un tiret*/
        char *valueperm = malloc(sizeof(char) * 9 + 1);
        mode_t perm = resStat->st_mode;
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

        /* la variable hostbuffer est une chaîne de caractère permetant de stocké le nom du propriétaire du node*/
        /* on utlise la fonction getpwuid qui renvoie une structure */
	
	struct passwd *hostname = getpwuid(resStat->st_uid);
        printf("\nAccès : '%s'   UID : ( '%d'/'%s' )   GID : ( '%d'/'%s')",valueperm,resStat->st_uid,hostname->pw_name,resStat->st_gid,hostname->pw_name);

        /* pour les dates d'accès, de modifications et de changements, on utilise ctime() pour formater la date*/
        printf("\nAccès : %s", ctime(&resStat->st_atime));
        printf("Modif : %s", ctime(&resStat->st_mtime));
        printf("Changt : %s", ctime(&resStat->st_ctime));
        printf("Créé : -\n");

	free(resStat);
	free(valueperm);
        return 0;
}
