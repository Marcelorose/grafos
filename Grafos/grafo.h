#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
using namespace std;

struct Grafo {
	bool direcionado;
	bool ponderado;
	string vertices[10];
	

	Grafo(bool dir, bool pond) {
		this->direcionado = dir;
		this->ponderado = pond;
	};

	bool inserirVertice(string label) {
		this->vertices[0] = label;
		return true;
	};
};

#endif 