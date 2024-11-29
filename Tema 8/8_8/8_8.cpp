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
#include <map>
#include <deque>
#include <unordered_map>
#include <algorithm>

using namespace std;

using Heroe = string;
using Villano = string;

using vida = int;
using dano = int;
using ataques = map<string, dano>;

class SistemaBatallas {
private:
    //El mapa guarda el nombre y luego la vida y el ataque
    unordered_map <string, pair<vida, dano>> villanos;
    unordered_map <string, pair<vida, ataques>> heroes;
    deque<string> turnos;

public:
    // Coste: logaritmico O(log n) debido a la insercion del ataque
    void aparece_villano(Villano const& v, int puntos, int valor) {
        if(villanos.count(v) == 0){
            villanos.insert({ v, {puntos, valor} });
            turnos.push_back(v);
        }
        else throw invalid_argument("Personaje ya existente");
       
    }

    // Coste: logaritmico O(log n) debido a la insercion del ataque
    void aparece_heroe(Heroe const& h, int puntos) {
        
        if (heroes.count(h) == 0) {
            ataques a;
            heroes.insert({ h, {puntos, a} });
            turnos.push_back(h);
        }
        else throw invalid_argument("Personaje ya existente");
        
    }

    // Coste: A causa de que los ataques son un map el coste es O(log n)
    void aprende_ataque(Heroe const& h, string const& ataque, int valor) {

        auto it = heroes.find(h);

        if (it != heroes.end()) {
            if(it->second.second.count(ataque) == 0) it->second.second.insert({ ataque, valor });
            else throw invalid_argument("Ataque repetido");
        }
        else throw invalid_argument("Heroe inexistente");
    }

    // Coste: O(n) siendo n el numero de ataques que tenga el heroe
    vector<pair<string, dano>> mostrar_ataques(Heroe const& h) {

        auto it = heroes.find(h);

        if (it != heroes.end()) {
            vector<pair<string, dano>> res;

            for (auto a : it->second.second) {res.push_back({ a.first, a.second }); }
            return res;
        }
        else throw invalid_argument("Heroe inexistente");
    }

    // Coste: lineal siendo n el numero de personajes que hay O(n)
    vector<pair<string, int>> mostrar_turnos() {
        vector<pair<string, int>> res;

        int tur = turnos.size();
        int i = 0;

        while (i < tur) {

            string it = *turnos.begin();
            auto itV = villanos.find(it);
            auto itH = heroes.find(it);

            if (itV != villanos.end()) { res.push_back({ itV->first, itV->second.first }); }
            else { res.push_back({ itH->first, itH->second.first }); }

            turnos.push_back(it);
            turnos.erase(turnos.begin());
            i++;
        }
        return res; 
    }

    // Coste:  Constante O(n) siendo n el numero de turnos
    //Esto es en el caso peor si su turno del eliminado es el ultimo a eliminar
    //Si no se muere es constante O(1)
    bool villano_ataca(Villano const& v, Heroe const& h) {
        
        auto itV = villanos.find(v);
       
        if (itV != villanos.end()) {
            auto itH = heroes.find(h);
            
            if (itH != heroes.end()) {

                string i = *turnos.begin();
                if (i == itV->first) {
                    itH->second.first -= itV->second.second;

                    turnos.erase(turnos.begin());
                    turnos.push_back(i);

                    if (itH->second.first <= 0) {
                        auto it = remove(turnos.begin(), turnos.end(),itH->first);
                        turnos.erase(it, turnos.end());
                        heroes.erase(itH);
                        return true;
                    }
                }
                else throw invalid_argument("No es su turno");
            }
            else throw invalid_argument("Heroe inexistente");
        }
        else throw invalid_argument("Villano inexistente");

        return false;
    }

    // Coste: Constante O(n) siendo n el numero de turnos
    //Esto es en el caso peor si su turno es el ultimo a eliminar
    //Si no se muere es constante O(1)
    bool heroe_ataca(Heroe const& h, string const& ataque, Villano const& v) {
        
        auto itV = villanos.find(v);
        if (itV != villanos.end()) {
            
            auto itH = heroes.find(h);
            if (itH != heroes.end()) {

                string i = *turnos.begin();
                if (i == itH->first) {

                    auto at = itH->second.second.find(ataque);
                    if (at != itH->second.second.end()) {
                        itV->second.first -= at->second;

                        turnos.erase(turnos.begin());
                        turnos.push_back(i);

                        if (itV->second.first <= 0) {
                            auto it = remove(turnos.begin(), turnos.end(), itV->first);
                            turnos.erase(it, turnos.end());
                            villanos.erase(itV);
                            return true;
                        }

                    }
                    else throw invalid_argument("Ataque no aprendido");
                }
                else throw invalid_argument("No es su turno");
            }
            else throw invalid_argument("Heroe inexistente");
        }
        else throw invalid_argument("Villano inexistente"); 
        return false;    
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
                for (auto par : ataques) {
                    cout << par.first << " " << par.second << "\n";
                }
            }
            else if (comando == "mostrar_turnos") {
                cout << "Turno: " << endl;
                auto turnos = sistema.mostrar_turnos();
                for (auto par : turnos) {
                    cout << par.first << " " << par.second << "\n";
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
