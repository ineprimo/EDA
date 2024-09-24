// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



bool Divisible(long long dato, int digito) {
    
    return dato % digito == 0;
}

// función que resuelve el problema
bool resolver(long long dato, int digito) {

    // setup

    // caso base
    if (digito <= 0) {
        return false;
    }
    else if (!Divisible(dato, digito)) {
        return false;
    }
    else if (dato%digito < 9) {

        std::cout << dato << std::endl;

        return resolver(dato+1, digito);
    }
    else {

        std::cout << dato << std::endl;

       return resolver(dato*10, digito + 1);
    }

}

void escribePolidivisibles(long long raiz, int maxDigitos) {

    // ajusta con 0s
    

    // llama a la funcion recursiva
    resolver(raiz, maxDigitos);

    //
    std::cout << "---" << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::pair<long long, int> par;

    std::cin >> par.first;
    std::cin >> par.second;

    if (!std::cin)
        return false;

    //std::vector<int> sol = resolver(par);

    // escribir sol
    escribePolidivisibles(par.first, par.second);


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