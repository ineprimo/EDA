// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> datos) {

    std::vector<int> sol(datos.size());

    for (int i = 0; i < datos.size(); ++i) {
        sol[i] = datos[i] * 2;
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Leer el número de elementos
    int n;
    std::cin >> n;

    std::vector<int> datos(n);

    if (n == 0) {

    }
    else {
        // Leer los datos de entrada
        for (int i = 0; i < n; ++i) {
            std::cin >> datos[i];
        }
    }    

    // Llamar a la función resolver para obtener la solución
    std::vector<int> sol = resolver(datos);

    // Escribir la solución
    for (int i = 0; i < sol.size(); ++i) {
        std::cout << sol[i] << " ";
    }
    std::cout << std::endl; // Nueva línea tras la solución

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