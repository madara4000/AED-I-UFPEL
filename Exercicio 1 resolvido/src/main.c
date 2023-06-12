#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{ char *str;
 int tamanho=10;
 int i=0;
 str=(char*) malloc (tamanho * sizeof(char));
    printf("adicionar nome!\n");
    fgets (str,tamanho,stdin);
    while(str(i)!='\n'&& str(i)!='\0'){
        while(str(i)==' ')i++;
    }
    return 0;                   
}
]