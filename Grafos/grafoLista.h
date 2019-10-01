#pragma once
#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include <iostream>
#include <vector>
#include "vertice.h"
#include "grafo.h"
#include <stack>
#include "dijkstra.h"
#include "coloracao.h"

using namespace std;

class GrafoLista : public Grafo {
public:
	vector <Vertice> vertices;

	GrafoLista(bool dir = false, bool pond = false) : Grafo(dir, pond) {

	}

	string labelVertice(int indice) {
		if (indice <= this->vertices.size() - 1) {
			return this->vertices[indice].label;
		}
	};

	bool inserirVertice(string label) {
		Vertice ver;
		ver.label = label;
		if (Grafo::inserirVertice(label)) {
			this->vertices.push_back(ver);
			return true;
		}
	};

	bool inserirAresta(int origem, int destino, int peso = 1) {
		if (origem > this->vertices.size() || destino > this->vertices.size()) {
			return false;
		}
		else
		{
			Adjacente adj;
			adj.id = destino;
			adj.peso = peso;
			this->vertices.at(origem).adj.push_back(adj);
			if (!this->direcionado) {
				adj.id = origem;
				adj.peso = peso;
				this->vertices.at(destino).adj.push_back(adj);
			}
		}
	}

	int existeAresta(int origem, int destino) {
		if (origem > this->vertices.size() || destino > this->vertices.size()) {
			return 0;
		}
		else
		{
			for (int i = 0; i < this->vertices.at(origem).adj.size(); i++)
			{
				if (this->vertices.at(origem).adj.at(i).id == destino) {
					return this->vertices.at(origem).adj.at(i).peso;
				}
			}
			return 0;
		}
	};

	vector<int> retornarVizinhos(int vertice) {
		vector<int> vizinhos;
		if (vertice < this->vertices.size()) {
			for (int i = 0; i < this->vertices.at(vertice).adj.size(); i++)
			{
				vizinhos.push_back(this->vertices.at(vertice).adj.at(i).id);
			}
		}
		return vizinhos;
	}

	vector<Adjacente> retornarVizinhosPond(int vertice) {
		vector<Adjacente> vizinhos;
		if (vertice < this->vertices.size()) {
			for (int i = 0; i < this->vertices.at(vertice).adj.size(); i++)
			{
				vizinhos.push_back(this->vertices.at(vertice).adj.at(i));
			}
		}
		return vizinhos;
	}

	bool isVisitado(vector<int> vetor, int num) {
		for (int i = 0; i < vetor.size(); i++)
		{
			if (vetor.at(i) == num) {
				return true;
			}
		}
		return false;
	}

	vector<int> buscaProfundidade(int pos = 0) {
		vector<int> visitados;
		stack<int> pilha;

		visitados.push_back(pos);
		pilha.push(pos);

		int aux;

		while (true)
		{
			if (this->vertices.at(pilha.top()).adj.size() > 0)
			{
				bool check = false;
				for (int i = 0; i < this->vertices.at(pilha.top()).adj.size(); i++)
				{
					if (!isVisitado(visitados, this->vertices.at(pilha.top()).adj.at(i).id)) {
						check = true;
						aux = this->vertices.at(pilha.top()).adj.at(i).id;
						pilha.push(aux);
						visitados.push_back(aux);
						break;
					}
				}
				if (!check) {
					pilha.pop();

					if (pilha.size() == 0) {
						break;
					}
				}
			}
		}

		return visitados;
	}

	void checkIsVisited(vector<int>& visitados, vector<int>& fila, vector<int> vizinhos) {
		vector<int>::iterator it;
		bool isVisited;

		for (int i = 0; i < vizinhos.size(); i++)
		{
			isVisited = false;
			for (int x = 0; x < visitados.size(); x++)
			{
				if (vizinhos.at(i) == visitados.at(x)) {
					isVisited = true;
				}
			}
			if (!isVisited) {
				fila.push_back(vizinhos.at(i));
				visitados.push_back(vizinhos.at(i));
			}
		}
		it = fila.begin();
		fila.erase(it);
	}

	vector<int> buscaLargura(int pos = 0) {
		vector<int> visitados;
		vector<int> fila;
		vector<int>::iterator it;
		vector<int> viz;

		visitados.push_back(pos);
		fila.push_back(pos);

		int aux;

		while (true)
		{
			viz = retornarVizinhos(pos);
			checkIsVisited(visitados, fila, viz);

			if (fila.size() == 0) {
				break;
			}
			else {
				pos = fila.at(0);
			}
		}

		return visitados;
	}

	bool aberto_distancia_nao_finita(vector<Dijkstra> vector) {
		for (int i = 0; i < vector.size(); i++)
		{
			if (vector.at(i).isFechado == false && vector.at(i).distancia != INT_MAX) {
				return true;
			}

		}
		return false;
	}

