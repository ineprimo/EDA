// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<int> resolver(std::vector<int> datos) {

    int imp = -1;   // indice para el primer impar que encuentre
    
    int i = 0;
    while (i < datos.size()) {

        if (datos[i] % 2 == 1 && imp == -1)    // impar
        {
            imp = i;
            i++;
        }
        else if (datos[i] % 2 == 0 && imp != -1)     // par e impar cogido
        {
            // intercambia posiciones
            int aux = datos[imp];

            datos[imp] = datos[i];
            datos[i] = aux;

            i = imp;

            // reinicia indices
            imp = -1;

        }
        else
            i++;
    }

    // resize 
    if(imp != -1)
        datos.resize(imp);

    return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    std::cin >> a;

    std::vector<int> vec;

    for (int i = 0; i < a; i++) {
        std::cin >> b;
        vec.push_back(b);
    }

    std::vector<int> sol = resolver(vec);


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