#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "grafoLista.h"
#include "grafoMatriz.h"
using namespace std;
const int TAMANHO = 100;
struct Grafo {
	GrafoLista grafoLista;
	GrafoMatriz grafoMatriz;
	int arestas[TAMANHO][2] = {};
	int peso_aresta[TAMANHO] = {};
	bool direcionado;
	bool ponderado;

	Grafo(bool dir, bool pond) {
		this->direcionado = dir;
		this->ponderado = pond;
		grafoMatriz = GrafoMatriz();
		grafoLista = GrafoLista();
	};

	string labelVertice(int indice) {
		return grafoMatriz.labelVertice(indice);
	};

	/*bool inserirVertice(string label) {
		if (grafoLista.inserirVertice(label) & grafoMatriz.inserirVertice(label)) {
			return true;
		}
		return false;
	};*/

	bool inserirAresta(int origem, int destino, int peso = 1) {
		if (!this->ponderado) {
			peso = 1;
		}
		if (grafoMatriz.inserirAresta(this->direcionado, origem, destino, peso)) {
			return true;
		}
		return false;
	}

	void imprimeGrafo() {
		grafoMatriz.imprimeGrafo();
	}

};

#endif 