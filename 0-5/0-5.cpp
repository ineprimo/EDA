// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver(int datos) {
    return datos*2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++)
    {
	    int dato = 0;
        std::cin >> dato;
        std::cout << resolver(dato) << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}