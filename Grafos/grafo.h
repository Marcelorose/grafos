#pragma once

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
