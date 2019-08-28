#pragma once
#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include "adjacente.h"
using namespace std;

struct Vertice {
	Vertice *prox;
	Adjacente *raiz;
	string label;

	Vertice() {
		
	}
};

#endif