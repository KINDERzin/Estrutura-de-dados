// Faça um algoritmo de que mostre os valores pares de 0 a 100.

int main()
{
    printf("\n=== Numeros pares ===\n\n");
    for(int i = 0; i < 101; i++)
        if(i % 2 == 0)
            printf("%d\n", i);
}