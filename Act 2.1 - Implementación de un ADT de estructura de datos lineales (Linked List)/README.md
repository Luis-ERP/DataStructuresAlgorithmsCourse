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
### Función: add(T val)
#### Análisis de complejidad temporal
Para agregar un nuevo elemento a la lista, es necesario que primero recorra todos los elementos ya existentes. Es por esto que tienen una complejidad O(n).

### Función: find(T val)
#### Análisis de complejidad temporal
Para el peor de los casos, el elemento a buscar está hasta el final de la lista, por lo que igual tendría que recorrer toda la lista de forma lineal y es por esto que también tiene una complejidad O(n).

### Función: update(int index, T val)
#### Análisis de complejidad temporal
Ocurre lo mismo que con la función find(), en caso de que el elemento a modificar se encuentre hasta el final de la lista, tendría que recorrerla toda. Es por esto que su complejidad es O(n).

### Función: remove(int index)
#### Análisis de complejidad temporal
De igual manera, para eliminar un elemento, tiene que recorrer todos los nodos anteriores a ese. En el peor de los casos, tendría que recorrer toda la lista, la complejidad para este caso sería O(n).