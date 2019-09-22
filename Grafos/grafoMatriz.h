#pragma once
#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H
#include <iostream>
#include <vector>
using namespace std;

class GrafoMatriz : public Grafo {
	vector <string> vertices;
	vector <vector <int>> arestas;

	GrafoMatriz(bool dir = false, bool pond = false) : Grafo(dir, pond) {

	};

	string labelVertice(int indice) {
		return this->vertices[indice];
	};

	bool inserirVertice(string label) {
		if (Grafo::inserirVertice(label)) {
			vertices.push_back(label);
			arestas.push_back({ 0 });
			for (int x = 0; x < arestas.size(); x++)
				arestas[x].resize(vertices.size());
			return true;
		}
	};

	bool inserirAresta(int origem, int destino, int peso = 1) {
		this->arestas[origem][destino] = peso;
		if (!this->direcionado) {
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
					cout << arestas[i - 1][x - 1] << "\t";
				}
			}
			cout << "\n";
		}
	};

	int existeAresta(int origem, int destino) {
		if (arestas.size() < origem || arestas[origem][destino] == NULL) {
			return 0;
		}
		return arestas[origem][destino];
	};

	vector<int> retornarVizinhos(int vertice) {
		vector <int> vizinhos;
		int percorrer = vertices.size();
		int percorrer_aresta = arestas.size();
		for (int i = 0; i < percorrer; i++) {
			if (this->direcionado)
				percorrer_aresta = i;
			for (int x = 0; x < percorrer_aresta; x++) {
				if (arestas[i][x] != 0 & i == vertice) {
					vizinhos.push_back(x);
				}
				else if (arestas[i][x] != 0 & x == vertice) {
					vizinhos.push_back(i);
				}
			}
		}
		return vizinhos;
	}

	vector<int> buscaLargura(int vertice_inicial) {
		vector<int> fila;
		vector<int> saida;
		int percorrer = vertices.size();
		int percorrer_aresta = arestas.size();
		fila.push_back(vertice_inicial);
		saida.push_back(vertice_inicial);
		while (fila.size() != 0) {
			int atual = fila.front();
			for (int x = 0; x < percorrer_aresta; x++) {
				if (arestas[atual][x] != 0 & verificaJaPassou(saida, x)) {
					fila.push_back(x);
					saida.push_back(x);
				}
			}
			fila.erase(fila.begin());
		}
		return saida;
	}

	vector<int> buscaProfundidade(int vertice_inicial) {
		vector<int> pilha;
		vector<int> saida;
		int percorrer = vertices.size();
		int percorrer_aresta = arestas.size();
		pilha.push_back(vertice_inicial);
		saida.push_back(vertice_inicial);
		while (pilha.size() != 0) {
			int atual = pilha.back();
			for (int x = 0; x < percorrer_aresta; x++) {
				if (arestas[atual][x] != 0 & verificaJaPassou(saida, x)) {
					pilha.push_back(x);
					saida.push_back(x);
					break;
				}
				else if (x == percorrer_aresta - 1) {
					pilha.pop_back();
				}
			}
		}
		return saida;
	}

	vector<int> dijkstra_retornoDistancia(int vertice_inicial) {
		vector<int> fechado(vertices.size(), 0);
		vector<int> anterior;
		vector<int> distancia;
		int percorrer = vertices.size();
		int percorrer_aresta = arestas.size();
		anterior.push_back(vertice_inicial);
		distancia.push_back(0);
		fechado[0] = 1;
		while (distancia.size() < fechado.size()) {
			for (int x = 0; x < percorrer_aresta; x++) {
				if (arestas[vertice_inicial][x] != 0) {
					anterior.push_back(vertice_inicial);
					distancia.push_back(arestas[vertice_inicial][x]);
				}
			}
		}
		int soma_fechado = 0;
		while (soma_fechado < fechado.size()) {
			int soma_temp = 0;
			for (int i = 0; i < fechado.size(); i++) {
				if (fechado[i] != 1) {
					for (int x = 0; x < percorrer_aresta; x++) {
						if (arestas[x][i] != 0) {
							if (distancia[i] > (arestas[vertice_inicial][x] + arestas[x][i])) {
								anterior[i] = x;
								distancia[i] = arestas[vertice_inicial][x] + arestas[x][i];
							}
						}
						if (x == percorrer_aresta - 1) {
							fechado[i] = 1;
						}
					}
				}
			}
			for (int x = 0; x < fechado.size(); x++) {
				if (fechado[x] == 1)
					soma_fechado = x;
			}
		}
		return distancia;
	}

	vector<int> dijkstra_retornoAnterior(int vertice_inicial) {
		vector<int> fechado(vertices.size(), 0);
		vector<int> anterior;
		vector<int> distancia;
		int percorrer = vertices.size();
		int percorrer_aresta = arestas.size();
		anterior.push_back(vertice_inicial);
		distancia.push_back(0);
		fechado[0] = 1;
		while (distancia.size() < fechado.size()) {
			for (int x = 0; x < percorrer_aresta; x++) {
				if (arestas[vertice_inicial][x] != 0) {
					anterior.push_back(vertice_inicial);
					distancia.push_back(arestas[vertice_inicial][x]);
				}
			}
		}
		int soma_fechado = 0;
		while (soma_fechado < fechado.size()) {
			int soma_temp = 0;
			for (int i = 0; i < fechado.size(); i++) {
				if (fechado[i] != 1) {
					for (int x = 0; x < percorrer_aresta; x++) {
						if (arestas[x][i] != 0) {
							if (distancia[i] > (arestas[vertice_inicial][x] + arestas[x][i])) {
								anterior[i] = x;
								distancia[i] = arestas[vertice_inicial][x] + arestas[x][i];
							}
						}
						if (x == percorrer_aresta - 1) {
							fechado[i] = 1;
						}
					}
				}
			}
			for (int x = 0; x < fechado.size(); x++) {
				if (fechado[x] == 1)
					soma_fechado = x + 1;
			}
		}
		return anterior;
	}


	bool verificaJaPassou(vector<int> busca, int vertice) {
		for (int i = 0; i < busca.size(); i++) {
			if (vertice == busca[i])
				return false;
		}
		return true;
	}
};
#endif 