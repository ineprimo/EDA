// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> datos) {

    bool dalton = true;
    int i = 1, prev, post;

    // suponiendo que son los dalton, se buscan errores en el vector
    // aka mira en todas las posiciones si  siguien un orden ascendente o descendiente
    while (dalton && i < datos.size() - 1) {
        prev = datos[i - 1];
        post = datos[i + 1];

       /* std::cout << ((prev < datos[i]) && (datos[i] < post)) << std::endl;
        std::cout << ((prev > datos[i]) && (datos[i] > post)) << std::endl;*/
        if (
            !(((prev < datos[i]) && (datos[i] < post)) ||
            ((prev > datos[i]) && (datos[i] > post))))
            dalton = false;
        i++;
    }


    return dalton;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int size, a;
    std::cin >> size;
    if (size == 0) 
        return false;

    std::vector<int> vec;
    for (int i = 0; i < size; i++) {
        std::cin >> a;
        vec.push_back(a);
    }

    bool sol = resolver(vec);

    // escribir sol
    if (sol) std::cout << "DALTON" << std::endl;
    else std::cout << "DESCONOCIDOS" << std::endl;

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