// INES PRIMO
//  GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>


// función que resuelve el problema
int resolver(const int& datos) {

    if (datos <= 9) {
        return 9 - datos;
    }

    // llamada recursiva
    int a = resolver(datos/10);

    // offset
    int b = 9-(datos%10);

    // solucion
    int sol = a * 10 + b;
    
    // return
    return sol;

}


int flip(const int& datos, int& cont) {

    if (cont == 0) {
        return datos;
    }

    int cc = cont - 1;

    // ultimos digitos 
    int a = flip(datos/10, cc);

    // primer digito
    int b = (datos % 10);

    //
    int sol = (b * std::pow(10, cont)) + a;

    //
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int a;
    std::cin >> a;

    int sol = resolver(a);
    // escribir sol

    std::cout << sol << " ";

    int power = 0, aux = a;
    while (aux > 10) {
        power++;
        aux = aux / 10;
    }
    int flipped = flip(sol, power);

    std::cout << flipped << std::endl;
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