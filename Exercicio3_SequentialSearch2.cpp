// Exercicio3_SequentialSearch2.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
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
void sequential_search(std::vector<T> V, T senha)
{
    v.push_back(senha);
    int i = 0;
    while (v[i] != senha) // compara uma senha com os elementos do vetor e retorna a posição em que a senha se encontra
    {
        i++;
    }
    if (i < v.size())
    {
        std::cout << "Senha encontrada na posicao:" << i;
    }
    else
        std::cout << "Senha nao encontrada";

int main()
{
    //Exemplo com entrada de inteiros
    std::vector<int> vetor_senhas = { 10,7,55,23,24,10,11,8,19,50 };
    int senha = 19;
    
    //Exemplo com entrada de string
    //std::vector<std::string> vetor_senhas = { "gadf","eadf","etdf","hfaf","naw","aqdd","raf","fbf","zaf","ado" };
    //std::string senha = "fbf";
    
    //Exemplo com entrada de double
    //std::vector<float> vetor_senhas = { 11.4,312.54,34.0,2.3,6.75,89.4,23.5,5.65,65.4,8.43 };
    //float senha = 2.3;


    std::cout << "Arranjo de senhas:";
    imprime_vetor(vetor_senhas);
    sequential_search(vetor_senhas, senha);

   
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
