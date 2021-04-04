// Exercicio5_BruteForceClosestPair.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <iomanip> //afeta o estado de objetos iostream
#include <math.h>

struct Ponto //estrutura para definir os pontos 
{
    float x, y;
};


float dist(Ponto p1, Ponto p2) //função que calcula a distancia entre dois pontos
{
    float distancia;
    distancia = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return distancia;
}

float minimo(float d1, float d2) // determina o menor entre dois valores
{
    return (d1 < d2) ? d1 : d2;
}

void Brute_Force_Closest_Pair(Ponto P[], int num_elem) //Brute Force Closest Pair: encontra em um conjuto de pontos os pares mais próximos
{
    int n = num_elem; //numero de pontos
    float d = INFINITY; //d tem que ser um número grande (tender ao infinito)
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            d = minimo(d, dist(P[i], P[j]));
            std::cout << "distancia ponto " << i+1 << " para o ponto " << j+1 << ": " << dist(P[i], P[j]) << std::endl;
        }
    }
    std::cout << "A distancia minima e de:" << d << std::endl;
}

int main()
{
    //Ponto point[] = { {4,6}, {5,4}, {2,3}, {2,5}, {9,8}, {7,7}, {3,10}, {6,1}, {6,4} };
    Ponto point[] = { {-2.7,5}, {3,12}, {5,6}, {10,2}, {15,5}, {17,1}, {3,23}, {-3,9}, {11,8}, {-5,4} };
    std::cout << std::fixed << std::setprecision(2); // número de casas decimais exibidas

    int n = sizeof(point) / sizeof(point[0]);
    Brute_Force_Closest_Pair(point, n);
    
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
