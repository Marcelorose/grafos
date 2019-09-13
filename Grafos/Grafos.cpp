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

	gr.inserirAresta(0, 1, 3);
	gr.inserirAresta(0, 2, 5);
	gr.inserirAresta(0, 3, 6);
	gr.inserirAresta(0, 4, 8);
	gr.inserirAresta(1, 3, 2);
	gr.inserirAresta(1, 4, 11);
	gr.inserirAresta(2, 4, 2);

	gr.dijkstra(0);

	return 0;
}