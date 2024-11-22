#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
using namespace std;


using Pelicula = string;
using Actor = string;

using RepartosPeliculas = map<Pelicula, vector<pair<Actor, int>>>;

void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas) {
    Pelicula peli; int numActores;
    Actor actor; int minutos = 0;
    vector <pair<Actor, int>> actores;
    pair<Actor, int> par;
    for (int i = 0; i < numPeliculas; ++i) {
        cin >> peli; cin >> numActores;
        
            for (int j = 0; j < numActores; ++j) {
                cin >> actor >> minutos;

                par.first = actor;
                par.second = minutos;
                
                actores.push_back(par);
            }

            peliculas.insert({ {peli, 0}, actores });
            actores.clear();
    }

    
}


void procesarEmisiones(RepartosPeliculas const& repartos, vector<string> const& secEmisiones) {
    
    map<pair<Pelicula, int>, pair<Actor, int>> sol;
    //Primero recorremos el vector de emisiones
    //Nos guardamos cuantas veces aparece cada una

    pair<Pelicula, int> solP = { "", 0 };
    map <Pelicula, int> solPeli;

    pair<Actor, int> solA = { "",0 };
    map<Actor, int> solActor;

    int cont = 0;

    for (auto emi : secEmisiones) {

        auto it = solPeli.find(emi);

        //Buscamos el reparto de la peli
        auto i = repartos.find(emi);

        if (it == solPeli.end()) {  //La peli aparece por primera vez
            solPeli.insert({ emi, 1 });

            for (auto j : i->second) {

                //Metemos a los actores y su tiempo
                solActor.insert({ j.first, j.second });
            }
        }
        else 
        {
            it->second++; 

            for (auto j : i->second) {

                //Sumamos a los actores el tiempo de la pelicula
                auto a = solActor.find(j.first);

                a->second += j.second;
            }
        }
    }

    for (auto i : solPeli) {
        if (solP.second < i.second) {
            solP.first = i.first;
            solP.second = i.second;
        }
    }

    //Buscamos el actor con mas tiempo en pantalla
    for (auto i : solActor) {
        if (solA.second < i.second) {
            solA.first = i.first;
            solA.second = i.second;
        }
    }
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

    //Escribimos el resultado
    for (auto par : repartos) cout << par.first << " " << par.second << "\n";

    cout << "---------\n";

    return true;
}


//#define DOMJUDGE
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
#endif

    return 0;
}