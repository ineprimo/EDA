/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no:
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <list>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

class Fecha {
    int _dia, _mes, _anio;

public:
    Fecha(int d = 0, int m = 0, int a = 0) : _dia(d), _mes(m), _anio(a) {}
    int dia() const { return _dia; }
    int mes() const { return _mes; }
    int anio() const { return _anio; }
    bool operator<(Fecha const& other) const {
        return _anio < other._anio ||
            (_anio == other._anio && _mes < other._mes) ||
            (_anio == other._anio && _mes == other._mes && _dia < other._dia);
    }
};

inline std::istream& operator>>(std::istream& entrada, Fecha& h) {
    int d, m, a; char c;
    std::cin >> d >> c >> m >> c >> a;
    h = Fecha(d, m, a);
    return entrada;
}

inline std::ostream& operator<<(std::ostream& salida, Fecha const& f) {
    salida << std::setfill('0') << std::setw(2) << f.dia() << '/';
    salida << std::setfill('0') << std::setw(2) << f.mes() << '/';
    salida << std::setfill('0') << std::setw(2) << f.anio();
    return salida;
}

using Codigo = string;
using Cliente = string;

class Tienda 
{
private:
    unordered_map<Codigo, map<Fecha, int>> almacen;

    unordered_map<Codigo, queue<Cliente>> clientes;

    unordered_map<Codigo, int> cantidad;

public:

    Tienda() {}

    vector<Cliente> adquirir(Codigo const& cod, Fecha const& f, int cant) 
    {
        vector<Cliente> res;

        while (cant > 0 && !clientes[cod].empty())  //mientras haya almacen 
        {
            Cliente cli = clientes[cod].front();

            clientes[cod].pop();
            res.push_back(cli);

            cant--;
        }

        if (cant > 0) 
        {
            almacen[cod][f] += cant;
            cantidad[cod] += cant;
        }
        else 
        {
            cantidad[cod] += res.size();
        }

        return res;
    }

    pair<bool, Fecha> vender(Codigo const& cod, Cliente const& cli)
    {
        auto itAlm = almacen.find(cod);

        if (itAlm != almacen.end()) 
        {
            auto& fechas = itAlm->second;

            if (!fechas.empty()) 
            {
                auto itF = fechas.begin();
                if (itF->second > 0) 
                {
                    Fecha fechaVenta = itF->first;

                    itF->second--;
                    cantidad[cod]--;

                    if (itF->second == 0) 
                    {
                        fechas.erase(itF);
                    }

                    return { true, fechaVenta };
                }
            }
        }

        clientes[cod].push(cli);
        return { false, Fecha() };
    }


    int cuantos(Codigo const& cod) const 
    {
        auto it = cantidad.find(cod);
        if (it != cantidad.end()) 
        {
            return it->second;
        }
        return 0;
    }

    bool hay_esperando(Codigo const& cod) const 
    {
        auto it = clientes.find(cod);
        // si hay clientes para el codigo y la cola no esta vacia:
        return it != clientes.end() && !it->second.empty();
    }
};

bool resuelveCaso() {
    std::string operacion, cod, cli;
    Fecha f;
    int cant;
    std::cin >> operacion;
    if (!std::cin)
        return false;

    Tienda tienda;

    while (operacion != "FIN") {
        if (operacion == "adquirir") {
            cin >> cod >> f >> cant;
            vector<Cliente> clientes = tienda.adquirir(cod, f, cant);
            cout << "PRODUCTO ADQUIRIDO";
            for (auto c : clientes)
                cout << ' ' << c;
            cout << '\n';
        }
        else if (operacion == "vender") {
            cin >> cod >> cli;
            pair<bool, Fecha> venta = tienda.vender(cod, cli);
            if (venta.first) {
                cout << "VENDIDO " << venta.second << '\n';
            }
            else
                cout << "EN ESPERA\n";
        }
        else if (operacion == "cuantos") {
            cin >> cod;
            cout << tienda.cuantos(cod) << '\n';
        }
        else if (operacion == "hay_esperando") {
            cin >> cod;
            if (tienda.hay_esperando(cod))
                cout << "SI\n";
            else
                cout << "NO\n";
        }

        std::cin >> operacion;
    }
    std::cout << "---\n";
    return true;
}


//#define DOMJUDGE
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
#endif

    return 0;
}