typedef struct celula {
   int numero;
   struct celula* proximo; // anterior (n - 1)   
} celula;

typedef struct pilha {
   int quantidade;
   struct celula* topo;
}pilha;

void criar_pilha(pilha *p) {
   p->quantidade = 0;
   p->topo = NULL;
}

int pilha_vazia(pilha *p) {
   return (p->topo == NULL && p->quantidade == 0);
}

int tamanho_pilha(pilha *p) {
   return p->quantidade;
}

void empilhar(pilha *p) {
   printf("%d", pilha_vazia(p));

   celula *atual = (celula*) malloc(sizeof(celula));

   if(pilha_vazia(p)) {
      atual->numero = 1;
      atual->proximo = NULL;
   }     
   else {
      
      
      printf("%d", p->topo->numero);
      atual->numero = p->topo->numero++;
      atual->proximo = p->topo;
      p->topo = atual;
   }
   p->quantidade++;
}

void desempilhar(pilha *p) {
   if(pilha_vazia(p))
      return;

   celula *atual = p->topo;

   p->topo = atual->proximo;
   free(atual);
   p->quantidade++;
}

int main() {
   printf("Main");
   pilha p;
   celula c;

   criar_pilha(&p);
   
   if(pilha_vazia(&p))
      printf("A pilha esta vazia");
   else
      printf("A pilha nao esta vazia");

   for(int i = 0; i < 10; i++)
      empilhar(&p);

   
   printf("Mostrando pilha");

   celula *atual = p.topo;
   while(atual != NULL)
   {
      printf("Pilha %d\n Proximo: %p", atual->numero, atual->proximo);
   }
   
   printf("Desempilhando");
   
   atual = p.topo;
   while(atual != NULL)
   {
      printf("Pilha %d\n Proximo: %p", atual->numero, atual->proximo);
      if(atual == NULL)
         printf("Desempilhamento concluido!");
      
         atual = atual->proximo;
   }

}