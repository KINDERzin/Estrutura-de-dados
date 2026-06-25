typedef struct celula
{
   int numero;
   struct celula *proximo;
} celula;

typedef struct lista
{
   struct celula *primeira;
   struct celula *ultima;
} lista;

void criar_lista(lista *l)
{
   l->primeira = NULL;
   l->ultima = NULL;
}

int esta_vazia(lista *l)
{
   return l->primeira == NULL;
}

void adicionar_celula_fim(lista *l)
{
   int quantidade;
   printf("Quantas celulas serao adicionadas? ");
   scanf("%d", &quantidade);

   for (int i = 0; i < quantidade; i++)
   {
      celula *nova_celula = (celula *)malloc(sizeof(celula));

      printf("Digite o numero da celula: ");
      scanf("%d", &nova_celula->numero);
      nova_celula->proximo = NULL;

      if (esta_vazia(l))
      {
         l->primeira = nova_celula;
         l->ultima = nova_celula;
      }
      else
      {
         l->ultima->proximo = nova_celula;
         l->ultima = nova_celula;
      }
   }
}

struct lista *copia_lista(lista *l1)
{
   lista *nova_lista;
   celula *atual = l1->primeira;

   while (atual != NULL)
   {
      atual->numero++;

      if (esta_vazia(nova_lista))
      {
         nova_lista->primeira = atual;
         nova_lista->ultima = atual;
      }
      else
         nova_lista->ultima = atual;

      atual = atual->proximo;
   }

   return nova_lista;
}

int main()
{
   celula c1;
   lista l1;
   lista *l2;

   criar_lista(&l1);
   adicionar_celula_fim(&l1);

   criar_lista(&l2);
   l2 = copia_lista(&l1);
}