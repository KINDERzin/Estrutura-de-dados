int main()
{
    int tamanho_matriz;

    printf("Insira o tamanho da matriz nxn: ");
    scanf("%d", &tamanho_matriz);

    int matriz[tamanho_matriz][tamanho_matriz];

    for (int i = 0; i < tamanho_matriz; i++)
        for (int j = 0; j < tamanho_matriz; j++)
        {
            printf("Posicao %dx%d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }

    printf("\n\n=== Printando a matriz ===\n");
    for (int i = 0; i < tamanho_matriz; i++)
    {
        for (int j = 0; j < tamanho_matriz; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}