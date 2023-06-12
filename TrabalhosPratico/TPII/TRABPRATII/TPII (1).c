/*Nome:Yago Martins Pintos
Matricula:20100404*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int CrawlerLogFolder ( char *log )
{ int diretorio=0;
for (int i = 0; i < strlen(log); i++)
{ 
    if (log[i]=='.'){   i++;
 if(log[i]=='.')
{if(diretorio>0){diretorio --;}
}
}

  


if(log[i]=='a'|| log[i]=='b'|| log[i]=='c'||log[i]=='d'||log[i]=='e'||log[i]=='f'||log[i]=='g'||log[i]=='h'||log[i]=='i'||log[i]=='j'||log[i]=='k'||log[i]=='l'||log[i]=='m'||log[i]=='n'||log[i]=='o'||log[i]=='p'||log[i]=='q'||log[i]=='r'
||log[i]=='s'||log[i]=='t'||log[i]=='u'||log[i]=='v'||log[i]=='x'||log[i]=='w'||log[i]=='y'||log[i]=='z'||log[i]=='A'||log[i]=='B'||log[i]=='C'||log[i]=='D'||log[i]=='E'||log[i]=='F'||log[i]=='G'||log[i]=='H'||log[i]=='I'||log[i]=='J'||log[i]=='K'
||log[i]=='L'||log[i]=='M'||log[i]=='N'||log[i]=='O'||log[i]=='P'||log[i]=='Q'||log[i]=='R'||log[i]=='S'||log[i]=='T'||log[i]=='U'||log[i]=='V'||log[i]=='X'||log[i]=='Y'||log[i]=='W'||log[i]=='Z'||log[i]=='1'||log[i]=='2'||log[i]=='3'||log[i]=='4'||log[i]=='5'||log[i]=='6'||log[i]=='7'||log[i]=='8'||log[i]=='9'||log[i]=='0'
){ i++; 
if(log[i]=='/') {diretorio ++;}}

}

    return diretorio ;



}
int main()
{
    char*log;
    int tamanho=0,i=0 ,terminar,resultado;
    terminar=0;
    log= ( char*) malloc (tamanho *sizeof(char));
    do
    {  tamanho++;
      log = realloc(log, tamanho * sizeof(char));
        if (log == NULL)  {
            printf("nao tem memoria avaliavel\n");
        }
        printf("entre com o caractere:\n " );
        scanf(" %c" , &log[i]);
        i++;
        printf("quer continuar adicionando se sim pressione 0 senao  qualquer numero \n");
        scanf(" %d" , &terminar );
    } while (terminar == 0);
    CrawlerLogFolder(log);
    resultado= CrawlerLogFolder(log);
    printf("%d\n",resultado);
     if (resultado == 0)
     {
        printf("esta no diretorio inicial\n");
     } 
        else {
        printf("nao esta\n");}
    
     free(log);

    return 0;
}
