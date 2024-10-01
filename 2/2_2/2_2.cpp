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


void flipinv(const int& datos, int& inv) {
  
    if (datos < 10) {
        //  le suma el ultimo numero
        int a = inv * 10;
        int b = 9 - datos;

        inv = a + b;
    }
    else {

        // le quita un numero a datos y se lo añade a inv
        inv *= 10;
        inv += 9 - (datos % 10);
        flipinv(datos / 10, inv);
    }

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

    int aux = a, flipped = 0;

    flipinv(a, flipped);

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