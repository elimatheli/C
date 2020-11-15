#   Décodage du format `tar`

Membre du binôme : ***Eliot Viseux***

## le fichier makefile

le fichier comporte la commande `make all` pour tout construire ou `make lstar` qui revient à la même chose, la commande clean pour supprimer les fichiers compilés.

### Pour construire :
```bash 
make all
```
ou
```bash 
make lstar
```

### Pour Tester :
```bash 
make test
```
Cela va créer deux fichiers `test` et `vide`, va créer ensuite l'archive puis excute la commande et ensuite supprime les fichiers test.


### Pour Lancer la commande :

**Avec Pipe :**
```bash 
tar -H ustar -c <Nom des fichiers du .tar> | ./lstar
```

**Avec des arguments :**
```bash 
./lstar <Nom du fichier.tar>
```

### Pour supprimer :
```bash 
make clean
```
# Compte-rendu Stat

Le but de cet exercice était de reproduire au mieux la commande tar avec un format d'archive ustar, Tout d'abord il fallait effectuer la commande `man tar` pour avoir des informations sur la function système tar et sa structure.

on nous donne :

```bash
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
```
Le principe est le suivant, une archive est constituée de chaque entête de fichier avec des informations sur ce fichier, puis ensuite le contenu de ce fichier.
Une archive peut être lu par bloc de 512 octets. Si la taille n'est pas multiple de 512 alors des octets sont rajoutés pour compléter.

---

Le principe de la fonction main() dans lstar.c :

soit un argument est mis alors la fonction va utiliser `read()` et `lseek()` pour déplacer le curseur de 512 en 512 octets et lire les entêtes,

soit c'est un pipe dans ce cas la fonction utilise `read()` pour lire les entêtes puis ensuite entre dans une boucle qui lit le fichier jusqu'à ce que une nouvelle entête soit mise dans la structure, cela est verifié avec les valeurs de **magic** et **version**.

Quand une entête de fichier est lue, les informations sont formatées pour être affichées.
- Les permissions sont affichées grâce à un *masque*.
- La taille est traduite de la base octal en décimal grâce à la fonction `strtol()`;
- La date est affichée grâce à la struct `tm` et aux fonctions `localtime()` et `strftime`.

