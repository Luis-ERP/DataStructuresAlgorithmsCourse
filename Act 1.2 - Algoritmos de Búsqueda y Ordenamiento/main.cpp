/*
 * main.cpp
 *
 *  Created on: 07/09/2020
 *      Author: Luis Ramirez
 */

// Ordena ordenaBurbuja
// Busqueda binaria

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include "sorts.h"

using namespace std;

template <class T>
string arrayToString(const vector<T> &v) {
	stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
}


int main(int argc, char* argv[]) {

	int array1[] = {61, 64, 5, 28, 11, 8, 21, 58, 54, 52};
	vector<int> original1 (array1, array1 + sizeof(array1) / sizeof(int) );

	int array2[] = {1390, 4422, 8829, 2922, 81};
	vector<int> original2 (array2, array2 + sizeof(array2) / sizeof(int) );

	vector<int> prueba;
	Sorts<int> sorts;
	string resp1 = "[5, 8, 11, 21, 28, 52, 54, 58, 61, 64]";
	string resp2 = "[81, 1390, 2922, 4422, 8829]";

	prueba = original1;
	sorts.ordenaSeleccion(prueba);

	cout << " 1 " <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaSeleccion(prueba);
	cout << " 2 " <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original1;
	sorts.ordenaBurbuja(prueba);
	cout << " 3 " <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaBurbuja(prueba);
	cout << " 4 " <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original1;
	sorts.ordenaMerge(prueba);
	cout << " 5 " <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaMerge(prueba);
	cout << " 6 " <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	sorts.ordenaMerge(prueba);
    cout << " 7 " <<	(0 == sorts.busqSecuencial(prueba, 81) ? "success\n" : "fail\n");

	cout << " 8 " <<	(-1 == sorts.busqSecuencial(prueba, 7) ? "success\n" : "fail\n");

	cout << " 9 " <<	(3 == sorts.busqBinaria(prueba, 4422) ? "success\n" : "fail\n");

	cout << " 10 " <<	(4 == sorts.busqBinaria(prueba, 5555) ? "success\n" : "fail\n");
}