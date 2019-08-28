// Grafos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include "grafo.h"
#include "vertice.h"
#include <iostream>

using namespace std;

int main()
{
	Grafo teste = Grafo(true, false);
	teste.inserirVertice("Vertice 1");
	teste.inserirVertice("Vertice 2");
	teste.inserirAresta(10, 2, 5);
	teste.inserirAresta(4, 3, 2);
	teste.inserirAresta(1, 6, 1);
	teste.inserirAresta(2, 9, 3);
	teste.imprimeGrafo();
	cout << teste.labelVertice(0) << "\n" << teste.labelVertice(1);

}
