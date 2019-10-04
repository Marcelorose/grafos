#pragma once
#ifndef DSATUR_H
#define DSATUR_H

#include <iostream>

struct Dsatur
{
	int vertice;
	int grau;
	int cor;
	int saturacao;
	vector<int> coresAdjacentes;
};

#endif