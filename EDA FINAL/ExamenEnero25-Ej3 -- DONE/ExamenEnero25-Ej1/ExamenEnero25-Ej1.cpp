#include <iostream>
#include <stdexcept>
#include <fstream>
#include <list>
#include <unordered_map>
using namespace std;

using Jugador = string;
using Equipo = string;

class GestorFutbolistas {
private:
    struct InfoEquipo {
        list<Jugador> jugadores; // Jugadores actualmente fichados (más reciente al principio)
        unordered_map<Jugador, list<Jugador>::iterator> itJugador; // Para borrado O(1)
    };

    struct InfoJugador {
        list<Equipo> historial; // Historial de equipos, sin repeticiones
        unordered_map<Equipo, list<Equipo>::iterator> itEquipo; // Para borrado O(1) en historial
        Equipo equipoActual; // Equipo actual
    };

    unordered_map<Equipo, InfoEquipo> equipos;
    unordered_map<Jugador, InfoJugador> jugadores;

public:
    void fichar(const Jugador& jugador, const Equipo& equipo) {
        auto& infoJ = jugadores[jugador];

        // Si ya está en ese equipo, no hacemos nada
        if (infoJ.equipoActual == equipo) return;

        // Si estaba en otro equipo, lo quitamos de la lista de ese equipo
        if (!infoJ.equipoActual.empty()) {
            auto& infoEAnt = equipos[infoJ.equipoActual];
            infoEAnt.jugadores.erase(infoEAnt.itJugador[jugador]);
            infoEAnt.itJugador.erase(jugador);
        }

        // Eliminar el equipo del historial si ya estaba (para evitar repeticiones)
        auto itEq = infoJ.itEquipo.find(equipo);
        if (itEq != infoJ.itEquipo.end()) {
            infoJ.historial.erase(itEq->second);
            infoJ.itEquipo.erase(itEq);
        }

        // Añadir al final del historial y guardar el iterador
        infoJ.historial.push_back(equipo);
        auto itHist = infoJ.historial.end();
        --itHist;
        infoJ.itEquipo[equipo] = itHist;
        infoJ.equipoActual = equipo;

        // Añadir al nuevo equipo
        auto& infoENuevo = equipos[equipo];
        infoENuevo.jugadores.push_front(jugador);
        infoENuevo.itJugador[jugador] = infoENuevo.jugadores.begin();
    }

    Equipo equipoActual(const Jugador& jugador) const {
        auto it = jugadores.find(jugador);
        if (it == jugadores.end() || it->second.equipoActual.empty())
            throw domain_error("Jugador inexistente");
        return it->second.equipoActual;
    }

    int fichados(const Equipo& equipo) const {
        auto it = equipos.find(equipo);
        if (it == equipos.end())
            throw domain_error("Equipo inexistente");
        return it->second.jugadores.size();
    }

    list<Jugador> ultimosFichajes(const Equipo& equipo, int n) const {
        auto it = equipos.find(equipo);
        if (it == equipos.end())
            throw domain_error("Equipo inexistente");
        list<Jugador> res;
        int count = 0;
        for (const auto& jug : it->second.jugadores) {
            if (count++ == n) break;
            res.push_back(jug);
        }
        return res;
    }

    int cuantosEquipos(const Jugador& jugador) const {
        auto it = jugadores.find(jugador);
        if (it == jugadores.end()) return 0;
        return it->second.historial.size();
    }
};


bool resuelveCaso() {
    string operacion;
    cin >> operacion;
    if (!cin) return false;

    GestorFutbolistas gestor;
    while (operacion != "FIN") {
        try {
            if (operacion == "fichar") {
                string jugador, equipo;
                cin >> jugador >> equipo;
                gestor.fichar(jugador, equipo);
            }
            else if (operacion == "equipo_actual") {
                string jugador;
                cin >> jugador;
                string equipo = gestor.equipoActual(jugador);
                cout << "El equipo de " << jugador << " es " << equipo << endl;
            }
            else if (operacion == "fichados") {
                string equipo;
                cin >> equipo;
                int n = gestor.fichados(equipo);
                cout << "Jugadores fichados por " << equipo << ": " << n << endl;
            }
            else if (operacion == "ultimos_fichajes") {
                string equipo;
                int n;
                cin >> equipo >> n;
                list<string> ultimos = gestor.ultimosFichajes(equipo, n);
                cout << "Ultimos fichajes de " << equipo << ": ";
                for (const auto& jugador : ultimos) {
                    cout << jugador << " ";
                }
                cout << endl;
            }
            else if (operacion == "cuantos_equipos") {
                string jugador;
                cin >> jugador;
                int n = gestor.cuantosEquipos(jugador);
                cout << "Equipos que han fichado a " << jugador << ": " << n << endl;
            }
        }
        catch (std::exception& e) {
            cout << "ERROR: " << e.what() << "\n";
        }
        cin >> operacion;
    }

    cout << "---\n";
    return true;
}

//#define DOMJUDGE
int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}