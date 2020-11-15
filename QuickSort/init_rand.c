#include <stdlib.h>

void init_rand(int t[], int size){
  int i;
  for(i=0;i<size;i++){
    t[i]=rand();
  }
}
