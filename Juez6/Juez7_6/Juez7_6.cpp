//Denisa Juarranz Berindea
// Complejidad lineal O(n) siendo n el num de palabras del txt. Solo se recorre una vez de principio a fin

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <stack>
using namespace std;


using Pelicula = string;
using Actor = string;

using RepartoPelicula = map<Pelicula, vector<pair<Actor, int>>>;

void leerRepartos(int numPeliculas, RepartoPelicula& peliculas) {
    Pelicula peli; int nActores;
    Actor actor; int minutos = 0;
    vector <pair<Actor, int>> actores;
    pair<Actor, int> par;
    for (int i = 0; i < numPeliculas; ++i) {
        cin >> peli; cin >> nActores;

        for (int j = 0; j < nActores; ++j) {
            cin >> actor >> minutos;

            par.first = actor;
            par.second = minutos;

            actores.push_back(par);
        }

        peliculas.insert({ {peli, 0}, actores });
        actores.clear();
    }


}


map<pair<Pelicula, int>, pair<int, map<Actor, int>>>

procesarEmisiones(RepartoPelicula const& repartos, vector<string> const& secEmisiones) {

    map<pair<Pelicula, int>, pair<int, map<Actor, int>>> sol;

    pair<Pelicula, int> solP = { "", 0 };
    unordered_map <Pelicula, int> solPeli;

    pair<Actor, int> solA = { "",0 };
    map<Actor, int> solActor;
    map<Actor, int> solutionA;

    int cont = 0;

    for (auto emi : secEmisiones) {

        auto it = solPeli.find(emi);

        auto i = repartos.find(emi);

        if (it == solPeli.end()) {  
            solPeli.insert({ emi, 1 });

            for (auto j : i->second) {

                auto a = solActor.find(j.first);
                if (a != solActor.end())a->second += j.second;
                else solActor.insert({ j.first, j.second });
            }
        }
        else
        {
            it->second++;

            for (auto j : i->second) {

                auto a = solActor.find(j.first);

                a->second += j.second;
            }
        }

        it = solPeli.find(emi);

        if (it->second >= solP.second) {
            solP.second = it->second;
            solP.first = it->first;
        }
    }

    for (auto i : solActor) {
        if (solA.second < i.second) {
            solA.first = i.first;
            solA.second = i.second;
            solutionA.clear();
        }
        else if (solA.second == i.second) {
            solutionA.insert(i);
        }
    }
    solutionA.insert({ solA.first, solA.second });

    pair<int, map<Actor, int>> s = { solA.second, solutionA };
    sol.insert({ solP, s });

    return sol;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPelis, numEmisiones;
    map<pair<Pelicula, int>, pair<int, map<Actor, int>>> sol;
    cin >> numPelis;

    if (numPelis == 0)
        return false;

    // Lectura de los repartos de las peliculas
    RepartoPelicula repartos;
    leerRepartos(numPelis, repartos);

    // Lectura de la secuencia de peliculas emitidas en vector<string>
    cin >> numEmisiones;
    vector<string> secEmisiones(numEmisiones);
    for (string& s : secEmisiones) cin >> s;

    sol = procesarEmisiones(repartos, secEmisiones);

    //Escribimos el resultado
    for (auto par : sol) {

        cout << par.first.second << " " << par.first.first << endl;

        cout << par.second.first;

        for (auto actor : par.second.second) {
            cout << " " << actor.first;
        }
    }

    cout << endl;

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