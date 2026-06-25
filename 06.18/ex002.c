typedef struct letra {
   char letra;
   struct letra *proxima;
} letra;

typedef struct fila{
   struct letra *primeira;
   struct letra *ultima;
} fila; 

void inicializar_fila(struct fila *f) {
   f->primeira = NULL;
   f->ultima   = NULL;
}

int fila_vazia(struct fila *f) {
   return (f->primeira == NULL && f->ultima == NULL);
}

void enfileirar(struct fila *f, char p) {
   letra *atual = (letra *) malloc(sizeof(letra));

   atual->proxima = NULL;
   atual->letra = p;
   
   if(fila_vazia(f)) {
      f->primeira = atual;
      f->ultima = atual;
      return;
   }

   f->ultima->proxima = atual;
   f->ultima = atual;
}

void desenfileirar(struct fila *f) {
   if(fila_vazia(f)) {
      printf("Fila vazia!\n");
      return;
   } 
   
   letra *atual = f->primeira;

   if(f->primeira == f->ultima) {
      f->primeira = atual->proxima;
      inicializar_fila(f);
   }
   f->primeira = atual->proxima;
   
   free(atual);
}
int tamanho_fila(struct fila *f) {
   struct letra *atual = f->primeira;
   int contador = 0;

   while(atual != NULL) {
      contador++;
      atual = atual->proxima;
   }

   return contador;
}

int palindromo(struct fila *f) {
   if(fila_vazia(f)) return 1;

   struct letra *atual = f->primeira;
   struct letra *ultima = f->ultima;
   struct letra *assistente;

   while(atual != NULL && ultima != NULL && atual != ultima) {      
      if(atual->letra != ultima->letra) return 0;

      if(atual->proxima == ultima) return 1;

      assistente = atual;
      // Busca o penultimo elemento
      while(assistente->proxima != ultima) {
         assistente = assistente->proxima;   
      }

      f->primeira = atual->proxima;
      free(atual);

      f->ultima = assistente;
      f->ultima->proxima = NULL;
      free(ultima);
      
      atual = f->primeira;
      ultima = f->ultima;

   }

   return 1;
}

int main() {
   struct letra letra;
   struct fila fila;
   char palavra[47];

   inicializar_fila(&fila);

   printf("Insira uma palavra e descubra se ela eh um palindromo: ");
   
   fgets(palavra, 47, stdin);
   palavra[strcspn(palavra, "\n")] = '\0';

   for(int i = 0; i < strlen(palavra); i++) {
      if(palavra[i] == '\0')
         break;

      enfileirar(&fila, palavra[i]);
   }

   if(palindromo(&fila))
      printf("A palavra digitada eh um palindromo");
   else
      printf("A palavra digitada nao eh um palindromo");
}