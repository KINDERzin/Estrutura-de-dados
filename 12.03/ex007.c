// Faça um algoritmo que receba valores enquanto 
// forem diferntes de 0 e mostre se eles são primos ou não.


int main()
{
    int entrada = 1;
    int quantidade_div = 0;
    int valida = 0;
    
    while (entrada != 0)
    {
        printf("Digite um numero: ");
        scanf("%d", &entrada);

        if(entrada == 0)
            break;
            
        for (int i = 1; i <= entrada; i++)
            if (entrada % i == 0)
                quantidade_div++;

        valida = quantidade_div <= 2 ? 1 : 0;

        printf("%s", valida == 1 ? "Eh primo\n" : "Nao eh primo\n");

        quantidade_div = 0;
        valida = 0;
    }
}