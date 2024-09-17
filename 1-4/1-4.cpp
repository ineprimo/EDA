// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int>& datos) {
    int n = 0;

    for (int i = 0; i < datos.size(); i++)
    {
	    if (datos[i] % 2 == 0) // si es impar
	    {
            datos[n] = datos[i]; 
            n++;
	    }
    }

	datos.resize(n);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n;
    std::cin >> n;

    std::vector<int> datos(n);
    for (int i = 0; i < n; i++)
        std::cin >> datos[i];

    resolver(datos);
    
	for (const int dato : datos)
        std::cout << dato << " ";
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