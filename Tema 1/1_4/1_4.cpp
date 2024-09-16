// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<int> resolver(std::vector<int> datos) {

    //Como cambia el tamaño del vector estaría bien recorrerlo hacia atrás

    for (int i = datos.size() - 1; i >= 0; i--) {
        if (datos[i] % 2 != 0) {
            datos.erase(datos.begin() + i);
        }
    }

    return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    std::vector<int> datos;
    int n;
    int d;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> d;
        datos.push_back(d);
    }

    std::vector<int> sol = resolver(datos);

    // escribir sol
    for (int i = 0; i < sol.size(); i++) {
        std::cout << sol[i] << " ";
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