/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
const int MAX = 10;
struct Pessoa
{
    char Nome[50];
    int idade;
    int telefone;
};
struct Pilha
{
    struct Pessoa pessoa[MAX];
    int topo;
    int base;
    int limite;
};

void Reset(Pilha *pilha)
{
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
};

bool Empty(Pilha *pilha) {
     return pilha->topo == 0; 
     };


bool Full(Pilha *pilha) {
     return pilha->topo == MAX; 
     }


bool Push(Pilha *pilha, Pessoa *item)
{
    if (!Full(pilha))
    {
        pilha->pessoa[pilha->topo] = *item;
        pilha->topo++;
        return true;
    }
    else
    {
        return false;
    }
}
int main(int argc, char const *argv[])
{
    printf("Hello World!\n");

    return 0;
}
*/ 
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int MAX = 10;

struct Pessoa {
    char Nome[50];
    int idade;
    int telefone;
};

struct Pilha {
    struct Pessoa pessoa[MAX];
    int topo;
    int base;
    int limite;
};

void Reset(struct Pilha *pilha) {
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
}

bool Empty(struct Pilha *pilha) {
    return pilha->topo == 0;
}

bool Full(struct Pilha *pilha) {
    return pilha->topo == MAX;
}

bool Push(struct Pilha *pilha,struct Pessoa *item) {
    if (!Full(pilha)) {
        pilha->pessoa[pilha->topo] = *item;
        pilha->topo++;
        return true;
    }
    else {
        return false;
    }
}
 void Pop (struct Pilha *pilha,struct Pessoa *pessoa)
 {
    if (pilha->topo == 0)return;
    pilha->topo--;
    *pessoa = pilha->pessoa[pilha->topo];}
 ;
 
int main(int argc, char const *argv[]) {
    printf("Hello World!\n");
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

struct Pessoa {
    char nome[50];
    int idade;
    
};

struct Pilha {
    struct Pessoa pessoa[MAX];
    int topo;
};

void Reset(struct Pilha *pilha) {
    pilha->topo = 0;
}

bool Empty(struct Pilha *pilha) {
    return pilha->topo == 0;
}

bool Full(struct Pilha *pilha) {
    return pilha->topo == MAX;
}

bool Push(struct Pilha *pilha, struct Pessoa *item) {
    if (!Full(pilha)) {
        pilha->pessoa[pilha->topo] = *item;
        pilha->topo++;
        return true;
    } else {
        return false;
    }
}

bool Pop(struct Pilha *pilha, struct Pessoa *pessoa) {
    if (Empty(pilha)) {
        return false;
    } else {
        pilha->topo--;
        *pessoa = pilha->pessoa[pilha->topo];
        return true;
    }
}

bool PopByName(struct Pilha *pilha, char *nome) {
    int i, j;
   
    bool encontrado = false;
    
    // Busca a pessoa pelo nome na pilha
    for (i = pilha->topo - 1; i >= 0; i--) {
        if (strcmp(pilha->pessoa[i].nome, nome) == 0) {
            encontrado = true;
            break;
        }
    }
    
    if (encontrado) {
        // Remove a pessoa da pilha
        for (j = i; j < pilha->topo - 1; j++) {
            pilha->pessoa[j] = pilha->pessoa[j + 1];
        }
        pilha->topo--;
        return true;
    } else {
        return false;
    }
}

void Clear(struct Pilha *pilha) {
    Reset(pilha);
}

void List(struct Pilha *pilha) {
    int i;
    printf("Pessoas na pilha:\n");
    for (i = pilha->topo - 1; i >= 0; i--) {
        printf("%s, %d anos\n", pilha->pessoa[i].nome, pilha->pessoa[i].idade);
    }
}
int main() {
    struct Pilha pilha;
    struct Pessoa pessoa;
    int opcao;
    char nome[50];

    Reset(&pilha);

    do {
        printf("\nMenu:\n");
        printf("0: Insere pessoa\n");
        printf("1: Deleta pessoa do topo\n");
        printf("2: Deleta pessoa por nome\n");
        printf("3: Limpa a pilha\n");
        printf("4: Lista na tela as pessoas\n");
        printf("5: Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Insira o nome da pessoa: ");
                scanf("%s", pessoa.nome);
                printf("Insira a idade da pessoa: ");
                scanf("%d", &pessoa.idade);
              
                if (Push(&pilha, &pessoa)) {
                    printf("Pessoa inserida com sucesso!\n");
                } else {
                    printf("A pilha esta cheia!\n");
                }
                break;
            case 1:
                if (Pop(&pilha, &pessoa)) {
                    printf("Pessoa %s removida do topo da pilha!\n", pessoa.nome);
                } else {
                    printf("A pilha esta vazia!\n");
                }
                break;
            case 2:
                printf("Insira o nome da pessoa a ser removida: ");
                scanf("%s", nome);
                if (PopByName(&pilha, nome)) {
                    printf("Pessoa %s removida da pilha!\n", nome);
                } else {
                    printf("Pessoa nao encontrada na pilha!\n");
                }
                break;
            case 3:
                Clear(&pilha);
                printf("A pilha foi limpa!\n");
                break;
            case 4:
                List(&pilha);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao != 5);

    return 0;
}