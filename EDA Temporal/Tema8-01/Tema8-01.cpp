// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>

using namespace std;
using dni = string;

class carnet_puntos {
private:
    unordered_map<dni, int> conductores;
    unordered_map<int, int> puntos_conductores;
public:
    void nuevo(const dni& dni) {
        auto [_, ok] = conductores.insert({ dni, 15 });
        if (!ok) throw domain_error("Conductor duplicado");
        puntos_conductores[15]++;
    }

    void quitar(const dni& dni, int puntos) {
        auto dniIt = conductores.find(dni);
        if (dniIt != conductores.end()) {
            int puntosAnteriores = dniIt->second;
            int puntosNuevos = max(0, puntosAnteriores - puntos);

            puntos_conductores[puntosAnteriores]--;
            puntos_conductores[puntosNuevos]++;

            dniIt->second = puntosNuevos;
        }
        else throw domain_error("Conductor inexistente");
    }

    int consultar(const dni& dni) const {
        auto dniIt = conductores.find(dni);
        if (dniIt != conductores.end()) return dniIt->second;
        else throw domain_error("Conductor inexistente");
    }
    

    int cuantos_con_puntos(int puntos) {
        if (0 <= puntos && puntos <= 15) {
            return puntos_conductores[puntos];
        }
        else throw domain_error("Puntos no validos");
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string comando;

    if (!std::cin)
        return false;

    cin >> comando;
    carnet_puntos carnetsPuntos;

    while (comando != "FIN") {

        try {
            if (comando == "nuevo") {
                dni dni;
                cin >> dni;
                carnetsPuntos.nuevo(dni);
            }
            else if (comando == "quitar") {
                dni dni;
                int puntos;
                cin >> dni >> puntos;
                carnetsPuntos.quitar(dni, puntos);
            }
            else if (comando == "consultar") {
                dni dni;
                cin >> dni;
                int auxPuntos = carnetsPuntos.consultar(dni);
                cout << "Puntos de " << dni << ": " << auxPuntos << endl;
            }
            else if (comando == "cuantos_con_puntos") {
                int puntos;
                cin >> puntos;
                int auxCon = carnetsPuntos.cuantos_con_puntos(puntos);
                cout << "Con " << puntos << " puntos hay " << auxCon << endl;
            }
        }
        catch (exception& e) {
            cout << "ERROR: " << e.what() << endl;
        }

        cin >> comando;
    }

    cout << "---" << endl;
    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}