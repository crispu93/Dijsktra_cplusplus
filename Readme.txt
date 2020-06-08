- El archivo dijkstra.cpp contiene una implementación en c++ de una clase graph con varios métodos para el manejo de datos.
- El constructor del objeto graph recibe como parámetro un entero n que representa el número de nodos con etiquetas 1,2,3,...,n-1.
- La clase graph contiene el método:
	void erdosRenyi(int m, int min, int max)
el cuál genera m aristas aleatorias de manera uniforme entre los n nodos con pesos en el intervalo [min,max]
- Dentro de la clase también se encuentran los métodos auxiliares
	void printEdges() 
	void printTofile(string ofile)
que imprimen las listas de adyacencia del grafo en la salida de la terminal y en archivo del ofile.csv respectivamente.
Finalmente la clase grpah contiene un método llamado
	graph dijkstra(int s)
que ejecuta el algoritmo de Dijkstra desde el nodo con etiqueta s, y regresa otro objeto del tipo graph que representa el arbol de caminos mínimos.

Para la visualización de los grafos se utilizaron los archivos .csv de salida del grafo original y del obtenido por el algoritmo de Dijkstra, en el programa Gephi. En la carpeta de imagenes se muestran ejemplos de dos grafos generados de manera aleatoria, uno con 10 nodos y uno con 5.
	
