// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
   
  
    
    Set<int> a, b;
    int aux, size, i = 0;
    string ugu;


    std::cin >> size;
    for (i; i < size; i++) {
        std::cin >> aux;
        a.add(aux);
    }    
    
    std::cin >> size;
    i = 0;
    for (i; i < size; i++) {
        std::cin >> aux;
        b.add(aux);
    }

      if (!std::cin)
        return false;


    /// esto es por si no da el size de los sets al principio
    //getline(std::cin, ugu);
    //aux = std::stoi(ugu);
    //while (i < ugu.size()) {
    //    aux = (int)ugu.at(i) - '0';
    //    a.add(aux);

    //    i = i + 2;  // por los espacios
    //}

    //i = 0;
    //getline(std::cin, ugu);
    //aux = std::stoi(ugu);
    //while (i < ugu.size()) {
    //    aux = (int)ugu.at(i) - '0';
    //    b.add(aux);

    //    i = i + 2;  // por los espacios
    //}


    //Set<int> sol1 = a || b;
    //Set<int> sol2 = a && b;

    // escribir sol
    std::cout << (a || b) << std::endl << (a && b) << std::endl;

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