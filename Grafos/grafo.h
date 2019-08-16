#pragma once

struct Grafo {
	bool direcionado;
	bool ponderado;
	

	Grafo(bool dir, bool pond) {
		this->direcionado = dir;
		this->ponderado = pond;
	};
};
