// Exercioco6_ConvexHull.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <iomanip> //afeta o estado de objetos iostream
#include <math.h>
#include <vector>

struct Ponto //estrutura para definir os pontos 
{
    float x, y;
};

float funcao_dist(Ponto p1, Ponto p2, Ponto p3) //função que determina que posição p3 está em retação a reta formada por dois pontos(p1 e p2)
{
    float a, b, c;
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = p1.x * p2.y - p1.y * p2.x;
           
    if ((a * p3.x + b * p3.y) > c) return 1;
    else if ((a * p3.x + b * p3.y) == c) return 0;
    else return -1;
    
}

void convex_hull(Ponto P[], int n)
{
    int i, j, k;
    std::vector<int> aux = {}; // vetor auxiliar que armazena o resultado da funcao(Ponto p1, Ponto p2, Ponto p3)
    
    for (i = 0; i < n; i++) //Fixa o primeiro ponto que faz parte da reta
    {
        for (j = i + 1; j < n; j++) //Fixa o segundo ponto que faz parte da reta
        {
            int flag1 = 0;
            int flag2 = 0;
            int flag3 = 0;
            aux.clear();
            for (k = 0; k < n; k++) //Fixa o terceiro ponto para fazer a comparação se está acima ou abaixo da reta
            {
                aux.push_back(funcao_dist(P[i], P[j], P[k])); // se aux for todo composto de 0 e 1 ou 0 e -1 é um ponto externo.

                //Linha para conferencia dos vetores auxiliares computados:
                //std::cout << "reta: " << i << " e " << j << "comparacao com ponto: " << k << "resultado=" << aux[k] << ", " << std::endl;
                if (aux[k] == 1) { flag1++; } // conta quantos 1 o vetor tem
                else if (aux[k] == -1) { flag2++; } // conta quantos -1 o vetor tem
                else { flag3++; } // conta quantos 0 o vetor tem

            }
            //Monitora os valores das flags:
            //std::cout << flag1 << " " << flag2 << " " << flag3 << std::endl;
            if ((flag1 + flag3) >= n || (flag2 + flag3) >= n)// se o somatório de 1s e 0s for n ou o somatório de -1s e 0s for n o par de pontos é uma aresta do casco convexo
            {
                //mostra ao usuário quais os pares de pontos formam uma aresta do casco convexo
                std::cout << "A ligacao dos pontos: " << "{" << P[i].x << "," << P[i].y << "}" << " com " << "{" << P[j].x << "," << P[j].y << "}" << " forma uma das arestas do casco convexo" << std::endl;

            }
            else continue; //do contrario o vetor auxiliar tem 3 elementos diferente e o par de pontos não forma uma aresta do casco convexo

        }

    }
}

int main()
{
    Ponto point[] = { {4,6}, {5,4}, {-2,2}, {2,5}, {9,8}, {7,7}, {3,10}, {6,1}, {6,4} };

    int point_num = sizeof(point) / sizeof(point[0]);; //numero de pontos
    std::cout << std::fixed << std::setprecision(1); // número de casas decimais

    convex_hull(point, point_num);

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
