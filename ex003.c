// Desenvolva um algoritmo em C que receba um dia de 1 a 7
// e mostre o nome do dia da semana, por exemplo: 3: Terça-feira, 7: Sábado.

int main()
{
    int diaSemana;

    printf("Digite o dia da semana: ");
    scanf("%d", &diaSemana);

    switch (diaSemana)
    {
        case 1:
            printf("Segunda-Feira");
            break;
        case 2:
            printf("Terca-Feira");
            break;
        case 3:
            printf("Quarta-Feira");
            break;
        case 4:
            printf("Quinta-Feira");
            break;
        case 5:
            printf("Sexta-Feira");
            break;
        case 6:
            printf("Sabado");
            break;
        case 7:
            printf("Domingo");
            break;

        default:
            break;
    }
}