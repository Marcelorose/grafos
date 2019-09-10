#pragma once
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include "vertice.h"

struct Dijkstra
{
	Vertice vertice;
	int distancia;
	Vertice anterior;
	bool isFechado;
};

#endif