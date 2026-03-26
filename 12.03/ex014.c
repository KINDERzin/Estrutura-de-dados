typedef struct Carro
{
    char Nome[30];
    float Preco;
} carro;

int main()
{
    carro Veiculo[5];

    printf("Vamos preencher nosso vetor de carros com 5 veiculos.\n");

    for(int i = 0; i < 5; i++)
    {
        printf("\n=== Veiculo %d ===\n", i + 1);
        printf("Insira o nome do veiculo: ");
        fgets(Veiculo[i].Nome, 30, stdin);
        printf("Insira o valor do veiculo: ");
        scanf("%f", &Veiculo[i].Preco);
        // Ele encontra o \n e não deixa ele pra fora, aí nao buga o terminal
        while (getchar() != '\n');
    }

    printf("\nVeiculos cadastrados!\n\n");

    for(int i = 0; i < 5; i++)
    {
        printf("\n===VEICULO %d===\n", i + 1);
        printf("Nome: %s", Veiculo[i].Nome);
        printf("Preco: %.2f\n", Veiculo[i].Preco);
    }
}