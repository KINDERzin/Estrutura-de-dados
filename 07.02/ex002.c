typedef struct pessoa {
    int idade;
    char nome[20];
    struct pessoa *proximo;
} pessoa;

typedef struct fila{
    struct pessoa *primeiro;
    struct pessoa *ultimo;
} fila; 

void inicializar_fila(struct fila *f) {
    f->primeiro = NULL;
    f->ultimo   = NULL;
}

int fila_vazia(struct fila *f) {
    return (f->primeiro == NULL && f->ultimo == NULL);
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

void desenfileirar(struct fila *f) {
    if(fila_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    } 
    
    pessoa *atual = f->primeiro;

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

    pessoa *atual = f->primeiro;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("Idade: %d\n", atual->idade);

        atual = atual->proximo;
    }
}

void ordenar_fila(struct fila *f1, struct fila *f_p) {
    struct pessoa *p_f1 = f1->primeiro;
    struct pessoa *auxiliar = f1->primeiro;

    while(p_f1 != f1->ultimo) {
        if(p_f1->idade >= 70) {
            if(auxiliar == p_f1)
                auxiliar = NULL;
            else
                while(auxiliar->proximo != p_f1) {
                    auxiliar = auxiliar->proximo;
                }

            if(fila_vazia(f_p)) {
                f_p->primeiro = p_f1;
                f_p->ultimo   = p_f1;
                if(auxiliar == NULL) {
                    f1->primeiro = p_f1->proximo;
                }
                else
                    auxiliar->proximo = p_f1->proximo;
            }
            else {
                f_p->ultimo = p_f1;
                auxiliar->proximo = p_f1->proximo;
                p_f1->proximo = NULL;
            }
        }

        p_f1 = p_f1->proximo;
    }
}

int main() {
    struct fila fila;
    struct fila fila_p;
    struct pessoa pessoa;
    
    int opcao;
    char gambiarra;
    char nome[20];
    int idade;

    inicializar_fila(&fila);
    inicializar_fila(&fila_p);

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
                printf("Idade: ");
                scanf("%d", &idade);

                enfileirar(&fila, nome, idade);
                break;
                
            case 2:
                printf("\n=== PRIORIDADE ===\n");
                imprimir_fila(&fila_p);
                
                printf("\n=== FILA ===\n");
                imprimir_fila(&fila);
                break;

            case 3:
                if(fila_vazia(&fila)) {
                    printf("A fila está vazia!\n");
                    break;
                }    
                
                ordenar_fila(&fila, &fila_p);
                break;
            case 0: 
                printf("Saindo...");
                break;
        }
    } while(opcao != 0);
}