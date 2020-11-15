#include <stdio.h>
#include "mcu_putint.h"
#include "mcu_readl.h"

int length(int t[]){
  int i=0;
  while ( (t[i]!=0) && (i<MAXLINE) ){
    i++;
  }
  return i;
}


void rev(int t[]){
  int l=length(t);
  int nb=l/2;
  int i; int temp;
  for (i=0;i<nb;i++){
    temp=t[i];
    t[i]=t[l-i-1];
    t[l-i-1]=temp;
  }
}


int main(void){
  int line[MAXLINE];
  int c;
  int r;
  int i;
  while ( (c=readl(line))!=EOF ){
    rev(line);
    for (i=0;i<length(line);i++){
      r=putchar(line[i]);
      if (r==-1) return 1;
    }
    putchar('\n');
  }
  rev(line);
  for (i=0;i<length(line);i++){
    r=putchar(line[i]);
    if (r==-1) return 1;
  }
  return 0;
}
