#include <iostream>
#include <stdexcept>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <list>

using namespace std;

using Cliente = string;
using Hotel = string;

class Agencia {
private:
    using InfoHotel = unordered_set<Cliente>;
    unordered_map<Cliente, Hotel> clientes;
    map<Hotel, InfoHotel> hoteles;

public:
    // O(1)
    Agencia() { };

    // O(log(H)), H = nº de hoteles
    void aloja(const Cliente& c, const Hotel& h) {
        auto [itC, insertado] = clientes.insert({ c, h }); // O(1)
        if (!insertado) { // c ya estaba registrado
            // Quitamos c del hotel en el que estaba
            hoteles[itC->second].erase(c); // O(log(H)) por el []. El erase es O(1)
            itC->second = h; // Se actualiza el hotel del cliente c
        }
        hoteles[h].insert(c); // Ponemos c como cliente del hotel h. O(log(H)) por el []. El insert es O(1)
    }

    // O(log(H)), H = nº de hoteles
    void desaloja(const Cliente& c) {
        auto it = clientes.find(c); // O(1)
        if (it != clientes.end()) {
            hoteles[it->second].erase(c); // O(log(H)) por el []. El erase es O(1)
            clientes.erase(c); // O(1)
        }
    }

    // O(1)
    const Hotel& alojamiento(const Cliente& c) const {
        try {
            return clientes.at(c); // O(1)
        }
        catch (std::out_of_range& e) {
            throw domain_error("Cliente no encontrado");
        }
    }

    // O(H),  H = nº de hoteles
    list<Hotel> listado_hoteles() const {
        list<Hotel> l;
        for (auto it = hoteles.cbegin(); it != hoteles.cend(); ++it)
            l.push_back(it->first);
        return l;
    }

    //O(max(log(H), MaxC)), con H = nº de hoteles y MaxC = max nº de clientes en un hotel.
    vector<Cliente> huespedes(const Hotel& h) const {
        auto itH = hoteles.find(h); // O(log(H))
        if (itH == hoteles.end()) throw domain_error("Hotel no encontrado");
        else {
            vector<Cliente> l(itH->second.size());
            for (Cliente const& c : itH->second) // O(MaxC)
                l.push_back(c);
            return l;
        }
    }

};


bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    Agencia agencia;
    while (comando != "FIN") {
        try {
            if (comando == "aloja") {
                Cliente c; Hotel h;
                cin >> c >> h;
                agencia.aloja(c, h);
            }
            else if (comando == "desaloja") {
                Cliente c;
                cin >> c;
                agencia.desaloja(c);
            }
            else if (comando == "alojamiento") {
                Cliente c; Hotel h;
                cin >> c;
                h = agencia.alojamiento(c);
                cout << c << " tiene reserva en el hotel " << h << endl;
            }
            else if (comando == "listado_hoteles") {
                cout << "Listado de hoteles: ";
                for (const auto h : agencia.listado_hoteles())
                    cout << h << " ";
                cout << endl;
            }
            else if (comando == "huespedes") {
                Hotel h;
                cin >> h;
                vector<Cliente> v = agencia.huespedes(h);
                cout << "Reservas del hotel " << h << ": ";
                sort(v.begin(), v.end());
                for (const auto c : v)
                    cout << c << " ";
                cout << endl;
            }
        }
        catch (std::exception& e) {
            cout << "ERROR: " << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("../../Ejercicios/08AgenciaHotelera/agencia1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
