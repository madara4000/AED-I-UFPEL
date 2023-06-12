/*Nome:Yago Martins Pintos
Matricula:20100404*//*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int minOperations(char **logs, int logsSize)
{
    int count = 0, i;
    for (i = 0; i < logsSize; i++)
    {
        if (strcmp(logs[i], "../") == 0)
        {
            if (count > 0) 
            {
                count--;
            }
        }
        else if (strcmp(logs[i], "./") != 0)
        {
            count++;
        }
    }
    return count;
}


int main()
{
    char **log;
    int tamanho = 0, i = 0, terminar, resultado;
    terminar = 0;
    *log = (char*) malloc (tamanho * sizeof(char));
    do
    {
        tamanho++;
        *log = realloc(*log, tamanho * sizeof(char));
        if (*log == NULL)  
        {
            printf("nao tem memoria avaliavel\n");
        }
        printf("entre com o caractere:\n " );
        scanf(" %c", &*log[i]);
        i++;
        printf("quer continuar adicionando se sim pressione 0 senao  qualquer numero \n");
        scanf(" %d", &terminar);
    } while (terminar == 0);
    CrawlerLogFolder(*log);
    resultado = CrawlerLogFolder(*log);
    printf("%d\n", resultado);
    if (resultado == 0)
    {
        printf("esta no diretorio inicial\n");
    } 
    else 
    {
        printf("nao esta\n");
    }
    free(*log);
    return 0;
}*/
/* Nome: Yago Martins Pintos
   Matricula: 20100404
*/
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int minOperations(char **logs, int logsSize) {
    int count = 0, i;
    for (i = 0; i < logsSize; i++) {
        if (strcmp(logs[i], "../") == 0) {
            if (count > 0) 
                count--;
        } else if (strcmp(logs[i], "./") != 0) {
            count++;
        }
    }
    return count;
}*/

/*int main() {
    char *log=NULL;TR
    int tamalloc = 0, i = 0, implefunc, resultado;
    implefunc= 0;
    log = (char*) malloc(tamalloc * sizeof(char));
    do {
        tamalloc++;
        log = realloc(log, tamalloc * sizeof(char));
        if (log == NULL) {
            printf("nao tem memoria disponivel\n");
            return 1;    /*indica erro de memoria 
        }
        printf("entre com o caractere:\n ");
        scanf(" %c", &log[i]);
        i++;
        printf("Deseja continuar adicionando caractere? Digite 1 para sair:  \n");
        scanf(" %d", &implefunc);
    } while (implefunc != 0);
    
    resultado = minOperations(log, implefunc);
    printf("%d\n", resultado);
    if (resultado == 0) {
        printf("esta no diretorio inicial\n");
    } else {
        printf("nao esta\n");
    }
    free(log);

    return 0;
}

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int minOperations(char **logs, int logsSize) {
int count = 0, i;
for (i = 0; i < logsSize; i++) {
if (strcmp(logs[i], "../") == 0) {
if (count > 0)
count--;
} else if (strcmp(logs[i], "./") != 0) {
count++;
}
}
return count;
}

int main() {
char *log = NULL;
int tamanho = 0, i = 0, terminar = 0;
do {
tamanho++;
log = realloc(log, tamanho * sizeof(char));
if (log == NULL) {
printf("Nao ha memoria disponivel\n");
return 1;
}
printf("Digite o proximo caractere :\n ");
scanf(" %c", &log[i]);
i++;
printf("Deseja continuar digitando? Digite 0 para continuar ou qualquer outro numero para terminar: \n ");
scanf(" %d", &terminar);
} while (terminar == 0);
log[i] = '\0';
char *token = strtok(log, "/");
char **logs = NULL;
int logsSize = 0;
while (token != NULL) {
logsSize++;
logs = realloc(logs, logsSize * sizeof(char *));
if (logs == NULL) {
printf("Nao ha memoria disponivel\n");
return 1;
}
logs[logsSize - 1] = token;
token = strtok(NULL, "/");
}
int resultado = minOperations(logs, logsSize);
printf("O numero minimo de operacoes necessarias para voltar a pasta principal e: %d\n", resultado);
free(log);
free(logs);
return 0;
}