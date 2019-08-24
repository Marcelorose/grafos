#pragma once

struct GrafoMatriz {

	GrafoMatriz() {

	};
	string inserirVertice(string vertices[],string label) {
		vertices[0] = label;
		return *vertices;
	};

	string labelVertice(int indice);

	bool existeAresta(int origem, int destino);
};