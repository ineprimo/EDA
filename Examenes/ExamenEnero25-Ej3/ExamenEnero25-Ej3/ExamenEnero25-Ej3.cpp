// paula sierra luque
// gdv-eda70

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <list>
#include <unordered_map>

using namespace std;

using jugador = std::string;
using equipo = std::string;

class GestorFutbolistas 
{
private:

    struct InfoJugador
    {
        equipo actual;
        unordered_map<equipo, int> historialEquipos;
        list<jugador>::iterator posJugador;
    };

    unordered_map<jugador, InfoJugador> jugadores;
    unordered_map<equipo, list<jugador>> equipos;
        

public:
    // o(1) insertar y erase
    void fichar(jugador j, equipo e)
    {
        auto itJ = jugadores.find(j);

        if (itJ != jugadores.end()) // ya existe
        {
            // si esta en ese equipo, no se hace nada
            if (itJ->second.actual == e) return;

            ///--- cambio de equipo
            // eliminamos del equipo anterior
            auto& equipoAnterior = equipos[itJ->second.actual];
            equipoAnterior.erase(itJ->second.posJugador);

            // añadimos a nuevo equipo:
            auto& equipoNuevo = equipos[e]; // []: crea si no existia

            // insertamos al ppio:
            equipoNuevo.push_front(j);

            // actualizamos info del jugador
            itJ->second.actual = e;
            itJ->second.historialEquipos.insert({ e,0 });
            itJ->second.posJugador = equipoNuevo.begin();
        }
        else  // jugador nuevo
        {
            auto& equipoNuevo = equipos[e]; // []: crea si no existia

            equipoNuevo.push_front(j);
            
            // info del jugador
            jugadores[j].actual = e;
            jugadores[j].historialEquipos.insert({ e,0 });
            jugadores[j].posJugador = equipoNuevo.begin();
         
        }

        //cout << "fichar " << j << " en " << e << endl;
    }

    equipo equipo_actual(jugador j) const
    {
        auto it = jugadores.find(j);
        if (it == jugadores.end()) throw domain_error("Jugador inexistente");

        return it->second.actual;
    }

    int fichados(equipo e) const
    {
        auto it = equipos.find(e);
        if (it == equipos.end()) throw domain_error("Equipo inexistente");

        return it->second.size(); // mirar si es o(1)
    }

    list<jugador> ultimos_fichajes(equipo e, int n)
    {
        auto it = equipos.find(e);
        if (it == equipos.end()) 
            throw domain_error("Equipo inexistente");

        if (fichados(e) < n)
            return it->second;

        // ESTA FORMA ES O(n) porque copiamos la lista jugador por jugador a res
        list<jugador> res = it->second;
        while (res.size() > n)
        {
            res.pop_back();
        }

        return res;
    }

    int cuantos_equipos(jugador j) const
    {
        auto it = jugadores.find(j);
        if (it == jugadores.end())
            return 0;

        return it->second.historialEquipos.size();
    }
};

bool resuelve() {
    string orden;
    cin >> orden;
    if (!cin)
        return false;

    jugador jug; equipo equ; int n;
    GestorFutbolistas gest;

    while (orden != "FIN") {
        try {
            if (orden == "fichar") {
                cin >> jug >> equ;
                gest.fichar(jug, equ);
            }
            else if (orden == "equipo_actual") {
                cin >> jug;
                equipo e = gest.equipo_actual(jug);
                cout << "El equipo de " << jug << " es " << e << endl;
            }
            else if (orden == "fichados") {
                cin >> equ;
                int aux = gest.fichados(equ);
                cout << "Jugadores fichados por " << equ << ": " << aux << endl;
            }
            else if (orden == "ultimos_fichajes") {
                cin >> equ >> n;
                list<jugador> aux = gest.ultimos_fichajes(equ, n);
                cout << "Ultimos fichajes de " << equ << ": ";
                for (auto j : aux) {
                    cout << j << " ";
                }
                cout << endl;
            }
            else if (orden == "cuantos_equipos") {
                cin >> jug;
                int aux = gest.cuantos_equipos(jug);
                cout << "Equipos que han fichado a " << jug << ": " << aux << endl;
            }
            else {
                assert(false);
            }
        }
        catch (domain_error e) {
            cout << "ERROR: " << e.what() << '\n';
        }
        cin >> orden;
    }
    cout << "---\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelve())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
