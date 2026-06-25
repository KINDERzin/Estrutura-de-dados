typedef struct celula
{
   int numero;
   struct celula *proximo;
   struct celula *anterior;
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

int eh_palindromo(lista *l)
{
   celula *primeiro = l->primeira;
   celula *ultimo = l->ultima;

   while (primeiro != ultimo || (primeiro->proximo != ultimo && ultimo->anterior != primeiro))
   {
      if (esta_vazia(l))
         return 0;

      if (primeiro->numero != ultimo->numero)
         return 0; // nao é palindromo

      primeiro = primeiro->proximo;
      ultimo = ultimo->anterior;
   }
   return 1; // é palindromo
}

int main()
{
   celula c1;
   lista l1;

   criar_lista(&l1);
   adicionar_celula_fim(&l1);

   if (eh_palindromo(&l1))
      printf("Eh um palindromo");
   else
      printf("Nao eh um palindromo");
}