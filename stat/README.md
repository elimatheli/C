# TP STAT

**Membre du binôme : Eliot Viseux**

## le fichier makefile

le fichier comporte la commande `make all` pour tout construire ou `make stat` qui revient à la même chose, la commande clean pour supprimer les fichiers compilés.

### Pour construire :
```bash 
make all
```
ou
```bash 
make stat
```

### Pour Lancer la commande :

```bash 
./stat <Nom du paramètre>
```

### Pour supprimer :
```bash 
make clean
```
# Compte-rendu Stat

Le but de cet exercice était de reproduire au mieux la commande `stat`, Tout d'abord il fallait effectuer la commande 
`man stat`
et 
`man 2 stat`
Pour avoir des informations sur la function système stat et sa structure. On peut voir que sa structure est de la forme :

```bash
struct stat {
               dev_t     st_dev;         /* ID of device containing file */
               ino_t     st_ino;         /* Inode number */
               mode_t    st_mode;        /* File type and mode */
               nlink_t   st_nlink;       /* Number of hard links */
               uid_t     st_uid;         /* User ID of owner */
               gid_t     st_gid;         /* Group ID of owner */
               dev_t     st_rdev;        /* Device ID (if special file) */
               off_t     st_size;        /* Total size, in bytes */
               blksize_t st_blksize;     /* Block size for filesystem I/O */
               blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */
               struct timespec st_atim;  /* Time of last access */
               struct timespec st_mtim;  /* Time of last modification */
               struct timespec st_ctim;  /* Time of last status change */
}
```
A partir des informations stockés dans les différentes parties de la structure nous allons peu à peu reconstituer la commande.

Dans mon fichier **stat.c** j'ai commencé par faire une verification que 2 arguments n'étaient pas donnés, s'il y a bien un seul argument alors on ouvre le fichier avec l'appel system open() en lecteur seule, puis si le fichier est bien ouvert alors on appelle la fonction fstat() que l'on stock dans une structure de la forme stat et ensuite on print les différentes informations.

Pour la permission, j'ai utilisé un masque binaire pour vérifier chaque valeur.

Pour le temps, j'ai dû utiliser la fonction ctime qui permet de formater une date.

Pour le nom de l'utilisateur, j'ai utilisé la fonction getpwuid() qui renvoie une strucutre avec notemment le nom de l'utilisateur.