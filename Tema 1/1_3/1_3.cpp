// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> datos, int p) {

    //Dividimos el vector hasta p
    std::vector<int> mins;

    for (int i = 0; i <= p; i++) {
        mins.push_back(datos[i]);
    }
    
    //Buscamos el dato más alto del vector mins
    int max = mins[0];
    for (int i = 0; i < mins.size(); i++) {
        if (max < mins[i]) max = mins[i];
    }

    //Ahora comparamos el dato mayor de esa mitad con la otra parte del vector
    int i = p + 1;

    while (i < datos.size() && max < datos[i]) i++;

    return i == datos.size();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    std::vector<int> datos;
    int n;
    int p;
    int d;

    std::cin >> n;
    std::cin >> p;

    for (int i = 0; i < n; i++) {
        std::cin >> d;
        datos.push_back(d);
    }

    bool sol = resolver(datos, p);

    // escribir sol
    if (sol) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;
    
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