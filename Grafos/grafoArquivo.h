#pragma once
#ifndef GRAFOARQUIVO_H
#define GRAFOARQUIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include "grafoMatriz.h"
#include "grafoLista.h"

template <class grafo>
grafo criarGrafoArquivo(string arquivo) {
	string line;
	ifstream myfile(arquivo);
	ifstream myfile2(arquivo);
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
	else {
		cout << "Unable to open file";
		return NULL;
	}

	grafo gr = grafo(direcionado, ponderado);


	if (myfile2.is_open()) {

		while (!myfile2.eof()) 
		{
			getline(myfile2, line); 

			if (cont > 0 && cont == vertices) {
				gr.inserirVertice(line);
				while (myfile2 >> auxOrigem >> auxDestino)
				{
					origem = auxOrigem;
					destino = auxDestino;
					gr.inserirAresta(origem, destino);
				}
			}
			else if (cont > 0 && cont <= vertices) {
				gr.inserirVertice(line);
			}

			cont++;
		}
		myfile2.close();
	}

	else {
		cout << "Unable to open file";
		return NULL;
	}

	return gr;
}

#endif