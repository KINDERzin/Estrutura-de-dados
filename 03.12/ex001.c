// Desenvolva um algoritmo em C que receba o peso e altura
// de uma pessoa e calcule o seu imc (peso / altura²)

int main()
{
    float peso;
    float altura;
    float imc = peso / pow(altura, 2);
    
    printf("Digite o seu peso: ");
    scanf("%f", &peso);
    printf("Digite sua altura: ");
    scanf("%f", &altura);
    
    imc = peso / pow(altura, 2);
    
    printf("Seu IMC eh: %.2f", imc);
}