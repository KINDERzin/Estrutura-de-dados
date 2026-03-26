float CalculaMedia(float notas[4])
{
    float Soma_Notas = 0;

    for(int i = 0; i < 4; i++)
        Soma_Notas+=notas[i];

    return Soma_Notas / 4.0;
}

typedef struct Aluno
{
    char Nome[100];
    float Notas[4];
} aluno;

int main()
{
    aluno Estudantes[6];
    float Maior_Media = 0;
    float Media_Atual;
    char Aluno_Maior_Media[100];
    printf("Cadastrando notas dos alunos...\n");

    for(int i = 0; i < 6; i++)
    {
        printf("Nome do aluno: ");
        fgets(Estudantes[i].Nome, 100, stdin);
        for(int j = 0; j < 4; j++)
        {
            printf("Nota %.2d: ", j + 1);
            scanf("%f", &Estudantes[i].Notas[j]);
            while(getchar() != '\n');
        }

        Media_Atual = CalculaMedia(Estudantes[i].Notas);
        if(Media_Atual > Maior_Media)
        {
            Maior_Media = Media_Atual;
            strcpy(Aluno_Maior_Media, Estudantes[i].Nome);
        }
    }
    printf("===ATENCAO===");
    printf("O aluno com a maior media eh o(a) %s, com %.2f de media!\n", Aluno_Maior_Media, Maior_Media);
}