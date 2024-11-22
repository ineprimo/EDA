#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
using namespace std;


using Actor = pair<string, int>;        // nombre mins
using Pelicula = map<string, int>; // nombre emision

using RepartosPeliculas = map<string, vector<Actor>>; //


void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas) {

    int numActores;
    Actor actor; 
    string nombreA, nombreP;
    int min;
    vector<Actor> aux;

    for (int i = 0; i < numPeliculas; ++i) {
        // ---------------- ACTORES ---------------------
        cin >> nombreP;        // titulo de la pelicula
        cin >> numActores;  // numero de actores en la pelicula

       // peli.first = nombreP;
        // rellena el vector de actores
        for (int j = 0; j < numActores; ++j) {
            cin >> nombreA >> min;
            Actor a = Actor(nombreA, min);

            aux.push_back(a);
        }
        peliculas.insert({nombreP, aux});
        aux.clear();

    }

    peliculas;

}


void procesarEmisiones(RepartosPeliculas const& repartos, vector<string> const& secEmisiones) {
    
    // ----- PELI -----
    // pelicula mas emitida + veces emitida
    Pelicula p;      // Pelicula mas emitida
    map<Pelicula, int> emisiones;    // contador de numero de emisiones

    // CUENTA LAS PELICULAS
    int j = 0;
    while (j < secEmisiones.size()) {
        
        // si no esta registrado en emisiones
        auto e = emisiones.find(secEmisiones[j]);
        if (e == emisiones.end())
            // se registra
            emisiones.insert({ secEmisiones[j], 1});
        else
            // añade al contador
            e->second++;
        j++;
    }

    // ----- ACTOR ----
    // mapa con el nombre del actor y su screen time
    map<string, int> screentime;


    // cuenta actores
    it = emisiones.begin();
    while (it != emisiones.end()) {

        // saca el iterador de los actores de la peli
        string peli = it->first;
        auto it_actors = repartos.find(peli);

        // ACTORES
        int n_actores = it_actors->second.size();
        for (int i = 0; i < n_actores; i++) {

            string a_name = it_actors->second[i].first;
            int a_min = it_actors->second[i].second;
            auto ac = screentime.find(a_name);


            if (ac == screentime.end()) {
                screentime.insert({a_name, a_min * it->second });
            }
            else {
                ac->second = ac->second * it->second;
            }
        }

        it_actors = repartos.end();
        it++;
    }


    // COMPARA

    string peliMayor;
    auto it = peli.begin();
    peliMayor = (*it).first;
    while (it != peli.end())
    {
        if (peli[peliMayor] < (*it).second) {
            peliMayor = (*it).first;
        }

        it++;
    }



}


void procesarEmisiones2(RepartosPeliculas const& repartos, vector<string> const& secEmisiones) {



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

    procesarEmisiones(repartos, secEmisiones);

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