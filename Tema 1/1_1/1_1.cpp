// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> datos) {

    if (datos.size() == 1) return true;

    //Comprobamos si el vector está ordenado
    int n = datos[0];   //Primero comparamos con el primer dato
    int i = 1;  //Vamos comparando hacia atrás

    //Esto los tiene en cuenta de menor a mayor
    while (i < datos.size() && n < datos[i]) {
        n = datos[i];
        i++;
    }

    if (i != datos.size()) {
        //Si se corta miramos al contario que esté ordenado de mayor a menor
        n = datos[0];   //Primero comparamos con el primer dato
        i = 1;  //Vamos comparando hacia atrás

        while (i < datos.size() && n > datos[i]) {
            n = datos[i];
            i++;
        }
    }


    //Si llega al final del vector, está ordenado
    return i == datos.size();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    int d;
    std::cin >> n;

    if (n == 0)
        return false;

    //Le pasamos un vector con las alturas de las personas
    std::vector<int> datos;
    for (int i = 0; i < n; i++) {
        std::cin >> d;
        datos.push_back(d);
    }


    bool sol = resolver(datos);

    // escribir sol

    if (sol) {  //El vector está ordenado, son los dalton
        std::cout << "DALTON" << std::endl;
    }
    else {
        std::cout << "DESCONOCIDOS" << std::endl;
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
