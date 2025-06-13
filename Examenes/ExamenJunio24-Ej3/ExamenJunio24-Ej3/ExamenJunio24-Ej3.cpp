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


using namespace std;


using paciente = string;
using gravedad = int;

class urgencias {
protected:
    unordered_map<paciente, gravedad> salaEspera;

    list<paciente> graves;
    list<paciente> medios;
    list<paciente> leves;

    unordered_map<paciente, list<paciente>::iterator> localizacion;
    map<paciente, int> historialRecuperados;

public:

    // coste:
    void nuevo_paciente(paciente p, gravedad g) 
    {
        auto [_, in] = salaEspera.insert({ p, g });
        if(!in)
            throw domain_error("Paciente repetido");
        if(g < 1 || g > 3)
            throw domain_error("Gravedad incorrecta");

        if (g == 1) 
        {
            leves.push_back(p);
            localizacion[p] = prev(leves.end()); // guardamos iterador
        }
        else if (g == 2) 
        {
            medios.push_back(p);
            localizacion[p] = prev(medios.end()); // guardamos iterador
        }
        else 
        {
            graves.push_back(p);
            localizacion[p] = prev(graves.end()); // guardamos iterador
        }
    }

    // coste:
    int gravedad_actual(paciente p) const {
        auto it = salaEspera.find(p);
        if(it == salaEspera.end())
            throw domain_error("Paciente inexistente");

        return it->second;
    }

    // coste:
    paciente siguiente() 
    {
        paciente p;
        if (!graves.empty()) 
        {
            p = graves.front();
            graves.pop_front();
        }
        else if (!medios.empty()) 
        {
            p = medios.front();
            medios.pop_front();
        }
        else if(!leves.empty()) 
        {
            p = leves.front();
            leves.pop_front();
        }
        else 
        {
            throw domain_error("No hay pacientes"); 
        }

        salaEspera.erase(p);
        localizacion.erase(p);

        return p;
    }

    // coste: o(1) ya que no se hace ningun recorrido.
    void mejora(paciente p) 
    {
        int g = gravedad_actual(p);
        auto it = salaEspera.find(p);

        auto itListas = localizacion[p];

        // si esta leve abandona:
        if (g == 1) 
        {
            leves.erase(itListas);
            salaEspera.erase(p);
            localizacion.erase(p);

            historialRecuperados.insert({ p, 0 });
        }
        else if (g == 2) 
        {
            it->second--;

            /// pasar de lista medios a leves
            medios.erase(itListas);
            leves.push_front(p);
            localizacion[p] = leves.begin();
        }
        else 
        {
            it->second--;

            //pasar de lista graves a medios
            graves.erase(itListas);
            medios.push_front(p);
            localizacion[p] = medios.begin();
        }
    }
        
    // coste: o(n) siendo n el numero de gente recuperada
    list<paciente> recuperados() const 
    {
        list<paciente> result;

        for (auto it = historialRecuperados.begin(); it != historialRecuperados.end(); ++it)
        {
            result.push_back(it->first);
        }

        return result;
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
