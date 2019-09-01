#pragma once
#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <vector>
#include "adjacente.h"
using namespace std;

struct Vertice {
	/*Vertice *prox;
	Adjacente *raiz;*/
	string label;
	vector <Adjacente> adj;

	Vertice() {
		
	}
};

#endif