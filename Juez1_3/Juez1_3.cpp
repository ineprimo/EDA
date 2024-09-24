#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int>& v, int pos) {
    
    //Damos por hecho que es menor desde el principio, a menos que se dé el caso contrario
    bool menor = true;

    //Recorremos el array 
    int i = pos + 1; 

    while (i < v.size() && menor) {

        int j = 0;

        while (j < pos + 1 && menor) {

            if (v[j] > v[i]) {

                menor = false;
            }

            j++;

        }

        i++;
    }

    return menor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, pos;
    std::cin >> n >> pos;

    //rellenamos el vector
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    // escribir sol
    if (resolver(v, pos)) {
        std::cout << "SI" << std::endl;

    }
    else {
        std::cout << "NO" << std::endl;
    }
      
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