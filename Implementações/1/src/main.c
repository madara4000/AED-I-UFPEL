#include <stdio.h>
struct empregado{
    int cod;
    unsigned int salario


};
int main(){ struct empregado EP,*pEP;
EP.cod=1;
EP.salario=1210;
pEP=&EP;
printf("%d\n",pEP->cod);
pEP->cod=2;
printf("%d\n",pEP->cod);
printf("%d\n",pEP->salario);
printf("%d\n",pEP->salario);
return(0);
}