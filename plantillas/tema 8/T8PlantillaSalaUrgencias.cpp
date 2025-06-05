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

using namespace std;


using paciente = string;
using gravedad = int;

class urgencias {
protected:

public:

    // coste:
    void nuevo_paciente(paciente p, gravedad g) {
        ...
        throw domain_error("Paciente repetido");
        ...
        throw domain_error("Gravedad incorrecta");
        ...
    }
    
    // coste:
    int gravedad_actual(paciente p) const {
        ...
        throw domain_error("Paciente inexistente");
        ...
    }

    // coste:
    paciente siguiente() {
        ...
        throw domain_error("No hay pacientes");
        ...
    }

    // coste:
    void mejora(paciente p) {
        ...
    }

    // coste:
    list<paciente> recuperados() const {
        ...
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
            } else if (orden == "gravedad_actual") {
                cin >> pac;
                int g = sala.gravedad_actual(pac);
                cout << "La gravedad de " << pac << " es " << g << '\n';
            } else if (orden == "siguiente") {
                string p = sala.siguiente();
                cout << "Siguiente paciente: " << p << '\n';
            } else if (orden == "recuperados") {
                auto lista = sala.recuperados();
                cout << "Lista de recuperados:";
                for (auto & p : lista)
                    cout << ' ' << p;
                cout << '\n';
            } else if (orden == "mejora") {
                cin >> pac;
                sala.mejora(pac);
            } 
        } catch (std::domain_error e) {
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
    ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while(resuelveCaso()) { }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
