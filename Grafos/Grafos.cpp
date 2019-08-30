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
	/*Grafo teste = Grafo(true, false);
	teste.inserirVertice("Vertice 1");
	teste.inserirVertice("Vertice 2");
	teste.inserirAresta(10, 2, 5);
	teste.inserirAresta(4, 3, 2);
	teste.inserirAresta(1, 6, 1);
	teste.inserirAresta(2, 9, 3);
	teste.imprimeGrafo();
	cout << teste.labelVertice(0) << "\n" << teste.labelVertice(1);*/

}
