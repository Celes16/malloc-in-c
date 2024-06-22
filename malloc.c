#include <stdio.h>
#include <stdlib.h>

struct cel {
   int conteudo;
   struct cel *prox;
};

typedef struct cel cel;

int main(int argc, char const *argv[]) {
   FILE *arquivo;
   cel *lista, *nova, *posicao, *p;
   int v;

   arquivo = fopen("entrada.txt", "r");
   if (arquivo == NULL) {
      perror("Error opening file");
      return EXIT_FAILURE;
   }
   
   lista = (cel *)malloc(sizeof(struct cel));
   if (lista == NULL) {
      perror("Error allocating memory");
      fclose(arquivo);
      return EXIT_FAILURE;
   }

   lista->prox = NULL;  

   while (fscanf(arquivo, "%d", &v) != EOF) {
      posicao = lista;

      while (posicao->prox != NULL && posicao->prox->conteudo > v) {
         posicao = posicao->prox;
      }

      nova = (cel *)malloc(sizeof(struct cel));
      if (nova == NULL) {
         perror("Error allocating memory");
         fclose(arquivo);
         return EXIT_FAILURE;
      }

      nova->conteudo = v;
      nova->prox = posicao->prox;
      posicao->prox = nova;
   }
   fclose(arquivo);
   
   arquivo = fopen("saida.txt", "w");
   if (arquivo == NULL) {
      perror("Error opening file");
      return EXIT_FAILURE;
   }
   for (p = lista->prox; p != NULL; p = p->prox) {
      fprintf(arquivo, "%d\n", p->conteudo);
   }
   fclose(arquivo);
   
   while (lista != NULL) {
      p = lista;
      lista = lista->prox;
      free(p);
   }

   return 0;
}
