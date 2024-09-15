// // Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::pair<int, int> resolver(std::vector<int> datos) {

    int i = 1, prev, post;
    std::pair<int, int> sol;
    sol.first = 0;
    sol.second = 0;

    // recorre todo el vector
    for (int i = 1; i < datos.size() - 1; i++) {
        prev = datos[i - 1];
        post = datos[i + 1];

        if ((prev < datos[i]) && (datos[i] > post)) // pico
        {
            sol.first++;

        }
        else if ((prev > datos[i]) && (datos[i] < post))    // valle
        {
            sol.second++;
        }
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> datos;
    int size, a;
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> a;
        datos.push_back(a);
    }

    std::pair<int, int> sol = resolver(datos);

    // escribir sol
    std::cout << sol.first << " " << sol.second << std::endl;

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