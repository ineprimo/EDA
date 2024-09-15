// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> datos, int pivot) {

    int i = 0, 
        izq = datos[0], 
        der = datos[datos.size() - 1];


    // si pivot es menor que cero se pasa por poco y si es mayor que 
    // size -1 se pasa por mucho; se cumple porque no hay nada que mirar
    if (pivot < 0 || pivot >= datos.size() - 1)
        return true;


    // busca el mayor de la parte izq
    while (i <= pivot) {
        if (datos[i] > izq) izq = datos[i];
        i++;
    }

    // busca el menor de la parte der
    while (i < datos.size()) {
        if (datos[i] < der) der = datos[i];
        i++;
    }

    // compara
    return izq<der;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> datos;
    int size, pivot, a;
    std::cin >> size;
    std::cin >> pivot;
    for (int i = 0; i < size; i++) {
        std::cin >> a;
        datos.push_back(a);
    }


    bool sol = resolver(datos, pivot);
    // escribir sol

    if (sol)
        std::cout << "SI" << std::endl;
    else
        std::cout << "NO" << std::endl;
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