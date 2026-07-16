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

int filas_iguais(struct fila *f1, struct fila *f2) {
    pessoa *p_f1 = f1->primeiro;
    pessoa *p_f2 = f2->primeiro;
    int boolean;
    
    if(p_f1 == NULL && p_f2 == NULL)
        return 1;

    if(strcmp(f1->ultimo->nome,   f2->ultimo->nome)   != 0 ||
       strcmp(f1->primeiro->nome, f2->primeiro->nome) != 0 ||
       f1->ultimo->idade   != f2->ultimo->idade  ||
       f1->primeiro->idade != f2->primeiro->idade)
        return 0;
    
    while(p_f1 != NULL && p_f2 != NULL) {
        
        if(strcmp(p_f1->nome, p_f2->nome) != 0 || p_f1->idade != p_f2->idade)
            return 0;
            
        desenfileirar(f1);
        desenfileirar(f2);
        
        p_f1 = f1->primeiro;
        p_f2 = f2->primeiro;

    }
    
    return 1;
}

int main() {
    struct fila fila1;
    struct fila fila2;
    struct pessoa pessoa;
    
    int opcao;
    char gambiarra;
    char nome[20];
    int idade;

    inicializar_fila(&fila1);
    inicializar_fila(&fila2);

    do {
        printf("\n=== TERMINAL PRINCIPAL ===\n\n");
        printf("1 - Enfileirar (fila 1)\n");
        printf("2 - Enfileirar (fila 2)\n");
        printf("3 - Comparar filas\n");
        printf("4 - Mostrar filas\n");
        printf("0 - Sair\n");
        
        printf("Insira a opcao desejada: ");
        printf("Opção: ");
        scanf("%d", &opcao);
        scanf("%c", &gambiarra);

        switch(opcao) {
            case 1:
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                printf("Idade: ");
                scanf("%d", &idade);

                enfileirar(&fila1, nome, idade);
                break;
                
            case 2:
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                printf("Idade: ");
                scanf("%d", &idade);

                enfileirar(&fila2, nome, idade);
                break;
                
            case 3:
                if(filas_iguais(&fila1, &fila2))
                    printf("As filas são iguais");
                else
                    printf("As filas não são iguais");
                break;

            case 4:
                printf("\n=== FILA 1 ===\n");
                if(fila_vazia(&fila1))
                    printf("Fila vazia!\n");
                else
                    imprimir_fila(&fila1);
                    
                printf("\n=== FILA 2 ===\n");
                if(fila_vazia(&fila2))
                    printf("Fila vazia!\n");
                else
                    imprimir_fila(&fila2);

                break;

            case 0: 
                printf("Saindo...");
                break;
        }
    } while(opcao != 0);
}