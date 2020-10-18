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
### Función: push(T val)
#### Análisis de complejidad temporal
La función push() agrega un nuevo valor al final de la lista, esta operación se realiza de forma constante. Sin embargo, luego ejecuta una función heapify() para ordenar los elementos, esta operación toma un tiempo logarítmico, ya que en cada iteración reduce el tamaño de la lista con la que trabaja a la mitad. O(log n)

### Función: pop()
#### Análisis de complejidad temporal
De forma similar a la función push(), la función pop() elimina el primer valor de la lista y luego ejecuta una función heapify(), un tanto diferente a la utilizada por la función push(), en la que también toma un tiempo logarítmico O(log n).

### Función: top()
#### Análisis de complejidad temporal
La función top() regresa el primer valor que se encuentra en la lista, si hacer modificaciones a esta. Siempre realizar el proceso de forma constante o O(1).

### Función: empty()
#### Análisis de complejidad temporal
La función empty() regresa un booleano describiendo si la lista se encuentra vacía o no. El tiempo de ejecución es constante o O(1).

### Función: size()
#### Análisis de complejidad temporal
La función size() regresa el tamaño de la lista, ocupada por los elementos insertados. El tiempo de ejecución es constante o O(1).