// Faça um algoritmo que receba dois valores a e b, e mostre a
// soma de todos os valores entre eles, por exemplo: a = 5, b = 10, resultado: 45

int main()
{
    int a;
    int b;
    int soma = 0;

    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite outro numero: ");
    scanf("%d", &b);

    if( a < b)
        for(; a <= b; a++)
            soma+=a;
    else
        for(; b <= a; b++)
            soma+=b;

    printf("A soma dos numeros entre os inseridos eh: %d", soma);
}