/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no:
*/

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <utility>

#include <unordered_map>
#include <map>
#include <list>

using namespace std;

using Heroe = string;
using Villano = string;

using AtaqueH = string;

class SistemaBatallas {
private:
    struct infoHeroe {
        int ptsVida;
        map<AtaqueH, int> ataques;
    };
    struct infoVillano {
        int ptsVida;
        int ptsAtaque;
    };
    unordered_map<Heroe, infoHeroe> heroes;
    unordered_map<Villano, infoVillano> villanos;

    list<string> turnos;
    unordered_map<string, list<string>::iterator> it_turnos;

public:
    // Coste:
    void aparece_villano(Villano const& v, int puntos, int valor) {
        if (heroes.count(v) > 0 || villanos.count(v) > 0)
            throw invalid_argument("Personaje ya existente");
        villanos[v] = { puntos, valor };
        turnos.push_back(v);
        it_turnos[v] = prev(turnos.end());
    }

    // Coste:
    void aparece_heroe(Heroe const& h, int puntos) {
        if(heroes.count(h) > 0 || villanos.count(h) > 0)
            throw invalid_argument("Personaje ya existente");
        heroes[h] = { puntos, {} };
        turnos.push_back(h);
        it_turnos[h] = prev(turnos.end());
    }

    // Coste:
    void aprende_ataque(Heroe const& h, string const& ataque, int valor) {
        auto it = heroes.find(h);
        if(it == heroes.end()) 
            throw invalid_argument("Heroe inexistente");

        auto itAtq = it->second.ataques.find(ataque);
        if(itAtq != it->second.ataques.end())
            throw invalid_argument("Ataque repetido");

        it->second.ataques[ataque] = valor;
    }

    // Coste:
    vector<pair<string, int>> mostrar_ataques(Heroe const& h) {
        
        auto itH = heroes.find(h);
        if(itH == heroes.end())
            throw invalid_argument("Heroe inexistente");
        
        vector<pair<string, int>> res;
        for (auto it = itH->second.ataques.begin(); it != itH->second.ataques.end(); ++it) {
            res.push_back({ it->first, it->second });
        }

        return res;
    }

    // Coste:
    vector<pair<string, int>> mostrar_turnos() {
        vector<pair<string, int>> res;
        
        for (const auto& nombre : turnos) {
            auto itH = heroes.find(nombre);
            if (itH != heroes.end()) res.push_back({ itH->first, itH->second.ptsVida });
            else {
                auto itV = villanos.find(nombre);
                if (itV != villanos.end()) res.push_back({ itV->first, itV->second.ptsVida });
            }
        }

        return res;
    }

    // Coste:
    bool villano_ataca(Villano const& v, Heroe const& h) {
        // Comprobación villano existe
        auto itV = villanos.find(v);
        if(itV == villanos.end())
            throw invalid_argument("Villano inexistente");

        // Comprobación heroe existe
        auto itH = heroes.find(h);
        if(itH == heroes.end())
            throw invalid_argument("Heroe inexistente");
        
        // Comprobación turno correcto
        if(turnos.front() != itV->first)
            throw invalid_argument("No es su turno");
        
        // Resetear turno
        turnos.pop_front();
        turnos.push_back(v);

        // Restar vida sin derrotar al héroe
        if (itV->second.ptsAtaque < itH->second.ptsVida) {
            itH->second.ptsVida -= itV->second.ptsAtaque;
            return false;
        }

        // Heroe derrotado, desaparece y true
        else {
            itH->second.ptsVida = 0;
            heroes.erase(itH);
            turnos.erase(it_turnos[h]);
            it_turnos.erase(h);
            return true;
        }
    }

    // Coste:
    bool heroe_ataca(Heroe const& h, string const& ataque, Villano const& v) {
        // Comprobación villano existe
        auto itV = villanos.find(v);
        if (itV == villanos.end())
            throw invalid_argument("Villano inexistente");

        // Comprobación heroe existe
        auto itH = heroes.find(h);
        if (itH == heroes.end())
            throw invalid_argument("Heroe inexistente");

        // Comprobación turno correcto
        if (turnos.front() != itH->first)
            throw invalid_argument("No es su turno");
        
        auto itA = itH->second.ataques.find(ataque);
        if(itA == itH->second.ataques.end())
            throw invalid_argument("Ataque no aprendido");

        // Resetear turno
        turnos.pop_front();
        turnos.push_back(h);

        // Restar vida sin derrotar al villano
        if (itA->second < itV->second.ptsVida) {
            itV->second.ptsVida -= itA->second;
            return false;
        }

        // Villano derrotado, desaparece y true
        else {
            itV->second.ptsVida = 0;
            villanos.erase(itV);
            turnos.erase(it_turnos[v]);
            it_turnos.erase(v);
            return true;
        }
    }
};


bool resuelveCaso() { // No tacar nada de esta función!
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
