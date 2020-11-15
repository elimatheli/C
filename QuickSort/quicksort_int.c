void quicksort_int(int tab[], int nelem){
  int i;
  int j;
  int tmp;
  int not_sorted;
  for (i=0;i<nelem && not_sorted;++i){
    not_sorted = 0;
    for (j=1;j<nelem-i;++j){
      if (tab[j-1]>tab[j]){
      	tmp = tab[j-1];
      	tab[j-1] = tab[j];
      	tab[j] = tmp;
      	not_sorted = 1;
      }
    }
  }
}
