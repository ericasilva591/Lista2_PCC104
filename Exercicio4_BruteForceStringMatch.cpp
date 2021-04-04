// Exercicio4_BruteForceStringMatch.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <conio.h>

void string_match(std::string T, std::string P) //StringMatch: encontrar um padrão no texto e retorna a posição inicial deste padrão
{
    int i;
    int m, n;
    n = T.length();
    m = P.length();
    for (i = 0; i <= n - m; i++)
    {
        int j = 0;
        while ((j < m) && (P[j] == T[i + j]))
        {
            j++;
        }
        if (j == m)
        {
            std::cout << "O index do padrao e:" << i + 1 << std::endl;
        }
    }
}

int main()
{
    //Exemplo de texto e padrão
    std::string texto = { "AASDCD ABCDAABHA JNA AJKNAABKSJJABC HAVSHGSVSHHA ABC HAUHISNNISOA OOJABCOAHOHO ABC" };
    std::string padrao = { "ABC" };
     
    std::cout <<"Texto: " << texto << std::endl;
    string_match(texto, padrao);

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
