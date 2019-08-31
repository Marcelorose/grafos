// Grafos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include "grafo.h"
#include "vertice.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	GrafoLista gf = GrafoLista();
	vector <Vertice> v;
	Vertice ver;
	ver.label = "teste";
	v.push_back(ver);
	Adjacente adj;
	int x = 1;
	adj.prox = NULL;
	adj.id = &x;
	ver.adj.push_back(adj);
	//Adjacente adj;
	adj.prox = NULL;
	int a = 2;
	adj.id = &a;
	ver.adj.push_back(adj);
	//Adjacente adj;
	adj.prox = NULL;
	int b = 3;
	adj.id = &b;
	ver.adj.push_back(adj);
	gf.vertices = v;
	gf.existeAresta(0, 2);

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
