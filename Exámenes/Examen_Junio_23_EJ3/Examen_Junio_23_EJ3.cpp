/*
Nombre completo:    Paula Alemany Rodríguez
DNI: 77861739T
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
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>

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

struct pairHash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);  // Hash del primer elemento
        auto h2 = std::hash<T2>{}(p.second); // Hash del segundo elemento
        return h1 ^ (h2 << 1); // Combina los hashes
    }
};

using Codigo = string;
using Cliente = string;
using Producto = pair<set<Fecha>, int>;

class Tienda {
private:
    list<pair<Cliente, Codigo>> listaEspera;
    unordered_set<pair<Cliente, Codigo>, pairHash> listaIndice;
    unordered_map<Codigo, Producto> almacen;

public:
    vector<Cliente> adquirir(Codigo const& cod, Fecha const& f, int cant) {
        vector<Cliente> c;
        Producto p;
        bool borrar = false;
        p.first.insert(f);
        p.second = cant;
        auto pro = almacen.find(cod);

        if (pro == almacen.end()) almacen.insert({ cod, p });   //Si el almacen no tiene el producto
        else {
            pro->second.first.insert(f);    //Añadimos la fecha
            pro->second.second += cant;     //Sumamos la cantidad de producto
        }

        //Logica de la lista de espera
        auto it = listaEspera.begin();
        while (it != listaEspera.end()) {
            if (it->second == cod) {
                borrar = vender(cod, it->first).first;
                if (borrar)
                {
                    c.push_back(it->first);
                    // Eliminamos del índice y de la lista
                    listaIndice.erase(*it); // Actualizamos el índice
                    it = listaEspera.erase(it); // Avanzamos el iterador tras borrar
                }
                else it++;
                
            }
            else it++;
       
        }

        return c;
    }

    pair<bool, Fecha> vender(Codigo const& cod, Cliente const& cli) {
        Fecha f;

        auto p = almacen.find(cod);
        bool sol = p != almacen.end();
        if (sol) {  //Lo tenemos en el almacen

            --p->second.second; //Quitamos la existencia que vendemos  

            f = *p->second.first.begin();

            //Si ya no quedan en la fecha lo eliminamos 
            if (p->second.second == 0) {
                p->second.erase(p->second.begin());
            }

            if (cuantos(cod) == 0) {
                //Eliminamos todo
                almacen.erase(p);
            }
        }
        //Si no está en el almacen añadimos a la persona a la lista de espera
        else { 
            if (!listaIndice.count({ cli, cod })) listaEspera.push_back({ cli, cod });
            listaIndice.insert({ cli,cod });
        } 
        return {sol, f };
    }

    ///Ahora esto es constante
    int cuantos(Codigo const& cod) const {

        //Tenemos que mirar la suma de todas las fechas
        auto p = almacen.find(cod);
        return p->second.second;
    }

    ///En el caso peor es lineal y tiene que recorrer toda la lista
    bool hay_esperando(Codigo const& cod) const {

        auto it = listaEspera.begin();

        while (it != listaEspera.end() && it->second != cod) it++;

        return it != listaEspera.end(); //Si es == es que nadie esta esperando
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