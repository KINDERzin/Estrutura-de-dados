#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ContadorDeVogais(char palavra[101])
{
    int contador = 0;
    // Deixa todas as letras minusculas
    char palavra_formatada = tolower(palavra);
    //Mostra a quandidade de letras
    printf("\n===DEBUG===\n");
    printf("Esta palavra tem %d letras.\n\n", strlen(palavra));
    
    // Eh mais viavel guardar o tamanho da palavra em uma variavel
    // int tamanho = strlen(palavra)
    for(int i = 0; i < strlen(palavra); i++)
        if(palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u')
            contador++;    
    
    return contador;
}

int main()
{
    char nome[101];

    printf("Insira seu nome: ");
    fgets(nome, 101, stdin);

    printf("\nSeu nome tem %d vogais.", ContadorDeVogais(nome));
}