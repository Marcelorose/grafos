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
	/*setlocale(LC_ALL, "Portuguese");

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

	gf.imprimirGrafo();*/


	
	Grafo teste = Grafo(false, true);
	teste.grafoMatriz.inserirVertice("A"); // 0
	teste.grafoMatriz.inserirVertice("B"); // 1
	teste.grafoMatriz.inserirVertice("C"); // 2
	teste.grafoMatriz.inserirVertice("D"); // 3
	teste.grafoMatriz.inserirVertice("E"); // 4
	teste.grafoMatriz.inserirAresta(0, 1, 3); // A-B
	teste.grafoMatriz.inserirAresta(0, 2, 5); // A-C
	teste.grafoMatriz.inserirAresta(0, 3, 6); // A-D
	teste.grafoMatriz.inserirAresta(0, 4, 8); // A-E
	teste.grafoMatriz.inserirAresta(2, 4, 2); // C-E
	teste.grafoMatriz.inserirAresta(4, 1, 11); // E-B
	teste.grafoMatriz.inserirAresta(1, 3, 2); // F-C
	teste.grafoMatriz.imprimeGrafo();
	//cout << teste.grafoMatriz.existeAresta(0, 0);
	//cout << teste.grafoMatriz.existeAresta(0, 1);
	vector <int> temp = teste.grafoMatriz.dijkstra_retornoAnterior(0);
	for (int x = 0; x < temp.size(); x++) {
		cout << temp[x] << "\t";
	}

}