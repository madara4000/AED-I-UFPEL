#include <stdio.h>

int main()
{ 
int x = 10;
int *ptr1 = &x;
int **ptr2 = &ptr1;
int *ptr = (int*) malloc(sizeof(int)); 
*ptr=20;
printf("%d\n",*ptr);
*ptr=32;
printf("%d\n",*ptr);
printf("%d\n",*ptr1);
printf("%d\n",**ptr2);
printf("%p\n",**ptr2);
}