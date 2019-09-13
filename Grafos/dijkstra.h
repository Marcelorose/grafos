#pragma once
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include "vertice.h"

struct Dijkstra
{
	int vertice;
	int distancia;
	int anterior;
	bool isFechado;
};

#endif