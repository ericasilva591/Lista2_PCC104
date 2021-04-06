// Exercicio10_BuscaProfundidade.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm> //usar a função find

class Grafo {
    int numvertice;
    std::list<int>* lista_adj; //para cada vertice tem um ponteiro apontando para uma lista de vertices adjacente a ele
    bool* busca;

public:
    Grafo(int numvertice); //construtor do grafo que vai receber o número de vertices
    void add_arestas(int vertice1, int vertice2); //adiciona uma aresta ligando vertice1 ao vertice2
    bool verifica_adj(int vertice1, int vertice2); //verifica se vertice2 é vizinho de vertice1
    void Busca_Profundidade(int vertice_inicio); //função que faz a busca em profundidade no grafo e retorna os vertices na ordem em que foram visitados
};

Grafo::Grafo(int vertice)
{
    numvertice = vertice; //defini o numero de vértices que o grafo vai ter
    lista_adj = new std::list<int>[vertice]; //cria uma lista de adjacencia para cada vertice
}

void Grafo::add_arestas(int vertice1, int vertice2)
{
    lista_adj[vertice1].push_back(vertice2);// adiciona vertice2 na lista de adjacencia de vertice1
    lista_adj[vertice2].push_back(vertice1);// adiciona vertice1 na lista de adjacencia de vertice2

}

bool Grafo::verifica_adj(int vertice1, int vertice2)
{
    // verifica se o vertice2 está na lista de adjacencia do vertice1, se sim retorna true
    if (find(lista_adj[vertice1].begin(), lista_adj[vertice1].end(), vertice2) != lista_adj[vertice1].end())
        return true;
    else return false;
}

void Grafo::Busca_Profundidade(int vertice_inicio)
{
    busca = new bool[numvertice]; // cria uma lista de ponteiros com numvertice elementos que armazena se um vertice[X] foi visitado ou não
    std::stack<int> list_vertice; //pilha de vertices visitados - metotodologia FiFO
    std::list<int>::iterator i; //iterador de busca nas listas de adjacencias dos vertices

    for (int j = 0; j < numvertice; j++) { busca[j] = false; } //preenche a lista com falso já que nenhum vertice foi visitado ainda
    while (true)
    {
        if (!busca[vertice_inicio])// se o status do vertice de inicio foi 0, marca o vertice como visitado e coloca ele na pilha
        {
            std::cout << "Vertice visitado " << vertice_inicio << " " << std::endl;
            busca[vertice_inicio] = true;
            list_vertice.push(vertice_inicio); //adiciona à pilha o primeiro vertice visitado que é o de inicio
        }

        bool achou = false; //flag auxiliar que verifica se algum vertice adjacente a vertice_inicio ainda não foi visitado
        for (i = lista_adj[vertice_inicio].begin(); i != lista_adj[vertice_inicio].end(); i++)
        {
            std::cout << "Vertice adjacente de " << vertice_inicio << " eh: " << *i << std::endl;
            if (!busca[*i])// se existe algum vertice adijacente de vertice_inicio que ainda não foi visitado
            {
                achou = true;// a flag vai mudar de status, 
                break;//o loop de busca nos vetores de adj de vertice_inicio vai ser interrompido para que o vertice *i seja explorado
            }
        }
        if (achou) { vertice_inicio = *i; } // vertice_inicio vai ser atualizado para a busca de profundidade ser realizada
        else 
        {
            list_vertice.pop();//todos os vertices de o vertices de vertice_inicio ja foram visitados e ele será retirado da pilha para fazer o backtracking
            if (list_vertice.empty()) break;// no momento que a pilha estiver vazia a busca terminou, pois não existe mais vértices não visitados e o break faz com que o loop acabe
            else vertice_inicio = list_vertice.top(); // do contrário a pilha não esta vazia e o vertice de inicio é atualizado para o que esta no top da pilha
        }
    }
}

int main()
{
    int numVertice = 7;
    int vertice_inicial = 4;

    Grafo grafo(numVertice); //criando um grafo de 7 vertices com os vértices {0,1,2,3,4,5,6}, consequentemente cria 7 listas de adjacencia
    grafo.add_arestas(0, 1);
    grafo.add_arestas(0, 4);
    grafo.add_arestas(0, 2);
    grafo.add_arestas(1, 2);
    grafo.add_arestas(1, 5);
    grafo.add_arestas(2, 3);
    grafo.add_arestas(3, 4);
    grafo.add_arestas(3, 6);
    grafo.add_arestas(4, 5);
    grafo.add_arestas(5, 6);
        
    grafo.Busca_Profundidade(vertice_inicial); //Faz a DSF com inicio no vértice 4

    int v1, v2;
    v1 = 1;
    v2 = 5;

    if (grafo.verifica_adj(v1, v2)) // se v1 for adjacente de v2
    {
        std::cout << std::endl << "O vertice " << v1 << " eh adjacente de " << v2 << std::endl;
    }
    else std::cout << std::endl << "O vertice " << v1 << " nao eh adjacente de " << v2 << std::endl;

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
