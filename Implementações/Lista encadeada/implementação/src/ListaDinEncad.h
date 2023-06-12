struct Pessoa
{
 char nome[20];
 int idade;
 int telefone;
};
typedef struct elemento*Lista;
Lista* cria_lista();
Lista* libera_lista();