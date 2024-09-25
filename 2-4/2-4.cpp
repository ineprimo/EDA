// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// O(log n) 
bool resolver(std::vector<int>& n, int d, int ini, int fin) {
	const int cant = fin - ini;
	if (cant == 1) // unitario
		return true; // por definicion
	if (cant == 2) // doble
		return abs(n[ini + 1] - n[ini]) >= d;

	const int diff = abs(n[fin - 1] - n[ini]);
    if (diff < d)
        return false;

    // por enunciado, ambas mitades y el vector entero han de cumplir la condicion
	const int mitad = (ini + fin) / 2; // indice medio
	const bool izq = resolver(n, d, ini, mitad);
	const bool der = resolver(n, d, mitad, fin);

	return izq && der && diff >= d;
}

bool resuelveCaso() {
    int n = 0, d = 0;
    std::cin >> n >> d;

    if (! std::cin)
        return false;

    std::vector<int> datos(n);

    for (int& i : datos)
        std::cin >> i;

    std::cout << (resolver(datos, d, 0, datos.size()) ? "SI\n" : "NO\n" );
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}