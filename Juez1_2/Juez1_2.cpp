#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int>& v) {

    int pico = 0, valle = 0;

    for (int i = 1; i < v.size() - 1; i++) {

        if (v[i] < v[i - 1] && v[i] < v[i + 1])
        {
            valle++;
        }
        else if (v[i] > v[i - 1] && v[i] > v[i + 1])
        {
            pico++;
        }
    }

    //Reutilizamos el propio vector para devolver el resultado
    v.clear();
    v.resize(2);
    v[0] = pico;
    v[1] = valle;
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
    std::cout << v[0] << " " << v[1] << std::endl;

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
