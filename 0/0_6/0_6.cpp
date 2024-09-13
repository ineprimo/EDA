// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
std::vector<int> resolver(std::vector<int> datos) {
    for (int i = 0; i < datos.size(); i++) {
        datos[i] *= 2;
    }
    return datos;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size, a;
    std::cin >> size;

    if (size == -1)
        return false;


    std::vector<int> vec;

    for (int i = 0; i < size; i++) {
        std::cin >> a;
        vec.push_back(a);
    }

    std::vector<int> sol = resolver(vec);
    // escribir sol


    for (int i = 0; i < size; i++) {
        std::cout << sol[i] << " ";
    }
    std::cout << std::endl;

    return size > -1;
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