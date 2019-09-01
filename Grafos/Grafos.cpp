// Grafos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include "grafo.h"
#include "vertice.h"
#include <vector>
#include <locale.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	GrafoLista gf = GrafoLista();
	gf.inserirVertice("vertice 1");
	gf.inserirVertice("vertice 2");
	gf.inserirVertice("vertice 3");
	gf.inserirVertice("vertice 4");
	gf.inserirVertice("vertice 5");
	gf.inserirVertice("vertice 6");
	gf.inserirVertice("vertice 7");

	gf.inserirAresta(0, 1);
	gf.inserirAresta(0, 2);
	gf.inserirAresta(1, 5);
	gf.inserirAresta(2, 4);
	gf.inserirAresta(3, 1);
	gf.inserirAresta(3, 6);
	gf.inserirAresta(4, 2);
	gf.inserirAresta(5, 4);
	gf.inserirAresta(6, 2);
	gf.inserirAresta(6, 1);
	gf.inserirAresta(6, 4);

	gf.imprimirGrafo();


	/*
	Grafo teste = Grafo(true, true);
	teste.grafoMatriz.inserirVertice("Vertice 1");
	teste.grafoMatriz.inserirVertice("Vertice 2");
	teste.grafoMatriz.inserirVertice("Vertice 3");
	teste.grafoMatriz.inserirVertice("Vertice 4");
	teste.grafoMatriz.inserirVertice("Vertice 5");
	teste.grafoMatriz.inserirVertice("Vertice 6");
	teste.grafoMatriz.inserirVertice("Vertice 7");
	teste.grafoMatriz.inserirAresta(0, 1, 5);
	teste.grafoMatriz.inserirAresta(2, 0, 6);
	teste.grafoMatriz.inserirAresta(5, 3, 8);
	teste.grafoMatriz.inserirAresta(2, 4, 1);
	teste.grafoMatriz.inserirAresta(6, 5, 4);
	teste.grafoMatriz.imprimeGrafo();
	cout << teste.grafoMatriz.existeAresta(0, 0);
	cout << teste.grafoMatriz.existeAresta(0, 1);
	vector <int> temp = teste.grafoMatriz.retornarVizinhos(5);
	for (int x = 0; x < temp.size(); x++) {
		cout << temp[x] << endl;
	}*/

}
