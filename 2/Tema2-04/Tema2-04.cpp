// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>





// función que resuelve el problema
bool resolver(const std::vector<int>& datos, int ini, int fin, int k) {

    // casos base
    if(fin - ini == 1)
        return true;
    else if (fin - ini == 2) {
        return abs(datos[ini] - datos[ini + 1]) >= k;
    }

    // abs para que no de negativo (es la diferencia)
    int dif = abs(datos[fin-1] - datos[ini]);

    if (dif < k)
        return false;

    int mid = (fin + ini) / 2;
    bool izq = resolver(datos, ini, mid, k);
    bool der = resolver(datos, mid, fin, k);

    return der && izq && dif >= k;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> datos;
    int a, k, aux;

    std::cin >> a;  // numero de tiradas

    if (!std::cin)
        return false;

    std::cin >> k;  // k



    for (int i = 0; i < a; i++) {
        std::cin >> aux;
        datos.push_back(aux);
    }


    std::cout << (resolver(datos, 0, a, k) ? "SI" : "NO") << std::endl;

    // escribir sol


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