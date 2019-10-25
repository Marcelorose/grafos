#pragma once
#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H
#include <iostream>
#include <vector>
using namespace std;

class GrafoMatriz : public Grafo {
public:
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
		for (int x = 0; x < vertices.size(); x++) {
			if (arestas[vertice][x] != 0) {
				vizinhos.push_back(x);
			}
			else if (arestas[x][vertice] != 0) {
				vizinhos.push_back(x);
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


	bool verificaCorEmBranco(vector<int> cores) {
		for (int x = 0; x < cores.size(); x++) {
			if (cores[x] == 0) {
				return true;
			}
		}
		return false;
	}


	int verificaProximo(vector<int> vetor) {
		for (int x = 0; x < vetor.size(); x++) {
			if (vetor[x] == 0) {
				return x;
			}
		}
		return vetor.size() - 1;
	}


	int welsh_e_powell() {
		vector<string> vertices_tmp = this->vertices;
		vector<int> indices;
		vector<int> historico;
		vector<int> vertices_cores;
		vector<int> grau;
		vector<int> cores;
		for (int x = 1; x < 1000; x++) {
			cores.push_back(x);
		}
		for (int x = 0; x < vertices_tmp.size(); x++) {
			grau.push_back(retornarVizinhos(x).size());
			vertices_cores.push_back(0);
			indices.push_back(x);
			historico.push_back(x);
		}
		for (int x = vertices_tmp.size() - 1; x > 0; x--) {
			for (int i = 0; i < x; i++) {
				if (grau[i] < grau[i + 1]) {
					int aux = grau[i];
					grau[i] = grau[i + 1];
					grau[i + 1] = aux;
					string aux2 = vertices_tmp[i];
					vertices_tmp[i] = vertices_tmp[i + 1];
					vertices_tmp[i + 1] = aux2;
					int aux3 = historico[i];
					historico[i] = historico[i + 1];
					historico[i + 1] = aux3;
				}
			}
		}
		for (int x = 0; x < vertices_tmp.size(); x++) {
			for (int y = 0; y < vertices_tmp.size(); y++) {
				if (vertices_tmp[x] == vertices[y])
					indices[y] = x;
			}
		}
		int cont_cor = 0;
		int cont_geral = 0;
		while (verificaCorEmBranco(vertices_cores)) {
			int cor_atual = cores[cont_cor];
			for (int x = verificaProximo(vertices_cores); x < vertices_tmp.size(); x++) {
				if (vertices_cores[x] == 0) {
					vector <int> vizinhos = retornarVizinhos(historico[x]);
					if (vizinhos.size() == 0)
						vertices_cores[x] = cor_atual;
					else {
						for (int i = 0; i < vizinhos.size(); i++) {
							if (vertices_cores[indices[vizinhos[i]]] == cor_atual)
								break;
							else if (i == vizinhos.size() - 1) {
								vertices_cores[x] = cor_atual;
							}
						}
					}
				}
			}
			cont_cor++;
		}
		vector <int> cores_ja_foram;
		for (int x = 0; x < vertices_cores.size(); x++) {
			if (x == 0)
				cores_ja_foram.push_back(vertices_cores[x]);
			for (int i = 0; i < cores_ja_foram.size(); i++) {
				if (vertices_cores[x] == cores_ja_foram[i])
					break;
				if (i == cores_ja_foram.size() - 1)
					cores_ja_foram.push_back(vertices_cores[x]);
			}
		}
		return cores_ja_foram.size();
	}

	int dsatur() {
		vector<string> vertices_tmp = this->vertices;
		vector<int> indices;
		vector<int> saturacao;
		vector<int> historico;
		vector<int> vertices_cores;
		vector<int> grau;
		vector<int> cores;
		for (int x = 1; x < 1000; x++) {
			cores.push_back(x);
		}
		for (int x = 0; x < vertices_tmp.size(); x++) {
			grau.push_back(retornarVizinhos(x).size());
			vertices_cores.push_back(0);
			indices.push_back(x);
			historico.push_back(x);
			saturacao.push_back(0);
		}
		for (int x = vertices_tmp.size() - 1; x > 0; x--) {
			for (int i = 0; i < x; i++) {
				if (grau[i] < grau[i + 1]) {
					int aux = grau[i];
					grau[i] = grau[i + 1];
					grau[i + 1] = aux;
					string aux2 = vertices_tmp[i];
					vertices_tmp[i] = vertices_tmp[i + 1];
					vertices_tmp[i + 1] = aux2;
					int aux3 = historico[i];
					historico[i] = historico[i + 1];
					historico[i + 1] = aux3;
				}
			}
		}
		for (int x = 0; x < vertices_tmp.size(); x++) {
			for (int y = 0; y < vertices.size(); y++) {
				if (vertices_tmp[x] == vertices[y]) {
					indices[y] = x;
				}
				if (historico[x] == -1)
					historico[x] = x;
			}
		}
		while (verificaCorEmBranco(vertices_cores)) {
			vector <int> saturados;
			int maior_saturacao = 0;
			int trocou = 0;
			for (int j = 0; j < saturacao.size(); j++) {
				if (j == 0 && vertices_cores[j] == 0)
					maior_saturacao = saturacao[j];
				else if (maior_saturacao < saturacao[j] && vertices_cores[j] == 0)
					maior_saturacao = saturacao[j];
			}
			for (int h = 0; h < saturacao.size(); h++) {
				if (saturacao[h] >= maior_saturacao && vertices_cores[h] == 0)
					saturados.push_back(historico[h]);
			}
			for (int g = 0; g < cores.size(); g++) {
				int cor_atual = cores[g];
				for (int x = 0; x < saturados.size(); x++) {
					vector <int> vizinhos = retornarVizinhos(saturados[x]);
					if (trocou == 1)
						break;
					if (vizinhos.size() == 0 and vertices_cores[indices[saturados[x]]] == 0) {
						vertices_cores[indices[saturados[x]]] = cor_atual;
						for (int y = 0; y < vizinhos.size(); y++) {
							if (vertices_cores[indices[vizinhos[y]]] != cor_atual) {
								saturacao[indices[vizinhos[y]]]++;
								trocou = 1;
							}
						}
					}
					else {
						for (int i = 0; i < vizinhos.size(); i++) {
							if (vertices_cores[indices[vizinhos[i]]] == cor_atual)
								break;
							else if (i == vizinhos.size() - 1) {
								vertices_cores[indices[saturados[x]]] = cor_atual;
								for (int y = 0; y < vizinhos.size(); y++) {
									if (vertices_cores[indices[vizinhos[y]]] != cor_atual) {
										saturacao[indices[vizinhos[y]]]++;
										trocou = 1;
									}
								}
							}
						}
					}
				}
			}
		}
		vector <int> cores_ja_foram;
		for (int x = 0; x < vertices_cores.size(); x++) {
			if (x == 0)
				cores_ja_foram.push_back(vertices_cores[x]);
			for (int i = 0; i < cores_ja_foram.size(); i++) {
				if (vertices_cores[x] == cores_ja_foram[i])
					break;
				if (i == cores_ja_foram.size() - 1)
					cores_ja_foram.push_back(vertices_cores[x]);
			}
		}
		return cores_ja_foram.size();
	}
};
#endif 