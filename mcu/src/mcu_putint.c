#include <stdio.h>

int put_digit(int d){
  if (d>=0&&d<=9){
    int chiffre = d+48;
    putchar(chiffre);
  }
}

int putdec(int d){
  unsigned int e;
  int fin;
  int unite;
  if ((d&(1<<31))!=0){
    putchar('-');
    e = -d;
  }else{
    e = d;
  }
  fin = e/10;
  if (fin>0){
    putdec(fin);
  }
  unite = e%10;
  put_digit(unite);
}

int put_hdigit(int h){
  if (h>=0&&h<=9){
    int chiffre = h+48;
    return putchar(chiffre);
  } else if (h>=10&&h<=15){
    int lettre = h+55;
    return putchar(lettre);
  }
  return -1;
}

int puthex0(int h){
  if (h==0){
    int k;
    for (k=0;k<8;k++){
      putchar('0');
    }
  }else{
    unsigned int mask = 0xF0000000;
    int i = 0;
    int err;
    while (mask){
      unsigned int courant = mask&h;
      courant>>=(28-4*i);
      err = put_hdigit(courant);
      if (err==-1){
	return -1;
      }
      i++;
      mask>>=4;
    }
    return 0;
  }
}

int puthex(int h){
  if (h==0){
    putchar('0');
  }else{
    int err2;
    unsigned int mask = 0x000000F0;
    int i = 0;
    while (mask){
      unsigned int courant = mask&h;
      courant>>=(4-4*i);
      err2 = put_hdigit(courant);
      if (err2==-1){
	return -1;
      }
      i++;
      mask>>=4;
    }
    return 0;
  }
}
