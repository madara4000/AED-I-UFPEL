#include <stdio.h>

int main()
{  int i=8,*pi;
    char c='c',*pc;
    float fl=9.00f;
   float *pf;
  printf("valor do char é %c\n",c);
 printf("valor do inteiro é %d\n",i);
  printf("valor do flutuante é %f\n",fl);
 pi=&i;
  pc=&c;
  pf=&fl;
   fl=8.00f;
 pi=4;
 pc='v';

printf("valor do char é %c\n",c);
 printf("valor do inteiro é %d\n",i);
  printf("valor do flutuante é %f\n",fl);
}
