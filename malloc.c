#include <stdio.h>
#include <stdlib.h>

struct cel
{
   int        conteudo;
   struct cel *prox;
};

typedef struct cel cel;

int main(int argc, char const *argv[])//função principal argc = argumentos e argv = argumentos
{
   FILE *arquivo;
   cel  *lista, *nova, *posicao, *p;
   int  v;

   arquivo = fopen("entrada.txt", "r");

   lista       = (cel *)malloc(sizeof(struct cel));
   lista->prox = NULL;  // cabeca da lista sem conteudo, para criar uma lista vazia sem cabeca basta colocar celula *ini; ini = NULL;//
           posicao->prox != NULL && posicao->prox->conteudo > v;
           posicao = posicao->prox); // p->prox o endereco do proximo elemento//

      nova           = (cel *)malloc(sizeof(struct cel));
      nova->conteudo = v;

      nova->prox    = posicao->prox;
      posicao->prox = nova;
   }
   fclose(arquivo);

   arquivo = fopen("saida.txt", "w");

   for (p = lista->prox; p != NULL; p = p->prox)
      fprintf(arquivo, "%d\n", p->conteudo);

   fclose(arquivo);

   return 0;
}
