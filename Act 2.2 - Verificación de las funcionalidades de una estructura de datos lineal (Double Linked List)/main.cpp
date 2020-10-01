/*
 * main.cpp
 *
 *  Created on: 30/09/2020
 *      Author: Luis Ramirez
 */

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "dlist.h"




using namespace std;

int main(int argc, char* argv[]) {
	DList<int> b1;
	string front, back;

	b1.add(2);
	front = "[2]";
	back = "[2]";
	cout << " 1 " <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
	cout << " 1 " <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

 	b1.add(3);
	b1.add(6);
	b1.add(10);
	front = "[2, 3, 6, 10]";
	back = "[10, 6, 3, 2]";
	cout << " 2 " <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
	cout << " 2 " <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

	cout << " 3 " <<	(3 == b1.find(10) ? "success\n" : "fail\n");

	cout << " 4 " <<	(-1 == b1.find(1) ? "success\n" : "fail\n");

	b1.update(1,13);
	front = "[2, 13, 6, 10]";
	back = "[10, 6, 13, 2]";
	cout << " 5 " <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
	cout << " 5 " <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

	b1.update(3,32);
	front = "[2, 13, 6, 32]";
	back = "[32, 6, 13, 2]";
	cout << " 6 " <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
	cout << " 6 " <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

	b1.remove(0);
	front = "[13, 6, 32]";
	back = "[32, 6, 13]";
	cout << " 7 " <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
	cout << " 7 " <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

	b1.remove(1);
	front = "[13, 32]";
	back = "[32, 13]";
	cout << " 8 " <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
	cout << " 8 " <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

	b1.remove(0);
	b1.remove(0);
	front = "[]";
	back = "[]";
	cout << " 9 " <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
	cout << " 9 " <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

	b1.add(1);
	b1.add(2);
	b1.add(3);
	b1.add(4);
	b1.add(5);

	b1.remove(0);
	front = "[2, 3, 4, 5]";
	back = "[5, 4, 3, 2]";
	cout << " 10 " <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
	cout << " 10 " <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

	b1.remove(3);
	front = "[2, 3, 4]";
	back = "[4, 3, 2]";
	cout << " 11 " <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
	cout << " 11 " <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

	b1.remove(1);
	front = "[2, 4]";
	back = "[4, 2]";
	cout << " 12 " <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
	cout << " 12 " <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

	b1.add(3);
	b1.add(6);
	b1.add(10);
	front = "[2, 4, 3, 6, 10]";
	back = "[10, 6, 3, 4, 2]";
	cout << " 13 " <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
	cout << " 13 " <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");
}