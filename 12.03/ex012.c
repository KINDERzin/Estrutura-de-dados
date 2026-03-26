int main()
{
    int vetor_1[5];
    int vetor_2[5];
    int vetor_3[10];
    int a = 0;

    printf("Preenchendo o primeiro vetor\n");
    for(int i = 0; i < 5; i++)
    {
        printf("Posicao %d: ", i + 1);
        scanf("%d", &vetor_1[i]);
    }

    printf("\nPreenchendo o segundo vetor\n");
    for(int i = 0; i < 5; i++)
    {
        printf("Posicao %d: ", i + 1);
        scanf("%d", &vetor_2[i]);
    }

    printf("Agora, vamos misturar o dois vetores intecalando os numeros\n");

    for(int i = 0; i < 10; i+=2)
    {
        vetor_3[i] = vetor_1[a];
        vetor_3[i + 1] = vetor_2[a];
        
        // Debug com base no vetor_1
        printf("\n====DEBUG====\n");
        printf("Valor do vetor_1 na posicao %d: %d\n", a + 1, vetor_1[a]);
        printf("Valor de vetor_3 na posicao %d: %d", i + 1, vetor_3[i]);
        // Debug com base no vetor_2
        printf("\n====DEBUG====\n");
        printf("Valor do vetor_2 na posicao %d: %d\n", a + 1, vetor_2[a]);
        printf("Valor de vetor_3 na posicao %d: %d", i + 2, vetor_3[i + 1]);
        
        a++;
    }

    printf("\n\n=== Resultado da intercalacao dos numeros ===\n");
    for(int i = 0; i < 10; i++)
        printf("%d ", vetor_3[i]);
}