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

    unordered_map<dni, int> conductores; // dni, puntos
    unordered_map<int, int> puntos; // puntos, cuantosconpuntos

public:
    void nuevo(const dni& d)  // o(1) es constasnte por insert
    {
        // conductores.insert({ d, 15 }); // basicamente

        auto [_, in] = conductores.insert({ d, 15 });
        if (!in) { // si in=false esq ya estaba
            throw domain_error("Conductor duplicado");
        }

        puntos[15]++; // {15, 0} -> {15, 1}
    }

    void quitar(const dni& d, int pts) 
    {
        auto it = conductores.find(d); // busca en conductores un dni d

        if (it != conductores.end()) // si no se ha llegado al final entonces lo habra encontrado
        {
            // restamos los pts
            int puntosActuales = it->second; // porq es [dni, puntos] (puntos es second en el pair)

            if (puntosActuales - pts < 0) it->second = 0;
            else it->second = puntosActuales - pts;

            // actualizamos tabla de pts
            puntos[puntosActuales]--; // suponemos que cambia
            puntos[it->second]++;
        }
        else {
            throw domain_error("Conductor inexistente");
        }
    }

    int consultar(const dni& d) const
    {
        auto it = conductores.find(d); // busca en conductores un dni d

        if (it != conductores.end()) // si no se ha llegado al final entonces lo habra encontrado
        {
            return it->second;
        }
        else {
            throw domain_error("Conductor inexistente");
        }
    }

    int cuantos_con_puntos(int p)
    {
        if (p < 0 || p > 15) throw domain_error("Puntos no validos");

        return puntos[p]; // devuelve el second {p, 13} -> devuelve 13
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
            if (orden == "nuevo") 
            {
                cin >> dni;
                dgt.nuevo(dni);
            }
            else if (orden == "quitar") 
            {
                cin >> dni >> puntos;
                dgt.quitar(dni, puntos);
            }
            else if (orden == "consultar") 
            {
                cin >> dni;
                puntos = dgt.consultar(dni);
                cout << "Puntos de " << dni << ": " << puntos << endl;
            }
            else if (orden == "cuantos_con_puntos") 
            {
                cin >> puntos;
                int i = dgt.cuantos_con_puntos(puntos);
                cout << "Con " << puntos << " puntos hay " << i << endl;
            }
            else 
            {
                cout << "OPERACION DESCONOCIDA\n";
            }
        }
        catch (domain_error e) 
        {
            cout << "ERROR: " << e.what() << endl;
        }

        cin >> orden;
    }
    
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