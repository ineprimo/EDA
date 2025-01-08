// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <list>

using namespace std;
using Rio = string;
using Pantano = string;

class ConHidrografica {
private:
    struct InfoPantano {
        int capacidad;
        int carga;
    };
    struct InfoRio {
        unordered_map<Pantano, InfoPantano> pantanos;
        int carga;
    };

    unordered_map<Rio, InfoRio> rios;

public:
    ConHidrografica() {};

    void an_rio(const Rio& r) {
        // si r ya esta en rios, no se inserta
        rios.insert({ r, InfoRio() });
    }

    void an_pantano(const Rio& r, const Pantano& p, int cap, int carga) 
    {
        auto itRio = rios.find(r);
        if (itRio != rios.end()) {
            auto [_,ok] = itRio->second.pantanos.insert({ p, {cap, min(cap, carga)} }); // {pantano, infopantano}
            // si el pantano ya estaba en el rio: ok = false
            // si insertamos el pantano, sumamos su carga al rio
            if (ok) itRio->second.carga += min(cap, carga);
            
        }
    }

    void embalsar(const Rio& r, const Pantano& p, int carga) {
        auto itRio = rios.find(r);
        if (itRio != rios.end()) {
            auto itPantano = itRio->second.pantanos.find(p);
            if (itPantano != itRio->second.pantanos.end()) {
                int incremento = min(carga, itPantano->second.capacidad - itPantano->second.carga);
                itPantano->second.carga += incremento;
                itRio->second.carga += incremento;
            }
        }
    }

    int embalsado_pantano(const Rio& r, const Pantano& p) const {
        try {
            return rios.at(r).pantanos.at(p).carga;
        }
        catch(out_of_range& e){
            return -1;
        }
    }

    int reserva_cuenca(const Rio& r) const {
        try {
            return rios.at(r).carga;
        }
        catch (out_of_range& e) {
            return -1;
        }
    }
    void trasvase(const Rio& r1, const Pantano& p1, const Rio& r2, const Pantano& p2, int n) {
        auto itRio1 = rios.find(r1);
        auto itRio2 = rios.find(r2);
        if (itRio1 != rios.end() && itRio2 != rios.end()) {
            auto itPantano1 = itRio1->second.pantanos.find(p1);
            auto itPantano2 = itRio2->second.pantanos.find(p2);
            if (itPantano1 != itRio1->second.pantanos.end() && 
                itPantano2 != itRio2->second.pantanos.end()) {
                if (n <= itPantano1->second.carga && n <=
                    itPantano2->second.capacidad - itPantano2->second.carga) {
                    itPantano1->second.carga -= n;
                    itRio1->second.carga -= n;
                    itPantano2->second.carga += n;
                    itRio2->second.carga += n;
                }
            }
        }
    }
};


bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    ConHidrografica rios;
    while (comando != "FIN") {
        try {
            if (comando == "an_rio") {
                Rio r;
                cin >> r;
                rios.an_rio(r);
            }
            else if (comando == "an_pantano") {
                Rio r; Pantano p; int cap; int carga;
                cin >> r >> p >> cap >> carga;
                rios.an_pantano(r, p, cap, carga);
            }
            else if (comando == "embalsar") {
                Rio r; Pantano p; int carga;
                cin >> r >> p >> carga;
                rios.embalsar(r, p, carga);
            }
            else if (comando == "embalsado_pantano") {
                Rio r; Pantano p;
                cin >> r >> p;
                int res = rios.embalsado_pantano(r, p);
                if (res >= 0) cout << "El pantano " << p << " del " << r << " tiene " << res << " hm3\n";
                else cout << "El rio o el pantano no existe\n";
            }
            else if (comando == "reserva_cuenca") {
                Rio r;
                cin >> r;
                int res = rios.reserva_cuenca(r);
                if (res >= 0) cout << "La cuenca del rio " << r << " tiene " << res << " hm3\n";
                else cout << "El rio no existe\n";
            }
            else if (comando == "trasvase") {
                Rio r1, r2; Pantano p1, p2; int n;
                cin >> r1 >> p1 >> r2 >> p2 >> n;
                rios.trasvase(r1, p1, r2, p2, n);
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
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}