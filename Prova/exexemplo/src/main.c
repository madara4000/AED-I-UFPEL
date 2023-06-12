#include <stdio.h>
void set(int *i,int v) {
    *i=v;
}
void soma(int *a,int v) {
*a=*a+v;

}
int main()
{int i=2,h=6,n=1,r=1,*p;
int v[5]={10,8,6,4,2};
printf("EXEMPLO\n");
set(&i,1);
set(&h,1);
p=&h;
while (i<3){printf("%d\n",h);
soma(p,1);
i++;
}
n=r+i;
printf("n=%d\n",n);
printf("H=%d\n",*p);
set(&v[0],20);
p= &v[0];
*p=90;
set(&r,n+2);
set(&n,n*n);
printf("v[0]=%d\n",*p);
printf("r=%d\n",r);
printf("n=%d\n",n);
printf("P=%d\n",*(p+1));
p++;
printf("P=%d\n",*(p+1));
}