	vector<int> dijkstra(bool distancia, int pos = 0) {
		vector<Dijkstra> vector_dijkstra;
		vector<Adjacente> vizinhos;
		int atual = pos;
		Dijkstra dj;
		dj.distancia = INT_MAX;
		dj.anterior = -1;
		dj.isFechado = false;

		for (int i = 0; i < this->vertices.size(); i++)
		{
			dj.vertice = i;
			vector_dijkstra.push_back(dj);
		}

		vector_dijkstra.at(pos).distancia = 0;

		while (aberto_distancia_nao_finita(vector_dijkstra))
		{
			vizinhos = retornarVizinhosPond(pos);
			for (int i = 0; i < vizinhos.size(); i++)
			{
				if (!vector_dijkstra.at(vizinhos.at(i).id).isFechado) {
					if (vector_dijkstra.at(vizinhos.at(i).id).anterior == -1) {
						vector_dijkstra.at(vizinhos.at(i).id).anterior = pos;
						vector_dijkstra.at(vizinhos.at(i).id).distancia = vizinhos.at(i).peso;
					}
					else
					{
						if (vizinhos.at(i).peso + vector_dijkstra.at(pos).distancia < vector_dijkstra.at(vizinhos.at(i).id).distancia) {
							vector_dijkstra.at(vizinhos.at(i).id).anterior = pos;
							vector_dijkstra.at(vizinhos.at(i).id).distancia = vizinhos.at(i).peso + vector_dijkstra.at(pos).distancia;
						}
					}
				}
			}
			vector_dijkstra.at(pos).isFechado = true;
			pos++;
		}
		if (distancia) {
			vector<int> listaDistancia;
			for (int i = 0; i < vector_dijkstra.size(); i++)
			{
				listaDistancia.push_back(vector_dijkstra.at(i).distancia);
			}
			return listaDistancia;
		}
		else {
			vector<int> verticeAnterior;
			for (int i = 0; i < vector_dijkstra.size(); i++)
			{
				verticeAnterior.push_back(vector_dijkstra.at(i).anterior);
			}
			return verticeAnterior;
		}
	}

	bool podeColorir(vector<Coloracao> coloracao, int ver, int cor) {
		
		vector<Adjacente> adjacentes = this->vertices.at(ver).adj;
		int pos;

		for (int j = 0; j < adjacentes.size(); j++)
		{
			for (int i = 0; i < coloracao.size(); i++)
			{
				if (coloracao.at(i).vertice == adjacentes.at(j).id) {
					pos = i;
					break;
				}
			}

			if (coloracao.at(pos).cor == cor) {
				return false;
			}
		}
		
		return true;
	}

	//A função de coloração de Welsh e Powell retorna a quantidade de cores necessárias para colorir o grafo
	int welshPowell() {
		int corMax = 1;
		vector<Coloracao> welshPowell;
		Coloracao wp;
		wp.cor = 0;

		for (int i = 0; i < this->vertices.size(); i++)
		{
			wp.vertice = i;
			wp.grau = this->vertices.at(i).adj.size();
			welshPowell.push_back(wp);
		}

		int tam = welshPowell.size();
		Coloracao aux;
		int sum = 0;

		for (int i = 0; i < tam; i++)
		{
			for (int n = 0; n < tam - 1; n++)
			{
				sum = n + 1;
				if (welshPowell.at(n).grau < welshPowell.at(sum).grau) {
					aux = welshPowell.at(n);
					welshPowell.at(n) = welshPowell.at(sum);
					welshPowell.at(sum) = aux;
				}
			}
		}

		int vertices_coloridos = 0;
		int cont = 0;
		int ver = welshPowell.at(cont).vertice;
		int cor_atual = 1;

		do
		{
			if (welshPowell.at(cont).cor == 0 && podeColorir(welshPowell, ver, cor_atual)) {
				welshPowell.at(cont).cor = cor_atual;
				vertices_coloridos++;
			}
			if (cont == welshPowell.size() - 1) {
				cont = 0;
				cor_atual++;
			}
			else {
				cont++;
			}
			ver = welshPowell.at(cont).vertice;
		} while (vertices_coloridos < welshPowell.size());


		return cor_atual;
	}

	bool isPlano() {
		if (numeroVertices()) {
			return true;
		}
	}

	void imprimirGrafo() {
		for (int i = 0; i < this->vertices.size(); i++)
		{
			cout << i << "  " << this->vertices.at(i).label << "    ";
			cout << "Adjacentes: ";
			for (int a = 0; a < this->vertices.at(i).adj.size(); a++)
			{
				cout << this->vertices.at(i).adj.at(a).id << ", ";
			}
			cout << endl;
		}
	}
};
#endif 