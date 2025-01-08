#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <unordered_map>

using namespace std;

// TADs
#include <queue>

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

using ColaClientes = queue<Cliente>;

using ListaEspera = std::unordered_map<Codigo, ColaClientes>;         // codigo -> cola de clientes esperando a ese producto

// ALMACEN
using Existencias = std::unordered_map<Codigo, int>;                  // codigo -> existencias
using Adquisiciones = std::unordered_map<Codigo, std::vector<Fecha>>; // codigo -> todas los productos con ese codigo y sus fechas

class Tienda {
private:
    Existencias existencias;
    Adquisiciones adquisiciones;
    ListaEspera listaEspera;

public:
	// al comienzo el almacen esta vacio y no hay clientes en espera
    Tienda()
    {
        
    }

    // gestiona la adquisición de CANT unidades (un entero no negativo) del producto COD con fecha F
    // Si hubiera clientes esperando la llegada de este producto, devuelve un vector con los identificadores de los clientes
    // que han podido ser servidos, en el orden en que hicieron la petición
    // El resto de unidades (si las hay) se guardan en el almacén
    vector<Cliente> adquirir(Codigo const& cod, Fecha const& f, int cant)
	{
        // --- gestion de cola
        std::vector<Cliente> clientesServidos; // clientes que se han podido servir

        if(!listaEspera[cod].empty()) // si hay cola
        {
            // vaciar cola
            int i = 0;
            while(!listaEspera[cod].empty() && i <= cant)
            {
                clientesServidos.push_back(listaEspera[cod].front());
                listaEspera[cod].pop();
                cant--;
                i++;
            }
        }

        // --- guardo en el almacen
        // existencias
        if(!existencias.count(cod))
        {
			existencias.insert({cod, cant});
        }
        else
        {
			existencias[cod] += cant;
        }

	    // adquisiciones

        if(!adquisiciones.count(cod))
        {
	        std::vector<Fecha> fechas(cant);
	        for(int i = 0; i < cant; i++)
	        {
	            fechas[i] = f;
	        }
            adquisiciones.insert({ cod, fechas });
        }
        else
        {
            for(int i = 0; i < cant; i++)
            {
                adquisiciones[cod].push_back(f);
            }
        }

        return clientesServidos;
    }

    // gestiona la venta de una unidad del producto COD al cliente CLI
    // Si hay existencias, la operación devuelve true y la fecha del producto vendido
    // (la menor entre las disponibles).
    // Si no hay existencias, devuelve false y añade al cliente a la lista de espera de este producto
    // (un cliente puede aparecer varias veces en la lista de espera)
    pair<bool, Fecha> vender(Codigo const& cod, Cliente const& cli)
	{
        // si hay existencias
        if(existencias[cod] > 0)
        {
            existencias[cod]--;

            Fecha menorFecha (INT_MAX, INT_MAX,INT_MAX );

            int posMenor = -1;
            for(int i = 0; i < adquisiciones[cod].size(); i++)
            {
	            if(adquisiciones[cod][i] < menorFecha)
	            {
                    menorFecha = adquisiciones[cod][i];
                    posMenor = i;
	            }
            }

            // eliminar esa fecha del vector de su cod
            Fecha aux = adquisiciones[cod][posMenor];
            adquisiciones[cod][posMenor] = adquisiciones[cod][adquisiciones[cod].size() - 1];
            adquisiciones[cod][adquisiciones[cod].size() - 1] = aux;
            adquisiciones[cod].pop_back();

            return { true, menorFecha };
        }
        // si no hay existencias
        else
        {
            if(!listaEspera.count(cod))
            {
                std::queue<Cliente> cola;
                cola.push(cli);
                listaEspera.insert({ cod, cola });
            }
            else
            {
	            listaEspera[cod].push(cli);
            }
	        return { false, {-1,-1,-1}};
        }
    }

    // devuelve cuántas unidades tiene la tienda del producto COD (independientemente de la fecha).
    // Si se trata de un producto que nunca se ha adquirido simplemente se devuelve 0
    int cuantos(Codigo const& cod) const
	{
        if ((existencias.find(cod))->second > 0) return (existencias.find(cod))->second;
        else return 0;
    }

    // indica si hay clientes en la lista de espera del producto COD
    // Si se trata de un producto que nunca se ha adquirido simplemente se devuelve false
    bool hay_esperando(Codigo const& cod) const
	{
        if (!existencias.count(cod) || !listaEspera.count(cod) || listaEspera.find(cod)->second.empty()) return false;
        else return true;
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