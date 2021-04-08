// Exercicio7_TSP.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>

int maximo(std::vector<int> max) {//função que retorna o maior número de um vetor
    int maior = 0;
    for (int i = 0; i < max.size(); i++) {
        if (max[i] > maior) { maior = max[i]; }
    }
    return maior;
}

template <typename T>
void print_vector(std::vector<T>& v) {//função para imprimir um vetor
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
}


void perm(std::vector<int>& ca, std::vector<int>& v, std::vector<std::vector<int>>& d)
{
    if (v.empty()) { // se v estiver vazio, significa que, para aquele caminho, todas as cidades foram visitadas e podemos exibir a permutação
        int soma = 0;
        for (int i = 0; i < ca.size() - 1; i++) {
            soma += d[ca[i]][ca[i + 1]];//soma das distancias escolhendo o caminho atual
            //Exemplo: ca = {2,1,3,0,4} -> soma(i=0) = d[ca[0]][ca[1]] = d[2][1] = 8
        }
        std::cout << "Distancia passando pelo caminho ";
        print_vector(ca);
        std::cout << " eh igual a: " << soma << std::endl;

    }
    else {
        for (int i = 0; i < v.size(); i++) {
            std::vector<int> caminho(ca);
            caminho.push_back(v[i]);

            std::vector<int> visitar(v);
            visitar.erase(visitar.begin() + i);

            perm(caminho, visitar, d);
        }
    }

}

void TSP(std::vector<int>& x, int fix, std::vector<std::vector<int>>& d) //fix é a cidade de inicio
{
    int n = x.size();
    std::vector<int> caminho_atual = { fix };// começa com fix que é a cidade de origem
    std::vector<int> visitar;

    //armazena todas as cidades diferentes da origem (fix)
    for (auto i = x.begin(); i < x.end(); i++) {
        if ((*i) != fix) {
            visitar.push_back(*i);
        }
    }
    perm(caminho_atual, visitar, d); //função recursiva que gera as permutações e retorna as distancias para cada caminha
}


int main()
{
    int inicio = 2;
    std::vector<int> cidades = { 0,1,2,3,4 };
    std::vector<std::vector<int>> dist = { {0,2,5,7,6},
                                           {2,0,8,3,4},
                                           {5,8,0,2,3},
                                           {7,3,2,0,1},
                                           {6,4,3,1,0} };

    //Problema do caixeiro viajante: saindo do Ponto "inicio" e voltando para o ponto "inicio" passar por um mesmo vértice
    TSP(cidades, inicio, dist);
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
