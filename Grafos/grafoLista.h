#pragma once
#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include <iostream>
#include <vector>
#include "vertice.h"
#include "grafo.h"
#include <stack>

using namespace std;

class GrafoLista : public Grafo {
public:
	vector <Vertice> vertices;

	GrafoLista(bool dir = false, bool pond = false) : Grafo(dir, pond){
		
	}

	bool isDirecionado() {
		return direcionado;
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
			if (this->direcionado) {
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
						//pos = this->vertices.at(pilha.top()).adj.at(i).id;
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



	void imprimirGrafo() {
		for (int i = 0; i < this->vertices.size(); i++)
		{
			cout << i  << "  " << this->vertices.at(i).label << "    ";
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