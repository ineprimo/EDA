#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int>& v) {

    std::vector<int> aux;

    //Intercambiar, para dejarlos todos a un lado y redimensionar 
    int i = 0;
    int newSize = 0;

    while (i < v.size()) {

        if (v[i] % 2 == 0)
        {
            aux.insert(aux.begin() + newSize, v[i]);
            newSize++;
        }

        i++;
    }

    v.resize(newSize);
    for (int i = 0; i < v.size(); i++) {
        v[i] = aux[i];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    //rellenamos el vector
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    };

    resolver(v);

    // escribir sol
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
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