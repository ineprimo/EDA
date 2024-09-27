// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(const std::vector<int>& datos,int k, int ini, int fin) {

    int resta = 0;

    if (fin - ini == 0) {
        return true;
    }

    //Caso base, solo hay dos elementos
    if (fin - ini == 1) {

        //Si es negativo queremos hacerlo positivo
        resta = datos[fin] - datos[ini];

        if (datos[fin] < datos[ini]) resta *= -1;

        return resta >= k;
    }

    int mid = (ini + fin) / 2;

    bool izq = resolver(datos, k, ini, mid);
    bool der = resolver(datos, k, mid + 1, fin);

    resta = datos[fin] - datos[ini];
    if (datos[fin] < datos[ini]) resta *= -1;

    bool act = resta >= k;

    return izq && der && act;

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n = 0;
    int k = 0;
    
    std::vector<int> datos;
    int linea = 0;

    std::cin >> n >> k;
    
    
    for (int i = 0; i < n; i++) {
        std::cin >> linea;
        datos.push_back(linea);
    }

    int ini = 0;
    int fin = datos.size() - 1;

    if (!std::cin)
        return false;

    bool sol = resolver(datos, k, ini, fin);

    // escribir sol
    if (sol) {
        std::cout << "SI" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }


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