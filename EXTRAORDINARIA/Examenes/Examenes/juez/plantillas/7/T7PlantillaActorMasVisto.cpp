#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


using Pelicula = string;
using Actor = string;


void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas){
    Pelicula peli; int numActores;
    Actor actor; int minutos;
    for (int i = 0; i < numPeliculas; ++i){
        cin >> peli; cin >> numActores;
        ...
        for (int j = 0; j < numActores; ++j){
            cin >> actor >> minutos;
            ...
        }
    }
}


void procesarEmisiones(RepartosPeliculas const& repartos, vector<string> const& secEmisiones){
    ...
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPelis, numEmisiones;
    cin >> numPelis;
    if (numPelis == 0)
        return false;

    // Lectura de los repartos de las peliculas
    RepartosPeliculas repartos;
    leerRepartos(numPelis, repartos);

    // Lectura de la secuencia de peliculas emitidas en vector<string>
    cin >> numEmisiones;
    vector<string> secEmisiones(numEmisiones);
    for (string& s : secEmisiones) cin >> s;

    procesarEmisiones(repartos, secEmisiones);

    return true;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}