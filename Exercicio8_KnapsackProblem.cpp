// Exercicio8_KnapsackProblem.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>
#include <list>
#include <bitset>

int maximo(std::vector<int> max){
    int maior = 0;
    for (int i = 0; i < max.size(); i++) {
        if (max[i] > maior) { maior = max[i]; }
    }
    return maior;
}

int gera_numcomb(int numitens){
    int bin = 1;
    for (int i = 1; i <= numitens; i++) { bin *= 2; }
    return bin;
}

int knapsack(int max_peso, int numitens, std::vector<int> w, std::vector<int> v)
{
    int comb = gera_numcomb(numitens);
    int val = 0;
    int peso = 0;
    std::vector<int> valores, itens;
    
    for (int i = 0; i < comb; i++) {
        std::bitset<4> aux (i); //gera o numero i em binário - se a lista de itens mudar é necessário modificar esse parâmetro manualmente
        for (int j = 0; j < numitens; j++) {
            val += aux[j] * v[j];
            peso += aux[j] * w[j];
        }
        if (peso <= max_peso){
            valores.push_back(val);
            std::cout << " Itens na mochila: ";
            for (int j = 0; j < numitens; j++) {
                if (aux[j]){ std::cout << j+1 << "; "; }
            }
            std::cout <<"->"<< " Valor Total: "<< val<< "| Peso Total: " <<peso<< std::endl;
        }
        val = 0;
        peso = 0;
    }
    std::cout << std::endl;
    return maximo(valores);
    
}


int main()
{
    std::vector<int> w{ 2,4,5,6 }, v{ 23,56,78,12 };
    int peso_max = 15;
    int num_itens = w.size();

    std:: cout << "O maior valor que a mochila pode como peso maximo de "<< peso_max<<" eh: " << knapsack(peso_max, num_itens, w, v);
    std::cout << std::endl;
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
