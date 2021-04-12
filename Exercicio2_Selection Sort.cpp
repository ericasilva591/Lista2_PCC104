// Exercicio2_Selection Sort.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//


#include <iostream>
#include <vector>

template <typename T>
void imprime_vetor(std::vector<T>& v) {//função para imprimir um vetor
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
}

template <typename T>
void selection_sort(std::vector<T>& V)
{
    int i, j;
    int min = 0;
    for (i = 0; i < size(V) - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size(V); j++)
        {
            if (V[j] < V[min]) // verifica qual o menor número do vetor e troca com o primeiro
            {
                min = j;
            }
            std::swap(V[i], V[min]);

        }
    }
}

int main()
{
    //Exemplo com entrada de inteiros
   std::vector<int> vetor_in = { 10,7,55,23,24,10,11,8,19,50,-2};
    
    //Exemplo com entrada de string
    //std::vector<std::string> vetor_in = { "gadf","eadf","etdf","hfaf","naw","aqdd","raf","fbf","zaf","ado"};
   
    //Exemplo com entrada de double
    //std::vector<float> vetor_in = { 11.4,312.54,34.0,2.3,6.75,89.4,23.5,5.65,65.4,8.43};
    
    std::cout << "Arranjo nao ordenado:";
    imprime_vetor(vetor_in);
    selection_sort(vetor_in);
    std::cout << "Arranjo ordenado:";
    imprime_vetor(vetor_in);


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
