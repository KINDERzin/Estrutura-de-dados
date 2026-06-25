typedef struct cliente {
    char nome[100];
    int idade;
    struct cliente *proximo;
} cliente;

typedef struct fila{
    struct cliente *primeiro;
    struct cliente *ultimo;
} fila; 

void inicializar_fila(struct fila *f) {
    f->primeiro = NULL;
    f->ultimo   = NULL;
}

int fila_vazia(struct fila *f) {
    return (f->primeiro == NULL && f->ultimo == NULL);
}

void enfileirar(struct fila *f, char nome[], int idade) {
    cliente *atual = (cliente *) malloc(sizeof(cliente));

    atual->idade = idade;
    strcpy(atual->nome, nome);
    atual->proximo = NULL;
    
    if(fila_vazia(f)) {
        f->primeiro = atual;
        f->ultimo = atual;
        return;
    }
    
    if(atual->idade >= 60) {
        cliente *auxiliar = f->primeiro;
        
        if(auxiliar->idade < 60) {
            atual->proximo = f->primeiro;
            f->primeiro = atual;
            return;
        }
        
        while(auxiliar->proximo->idade >= 60 || auxiliar->proximo == NULL) {
            auxiliar = auxiliar->proximo;
        }
        
        atual->proximo = auxiliar->proximo;
        auxiliar->proximo = atual;

        return;
    }
        f->ultimo->proximo = atual;
        f->ultimo = atual;
}

void desenfileirar(struct fila *f) {
    if(fila_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    } 
    
    cliente *atual = f->primeiro;

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

    cliente *atual = f->primeiro;
    while (atual != NULL) {
        printf("Nome: %s", atual->nome);
        printf("Idade: %d\n", atual->idade);

        atual = atual->proximo;
    }
}

int main() {
    struct fila fila;
    struct cliente cliente;
    char opcao, a; 
    char nome[100];
    int idade;
    
    inicializar_fila(&fila);

    while(opcao != 'e') {
        printf("\n=== TERMINAL PRINCIPAL ===\n"); 
        printf("\na - Inserir cliente na fila\n");
        printf("b - Atender cliente (caixa 1)\n");
        printf("c - Atender cliente (caixa 2)\n");
        printf("d - Imprimir todos clientes na fila de espera\n");
        printf("e - Sair\n");

        printf("Insira a opcao desejada: ");
        scanf("%c", &opcao);
        scanf("%c", &a);

        switch(opcao) {
            case 'a':
                
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                printf("Idade: ");
                scanf("%d", &idade);
                scanf("%c", &a);
                
                enfileirar(&fila, nome, idade);
                break;
            case 'b':
                if(fila_vazia(&fila)) {
                    printf("Sem clientes na fila!\n");
                    break;
                }
                printf("\n=== CAIXA 1 ===\n");
                printf("Cliente: %s\n\n", fila.primeiro->nome);
                printf("Idade: %d\n", fila.primeiro->idade);
                
                desenfileirar(&fila);
                break;
                
            case 'c':
                if(fila_vazia(&fila)) {
                    printf("Sem clientes na fila!\n");
                    break;
                }
                printf("\n=== CAIXA 2 ===\n");
                printf("Cliente: %s\n", fila.primeiro->nome);
                printf("Idade: %d\n", fila.primeiro->idade);
                
                desenfileirar(&fila);
                break;

            case 'd':
                if(fila_vazia(&fila)) {
                    printf("Sem clientes na fila!\n");
                    break;
                }    
                printf("\n=== Clientes ===\n");
                imprimir_fila(&fila);
                break;
                
            case 'e':
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}