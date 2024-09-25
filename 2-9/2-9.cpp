// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// O(log n) - divide y vencerás
bool resolver(std::vector<int>& datos, int ini, int fin, int v) {
    int diff = fin - ini;

    if (diff == 1) return datos[ini] == v;

    int mit = (ini + fin) / 2;

    if (datos[ini] <= datos[mit]) // la primera mitad esta ordenada
    {
    	if (v >= datos[ini] && v < datos[mit]) // esta a la izq si el valor es menor
            return resolver(datos, ini, mit, v);
        return resolver(datos, mit, fin, v); // esta a la der
    }

    // esta desordenada
    if (v >= datos[mit] && v < datos[ini]) // mayor que el valor en medio y menor que el principio
        return resolver(datos, mit, fin, v); // esta a la der
    return resolver(datos, ini, mit, v);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n = 0, v = 0;
    std::cin  >> n >> v;

    if (n == -1)
        return false;

    std::vector<int> datos(n);
    for (int& i : datos)
        std::cin >> i;

	std::cout << (resolver(datos, 0, datos.size(), v) ? "SI" : "NO") << std::endl;
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
