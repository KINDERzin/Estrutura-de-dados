typedef struct celula {
    int id;
    char nome[100];
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
    printf("Enfileirando\n");
    celula *atual = (celula *) malloc(sizeof(celula));

    atual->id = (fila_vazia) ? 1 : f->ultimo->id + 1;
    strcpy(atual->nome, nome);
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
        printf("Nome: %s\n", atual->nome);

        atual = atual->proximo;
    }
}

int main() {
    struct fila fila;
    struct celula celula;
    int opcao = 0; 
    char a;
    
    inicializar_fila(&fila);

    printf("TERMINAL PRINCIPAL\n");

    while(opcao != 4) {
        printf("\n1 - enfileirar\n");
        printf("2 - desenfileirar\n");
        printf("3 - mostrar fila\n");
        printf("4 - sair\n");

        printf("Insira a opcao desejada: ");
        scanf("%d", &opcao);
        scanf("%c", &a); // GAMBIARRA

        switch(opcao) {
            case 1:
                char nome[100];

                printf("Nome: ");
                // scanf("%s", nome);
                fgets(nome, sizeof(nome), stdin);
                printf("%s", nome);
                
                enfileirar(&fila, nome);
                break;
            case 2:
                desenfileirar(&fila);
                break;
            case 3:
                imprimir_fila(&fila);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
            printf("Opcao invalida!\n");
                break;
        }
    }
}