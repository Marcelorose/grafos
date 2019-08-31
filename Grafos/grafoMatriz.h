#pragma once
#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H
#include <iostream>
#include <vector>
using namespace std;
struct GrafoMatriz {
	vector <string> vertices;
	vector <vector <int>> arestas;
	bool direcionado;
	bool ponderado;

	GrafoMatriz(bool dir = false, bool pond = false) {
		this->direcionado = dir;
		this->ponderado = pond;
	};

	string labelVertice(int indice) {
		return this->vertices[indice];
	};

	bool inserirVertice(string label) {
		vertices.push_back(label);
		arestas.push_back({0});
		for (int x = 0; x < arestas.size(); x++)
			arestas[x].resize(vertices.size());
		return true;
	};

	bool inserirAresta(int origem, int destino, int peso = 1) {
		this->arestas[origem][destino] = peso;
		if (this->direcionado) {
			this->arestas[destino][origem] = peso;
		}
		return true;
	}

	void imprimeGrafo() {
		for (int i = 0; i <= arestas.size(); i++) {
			for (int x = 0; x <= arestas.size(); x++) {
				if (x == 0) {
					cout << i << "\t";
				}
				else if (i == 0) {
					cout << x << "\t";
				}
				else {
					cout << arestas[i-1][x-1] << "\t";
				}
			}
			cout << "\n";
		}
	};

	bool existeAresta(int origem, int destino) {
		if (arestas.size() < origem || arestas[origem][destino] == NULL) {
				return 0;
		}
		return arestas[origem][destino];
	};

	vector<int> retornarVizinhos(int vertice) {
		vector <int> vizinhos;
		for (int x = 0; x < arestas[vertice].size(); x++) {
			if (arestas[vertice][x] != 0) {
				vizinhos.push_back(x);
			}
		}
		return vizinhos;
	}
};
#endif 