#pragma once
#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include <iostream>
#include "vertice.h"

using namespace std;
struct GrafoLista {
	string vertices[100] = {};

	Vertice *raiz;
	int qtd;

	GrafoLista() {
	};

	string labelVertice(int indice) {
		return this->vertices[indice];
	};

	bool inserirVertice(string label) {
		for (int x = 0; x < 100; x++) {
			if (this->vertices[x] == "") {
				this->vertices[x] = label;
				return true;
			}
			if (x == 100 - 1) {
				cout << "N�o a mais espa�os dispon�veis!";
				return false;
			}
		}
	};

	bool existeAresta(int origem, int destino) {
		
	};
};
#endif 