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

void enfileirar(struct fila *f, char nome[], int idade, int *t) {
    cliente *atual = (cliente *) malloc(sizeof(cliente));

    atual->idade = idade;
    strcpy(atual->nome, nome);
    atual->proximo = NULL;
    
    if(fila_vazia(f)) {
        f->primeiro = atual;
        f->ultimo = atual;
    }
    else if(atual->idade >= 60) {
        cliente *auxiliar = f->primeiro;
        
        if(auxiliar->idade < 60) {
            atual->proximo = f->primeiro;
            f->primeiro = atual;
            (t++);
            return;
        }
        
        while(auxiliar->proximo->idade >= 60 || auxiliar->proximo == NULL) {
            auxiliar = auxiliar->proximo;
        }
        
        atual->proximo = auxiliar->proximo;
        auxiliar->proximo = atual;

    }
    else {
        f->ultimo->proximo = atual;
        f->ultimo = atual;
    }
    (t++);
}

void desenfileirar(struct fila *f, int *t) {
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
    (t--);
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
int tamanho_fila(struct fila *f) {
    if(fila_vazia(f))
        return 0;

    cliente *atual = f->primeiro;
    int tamanho = 1;

    while(atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
}

void rebalancear_fila(struct fila *f1, struct fila *f2) {
    int tamanho1, tamanho2;
    tamanho1 = tamanho_fila(f1);
    tamanho2 = tamanho_fila(f2);
    
    cliente *atual_f1 = f1->primeiro;
    cliente *atual_f2 = f2->primeiro;
    cliente *atual, *auxiliar;
    
    if(tamanho1 > tamanho2 + 2) {
        while(atual_f1->proximo->proximo != NULL) { // Busca o ultimo elemento
            atual = atual->proximo;
            if(atual->proximo->proximo->proximo == NULL)
                auxiliar = atual // Pega o penultimo
        }

        auxiliar->proximo = NULL;

        atual->proximo = NULL;
        f2->ultimo->proximo = atual;
        f2->ultimo = atual;
    }
    else {
        while(atual_f2->proximo->proximo != NULL) { // Busca o ultimo elemento
            atual = atual->proximo;
            if(atual->proximo->proximo->proximo == NULL)
                auxiliar = atual // Pega o penultimo
        }

        auxiliar->proximo = NULL;

        atual->proximo = NULL;
        f1->ultimo->proximo = atual;
        f1->ultimo = atual;
    }
}

int main() {
    struct fila fila_um, fila_dois;
    struct cliente cliente;
    char opcao, a; 
    char nome[100];
    int idade;
    
    inicializar_fila(&fila_um);
    inicializar_fila(&fila_dois);

    while(opcao != 'e') {
        printf("\n=== TERMINAL PRINCIPAL ===\n"); 
        printf("\na - Inserir cliente na fila 1\n");
        printf("b - Inserir cliente na fila 2\n");
        printf("c - Atender cliente (caixa 1)\n");
        printf("d - Atender cliente (caixa 2)\n");
        printf("e - Imprimir todos clientes na fila de espera\n");
        printf("f - Sair\n");

        printf("Insira a opcao desejada: ");
        scanf("%c", &opcao);
        scanf("%c", &a);

        switch(opcao) {
            case 'a':
                printf("\n=== FILA 1 === \n");
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                printf("Idade: ");
                scanf("%d", &idade);
                scanf("%c", &a);
                
                enfileirar(&fila_um, nome, idade);
                break;

            case 'b':
                printf("\n=== FILA 2 === \n");
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                printf("Idade: ");
                scanf("%d", &idade);
                scanf("%c", &a);
                
                enfileirar(&fila_dois, nome, idade);
                break;

            case 'c':
                if(fila_vazia(&fila_um)) {
                    printf("Sem clientes na fila!\n");
                    break;
                }
                printf("\n=== CAIXA 1 ===\n");
                printf("Cliente: %s\n\n", fila_um.primeiro->nome);
                printf("Idade: %d\n", fila_um.primeiro->idade);
                
                desenfileirar(&fila_um);
                break;
                
            case 'd':
                if(fila_vazia(&fila_dois)) {
                    printf("Sem clientes na fila!\n");
                    break;
                }
                printf("\n=== CAIXA 2 ===\n");
                printf("Cliente: %s\n", fila_dois.primeiro->nome);
                printf("Idade: %d\n", fila_dois.primeiro->idade);
                
                desenfileirar(&fila_dois);
                break;

            case 'e':
                if(fila_vazia(&fila_um) && fila_vazia(&fila_dois)) {
                    printf("Sem clientes na fila de espera!\n");
                    break;
                }    
                printf("\n=== Clientes ===\n");
                imprimir_fila(&fila_um);
                imprimir_fila(&fila_dois);
                
                break;
                
            case 'f':
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}