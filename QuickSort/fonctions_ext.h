#ifndef _NOMINE_
#include "Nomine_s.h"
#endif

extern void init_rand(int t[], int size);
extern void quicksort_int(int tab[], int nelem);
extern int ConstruireTableaux(struct Nomine_s *t);
extern int CompareNomineParAgeDObtention(struct Nomine_s *nom1, struct Nomine_s *nom2);
extern int CompareNomineParAgeDObtentionVoid(const void *nom1, const void *nom2);
extern void quicksort(void *base, int nelem, int size, int(*compar)(const void *, const void *));
