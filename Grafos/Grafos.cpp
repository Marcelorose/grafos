// Grafos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include "grafoLista.h"
#include "grafoMatriz.h"
#include "grafoArquivo.h"
#include <vector>
#include <locale.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");


	GrafoLista gr = criarGrafoArquivo <GrafoLista>("Grafos/trabalho-28cores.txt");

	cout << gr.welshPowell();
	

	/*vector<int> distancia;
	distancia = gr.dijkstra(true, 0);

	cout << "Distancia dos vertices para a origem" << endl;

	for (int i = 0; i < distancia.size(); i++)
	{
		cout << " | " << distancia.at(i);
	}

	cout << " | ";

	vector<int> anterior;
	anterior = gr.dijkstra(false, 0);

	cout << endl << endl << "Vertice Anterior (Vertices que possuem -1 como anterior e porque nao possuem um anterior)" << endl;

	for (int i = 0; i < anterior.size(); i++)
	{
		cout << " | " << anterior.at(i);
	}

	cout << " | " << endl;*/


	return 0;
}