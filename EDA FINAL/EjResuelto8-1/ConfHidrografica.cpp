#include <iostream>
#include <stdexcept>
#include <fstream>
#include <unordered_map>
#include <list>

using namespace std;

using Rio = string;
using Pantano = string;

class ConfHidrografica {
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
    // O(1)
    ConfHidrografica() { }

    // O(1)
    void an_rio(const Rio& r){
        // Si el rio r estaba no se inserta
        rios.insert({r, InfoRio()}); // O(1)
    }

    // O(1)
    void an_pantano(const Rio& r, const Pantano& p, int cap, int carga){
        unordered_map<Rio,InfoRio>::iterator itR = rios.find(r); // O(1)
        if (itR != rios.end()) {
            auto [_,ok] = itR->second.pantanos.insert({p, {cap, std::min(cap, carga)}}); // O(1)
            if (!ok) itR->second.carga += std::min(cap, carga);
        }
    }

    // O(1)
    void embalsar(const Rio& r, const Pantano& p, int n){
        auto itR = rios.find(r); // O(1)
        if (itR != rios.end()) {
            auto itP = itR->second.pantanos.find(p); // O(1)
            if (itP != itR->second.pantanos.end()) {
                // Añade lo que quepa de n al pantano y a la cuenca de r
                int incrCarga = std::min(n, itP->second.capacidad - itP->second.carga);
                itP->second.carga += incrCarga;
                itR->second.carga += incrCarga;
            }
        }
    }

    // O(1)
    int embalsado_pantano(const Rio& r, const Pantano& p) const {
        try {
            return rios.at(r).pantanos.at(p).carga; // O(1)
        } catch (std::out_of_range& e){
            return -1;
        }
    }

    // O(1)
    int reserva_cuenca(const Rio& r) const {
        auto itR = rios.find(r); // O(1)
        if (itR != rios.end()) return itR->second.carga;
        else return -1;
    }

    // O(1)
    void trasvase(const Rio& r1, const Pantano& p1, const Rio& r2, const Pantano& p2, int n) {
        auto itR1 = rios.find(r1); // O(1)
        auto itR2 = rios.find(r2); // O(1)
        if (itR1 != rios.end() && itR2 != rios.end()) {
            auto itP1 = itR1->second.pantanos.find(p1); // O(1)
            auto itP2 = itR2->second.pantanos.find(p2); // O(1)
            if (itP1 != itR1->second.pantanos.end() && itP1 != itR1->second.pantanos.end()) {
                if (itP1->second.carga >= n && itP2->second.carga + n <= itP2->second.capacidad) {
                    itP1->second.carga -= n;
                    itP2->second.carga += n;
                    itR1->second.carga -= n;
                    itR2->second.carga += n;
                }
            }
        }
    }
};


bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    ConfHidrografica rios;
    while (comando != "FIN") {
        try {
            if (comando == "an_rio") {
                Rio r;
                cin >> r;
                rios.an_rio(r);
            } else if (comando == "an_pantano") {
                Rio r; Pantano p; int cap; int carga;
                cin >> r >> p >> cap >> carga;
                rios.an_pantano(r, p, cap, carga);
            } else if (comando == "embalsar") {
                Rio r; Pantano p; int carga;
                cin >> r >> p >> carga;
                rios.embalsar(r, p, carga);
            } else if (comando == "embalsado_pantano") {
                Rio r; Pantano p;
                cin >> r >> p;
                int res = rios.embalsado_pantano(r,p);
                if (res >= 0) cout << "El pantano " << p << " del " << r << " tiene " << res << " hm3\n";
                else cout << "El rio o el pantano no existe\n";
            } else if (comando == "reserva_cuenca") {
                Rio r;
                cin >> r;
                int res = rios.reserva_cuenca(r);
                if (res >= 0) cout << "La cuenca del rio " << r << " tiene " << res << " hm3\n";
                else cout << "El rio no existe\n";
            } else if (comando == "trasvase") {
                Rio r1, r2; Pantano p1, p2; int n;
                cin >> r1 >> p1 >> r2 >> p2 >> n;
                rios.trasvase(r1, p1, r2, p2, n);
            }
        } catch (std::exception &e) {
            cout << "ERROR: " << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("rios1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) { }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
