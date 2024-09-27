#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(std::vector<int> v) {

    int n = v.size();
    int i = 0, j = 0, k = 0;

    while (i < n - 1)
    {
        if (v[i] < v[i + 1]) //Menor a mayor
            j++;
        else if (v[i] > v[i + 1]) //Mayor a menor
            k++;
        i++;
    }

    return k == i || j == i;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (n < 1) return false;

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