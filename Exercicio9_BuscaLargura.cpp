// Exercicio9_BuscaLarguara.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.

//Referências para desenvolvimento do código: https://www.youtube.com/watch?v=DYLfrmHHAm0&list=PL8eBmR3QtPL13Dkn5eEfmG9TmzPpTp0cV&index=70

#include <iostream>
#include <vector>
#include <list>
#include <algorithm> //usar a função find

class Grafo {
    int numvertice;
    std::list<int>* lista_adj; //para cada vertice tem um ponteiro apontando para uma lista de vertices adjacente a ele
    bool* busca;

public:
    Grafo(int vertice); //construtor do grafo que vai receber o número de vertices
    void add_arestas(int vertice1, int vertice2); //adiciona uma aresta ligando vertice1 ao vertice2
    bool verifica_adj(int vertice1, int vertice2); //verifica se vertice2 é vizinho de vertice1
    void Busca_Largura(int vertice_inicio); //função que faz a busca em largura no grafo e retorna os vertices na ordem em que foram visitados
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
    if(find(lista_adj[vertice1].begin(), lista_adj[vertice1].end(), vertice2) != lista_adj[vertice1].end()) 
        return true;
    else return false;
}

void Grafo::Busca_Largura(int vertice_inicio)
{
    busca = new bool[numvertice]; // cria uma lista de ponteiros com numvertice elementos que armazena se um vertice[X] foi visitado ou não
    std::list<int> list_vertice; //lista de vertices visitados
    std::list<int>::iterator i;
    
    for (int j = 0; j < numvertice; j++) { busca[j] = false; } //preenche a lista com falso já que nenhum foi visitado ainda
    
    busca[vertice_inicio] = true;
    list_vertice.push_back(vertice_inicio); //adiciona à lista o primeiro vertice visitado que é o de inicio

    while (!(list_vertice.empty())) //enquanto a lista de vertices visitados não estiver vazia e todos os vertices foram vizitados
    {
        int VerticeAtual = list_vertice.front(); //atribui o primeiro elemento da lista de vétices visitados ao vértice atual
        std::cout << "Vertice visitado " << VerticeAtual << " " << std::endl;
        list_vertice.pop_front(); //apaga o primeiro elemento da lista de visitados
        
        for (i = lista_adj[VerticeAtual].begin(); i != lista_adj[VerticeAtual].end(); i++)
        {
            std::cout << "Vertice adjacente de " << VerticeAtual << " eh: " << *i << std::endl;
            int vertice_adjacente = *i; //vertice adjacente do vértice atual recebe a cada iteração um elemento da lista de adjacencia de vertice atual
            if (!busca[vertice_adjacente])//se o vertice adjacente i não foi visitado (busca[]=0)
            {
                list_vertice.push_back(vertice_adjacente);//vou adicionar o vertice a lista de visitados
                busca[vertice_adjacente] = true; //marco o vertice como visitado
            }
        }
    }

}

int main()
{
    int num_vertice = 7;
    int vertice_inicio = 4;
    
    Grafo grafo(num_vertice); //criando um grafo de 7 vertices com os vértices {0,1,2,3,4,5,6}, consequentemente cria 7 listas de adjacencia
    
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

    grafo.Busca_Largura(vertice_inicio); //Faz a BSF com inicio no vértice 3
    
    int v1, v2;
    v1 = 1;
    v2 = 6;

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
