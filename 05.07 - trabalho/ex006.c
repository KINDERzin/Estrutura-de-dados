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

int eh_circular(lista *l)
{
   if (esta_vazia(l))
      return 0;

   return l->ultima->proximo == l->primeira;
}

int main()
{
   celula c1;
   lista l1;

   criar_lista(&l1);
   adicionar_celula_fim(&l1);

   eh_circular(&l1);

   if (eh_circular(&l1))
      printf("Eh uma lista circular");
   else
      printf("Nao eh uma lista circular");
}