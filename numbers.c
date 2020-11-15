#include <stdio.h>
extern int putchar (int c);
int
newline()
{
  return putchar('\n');
}

//Exo23
int put_digit(int d){
  if (d>=0&&d<=9){
    int chiffre = d+48;
    return putchar(chiffre);
  }
  return -1;
}

//Exo24
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

//Exo25
void print_ascii_table(){
  int lig,col,code;
  for (int ligne=-1; ligne<=15; ligne++){
    for (int colonne=-1; colonne<=15; colonne++){
      if (ligne==-1 || colonne==-1){
	if (lig = put_hdigit(ligne)==-1){
	  putchar('-');     //pour les tirets de la premiere ligne
	}      
	if (col = put_hdigit(colonne)==-1){
	  putchar('-');     //pour les tirets de la premiere colonne
	  putchar(' ');     //pour l'espace supplementaire entre la premiere et la deuxiemme colonne
	}
      }else{
	code = ligne*16+colonne;     //calcul du code ascii
	if (32<=code && code<=126){     //pour les caracteres imprimables
	  putchar(' ');
	  putchar(code);
	}else{     //pour les caracteres non-imprimables
	  putchar('.');
	  putchar('.');
	}
      }
      putchar(' ');     //pour l'espace entre les colonnes
    }
    newline();     //pour les retours a la ligne en fin de ligne
  }
}

//Exo26
int putdec(int d){
  unsigned int e;
  if ((d&(1<<31))!=0){
    putchar('-');
    e = -d;
  }else{
    e = d;
  }
  int fin = e/10;
  if (fin>0){
    putdec(fin);
  }
  int unite = e%10;
  int err = put_digit(unite);
  if (err==-1){
      return -1;
  }
  return 0;
}

//Exo27
//voir le fichier exo-Differents_sens_pour_les_memes_nombres.txt

//Exo28
int putbin(int b){
  if (b==0){
    putchar('0');
  }else{
    int un = 0;
    unsigned int n = (unsigned int) b;
    unsigned int mask = 0x80000000;
    while (mask){
      int courant = mask&n;
      un |= courant;
      if (un){
	putchar(courant?'1':'0');
      }
      mask>>=1;
    }
    return 0;
  }
}

//Exo29
int puthex(int h){
  if (h==0){
    putchar('0');
  }else{
    int un = 0;
    unsigned int mask = 0xF0000000;
    int i = 0;
    while (mask){
      unsigned int courant = mask&h;
      courant>>=(28-4*i);
      un |= courant;
      if (un){
	int err2 = put_hdigit(courant);
	if (err2==-1){
	  return -1;
	}
      }
      i++;
      mask>>=4;
    }
    return 0;
  }
}

int put_test_line(int n)
{
    putchar('t');
    putchar('e');
    putchar('s');
    putchar('t');
    putchar(' ');
    putchar('#');
    putdec(n);
    putchar(':');

    return 0;
}

int main(){
  /*
  int test;
  printf("Entrez votre chiffre : ");
  scanf("%d",&test);
  //pour tester put_digit
  put_digit(test);
  printf("\nEn hexa: ");
  newline();
  //pour tester put_hdigit
  put_hdigit(test);
  newline();
  //pour tester putdec
  putdec(test);
    
  newline();
  newline();
  //pour afficher la table d'ascii
  print_ascii_table();
  newline();

  //pour tester putbin
  putbin(test);
  newline();

  //pour tester puthex
  puthex(test);
  newline();

  //pour l'Exo27
  int i=-2147483648;
  putdec(-i);
  return 0;
  */

  int i=-2147483648;
    put_test_line(1); putdec(214); newline();
    put_test_line(2); putdec(-74); newline();
    put_test_line(3); putdec(1); newline();
    put_test_line(4); putdec(-1); newline();
    put_test_line(5); putdec(0); newline();
    put_test_line(6); putdec(2147483647); newline();
    put_test_line(7); putdec(-2147483648); newline();
    put_test_line(8); putdec(-(-2147483648)); newline();
    put_test_line(9); puthex(0); newline();
    put_test_line(10); puthex(10); newline();
    put_test_line(11); puthex(16); newline();
    put_test_line(12); puthex(2147483647); newline();
    put_test_line(13); puthex(-2147483648); newline();
    put_test_line(14); puthex(0xCAFEBABE); newline();
    put_test_line(15); puthex(-1); newline();
    put_test_line(16); putbin(0); newline();
    put_test_line(17); putbin(1); newline();
    put_test_line(18); putbin(-1); newline();
    put_test_line(19); putbin(2147483647); newline();
    put_test_line(20); putbin(-2147483648); newline();

    return 0;
}
