// PAULA SIERRA LUQUE
// EDA-GDV70

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

using Heroe = string;
using Villano = string;

class SistemaBatallas {
private:
    struct Personaje {
        int vida;
        int ataque; // Solo para villanos
        map<string, int> ataques; // Solo para héroes
    };

    map<Heroe, Personaje> heroes;
    map<Villano, Personaje> villanos;
    list<string> turnos; // Mantiene el orden de turnos

    bool es_turno(string const& nombre) {
        return !turnos.empty() && turnos.front() == nombre;
    }

    void avanzar_turno() {
        turnos.push_back(turnos.front());
        turnos.pop_front();
    }

public:
    // Coste: O(log N)
    void aparece_villano(Villano const& v, int puntos, int valor) {
        if (villanos.count(v) || heroes.count(v))
            throw invalid_argument("Personaje ya existente");
        villanos[v] = { puntos, valor, {} };
        turnos.push_back(v);
    }

    // Coste: O(log N)
    void aparece_heroe(Heroe const& h, int puntos) {
        if (heroes.count(h) || villanos.count(h))
            throw invalid_argument("Personaje ya existente");
        heroes[h] = { puntos, 0, {} };
        turnos.push_back(h);
    }

    // Coste: O(log N + M log M)
    void aprende_ataque(Heroe const& h, string const& ataque, int valor) {
        if (!heroes.count(h))
            throw invalid_argument("Heroe inexistente");
        auto& ataques = heroes[h].ataques;
        if (ataques.count(ataque))
            throw invalid_argument("Ataque repetido");
        ataques[ataque] = valor;
    }

    // Coste: O(log N + M log M)
    vector<pair<string, int>> mostrar_ataques(Heroe const& h) {
        if (!heroes.count(h))
            throw invalid_argument("Heroe inexistente");
        vector<pair<string, int>> res(heroes[h].ataques.begin(), heroes[h].ataques.end());
        return res;
    }

    // Coste: O(N)
    vector<pair<string, int>> mostrar_turnos() {
        vector<pair<string, int>> res;
        for (const auto& nombre : turnos) {
            if (heroes.count(nombre))
                res.emplace_back(nombre, heroes[nombre].vida);
            else
                res.emplace_back(nombre, villanos[nombre].vida);
        }
        return res;
    }

    // Coste: O(log N)
    bool villano_ataca(Villano const& v, Heroe const& h) {
        if (!villanos.count(v))
            throw invalid_argument("Villano inexistente");
        if (!heroes.count(h))
            throw invalid_argument("Heroe inexistente");
        if (!es_turno(v))
            throw invalid_argument("No es su turno");
        heroes[h].vida -= villanos[v].ataque;
        avanzar_turno();
        if (heroes[h].vida <= 0) {
            heroes.erase(h);
            turnos.remove(h);
            return true;
        }
        return false;
    }

    // Coste: O(log N)
    bool heroe_ataca(Heroe const& h, string const& ataque, Villano const& v) {
        if (!heroes.count(h))
            throw invalid_argument("Heroe inexistente");
        if (!villanos.count(v))
            throw invalid_argument("Villano inexistente");
        if (!es_turno(h))
            throw invalid_argument("No es su turno");
        if (!heroes[h].ataques.count(ataque))
            throw invalid_argument("Ataque no aprendido");

        villanos[v].vida -= heroes[h].ataques[ataque];
        avanzar_turno();
        if (villanos[v].vida <= 0) {
            villanos.erase(v);
            turnos.remove(v);
            return true;
        }
        return false;
    }
};



bool resuelveCaso() { // No tocar nada de esta función!
    string comando;
    cin >> comando;
    if (!cin) return false;

    SistemaBatallas sistema;
    Villano v; Heroe h;
    string ataque; int ptos; int valor;
    while (comando != "FIN") {
        try {
            if (comando == "aparece_villano") {
                cin >> v >> ptos >> valor;
                sistema.aparece_villano(v, ptos, valor);
            }
            else if (comando == "aparece_heroe") {
                cin >> h >> ptos;
                sistema.aparece_heroe(h, ptos);
            }
            else if (comando == "aprende_ataque") {
                cin >> h >> ataque >> valor;
                sistema.aprende_ataque(h, ataque, valor);
            }
            else if (comando == "mostrar_ataques") {
                cin >> h;
                auto ataques = sistema.mostrar_ataques(h);
                cout << "Ataques de " << h << endl;
                for (auto& [ataque, valor] : ataques) {
                    cout << ataque << " " << valor << "\n";
                }
            }
            else if (comando == "mostrar_turnos") {
                cout << "Turno: " << endl;
                auto turnos = sistema.mostrar_turnos();
                for (auto& [pers, puntos] : turnos) {
                    cout << pers << " " << puntos << "\n";
                }
            }
            else if (comando == "villano_ataca") {
                cin >> v >> h;
                bool derrotado = sistema.villano_ataca(v, h);
                cout << v << " ataca a " << h << endl;
                if (derrotado) cout << h << " derrotado" << endl;
            }
            else if (comando == "heroe_ataca") {
                cin >> h >> ataque >> v;
                bool derrotado = sistema.heroe_ataca(h, ataque, v);
                cout << h << " ataca a " << v << endl;
                if (derrotado) cout << v << " derrotado" << endl;
            }
        }
        catch (std::exception& e) {
            cout << "ERROR: " << e.what() << "\n";
        }
        cin >> comando;
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