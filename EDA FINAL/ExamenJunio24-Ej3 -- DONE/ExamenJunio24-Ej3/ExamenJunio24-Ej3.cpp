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
#include <cassert>
#include <utility>

#include <unordered_map>
#include <map>
#include <list>
#include <set>

using namespace std;

using paciente = string;
using gravedad = int;

class urgencias {
protected:
    struct InfoPaciente {
        list<string>::iterator it_paciente;
        int gravedad_paciente;
    };

    unordered_map<paciente, InfoPaciente> pacientes;

    list<paciente> leves;
    list<paciente> medios;
    list<paciente> graves;

    list<paciente> recuperadosList;
    set<paciente> recuperadosSet;

public:

    // coste:
    void nuevo_paciente(paciente p, gravedad g) {
        auto [itP, ok] = pacientes.insert({ p, {list<string>::iterator{}, g} });
        if(!ok)
            throw domain_error("Paciente repetido");

        if(g < 1 || g > 3)
            throw domain_error("Gravedad incorrecta");
        
        if (g == 1) {
            leves.push_back(p);
            itP->second.it_paciente = prev(leves.end());
        }
        else if (g == 2) {
            medios.push_back(p);
            itP->second.it_paciente = prev(medios.end());
        }
        else if (g == 3) {
            graves.push_back(p);
            itP->second.it_paciente = prev(graves.end());
        }
    }

    // coste:
    int gravedad_actual(paciente p) const {
        auto itP = pacientes.find(p);
        if(itP == pacientes.end())
            throw domain_error("Paciente inexistente");
        return itP->second.gravedad_paciente;
    }

    // coste:
    paciente siguiente() {
        if (!graves.empty()) {
            paciente p = graves.front();
            graves.pop_front();
            pacientes.erase(p);
            //recuperadosList.push_back(p);    // SIN MAP NI ORDEN ALFB
            //recuperadosSet.insert(p);
            return p;
        }
        else if (!medios.empty()) {
            paciente p = medios.front();
            medios.pop_front();
            pacientes.erase(p);
            //recuperadosList.push_back(p);    // SIN MAP NI ORDEN ALFB
            //recuperadosSet.insert(p);
            return p;
        }
        else if (!leves.empty()) {
            paciente p = leves.front();
            leves.pop_front();
            pacientes.erase(p);
            //recuperadosList.push_back(p);    // SIN MAP NI ORDEN ALFB
            //recuperadosSet.insert(p);
            return p;
        }
        else
            throw domain_error("No hay pacientes");        
    }

    // coste:
    void mejora(paciente p) {
        auto itP = pacientes.find(p);
        if (itP == pacientes.end())
            throw domain_error("Paciente inexistente");

        if (itP->second.gravedad_paciente == 3) {
            itP->second.gravedad_paciente = 2;
            graves.erase(itP->second.it_paciente);
            medios.push_front(p);
            itP->second.it_paciente = medios.begin();
        }
        else if (itP->second.gravedad_paciente == 2) {
            itP->second.gravedad_paciente = 1;
            medios.erase(itP->second.it_paciente);
            leves.push_front(p);
            itP->second.it_paciente = leves.begin();
        }
        else if (itP->second.gravedad_paciente == 1) {
            paciente p = *itP->second.it_paciente;
            leves.erase(itP->second.it_paciente);
            pacientes.erase(itP);
            //recuperadosList.push_back(p);    // SIN MAP NI ORDEN ALFB
            recuperadosSet.insert(p);
        }
    }

    // coste:
    set<paciente> recuperados() const {
        return recuperadosSet;
    }


};

bool resuelveCaso() { // No tocar esta función
    string orden, pac;
    int grav;
    cin >> orden;
    if (!cin) return false;

    urgencias sala;

    while (orden != "FIN") {
        try {
            if (orden == "nuevo_paciente") {
                cin >> pac >> grav;
                sala.nuevo_paciente(pac, grav);
            }
            else if (orden == "gravedad_actual") {
                cin >> pac;
                int g = sala.gravedad_actual(pac);
                cout << "La gravedad de " << pac << " es " << g << '\n';
            }
            else if (orden == "siguiente") {
                string p = sala.siguiente();
                cout << "Siguiente paciente: " << p << '\n';
            }
            else if (orden == "recuperados") {
                auto lista = sala.recuperados();
                cout << "Lista de recuperados:";
                for (auto& p : lista)
                    cout << ' ' << p;
                cout << '\n';
            }
            else if (orden == "mejora") {
                cin >> pac;
                sala.mejora(pac);
            }
        }
        catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "---\n";
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
