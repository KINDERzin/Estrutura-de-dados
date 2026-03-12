// Faça um algoritmo para verificar se um número é triangular.
// Um número é triangular quando é resultado do produto de três 
// números consecutivos. Exemplo: 24 = 2 x 3 x 4.


int main()
{
    int entrada;
    int valida = 0;
    int a = 1, b, c;
    
    b = a + 1;
    c = b + 1;
    
    printf("Digite um numero: ");
    scanf("%d", &entrada);

    while (a * b * c <= entrada)
    {
        if (entrada == a * b * c)
        {
            printf("%d * %d * %d = %d\n", a, b, c, a*b*c);
            valida = 1;
            break;
        }
        
        a++;
        b = a + 1;
        c = b + 1;
    }
        
    printf("%s\n", valida == 1 ? "Eh triangular" : "Nao eh triangular");

    a = 1;
}