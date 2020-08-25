/*
 * funciones.h
 *
 *  Created on: 08/20/2020
 *      Author: Luis Ramirez
 */

#pragma once
#include <iostream>

using namespace std;


class Funciones{
	public:

	Funciones(){}

	int sumaIterativa(int n){
		int sum = 0;
		for(int i=0; i<n; i++){
			sum += i+1;
		}
		return sum;
	}


	int sumaRecursiva(int n){
		if (n<=1) {
			return n;
		} else {
			return n + sumaRecursiva(n-1);
		} 
	}


	int sumaDirecta(int n) {
		return n*(n + 1)/2;
	}

};