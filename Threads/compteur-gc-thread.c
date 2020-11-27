#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <pthread.h>


 // Création of the thread
void *compteur_gc_thread(void *);

struct tparam {
  char *tab;
  // start of tab
  unsigned long start;
  // size of tab
  unsigned long size;
  // result
  unsigned long res; 

};
unsigned long compte_gc(char *bloc, unsigned long start ,unsigned long taille) {

  unsigned long cptr = 0;
  for (unsigned long i = start ; i < start+taille; i++)
      if (bloc[i] == 'G' || bloc[i] == 'C')
          cptr++;

  return cptr;
}

void *compteur_gc_thread(void *arg) {
  struct tparam *p = (struct tparam *) arg;
  p->res = compte_gc(p->tab,p->start,p->size);
  return NULL;
}

int main(int argc, char *argv[]) {
    struct stat st;
    int fd;
    char *tampon;
    int lus;
    off_t taille = 0;
    // first agrument nb of threads wanted
    int nb_thread = strtol(argv[2], NULL, 10);;
    struct timespec debut, fin;
    // Tab with size of the total threads
    pthread_t thread[nb_thread];
    // Tab with the struct
    struct tparam div_tab[nb_thread];

    assert(argc > 2);

    /* Quelle taille ? */
    assert(stat(argv[1], &st) != -1);
    tampon = malloc(st.st_size);
    assert(tampon != NULL);

    /* Chargement en mémoire */
    fd = open(argv[1], O_RDONLY);
    assert(fd != -1);
    while ((lus = read(fd, tampon + taille, st.st_size - taille)) > 0)
        taille += lus;
    assert(lus != -1);
    assert(taille == st.st_size);
    close(fd);

    assert(clock_gettime(CLOCK_MONOTONIC, &debut) != -1);

    int size_each = taille/nb_thread
    int cpt_start = 0;
    for(int i=0;i<nb_thread-1;i++){
      div_tab[i].tab = tampon;
      div_tab[i].start = cpt_start;
      div_tab[i].size = size_each;
      cpt_start += size_each;
    }

     // not an even number
    div_tab[nb_thread-1].tab = tampon;
    div_tab[nb_thread-1].start = cpt_start;
    div_tab[nb_thread-1].size = taille-cpt_start;

    /* All the threads */
    for (int j=0;j<nb_thread;j++){
      pthread_create(&thread[j],NULL,compteur_gc_thread,(void *) & div_tab[j]);
    }

    /* join all the threads */
    for (int j=0;j<nb_thread;j++){
      pthread_join(thread[j],NULL);
    }

    /* sum of the threads result */
    long res = 0;
    for (int j=0;j<nb_thread;j++){
      res += div_tab[j].res;
    }
    assert(clock_gettime(CLOCK_MONOTONIC, &fin) != -1);

    /* Affichage des résultats */
    /*printf("Nombres de GC:   %ld\n", res);
    printf("Taux de GC:      %lf\n", ((double) res) / ((double) taille));

    fin.tv_sec  -= debut.tv_sec;
    fin.tv_nsec -= debut.tv_nsec;
    if (fin.tv_nsec < 0) {
        fin.tv_sec--;
        fin.tv_nsec += 1000000000;
    }
    printf("Durée de calcul: %ld.%09ld\n", fin.tv_sec, fin.tv_nsec);
    printf("(Attention: très peu de chiffres après la virgule sont réellement significatifs !)\n");
*/
    return 0;
}
