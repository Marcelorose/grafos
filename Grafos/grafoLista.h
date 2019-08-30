#pragma once
#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include <iostream>
#include <vector>
#include "vertice.h"

using namespace std;
struct GrafoLista {
	vector <Vertice> vertices;
	int qtd;

	GrafoLista() { 
		
	};

	string labelVertice(int indice) {
		if (indice <= this->vertices.size() - 1) {
			return this->vertices[indice].label;
		}
	};

	bool inserirVertice(string label) {
		Vertice ver;
		ver.label = label;
		this->vertices.push_back(ver);
	};

	bool existeAresta(int origem, int destino) {
		for (std::vector<Adjacente>::iterator it = this->vertices[origem].adj.begin(); it != this->vertices[origem].adj.end(); ++it) {
			
		}
		return true;
	};
};
#endif 