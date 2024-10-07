// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// O(log n) - busqueda binaria
int resolver(std::vector<int>& datos, int ini, int fin) {
    int diff = fin - ini;

    if (diff == 0) return 0;
    if (diff == 1) return datos[ini];

    int mit = (ini + fin) / 2;

    // si a la mitad es menor que el ini el menor estara a la der
	if (datos[mit] < datos[ini])
		return resolver(datos, mit, fin);
	return resolver(datos, ini, mit);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n = 0;
    std::cin >> n;
    if (! std::cin)
        return false;

    std::vector<int> datos(n);
    for (int& i : datos)
        std::cin >> i;

    std::cout << resolver(datos, 0, datos.size()) << std::endl;
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