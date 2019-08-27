#pragma once
#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H
#include <iostream>
using namespace std;
struct GrafoMatriz {
	string vertices[10] = {};
	int arestas[10][10] = {};

	GrafoMatriz() {
	};

	string labelVertice(int indice) {
		return this->vertices[indice];
	};

	bool inserirVertice(string label) {
		for (int x = 0; x < 10; x++) {
			if (this->vertices[x] == "") {
				this->vertices[x] = label;
				return true;
			}
			if (x == 10 - 1) {
				cout << "Não a mais espaços disponíveis!";
				return false;
			}
		}
	};

	bool inserirAresta(bool direcionado, int origem, int destino, int peso) {
		if (origem > 10 || destino > 10 || origem < 0 || destino < 0) {
			cout << "Origem ou destino inválidos!";
			return false;
		}
		this->arestas[origem][destino] = peso;
		if (!direcionado) {
			this->arestas[destino][origem] = peso;
		}
		return true;
	}

	void imprimeGrafo() {
		for (int i = 0; i < 10; i++) {
			for (int x = 0; x < 10; x++) {
				if (x == 0) {
					cout << i << "\t";
				}
				else if (i == 0) {
					cout << x << "\t";
				}
				else {
					cout << arestas[i][x] << "\t";
				}
			}
			cout << "\n";
		}
	};

	bool existeAresta(int origem, int destino) {
		if (this->arestas[origem][destino] != 0) {
			return true;
		}
		else {
			return false;
		}
	};
};
#endif 