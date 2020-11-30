# Splay Tree


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
### Función: add()
#### Análisis de complejidad temporal
La función add() agrega un nuevo valor al splay, recorre de forma recursiva el árbol y para el mejor de los casos, en cada iteración, se reduce a la mitad las posibilidades en las que recorre el árbol, tal que un BST. Por lo que su complejidad puede quedar en O(log n). Sin embargo, como primero agrega el elemento y luego se llama la función de reacomodo, existe la posibilidad de que el árbol esté desbalanceado y la complejidad aumente a O(n).

### Función: remove()
#### Análisis de complejidad temporal
La función remove() quita un valor del splay. Al igual que la función add(), la función remove() recorre el árbol de forma iterativa para buscar el nodo a eliminar, por lo que su complejidad para un caso estándar se queda en O(log n). También tiene el mismo problema que la función add() de que primero se busca al aobjeto y una que se elimina hace el reacomodo por lo que es posible que la alcance una complejidad de O(n) para el peor de los casos.

### Función: find()
#### Análisis de complejidad temporal
La función find() busca un valor a lo largo del splay tree. La complejidad de esta función es controversial ya que para el peor de los casos, el árbol puede estar desbalanceado y tomar un tiempo O(n) para encontrar el valor. Sin embargo, ya en la práctica se considera que son escasos estos casos de desbalance extremo y que en la mayoría de las veces va a tomar un tiempo O(log n) por lo mismo de que es un árbol binario.

### Función: inorder()
#### Análisis de complejidad temporal
La función inorder() recorre e imprime todos los valores que hay en el splay recorriendo cada nodo una sola vez. Por esto mismo es que tiene una complejidad O(n). Empieza por el nivel más bajo con el nodo más a la izquierda, y de ahí va agregando sus hijos y repite el procedimeinto de forma recursiva.

### Función: size()
#### Análisis de complejidad temporal
La función size() regresa la cantidad de valores que tienen el splay tree. El tiempo de ejecución es constante o O(1) ya que solo accede a la vairable size que se va actualizando cada que agregar o eliminan nodos.