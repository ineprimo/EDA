// Javier Tirado
// GDV-EDA72

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "hashmap_eda.h"
#include "treemap_eda.h"

using namespace std;

struct RepartosPeliculas {
    hashmap_eda_h::unordered_map<string, treemap_eda_h::map<string, int>> rp;
};


// O(peliculas * actores)

void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas){
    string peli;
    int nActores;

    string actor;
    int mins;

    for (int i = 0; i < numPeliculas; ++i){
        cin >> peli >> nActores;
        auto& reparto = peliculas.rp[peli];

        for (int j = 0; j < nActores; ++j){
            cin >> actor >> mins;
            reparto[actor] = reparto[actor] + mins;
        }
    }
}

//O(emisiones + actores)

void procesarEmisiones(RepartosPeliculas const& repartos, vector<string> const& secEmisiones){
    hashmap_eda_h::unordered_map<string, int> emisiones;
    hashmap_eda_h::unordered_map<string, int> ultEmis;
    string peliFav;
    int maxEmis = 0;

    for (int i = 0; i < secEmisiones.size(); ++i){
        auto& titulo = secEmisiones[i];
        int count = ++emisiones[titulo];
        ultEmis[titulo] = i;

        if ((count == maxEmis && ultEmis[titulo] > ultEmis[peliFav]) || count > maxEmis){
            maxEmis = count;
            peliFav = titulo;
        }
    }

    treemap_eda_h::map<string, int> tiemposTotales;

    for (const auto& titulo : secEmisiones)
    {
        if (repartos.rp.count(titulo)){
            auto& reparto = repartos.rp.at(titulo);
            for (const auto& [actor, tiempo] : reparto)
            {
                tiemposTotales[actor] += tiempo;
            }
        }
    }

    int maxT = 0;
    vector<string> actoresPreferidos;

    for (const auto& [actor, tiempo] : tiemposTotales){
        if (tiempo > maxT) {
            maxT = tiempo;
            actoresPreferidos = { actor };
        }
        else if (tiempo == maxT) {
            actoresPreferidos.push_back(actor);
        }
    }

    std::cout << maxEmis << " " << peliFav << std::endl;
    std::cout << maxT;
    for (const auto& actor : actoresPreferidos) std::cout << " " << actor;
    std::cout << endl;
}

bool resuelveCaso() {
    int p, e;
    cin >> p;

    if (p == 0) return false;

    RepartosPeliculas repartos;
    leerRepartos(p, repartos);

    cin >> e;
    vector<string> secuencia(e);

    for (auto& titulo : secuencia) cin >> titulo;

    procesarEmisiones(repartos, secuencia);

    return true;
}

//#define DOMJUDGE
int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
