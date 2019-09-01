#pragma once
#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include <iostream>
#include <vector>
#include "vertice.h"

using namespace std;
struct GrafoLista {
	vector <Vertice> vertices;

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
		return true;
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
		}
	}

	int existeAresta(int origem, int destino) {
		if (origem > this->vertices.size() || destino > this->vertices.size()) {
			return -1;
		}
		else
		{
			for (int i = 0; i < this->vertices.at(origem).adj.size(); i++)
			{
				if (this->vertices.at(origem).adj.at(i).id == destino) {
					return this->vertices.at(origem).adj.at(i).peso;
				}
			}
			return -1;
		}
	};

	vector<int> vizinhosVertice(int vertice){
		vector<int> vizinhos;
		if (vertice < this->vertices.size()) {
			for (int i = 0; i < this->vertices.at(vertice).adj.size(); i++)
			{
				vizinhos.push_back(this->vertices.at(vertice).adj.at(i).id);
			}
		}
		return vizinhos;
	}


	void imprimirGrafo() {
		for (int i = 0; i < this->vertices.size(); i++)
		{
			cout << "Vértice: " << i << "    ";
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