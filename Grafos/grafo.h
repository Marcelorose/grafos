#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include "vertice.h"

using namespace std;


class Grafo {
public:
	bool direcionado;
	bool ponderado;
	vector<Vertice> vertices_grafo;

	Grafo(bool dir, bool pond) {
		this->direcionado = dir;
		this->ponderado = pond;
	}

	bool inserirVertice(string label) {
		Vertice ver;
		ver.label = label;
		this->vertices_grafo.push_back(ver);
		return true;
	};

};


#endif 