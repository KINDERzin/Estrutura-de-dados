// Desenvolva um algoritmo em C que receba o salário de
// uma pessoa e calcule o o valor de IR a ser pago conforme a tabela:
//  - Até 3000: Isento
//  - > 3000 <= 5000: 5%
//  - > 5000 <= 8000: 10%
//  - > 8000 <= 12000: 15%
//  - > 12000: 20%


int main()
{
    float salario;
    float imposto;

    scanf("%f", &salario);

    if( salario < 3000)
        imposto = 0;
    else if(salario > 3000 && salario < 5000)
        imposto = 0.05;
    else if(salario > 5000 && salario < 8000)
        imposto = 0.1;
    else if(salario > 8000 && salario < 12000)
        imposto = 0.15;
    else 
        imposto = 0.2;

    float ir = salario * imposto;

    printf("%.2f", ir);
}