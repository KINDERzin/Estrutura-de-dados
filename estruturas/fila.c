typedef struct celula {
    int id;
    struct celula *proximo;
} celula;

typedef struct fila{
    struct celula *primeiro;
    struct celula *ultimo;
} fila; 

void inicializar_fila(struct fila *f) {
    f->primeiro = NULL;
    f->ultimo   = NULL;
}

int fila_vazia(struct fila *f) {
    return (f->primeiro == NULL && f->ultimo == NULL);
}

void enfileirar(struct fila *f, char nome[]) {
    celula *atual = (celula *) malloc(sizeof(celula));

    atual->id = (fila_vazia(f)) ? 1 : f->ultimo->id + 1;
    atual->proximo = NULL;
    
    if(fila_vazia(f)) {
        f->primeiro = atual;
        f->ultimo = atual;
    }
    else {
        f->ultimo->proximo = atual;
        f->ultimo = atual;
    }
}

void desenfileirar(struct fila *f) {
    if(fila_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    } 
    
    celula *atual = f->primeiro;

    if(f->primeiro == f->ultimo) {
        f->primeiro = atual->proximo;
        inicializar_fila(f);
    }
    f->primeiro = atual->proximo;
    
    free(atual);
}

void imprimir_fila(struct fila *f) {
    if(fila_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    }    

    celula *atual = f->primeiro;
    while (atual != NULL) {
        printf("ID: %d\n", atual->id);

        atual = atual->proximo;
    }
}

int main() {
    struct fila fila;
    struct celula celula;
    
    inicializar_fila(&fila);
                
    enfileirar(&fila);
    enfileirar(&fila);
    enfileirar(&fila);
    imprimir_fila(&fila);
    
    desenfileirar(&fila);
    imprimir_fila(&fila);
}