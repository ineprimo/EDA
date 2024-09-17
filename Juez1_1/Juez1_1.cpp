#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
bool resolver(std::vector<int> v) {

    //Damos por hecho que inicialmente la secuencia es correcta
    bool dalton = true;

    //Buscamos algún punto en el que sea incorrecta
    int indice = 0;
    while (indice < v.size() - 1 && v[indice] < v[indice + 1]) {
        indice++;
    }

    if (indice < v.size() - 1 && v[indice] >= v[indice + 1]) {
        dalton = false;
    }

    return dalton;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (!std::cin)
        return false;

    //rellenamos el vector
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    };

    // escribir sol
    if (resolver(v)) {
        std::cout << "DALTON" << std::endl;
    }
    else {
        std::cout << "DESCONOCIDOS" << std::endl;
    }

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