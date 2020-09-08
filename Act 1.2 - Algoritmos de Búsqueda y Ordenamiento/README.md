### función: ordenaSeleccion()
##### Análisis de complejidad temporal
La complejidad temporal de este algoritmo es menor que cuadrática. Sin embargo, contemplamos que para el peor de los casos la complejidad se redondea a cuadrática, O(n^2). Esto porque contiene un for loop anidado dentro de otro for loop. Por lo que, por cada elemento del arreglo, el algoritmo recorrerá de nuevo el arreglo a partir del índice en donde se encuentra el elemento.

### función: ordenaBurbuja()
##### Análisis de complejidad temporal
La complejidad temporal el la misma que la de la función ordenaSeleccion() ya que, si bien no es el mismo algoritmo, recorren el arreglo de la misma forma, con un doble for loop anidado. Y es por eso que la complejidad también es casi O(n^2).

### función: ordenaMerge()
##### Análisis de complejidad temporal
La complejida temporal es O(n*log n) porque divide el arreglo en mitades hasta que ya no se pueda más y luego le toma un tiempo lineal en volverlas a juntar ya acomodadas.
##### Análisis de complejidad espacial
La complejidad espacial es lineal, o O(n) porque, al menos en este algoritmo de merge sort, se tiene que crear una copia de del arreglo para hacer el sort de manera correcta y más fácil.

### función: busqSecuencial()
##### Análisis de complejidad temporal
La complejida temporal de la función es lineal para el peor de los casos, o O(n). Esto porque tiene que recorrer todo el arreglo para buscar el valor.

### función: busqBinaria()
##### Análisis de complejidad temporal
La complejida temporal de la función es logarítmica para el peor de los casos, o O(log n). Esto porque por cada iteración, va descartando la mitad de los resultados. La desventaja es que para que funcione, el arreglo debe de estar ordenado.