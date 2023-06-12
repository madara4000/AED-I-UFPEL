#include <stdio.h>

int main()
{ int array[5]={1,2,3,4,5},i;
int *parray;
parray=&array;
for ( i = 0; i < 5; i++)
{
    printf("%d\n",*parray*2);
    parray++;
}

    

    return 0;
}
