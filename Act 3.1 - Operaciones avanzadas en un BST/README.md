# Binary Search Tree


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
### Función: visit()
#### Análisis de complejidad temporal
La función visit() recorre todo el arbol de diferentes formas (pre-order, in-order, post-order y por nivel). En todas las formas, recorre todos los nodos del árbol solo una vez, por lo que la complejidad temporal se visit() es lineal o O(n).

### Función: height()
#### Análisis de complejidad temporal
Cada que se agrega un nodo, se actualiza una variable que contiene la altura del árbol. Cuando se manda a llamar esta función, solo tiene que consultar esa variable, por lo que la complejidad temporal es constante o O(1). 

### Función: ancestors(T val)
#### Análisis de complejidad temporal
La complejidad de este algoritmo viene de que tenemos que buscar el nodo en el árbol. En el caso ideal de que el árbol esté balanceado, la complejidad sería logarítmica. Sin embargo, para el peor de los casos, el árbol está degenerado y tomaría un tiempo O(n). 

### Función: whatlevelamI(T val)
#### Análisis de complejidad temporal
La función height devuelve el nivel al que se encuentra cierto nodo. Ocurre lo mismo que con la función ancestors(), tiene que buscar el nodo y eso toma tiempo logarítmico si el árbol está balanceado o tiempo lineal si está degenerado. Una vez que encuentra el nodo, solo regresa el atributo que almacena el nivel en el que se encuentra, ese tiempo es constante, O(1).