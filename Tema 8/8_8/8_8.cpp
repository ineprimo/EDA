/*
Nombre completo:    Paula Alemany Rodriguez
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
#include <unordered_map>
#include <algorithm>
#include <list>

using namespace std;

using Heroe = string;
using Villano = string;

class SistemaBatallas {
private:

    //Struct de la información de cada personaje
    struct infoVillano {

        int vida = 0;
        int dano = 0;
        list<pair<Villano, int>>::iterator it;  //Puntero a la lista de turnos
    };

    struct infoHeroe {

        int vida = 0;
        map<string, int> ataques;
        list<pair<Heroe, int>>::iterator it;    //Puntero a la lista de turnos
    };

    //El mapa guarda el nombre y luego la vida y el ataque
    unordered_map <Villano, infoVillano> villanos;
    unordered_map <Heroe, infoHeroe> heroes;
    list<pair<string, int>> turnos;

public:
    // Coste: logaritmico O(log n) debido a la insercion del ataque
    void aparece_villano(Villano const& v, int puntos, int valor) {
        if(villanos.count(v) == 0){
            villanos[v].vida = puntos;
            villanos[v].dano = valor;

            turnos.emplace_back(v, puntos);
            villanos[v].it = --turnos.end();
        }
        else throw invalid_argument("Personaje ya existente");
       
    }

    // Coste: logaritmico O(log n) debido a la insercion del ataque
    void aparece_heroe(Heroe const& h, int puntos) {
        
        if (heroes.count(h) == 0) {
            heroes[h].vida = puntos;

            turnos.emplace_back(h, puntos);
            heroes[h].it = --turnos.end();
            
        }
        else throw invalid_argument("Personaje ya existente");
        
    }

    // Coste: A causa de que los ataques son un map el coste es O(log n)
    void aprende_ataque(Heroe const& h, string const& ataque, int valor) {

        auto it = heroes.find(h);

        if (it != heroes.end()) {

            if (it->second.ataques.count(ataque) == 0) {
                heroes[h].ataques.insert({ ataque, valor });
            }
            else throw invalid_argument("Ataque repetido");
        }
        else throw invalid_argument("Heroe inexistente");
    }

    // Coste: O(n) siendo n el numero de ataques que tenga el heroe
    vector<pair<string, int>> mostrar_ataques(Heroe const& h) {

        auto it = heroes.find(h);

        if (it != heroes.end()) {
            vector<pair<string, int>> res;

            for (auto a : it->second.ataques) {res.push_back({ a.first, a.second }); }
            return res;
        }
        else throw invalid_argument("Heroe inexistente");
    }

    // Coste: lineal siendo n el numero de personajes que hay O(n)
    vector<pair<string, int>> mostrar_turnos() {
        vector<pair<string, int>> res;

        int tur = turnos.size();
        int i = 0;

        for (auto i : turnos) {
            res.emplace_back(i);
        }
        return res; 
    }

    // Coste: O(1) Como ya tenemos el iterador a eliminar es siempre contaste
    bool villano_ataca(Villano const& v, Heroe const& h) {
        
        auto itV = villanos.find(v);
       
        if (itV != villanos.end()) {
            auto itH = heroes.find(h);
            
            if (itH != heroes.end()) {

                if (turnos.front().first == itV->first) {  //Comprobamos si es su turno
                    itH->second.vida -= itV->second.dano;    //A la vida del heroe restamos el ataque
                    itH->second.it->second = itH->second.vida;

                    //Actualizamos el turno
                    turnos.pop_front();
                    turnos.emplace_back(v, itV->second.vida);   //Turno villano
                    itV->second.it = --turnos.end();

                    //Comprobamos si tiene que morir
                    if (itH->second.vida <= 0) {
                        turnos.erase(itH->second.it);
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

    // Coste: O(1) Como ya tenemos el iterador a eliminar es siempre contaste
    bool heroe_ataca(Heroe const& h, string const& ataque, Villano const& v) {
        
        auto itV = villanos.find(v);
        if (itV != villanos.end()) {
            
            auto itH = heroes.find(h);
            if (itH != heroes.end()) {

                if (turnos.front().first == itH->first) {

                    auto at = itH->second.ataques.find(ataque);
                    if (at != itH->second.ataques.end()) {
                        itV->second.vida -= at->second;
                        itV->second.it->second = itV->second.vida;

                        //Actualizamos el turno
                        turnos.pop_front();
                        turnos.emplace_back(h, itH->second.vida);   //Turno del heroe
                        itH->second.it = --turnos.end();

                        if (itV->second.vida <= 0) {
                            turnos.erase(itV->second.it);
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
