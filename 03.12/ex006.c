// Faça um algoritmo que receba valores enquanto forem 
// diferentes de 0. Ao final, deve-se mostrar a quantidade
// de números positivos e negativos, o maior, o menor, e a média entre positivos.


int main()
{
    int entrada;
    int quantidade_pos = 0;
    int quantidade_neg = 0;
    int maior = 0;
    int menor = 0;
    float media_pos = 0;

    while (entrada != 0)
    {
        printf("Digite um numero: ");
        while (scanf("%d", &entrada) != 1)
        {
            scanf("%d", &entrada);
        }

        if (entrada > 0)
        {
            media_pos+=entrada;
            quantidade_pos++;
        }
        else if (entrada < 0)
            quantidade_neg++;

        // Verifica o maior
        maior = maior < entrada ? entrada : maior;
        // Verifica o menor
        menor = menor > entrada ? entrada : menor;
    }

    media_pos= media_pos/quantidade_pos;

    printf("Quantidade de numeros positivos: %d\n", quantidade_pos);
    printf("Quantidade de numeros negativos: %d\n", quantidade_neg);
    printf("Maior numero digitado: %d\n", maior);
    printf("Menor numero digitado: %d\n", menor);
    printf("Media dos numeros positivos: %.2f\n", media_pos);
}