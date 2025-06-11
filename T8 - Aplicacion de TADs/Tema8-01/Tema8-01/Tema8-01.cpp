// paula sierra luque
// eda gdv 70

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <set>

using namespace std;

using dni = string;

class carnet_puntos
{
private:
    
    unordered_map<dni, int> conductor;

    // correccion: para llevar un conteo directo de cuántos conductores tienen cada cantidad específica de puntos.
    unordered_map<int, int> puntos;

public:
    void nuevo(const dni& d)  // o(1) es constasnte por insert
    {
        // si no se puede insertar porque d esta repe -> ok=false
        auto [_, ok] = conductor.insert({ d, 15 });
        if (!ok) throw domain_error("Conductor duplicado");

        puntos[15]++;
    }

    void quitar(const dni& d, int pts) {
        auto itD = conductor.find(d);

        if (itD != conductor.end()) // si se ha encontrado
        {
            int puntosAntes = itD->second;
            if (itD->second - pts < 0) {
                itD->second = 0;
                
                puntos[puntosAntes]--;
                puntos[0]++;
            }
            else {
                itD->second -= pts;
                puntos[puntosAntes]--;
                puntos[itD->second]++;
            }
        }
        else 
        {
            throw domain_error("Conductor inexistente");
        }
    }

    int consultar(const dni& d) const
    {
        auto itD = conductor.find(d);

        if (itD != conductor.end()) // si se ha encontrado
        {
            return itD->second;
        }
        else
        {
            throw domain_error("Conductor inexistente");
        }
    }

    int cuantos_con_puntos(int p)
    {
        // NO O(n): hace recorrido entero del mapa
        //if (p >= 0 && p <= 15) 
        //{
        //    int conductoresConP = 0;
        //    for (auto it = conductor.begin(); it != conductor.end(); ++it) {
        //        if (it->second == p) {
        //            conductoresConP++;
        //        }
        //    }
        //    return conductoresConP;
        //}
        //else {
        //    throw domain_error("Puntos no validos");
        //}

        // MEJOR O(1) acceso directo al mapa
        if (0 <= p && p <= 15) {
            return puntos[p];
        }
        else throw domain_error("Puntos no validos");
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string orden, dni;
    int puntos;
    cin >> orden;
    
    if (!std::cin)
        return false;

    carnet_puntos dgt;

    while (orden != "FIN")
    {
        try 
        {
            if (orden == "nuevo") {
                cin >> dni;
                dgt.nuevo(dni);
            }
            else if (orden == "quitar") {
                cin >> dni >> puntos;
                dgt.quitar(dni, puntos);
            }
            else if (orden == "consultar") {
                cin >> dni;
                puntos = dgt.consultar(dni);
                cout << "Puntos de " << dni << ": " << puntos << endl;
            }
            else if (orden == "cuantos_con_puntos") {
                cin >> puntos;
                int i = dgt.cuantos_con_puntos(puntos);
                cout << "Con " << puntos << " puntos hay " << i << endl;
            }
            else {
                cout << "OPERACION DESCONOCIDA\n";
            }
        }
        catch (domain_error& e) 
        {
            cout << "ERROR: " << e.what() << endl;
        }

        cin >> orden;
    }


    // termina caso
    cout << "---" << endl;

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