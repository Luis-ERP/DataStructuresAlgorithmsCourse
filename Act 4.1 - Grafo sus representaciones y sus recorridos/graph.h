/*
 * graph.cpp
 *
 *  Created on: 09/11/2020
 *      Author: Luis Ramirez
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;


class Graph {
	private:
	vector<vector<int>> adj_matrix;
	vector<vector<int>> adj_list;
	int nu_vertices;
	int nu_edges;

	public:
	Graph(){}

	// Loading functions
	void loadGraphMat(string filename, int vertices, int edges);
	void loadGraphList(string filename, int vertices, int edges);

	// Printing functions
	string printAdjMat();
	string printAdjList();

	// Search algorithms
	string DFS(int init_vertex, int target_vertex);
	string BFS(int init_vertex, int target_vertex);

	// Helper functions
	string print_vector(vector<int> vec);
};


string Graph::print_vector(vector<int> vec){
	string result = "";
	for (int i=0; i<vec.size(); i++){
		result = result + to_string(vec[i]) + " ";
	}
	return result;
}


void Graph::loadGraphMat(string filename, int vertices, int edges){
	nu_edges = edges;
	nu_vertices = vertices;
	// Create adjecency matrix
	for (int i=0; i<vertices; i++){
		vector<int> row(vertices, 0);
		adj_matrix.push_back(row);
	}
	// Read file
	ifstream file;
	file.open(filename);
	while(file.good()){
		string init_vertex;
		string end_vertex;
		getline(file, init_vertex, ',');
		if (init_vertex != ""){
			getline(file, end_vertex, '\n'); 
			init_vertex = init_vertex.substr(1, init_vertex.length()-1);
			end_vertex = end_vertex.substr(1, end_vertex.length()-2);
			int init_node = stoi(init_vertex);
			int end_node = stoi(end_vertex);
			// Fill graph
			adj_matrix[init_node][end_node] = 1;
			adj_matrix[end_node][init_node] = 1; 
		}
	}
}


void Graph::loadGraphList(string filename, int vertices, int edges){
	nu_vertices = vertices;
	nu_edges = edges;
	// Create adjecency list
	for (int i=0; i<vertices; i++){
		vector<int> row;
		adj_list.push_back(row);
	}
	// Read file
	ifstream file;
	file.open(filename);
	while(file.good()){
		string init_vertex;
		string end_vertex;
		getline(file, init_vertex, ',');
		if (init_vertex != ""){
			getline(file, end_vertex, '\n');
			init_vertex = init_vertex.substr(1, init_vertex.length()-1);
			end_vertex = end_vertex.substr(1, end_vertex.length()-2);
			int init_node = stoi(init_vertex);
			int end_node = stoi(end_vertex);
			// Fill graph
			adj_list[init_node].push_back(end_node);
			adj_list[end_node].push_back(init_node);
		}
	}
}


string Graph::printAdjMat(){
	string result = "";
	for(int i=0; i<adj_matrix.size(); i++){
		for(int j=0; j<adj_matrix[i].size(); j++){
			result = result + to_string(adj_matrix[i][j]) + " ";
		}
	}
	return result;
}


string Graph::printAdjList(){
	string result = "";
	for(int i=0; i<adj_list.size(); i++){
		result += "vertex " + to_string(i) + " : ";
		sort(adj_list[i].begin(), adj_list[i].end());
		for(int j=0; j<adj_list[i].size(); j++){
			result += to_string(adj_list[i][j]) + " ";
		}
	}
	return result;
}


string Graph::DFS(int init_vertex, int target_vertex){
	// Init vars
	vector<int> stack;
	vector<int> visited;
	int current = init_vertex;
	vector<vector<int>> adj_list_copy;

	// Copy adj_list
	for (int i=0; i<adj_list.size(); i++){
		adj_list_copy.push_back(adj_list[i]);
	}

	while (!(visited.size() >= nu_vertices)){ // O(n)
		// Check if the current is already in visited
		bool already_visited = false;
		for (int i=0; i<visited.size(); i++){ // O(menos de n)
			if(current == visited[i]) {
				already_visited = true;
				break;
			}
		}

		// Add to visited
		if (!already_visited) visited.push_back(current);

		// Check if target found
		if (current == target_vertex) break;

		// Remove already visited values
		for (int i=0; i<adj_list_copy[current].size(); i++){
			for (int j=0; j<visited.size(); j++){
				if(adj_list_copy[current][i] == visited[j])
					adj_list_copy[current].erase(adj_list_copy[current].begin()+i);
			}
		}
		if (adj_list_copy[current].size() > 0){
			stack.push_back(current);
			// Check for last child of current node
			int temp_index = current;
			current = adj_list_copy[current].back();
			adj_list_copy[temp_index].pop_back();
		} 
		else {
			// If you hit wall
			current = stack[stack.size()-1];
			stack.pop_back();
		}
	}

	// Add to the stack the found value to complete path
	stack.push_back(current);
	
	// Convert list to string
	string visited_str = print_vector(visited);
	string path_str = print_vector(stack);
	string result = "visited: " + visited_str + "path: " + path_str;
	result = result.substr(0, result.size()-1);
	return result;
}


string Graph::BFS(int init_vertex, int target_vertex){
	vector<vector<int>> queue;
	vector<vector<int>> visited;
	int current = init_vertex;
	int parent = -1;

	while (true){
		// Add to visited
		vector<int> temp_visited({parent, current});
		visited.push_back(temp_visited);
		// Check if found
		if (current == target_vertex) break;
		// Push children to queue if not visited
		for (int i=0; i<adj_list[current].size(); i++){
			int val = adj_list[current][i];
			bool already_visited = false;
			for (int j=0; j<visited.size(); j++){
				if (visited[j][1] == val){
					already_visited = true;
					break;
				}
			}
			vector<int> temp_queue({current, val});
			if (!already_visited) queue.push_back(temp_queue);
		}
		// Take from queue
		parent = queue[0][0];
		current = queue[0][1];
		queue.erase(queue.begin());
	}

	// Get the path
	vector<int> path;
	int find = target_vertex;
	do {
		for (int i=0; i<visited.size(); i++){
			if (visited[i][1] == find){
				path.insert(path.begin(), find);
				find = visited[i][0];
			}
		}
	} while (find != -1);

	// Convert visited into single arr
	vector<int> converted_visited;
	for (int i=0; i<visited.size(); i++){
		converted_visited.push_back(visited[i][1]);
	}

	// Convert list to string
	string visited_str = print_vector(converted_visited);
	string path_str = print_vector(path);
	string result = "visited: " + visited_str + "path: " + path_str;
	result = result.substr(0, result.size()-1);
	return result;	
}
