typedef struct celula {
    int codigo, idade;
    char nome[20];
    struct celula *prox; // Aponta pra proxima celula
} celula;

typedef struct {
    celula *primeiro;
    celula *ultimo;
} tipo_lista;

void create_list(tipo_lista *l) {
    l->primeiro = NULL; // Primeiro lugar = NULL
    l->ultimo = NULL; // Último lugar = NULL
}

int empty_list(tipo_lista *l) {
    // Retorna 1 se verdadeiro e 0 se for falso
    return l->primeiro == NULL;
}

void insert_end(celula c, tipo_lista *l) {
    // aponta o endereço
    celula *newGuy = (celula*) malloc(sizeof(celula));
    // pega as variaveis de "newGuy" e atribui o valor de "c" a elas
    *newGuy = c;
    newGuy->prox = NULL;

    if(empty_list(l)) {
        // "l" e "newGuy" apontam o endereço, logo 
        l->primeiro = newGuy;
        // atualiza o ultimo case a lista esteja vazia
        l->ultimo = newGuy;
    }
    else {
        // pega o ultimo da fila e atribui o "prox" ao newGuy
        l->ultimo->prox = newGuy;
        l->ultimo = newGuy;
    }

}

void show_list(tipo_lista *l) {
    celula *c = l->primeiro;
    while(c != NULL) {
        printf("Codigo: %d\n", c->codigo);
        c = c->prox;
    }
}

int main() {
    tipo_lista lista;
    celula cel;
    // Passa o endereço de "lista"
    create_list(&lista);

    cel.codigo = 2;
    insert_end(cel, &lista);
    cel.codigo = 3;
    insert_end(cel, &lista);
    show_list(&lista);
}