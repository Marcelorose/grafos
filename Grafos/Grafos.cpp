// Grafos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include "grafo.h"
#include <iostream>

using namespace std;

int main()
{
	Grafo teste = Grafo(true, false);

	teste.inserirVertice("asd");
	cout << teste.direcionado << "\n" << teste.ponderado << "\n" << teste.vertices[0];

}
