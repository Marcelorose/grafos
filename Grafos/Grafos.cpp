// Grafos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include "grafoLista.h"
#include "grafoMatriz.h"
#include <vector>
#include <string>
#include <fstream>
#include <locale.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	/*
	gr.inserirVertice("A");
	gr.inserirVertice("B");
	gr.inserirVertice("C");
	gr.inserirVertice("D");
	gr.inserirVertice("E");

	gr.inserirAresta(0, 1);
	gr.inserirAresta(0, 3);
	gr.inserirAresta(1, 2);
	gr.inserirAresta(1, 3);
	gr.inserirAresta(1, 4);
	gr.inserirAresta(2, 4);
	gr.inserirAresta(3, 4);

	cout << gr.welshPowel();
	*/

	string line;
	ifstream myfile("Grafos/trabalho-28cores.txt"); // ifstream = padrão ios:in
	ifstream myfile2("Grafos/trabalho-28cores.txt"); // ifstream = padrão ios:in
	int auxVertices, vertices, auxArestas, arestas, auxOrigem, origem, auxDestino, destino, auxPeso, peso;
	bool auxDirecionado, direcionado = false, auxPonderado, ponderado = false;
	int cont = 0;
	
	if (myfile.is_open())
	{
		while (myfile >> auxVertices >> auxArestas >> auxDirecionado >> auxPonderado)
		{
			vertices = auxVertices;
			arestas = auxArestas;
			direcionado = auxDirecionado;
			ponderado = auxPonderado;
		}

		myfile.close();
	}
	else cout << "Unable to open file";

	GrafoLista gr = GrafoLista(direcionado, ponderado);

	
	if (myfile2.is_open()) {
		
		while (!myfile2.eof()) //enquanto end of file for false continua
		{
			getline(myfile2, line); // como foi aberto em modo texto(padrão)
			
			if (cont > 0 && cont == vertices) {
				//cout << line << endl;
				gr.inserirVertice(line);
				while (myfile2 >> auxOrigem >> auxDestino)
				{
					origem = auxOrigem;
					destino = auxDestino;
					gr.inserirAresta(origem, destino);
				}
			}
			else if(cont > 0 && cont <= vertices){
				gr.inserirVertice(line);
			}
			
			cont++;
		}
		myfile2.close();
	}

	else cout << "Unable to open file";

	cout << gr.welshPowel();
	//gr.imprimirGrafo();

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