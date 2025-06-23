
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>

#include <unordered_map>

using namespace std;

using dni = string;
using puntos = int;

class carnet_puntos {
private:
    unordered_map<dni, puntos> conductores;

    vector<list<dni>> dnis = vector<list<dni>>(16);

    unordered_map <dni, list<dni>::iterator> posicion;

public:
    void nuevo(const dni& d) {
        auto [_, ok] = conductores.insert({ d, 15 });
        if (!ok) throw domain_error("Conductor duplicado");
        dnis[15].push_back(d);
        posicion[d] = prev(dnis[15].end());
    }

    void quitar(const dni& d, const puntos& p) {
        auto it = conductores.find(d);
        if (it == conductores.end()) throw domain_error("Conductor inexistente");
        int puntos_antes = it->second;
        int puntos_despues;
        if (puntos_antes <= p)
            puntos_despues = 0;
        else
            puntos_despues = puntos_antes - p;

        // Solo si cambia de puntos, actualiza las listas
        if (puntos_antes != puntos_despues) {
            dnis[puntos_antes].erase(posicion[d]);
            it->second = puntos_despues;
            dnis[puntos_despues].push_back(d);
            posicion[d] = prev(dnis[puntos_despues].end());
        }
    }

    void recuperar(const dni& d, const int& p) {
        auto it = conductores.find(d);
        if (it == conductores.end()) throw domain_error("Conductor inexistente");

        int puntos_antes = it->second;
        int puntos_despues;
        if (puntos_antes + p >= 15)
            puntos_despues = 15;
        else
            puntos_despues = puntos_antes + p;

        // Solo si cambia de puntos, actualiza las listas
        if (puntos_antes != puntos_despues) {
            dnis[puntos_antes].erase(posicion[d]);
            it->second = puntos_despues;
            dnis[puntos_despues].push_back(d);
            posicion[d] = prev(dnis[puntos_despues].end());
        }
        // Si no cambia de puntos, no se hace nada
    }

    puntos consultar(const dni& d) const {
        auto it = conductores.find(d);
        if (it != conductores.end()) {
            return it->second;
        }
        else throw domain_error("Conductor inexistente");
    }

    int cuantos_con_puntos(const puntos& p) {
        if (0 <= p && p <= 15) {
            int total = 0;
            for (auto it = conductores.begin(); it != conductores.end(); ++it) {
                if (it->second == p) ++total;
            }
            return total;
        }
        else throw domain_error("Puntos no validos");
    }

    list<dni> lista_por_puntos(const puntos& p) {
        if (0 <= p && p <= 15) {
            list<dni> aux;
            for (const auto& d : dnis[p]) aux.push_front(d);
            return aux;
        }
        else throw domain_error("Puntos no validos");
    }
};

bool resuelveCaso() {
    std::string orden, dni;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;

    carnet_puntos dgt;

    while (orden != "FIN") {
        try {
            if (orden == "nuevo") {
                cin >> dni;
                dgt.nuevo(dni);
            }
            else if (orden == "quitar") {
                cin >> dni >> punt;
                dgt.quitar(dni, punt);
            }
            else if (orden == "recuperar") {
                cin >> dni >> punt;
                dgt.recuperar(dni, punt);
            }
            else if (orden == "consultar") {
                cin >> dni;
                punt = dgt.consultar(dni);
                cout << "Puntos de " << dni << ": " << punt << '\n';
            }
            else if (orden == "cuantos_con_puntos") {
                cin >> punt;
                int cuantos = dgt.cuantos_con_puntos(punt);
                cout << "Con " << punt << " puntos hay " << cuantos << '\n';
            }
            else if (orden == "lista_por_puntos") {
                cin >> punt;
                auto const& lista = dgt.lista_por_puntos(punt);
                cout << "Tienen " << punt << " puntos:";
                for (auto const& dni : lista)
                    cout << ' ' << dni;
                cout << '\n';
            }
            else
                cout << "OPERACION DESCONOCIDA\n";
        }
        catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "---\n";
    return true;
}

int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}
