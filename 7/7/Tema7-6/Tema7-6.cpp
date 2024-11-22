#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


using Actor = pair<string, int>;        // nombre mins
using Pelicula = string; // nombre emision
using Actores = map<string, int>; // nombre emision

using RepartosPeliculas = map<string, vector<Actor>>; //

using Solution = map<pair<Pelicula, int>, pair<int, map<string, int>>>;


void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas) {


    Pelicula peli; int numActores;
    Actor actor; int minutos = 0;

    string nombreA, nombreP;
    vector<Actor> actores;

    for (int i = 0; i < numPeliculas; ++i) {
        // ---------------- ACTORES ---------------------
        cin >> nombreP;        // titulo de la pelicula
        cin >> numActores;  // numero de actores en la pelicula

        // peli.first = nombreP;
         // rellena el vector de actores
        for (int j = 0; j < numActores; ++j) {
            cin >> nombreA >> minutos;
            Actor a = Actor(nombreA, minutos);

            actores.push_back(a);
        }
        peliculas.insert({ {nombreP, 0}, actores });
        actores.clear();
    }
}

 Solution procesarEmisiones(RepartosPeliculas const& repartos, vector<string> const& secEmisiones) {

     // sol_pelicula, pair<mins, sol_actores>
     Solution sol;


     pair<Pelicula, int> sol_peliculas = { "", 0 };
     unordered_map <Pelicula, int> pelis;

     pair<string, int> sol_actores_aux = { "",0 };
     map<string, int> actores;
     map<string, int> sol_actores;

     // contador de cuantas veces aparece
     for (auto e : secEmisiones) {

         // pelicula actual
         auto it = pelis.find(e);

         // reparto de la peli
         auto i = repartos.find(e);

         // si no esta en pelis
         if (it == pelis.end()) {
             pelis.insert({e, 1});

             // recorre el reparto
             for (auto a : i->second) {

                 // coge el actor
                 auto actor = actores.find(a.first);

                 // si no esta en actores
                 if (actor == actores.end()) {
                     actores.insert(a);
                 }
                 else {
                     actor->second += a.second;
                 }
             }
         }
         else {
             // aumenta las emisiones
             it->second++;

             // recorre el reparto
             for (auto a : i->second) {

                 // coge el actor
                 auto actor = actores.find(a.first);
                 actor->second += a.second;
             }
         }


         // contador de emisiones
         it = pelis.find(e);
         if (it->second >= sol_peliculas.second) {
             sol_peliculas = *it;
         }
     }

     // busca al actor con mas screentime
     for (auto a : actores) {

         if (sol_actores_aux.second < a.second) {
             sol_actores_aux = a;

             // corrige el mapa solucion
             sol_actores.clear();
             sol_actores.insert(sol_actores_aux);
         }
         else if (sol_actores_aux.second == a.second) {
             sol_actores.insert(a);
         }
     }


     pair<int, map<string, int>> aux = {sol_actores_aux.second, sol_actores};
     sol.insert({sol_peliculas, aux});

     return sol;
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
    for (string& s : secEmisiones)
    {
        cin >> s;

    }

    Solution sol = procesarEmisiones(repartos, secEmisiones);


    // using Solution = map<pair<Pelicula, int>, pair<int, map<string, int>>>;
    
    for (auto p : sol) {
        cout << p.first.second << " " << p.first.first << endl;
        cout << p.second.first;
        for (auto a : p.second.second) {

            cout << " " << a.first;
        }
        cout << endl;
    }
    

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