# Grafos


## Ejecución del programa
El programa se probó en el editor de texto en línea, Repl.it
Para compilar en Linux el programa, corra el siguiente comando en la terminal:
~~~
clang++-7 -pthread -std=c++17 -o main main.cpp
~~~
Y para ejecutar el programa:
~~~
./main
~~~

## Análisis de complejidad de los algoritmos
### Función: loadGraphMat(filename, vertices, edges)
#### Análisis de complejidad temporal
La función loadGraphMat() recibe como parámetro el nombre del archivo, y el número de vértices y arcos. El algoritmo itera cada línea del  archivo y mete los valores a la matriz adyacente. La complejidad de la función es O(n), donde n es el número de líneas en el archivo. Esto porque lee todas las líneas del archivo una vez.

### Función: loadGraphList(filename, vertices, edges)
#### Análisis de complejidad temporal
La función loadGraphList() recibe como parámetro el nombre del archivo, y el número de vértices y arcos. El algoritmo itera cada línea del  archivo y mete los valores a la lista adyacente. La complejidad de la función es O(n), donde n es el número de líneas en el archivo. Esto porque lee todas las líneas del archivo una vez.

### Función: DFS(initial_vertex, end_vertex)
#### Análisis de complejidad temporal
La función DFS() busca el nodo objetivo en todo el grafo, empezando desde un nodo dado. Usa el algoritmo Depth First Search que busca y se mantiene en una ruta de nodos hasta tocar pared, antes de buscar en otras rutas ramificadas. Para recorrer el grafo, se usa una copia de la lista adyacente. La complejidad del algoritmo se remonta a que, para el peor de los casos tendrá que recorrer todos los nodos y todos los arcos, por lo que la complejidad es O(n+a), donde n es el número de nodos y a el número de arcos.

### Función: BFS(initial_vertex, end_vertex)
#### Análisis de complejidad temporal
La función BFS() busca el nodo objetivo en todo el grafo, empezando desde un nodo dado. Usa el algoritmo Breadth First Search que busca en el grafo por niveles de profundidad. Donde recorre todos los nodos de un nivel, antes de pasar al siguiente. Para recorrer el grafo, se usa una la lista adyacente. La complejidad del algoritmo es la misma que el DFS, ya que para el peor de los casos tendrá que recorrer todos los nodos y todos los arcos, por lo que la complejidad es O(n+a), donde n es el número de nodos y a el número de arcos.