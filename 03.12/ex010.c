int main()
{
    int vetor[10];
    int a = 1;

    for(int i = 0; i < 10; i++)
    {
        printf("Digite um numero para preencher o vetor: ");
        scanf("%d", &vetor[i]);
    }

    printf("\n\n=== Numeros pares do vetor ===\n");
    for(int i = 0; i < 10; i++)
        if(vetor[i] % 2 == 0)
        {
            printf("%dº: %d\n", a, vetor[i]);
            a++;
        }
}