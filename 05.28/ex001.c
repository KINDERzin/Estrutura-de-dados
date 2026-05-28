# include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct site {
    char url[100];
    struct celula* proximo; // anterior (n - 1)   
} site;

typedef struct pilha {
    int quantidade;
    struct celula* topo;
}pilha;

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

void empilhar(pilha *p, char url[100]) {
    site *atual = (site*) malloc(sizeof(site));

    strcpy(atual-url, url);
    atual->proximo = p->topo;
    p->topo = atual;
    p->quantidade++;
}

void desempilhar(pilha *p) {
    if(pilha_vazia(p))
        return;

    site *atual = p->topo;

    p->topo = atual->proximo;
    free(atual);
    p->quantidade--;
}

void limpar_pilha(pilha *p) {
    site *atual = p->topo;
    site *proximo;
    
    while(atual != NULL)
    {
        proximo = atual->proximo;
        free(atual);        
        atual = proximo;
    }
}

void visitar(pilha *h, pilha *f, char url[100]) {
    empilhar(h, url);
    limpar_pilha(f);
}

void avancar(pilha *h, pilha *f) {
    desempilhar(f);
    empilhar(h);
}

void voltar(pilha *p) {

}

int main() {
    pilha futuro;
    pilha historico;
    site s;

    criar_pilha(&futuro);
    criar_pilha(&historico);


}