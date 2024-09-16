// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<int> resolver(std::vector<int> datos) {

    //Contadores
    std::vector<int> sol;
    int picos = 0;
    int valles = 0;

    //Tenemos que comparar cada dato con los que tiene a los lados
    //No queremos comparar el primero y el último
    for (int i = 1; i < datos.size() - 1; i++) {

        if (datos[i - 1] < datos[i] && datos[i] > datos[i + 1]) picos++;
        else if (datos[i - 1] > datos[i] && datos[i] < datos[i + 1]) valles++;
    }

    

    sol.push_back(picos);
    sol.push_back(valles);

    return sol;

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
    //Escribimos el pico y el valle
    std::cout << sol[0] << " " << sol[1] << std::endl;
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