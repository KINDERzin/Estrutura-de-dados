typedef struct pessoa {
    int idade;
    char nome[20];
    struct pessoa *proximo;
} pessoa;

typedef struct fila {
    struct pessoa *primeiro;
    struct pessoa *ultimo;
} fila; 

typedef struct pilha {
    int quantidade;
    struct pessoa *topo;
} pilha;

void inicializar_fila(struct fila *f) {
    f->primeiro = NULL;
    f->ultimo   = NULL;
}

void inicializar_pilha(struct pilha *p) {
    p->quantidade = 0;
    p->topo = NULL;
}

int fila_vazia(struct fila *f) {
    return (f->primeiro == NULL && f->ultimo == NULL);
}

int pilha_vazia(struct pilha *p) {
    return p->quantidade == 0 && p->topo == NULL;
}

void enfileirar(struct fila *f, char nome[], int idade) {
    pessoa *atual = (pessoa *) malloc(sizeof(pessoa));

    strcpy(atual->nome, nome);
    atual->idade = idade;
    atual->proximo = NULL;
    
    if(fila_vazia(f)) {
        f->primeiro = atual;
        f->ultimo = atual;
        return;
    }
        f->ultimo->proximo = atual;
        f->ultimo = atual;
}

void empilhar(struct pilha *p, struct pessoa *atual) {
    atual->proximo = p->topo;
    p->topo = atual;
    p->quantidade++;
}

void desenfileirar(struct fila *f) {
    if(fila_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    } 
    
    pessoa *atual = f->primeiro;

    if(f->primeiro == f->ultimo) {
        inicializar_fila(f);
        free(atual);
        return;
    }

    f->primeiro = atual->proximo;
    free(atual);
}

void imprimir_fila(struct fila *f) {
    if(fila_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    }    

    pessoa *atual = f->primeiro;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("Idade: %d\n", atual->idade);

        atual = atual->proximo;
    }
}

void imprimir_pilha(struct pilha *p) {
    if(pilha_vazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }    

    pessoa *atual = p->topo;
    while(atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        atual = atual->proximo;
    }
}

void ordenar_fila(struct fila *f, struct pilha *p) {
    struct pessoa *atual = f->primeiro;
    struct pessoa *auxiliar = NULL;
    struct pessoa *prox;

    while(atual != NULL) {
        prox = atual->proximo;

        if(atual->idade <= 70) {
            if(atual == f->primeiro)
                f->primeiro = atual->proximo;
            else
                auxiliar->proximo = atual->proximo;

            if(atual == f->ultimo)
                f->ultimo = auxiliar;

            empilhar(p, atual);
        }
        else
            auxiliar = atual;

        atual = prox;
    }
}

int main() {
    struct fila fila;
    struct pilha prioridade;
    
    int opcao;
    char gambiarra;
    char nome[20];
    int idade;

    inicializar_fila(&fila);
    inicializar_pilha(&prioridade);

    do {
        printf("\n=== TERMINAL PRINCIPAL ===\n\n");
        printf("1 - Enfileirar\n");
        printf("2 - Mostrar fila\n");
        printf("3 - Ordenar fila\n");
        printf("0 - Sair\n");
        
        printf("Insira a opcao desejada: ");
        scanf("%d", &opcao);
        scanf("%c", &gambiarra);

        switch(opcao) {
            case 1:
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Idade: ");
                scanf("%d", &idade);

                enfileirar(&fila, nome, idade);
                break;
                
            case 2:
                printf("\n=== PRIORIDADE ===\n");
                imprimir_pilha(&prioridade);
                
                printf("\n=== FILA ===\n");
                imprimir_fila(&fila);
                break;

            case 3:
                if(fila_vazia(&fila)) {
                    printf("A fila está vazia!\n");
                    break;
                }    
                
                ordenar_fila(&fila, &prioridade);
                break;
            case 0: 
                printf("Saindo...");
                break;
        }
    } while(opcao != 0);

    return 0;
}