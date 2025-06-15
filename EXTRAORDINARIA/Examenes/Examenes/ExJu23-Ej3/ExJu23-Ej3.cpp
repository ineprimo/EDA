// Ejercicio 3: Gestion de una tienda (4 puntos)
// Tipo: APLICACIONES DE TADs

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <list>
#include <unordered_map>

using namespace std;

class Fecha {
    int _dia, _mes, _anio;

public:
    Fecha(int d = 0, int m = 0, int a = 0) : _dia(d), _mes(m), _anio(a) {}
    int dia() const { return _dia; }
    int mes() const { return _mes; }
    int anio() const { return _anio; }
    bool operator<(Fecha const& other) const
	{
        return _anio < other._anio ||
            (_anio == other._anio && _mes < other._mes) ||
            (_anio == other._anio && _mes == other._mes && _dia < other._dia);
    }
};

inline std::istream& operator>>(std::istream& entrada, Fecha& h)
{
    int d, m, a; char c;
    std::cin >> d >> c >> m >> c >> a;
    h = Fecha(d, m, a);
    return entrada;
}

inline std::ostream& operator<<(std::ostream& salida, Fecha const& f)
{
    salida << std::setfill('0') << std::setw(2) << f.dia() << '/';
    salida << std::setfill('0') << std::setw(2) << f.mes() << '/';
    salida << std::setfill('0') << std::setw(2) << f.anio();
    return salida;
}

using Codigo = string;
using Cliente = string;
using Existencias = int;

using FechasExistencias = list<std::pair<Fecha, Existencias>>;
using ListaEspera = list<Cliente>;

struct infoProducto
{
    Existencias existencias;
    ListaEspera listaEspera;
    FechasExistencias fechasExistencias;
};

using Productos = unordered_map<Codigo, infoProducto>;

class Tienda {
private:
    // al comienzo el almacén está vacío y no hay clientes en espera
    Productos productos;

    // gestiona la adquisición de CANT unidades (un entero no negativo del producto COD con fecha F).

    // Si hubiera clientes esperando la llegada de este producto, devuelve un vector con los identifcadores de
    // los clientes que han podido ser servidos, en el orden en que hicieron la petición.

    // El resto de unidades (si las hay) se guardan en el almacén
public:
    vector<Cliente> adquirir(Codigo const& cod, Fecha const& f, int cant)
	{
        vector<Cliente> atendidos;

        auto itPro = productos.find(cod);

        // si no lo tienes Y NADIE HA PREGUNTADO POR EL lo registras nuevo
        if (itPro == productos.end())
        {
            infoProducto info;
            info.existencias = cant;
            FechasExistencias e;
            e.push_back({ f, cant });
            info.fechasExistencias = e;
            ListaEspera l;
            info.listaEspera = l;
            productos.insert({cod, info});
        }
        // si lo tienes añades mas cantidades
        else
        {
            // si no tiene lista de espera -> adquieres tranquilamente
            if (itPro->second.listaEspera.empty())
            {
                itPro->second.existencias += cant;
                itPro->second.fechasExistencias.push_back({ f, cant });
            }
            else
            {
	            // atiendes a la lista de espera
                int i = 0;
                int esperando = itPro->second.listaEspera.size();
                while (i < esperando && cant > 0)
                {
                    atendidos.push_back(itPro->second.listaEspera.front());
                    itPro->second.listaEspera.pop_front();
                    cant--;
                    i++;
                }

                // si despues de atender aun te quedan productos -> adquieres
                if (cant > 0)
                {
                    itPro->second.existencias += cant;
                    itPro->second.fechasExistencias.push_back({ f, cant });
                }
            }
        }

        return atendidos;
    }

    // gestiona la venta de una unidad del producto COD al cliente CLI (un string sin espacios).
    // Si hay existencias, la operación devuelve true y la fecha del producto vendido (la menor entre las disponibles).
    // Si no hay existencias, devuelve false y añade al cliente a la lista de espera de este producto
    // (un cliente puede aparecer varias veces en la lista de espera).
    pair<bool, Fecha> vender(Codigo const& cod, Cliente const& cli)
	{
        auto itPro = productos.find(cod);
        bool meterALista = false; // control para hacer operacion de meter en lista

        // si no hay existencias
        if (itPro == productos.end())
        {
            // lo registras
            infoProducto info;
            info.existencias = 0;
            ListaEspera l;
            info.listaEspera = l;
            productos.insert({ cod, info });

            itPro = productos.find(cod);
            meterALista = true; // meter en lista de espera true
        }
        // si hay existencias
        if (itPro != productos.end() && itPro->second.existencias <= 0) meterALista = true; // meter en lista de espera true

        // meter en lista de espera, si no tienes existencias de ese producto
        if (meterALista)
        {
            itPro->second.listaEspera.push_back(cli);
            return { false, 0 };
        }
        // vender
        else
        {
            // la fecha del producto vendido (la menor entre las disponibles)
            Fecha f = itPro->second.fechasExistencias.back().first; // la fecha mas antigua

            itPro->second.existencias--;
            itPro->second.fechasExistencias.back().second--;

            if (itPro->second.fechasExistencias.back().second <= 0)
            {
                itPro->second.fechasExistencias.pop_back();
            }

            return { true, f };
        }
    }

    // devuelve cuántas unidades tiene la tienda del producto COD (independientemente de la fecha).
    // Si se trata de un producto que nunca se ha adquirido simplemente se devuelve 0
    int cuantos(Codigo const& cod) const
	{
        auto itPro = productos.find(cod);

        if (itPro == productos.end()) return 0;

        return itPro->second.existencias;
    }

    // indica si hay clientes en la lista de espera del producto COD.
    // Si se trata de un producto que nunca se ha adquirido simplemente se devuelve false
    bool hay_esperando(Codigo const& cod) const
	{
        auto itPro = productos.find(cod);

        if (itPro == productos.end()) return false;

        return !(itPro->second.listaEspera.empty());
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
    std::ifstream in("input.txt");
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