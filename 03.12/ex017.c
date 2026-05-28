typedef struct Carro
{
    char marca[50];
    char modelo[50];
    int ano;
    float preco;
} Carro;

int main()
{
    int Quantidade_De_Veiculos;
    printf("Quantos veiculos deseja cadastrar? ");
    scanf("%d", &Quantidade_De_Veiculos);

    Carro *Veiculo = malloc(Quantidade_De_Veiculos * sizeof(Carro)); // Alocando espaço para a quantidade de carros especificada

    for(int i = 0; i < Quantidade_De_Veiculos; i++)
    {
        printf("\n=== Veiculo %d ===\n", i + 1);
        printf("Marca: ");
        scanf("%s", Veiculo[i].marca);
        printf("Modelo: ");
        scanf("%s", Veiculo[i].modelo);
        printf("Ano: ");
        scanf("%d", &Veiculo[i].ano);
        printf("Preco: ");
        scanf("%f", &Veiculo[i].preco);
    }

    printf("\n=== Veiculos Cadastrados ===\n");
    for(int i = 0; i < Quantidade_De_Veiculos; i++)
    {
        printf("\n=== Veiculo %d ===\n", i + 1);
        printf("Marca: %s\n", Veiculo[i].marca);
        printf("Modelo: %s\n", Veiculo[i].modelo);
        printf("Ano: %d\n", Veiculo[i].ano);
        printf("Preco: %.2f\n", Veiculo[i].preco);
    }

    free(Veiculo); // Liberando a memória alocada    
}
