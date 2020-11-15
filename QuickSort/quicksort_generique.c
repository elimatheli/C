
void change(void *tab, int elemsize, int index1, int index2){
  char *p_tab = tab;
  char *p_1 = p_tab + elemsize * index1;
  char *p_2 = p_tab + elemsize * index2;
  int i; char tmp;
  for (i=0;i<elemsize;i++){
    tmp = *(p_1 + i);
    *(p_1 + i) = *(p_2 + i);
    *(p_2 + i) = tmp;
  }
}

void quicksort(void *base, int nelem, int size, int(*compar)(const void *, const void *)){
  int i; int j;
  int not_sorted;
  for (i=0;i<nelem && not_sorted;++i){
    not_sorted = 0;
    for (j=1;j<nelem-i;++j){
      if (1==compar(base+(j-1)*size,base+j*size)){
      	change(base, size, j-1, j);
      	not_sorted = 1;
      }
    }
  }
}
