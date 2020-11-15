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

void strcopy(int dst[],int src[]){
  int i=0;
  while(src[i]!=0){
    dst[i]=src[i];
    i++;
  }
  dst[i]=0;
}

int main(void){
  int line[MAXLINE];
  int cpy[MAXLINE];
  int c;
  int same=1;
  int r;
  int i;
  cpy[MAXLINE]=0;
  while ( (c=readl(line))!=EOF ){
    if (c==length(cpy)){
      int ind;
      for (ind=0;ind<c;ind++){
	if (line[ind]!=cpy[ind]){
	  same &= 0;
	}
      }
      if (same==0){
	for (i=0;i<c;i++){
	  r=putchar(line[i]);
	  if (r==-1) return 1;
	}
	putchar('\n');
      }
      same=1;
      strcopy(cpy,line);
    }else{
      for (i=0;i<length(line);i++){
	r=putchar(line[i]);
	if (r==-1) return 1;
      }
      putchar('\n');
      strcopy(cpy,line);
    }
  }
  return 0;
}
