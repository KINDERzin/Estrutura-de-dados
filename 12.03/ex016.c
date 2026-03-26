int main()
{
    int Horario1;
    int Horario2;
    int Horario_Final;
    
    printf("===SOMA DE HORARIOS===\n");
    printf("Digite um horario em segundos: ");
    scanf("%d", &Horario1);
    printf("Digite outro horario em segundos: ");
    scanf("%d", &Horario2);

    Horario_Final = Horario1 + Horario2;

    printf("===HORARIO===");
    printf("\nO resultado da soma dos horarios eh: %d:%d:%d", Horario_Final / 3600, (Horario_Final % 3600) / 60, Horario_Final % 60);
}
