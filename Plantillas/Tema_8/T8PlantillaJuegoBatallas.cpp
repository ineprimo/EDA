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

using namespace std;

using Heroe = string;
using Villano = string;

class SistemaBatallas {
private:
    ...

public:
    // Coste:
    void aparece_villano(Villano const& v, int puntos, int valor){
        ...
        throw invalid_argument("Personaje ya existente");
        ... 
    }

    // Coste:
    void aparece_heroe(Heroe const& h, int puntos){
        ...
        throw invalid_argument("Personaje ya existente");
        ...
    }

    // Coste:
    void aprende_ataque(Heroe const& h, string const& ataque, int valor){
        ...
        throw invalid_argument("Heroe inexistente");
        ...
        throw invalid_argument("Ataque repetido");
        ...
    }

    // Coste:
    vector<pair<string,int>> mostrar_ataques(Heroe const& h){
        ...
        throw invalid_argument("Heroe inexistente");
        ...
        vector<pair<string,int>> res;
        ...
        return res;
    }

    // Coste:
    vector<pair<string,int>> mostrar_turnos(){
        vector<pair<string,int>> res;
        ...
        return res;
    }

    // Coste:
    bool villano_ataca(Villano const& v, Heroe const& h){
        ...
        throw invalid_argument("Villano inexistente");
        ...
        throw invalid_argument("Heroe inexistente");
        ...
        throw invalid_argument("No es su turno");
        ...
    }

    // Coste:
    bool heroe_ataca(Heroe const& h, string const& ataque, Villano const& v){
        ...
        throw invalid_argument("Villano inexistente");
        ...
        throw invalid_argument("Heroe inexistente");
        ...
        throw invalid_argument("No es su turno");
        ...
        throw invalid_argument("Ataque no aprendido");
        ...
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
            } else if (comando == "aparece_heroe") {
                cin >> h >> ptos;
                sistema.aparece_heroe(h, ptos);
            } else if (comando == "aprende_ataque") {
                cin >> h >> ataque >> valor;
                sistema.aprende_ataque(h, ataque, valor);
            } else if (comando == "mostrar_ataques") {
                cin >> h;
                auto ataques = sistema.mostrar_ataques(h);
                cout << "Ataques de " << h << endl;
                for (auto& [ataque,valor] : ataques) {
                    cout << ataque << " " << valor << "\n";
                }
            } else if (comando == "mostrar_turnos") {
                cout << "Turno: " << endl;
                auto turnos = sistema.mostrar_turnos();
                for (auto &[pers, puntos] : turnos) {
                    cout << pers << " " << puntos << "\n";
                }
            } else if (comando == "villano_ataca") {
                cin >> v >> h;
                bool derrotado = sistema.villano_ataca(v, h);
                cout << v << " ataca a " << h << endl;
                if (derrotado) cout << h << " derrotado" << endl;
            } else if (comando == "heroe_ataca") {
                cin >> h >> ataque >> v;
                bool derrotado = sistema.heroe_ataca(h, ataque, v);
                cout << h << " ataca a " << v << endl;
                if (derrotado) cout << v << " derrotado" << endl;
            }
        } catch (std::exception& e) {
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
    ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while(resuelveCaso()) { }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
