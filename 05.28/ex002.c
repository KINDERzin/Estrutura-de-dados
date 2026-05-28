typedef struct celula {
    int numero;
    struct celula* proximo; // anterior (n - 1)   
} celula;

typedef struct pilha {
    int quantidade;
    struct celula* topo;
} pilha;

void criar_pilha(pilha *p) {
    p->quantidade = 0;
    p->topo = NULL;
}

int pilha_vazia(pilha *p) {
    return (p->topo == NULL && p->quantidade == 0);
}

int tamanho_pilha(pilha *p) {
    return p->quantidade;
}

void empilhar(pilha *p) {
    celula *atual = (celula*) malloc(sizeof(celula));

    if(pilha_vazia(p)) {
        atual->numero = 1;
        atual->proximo = NULL;
        p->topo = atual;
    }     
    else {
        atual->numero = p->quantidade + 1;
        atual->proximo = p->topo;
        p->topo = atual;
    }
    p->quantidade++;
}

pilha inverter_pilha(pilha *p) {
    pilha p_auxiliar;
    criar_pilha(&p_auxiliar);

    celula *atual = p->topo;
    celula *proximo;

    while(atual != NULL) {
        proximo = atual->proximo;
        if(pilha_vazia(&p_auxiliar)) {
            atual->proximo = NULL;
            p_auxiliar.topo = atual;
            p_auxiliar.quantidade++;
        }
        else {
            atual->proximo = p_auxiliar.topo;
            p_auxiliar.topo = atual;
            p_auxiliar.quantidade++;
        }
        atual = proximo;
    }

    p->quantidade = 0;
    p->topo = NULL;

    return p_auxiliar;
}

int main() {
    pilha p1;
    celula c;

    criar_pilha(&p1);

    printf("Alocando os valores da pilha\n");
    for(int i = 0; i < 10; i++)
        empilhar(&p1);

    printf("Mostrando pilha\n");

    celula *atual = p1.topo;
    while(atual != NULL)
    {
        printf("Pilha %d\n Proximo: %p\n", atual->numero, atual->proximo);
        atual = atual->proximo;
    }
    
    printf("\nInvertendo a ordem...\n");
    p1 = inverter_pilha(&p1);

    atual = p1.topo;
    while(atual != NULL)
    {
        printf("Pilha %d\n Proximo: %p\n", atual->numero, atual->proximo);
        atual = atual->proximo;
    }
}