// Faça um algoritmo que receba um valor x, e mostre a 
// soma da faixa de valores de 1 a x. (Utilize recursividade).


int SomaRecursiva(int a)
{    
    if (a <= 0)
        return 0;
    
    return a + SomaRecursiva(a-1);
}

int main()
{
    int x;
    
    printf("Digite um numero: ");
    scanf("%d", &x);
    
    int soma = SomaRecursiva(x);
    
    printf("%d", soma);
}
