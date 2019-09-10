// Grafos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include "grafoLista.h"
#include "grafoMatriz.h"
#include "vertice.h"
#include <vector>
#include <locale.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	GrafoLista gr = GrafoLista(true, true);

	//cout << gr.isDirecionado();

	gr.inserirVertice("A");
	gr.inserirVertice("B");
	gr.inserirVertice("C");
	gr.inserirVertice("D");
	gr.inserirVertice("E");
	gr.inserirVertice("F");

	gr.inserirAresta(0, 1);
	gr.inserirAresta(0, 3);
	gr.inserirAresta(1, 3);
	gr.inserirAresta(0, 2);
	gr.inserirAresta(2, 4);
	gr.inserirAresta(2, 5);
	gr.inserirAresta(4, 5);

	vector<int> a;
	a = gr.buscaLargura(0);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a.at(i);
	}

	//gr.imprimirGrafo();



	//gr.inserirVertice("A");
	/*gr.inserirVertice("B");
	gr.inserirVertice("C");
	gr.inserirVertice("D");
	gr.inserirVertice("E");
	
	gr.inserirAresta(0, 1, 3);
	gr.inserirAresta(0, 2, 5);
	gr.inserirAresta(0, 3, 6);
	gr.inserirAresta(0, 4, 8);
	gr.inserirAresta(1, 3, 2);
	gr.inserirAresta(1, 4, 11);
	gr.inserirAresta(2, 4, 2);*/
	

	//cout << gr.existeArestaMatriz(6, 4) << endl;
	//cout << gr.existeArestaLista(4, 6);

	//cout << gr.labelVerticeLista(2) << endl;
	//cout << gr.labelVerticeMatriz(2);

	//gr.imprimeGrafoMatriz();
	//gr.imprimeGrafoLista();

	
	//vector<int> a = gr.buscaLarguraMatriz(2);

	/*for (int i = 0; i < a.size(); i++)
	{
		cout << a.at(i) << " ";
	}*/

	return 0;
}