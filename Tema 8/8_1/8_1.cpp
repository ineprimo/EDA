
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map> 
#include <unordered_set> 
using namespace std;

class carnet_puntos {
public:

    carnet_puntos() {

    }

    void nuevo(const string dni) {
        //Comprobamos si ya tenemos el dni
        if (conductores.count(dni) == 0) {	//El dni es nuevo
            conductores.insert({ dni, 15 });

            //Lo anadimos tambien al multiset
            puntos.insert(15);
        }
        else throw std::domain_error("Conductor duplicado");
    }

    void quitar(const string dni, const int punto) {
        //Comprobamos si el conductor existe
        auto it = conductores.find(dni);
        if (it != conductores.end()) {	//El dni existe
            
            auto i = puntos.find(it->second);
            puntos.erase(i);

            it->second -= punto;

            if (it->second < 0) it->second = 0;

            puntos.insert(it->second);
        }
        else throw std::domain_error("Conductor inexistente");
    }

    int consultar(const string dni) {
        //Comprobamos si el conductor existe
        auto it = conductores.find(dni);

        //El dni existe
        if (it != conductores.end()) { return it->second; }
        else throw std::domain_error("Conductor inexistente");
    }

    int cuantos_con_puntos(const int punto) {

        if (punto >= 0 && punto <= 15)	//Los puntos estan dentro del rango
        {
            return puntos.count(punto);
        }
        else throw std::domain_error("Puntos no validos");
    }

private:
    //Nos guardamos un map de dni??
    unordered_map<string, int> conductores;
    unordered_multiset<int> puntos;
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
