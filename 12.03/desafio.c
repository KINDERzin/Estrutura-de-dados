int main()
{
    int quantidade_linhas;
    int qtd_num, qtd_esp;
    printf("=== APENAS NUMEROS IMPARES ===");
    printf("Digite quantas linhas tera a piramide: ");
    scanf("%d", quantidade_linhas);

    for (int i = 1; i <= quantidade_linhas; i++)
    {
        qtd_num = i;
        qtd_esp = quantidade_linhas - qtd_num;
        for (int j = 1; j <= qtd_esp/2; j++)
            printf("  ");
        for (int j = 1; j <= qtd_num; j++)
            printf("0 ");
        for (int j = 1; j <= qtd_esp/2; j++)
            printf("  ");
        printf("\n");
    }
}