#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "grafoLista.h"
#include "grafoMatriz.h"
using namespace std;

struct Grafo {
	bool direcionado;
	bool ponderado;
	GrafoLista grafoLista;
	GrafoMatriz grafoMatriz;
	string vertices[10];
	

	Grafo(bool dir, bool pond) {
		this->direcionado = dir;
		this->ponderado = pond;
		grafoLista = GrafoLista();
		grafoMatriz = GrafoMatriz();
	};

	bool inserirVertice(string label) {
		grafoLista.inserirVertice(vertices, label);
		grafoMatriz.inserirVertice(vertices, label);
		return true;
	};

};

#endif 