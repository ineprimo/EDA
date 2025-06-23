#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>

//#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

using Estado = string;
using Partido = string;


class ConteoVotos {

private:
    struct InfoEstado {
        int numCompromisarios;
        unordered_map<Partido, int> partidos;
        Partido ganador;
        int maxVotos = -1;
    };

    unordered_map<Estado, InfoEstado> estados;

public:

    void nuevo_estado(const Estado& nombre, int num_compromisarios)
    {
        auto [_, ok] = estados.insert({ nombre, {num_compromisarios, {}, "", -1}});
        if (!ok) throw domain_error("Estado ya existente");
    }

    void sumar_votos(const Estado& estado, const Partido& partido, int num_votos) 
    {
        auto it = estados.find(estado);
        if (it == estados.end()) throw domain_error("Estado no encontrado");

        int& votos = it->second.partidos[partido];
        votos += num_votos;
        // Actualiza el ganador si es necesario
        if (votos > it->second.maxVotos || it->second.maxVotos == -1) {
            it->second.maxVotos = votos;
            it->second.ganador = partido;
        }
    }

    Partido ganador_en(const Estado& estado) const {
        auto it = estados.find(estado);
        if (it == estados.end()) throw domain_error("Estado no encontrado");
        return it->second.ganador;
    }

    vector<pair<Partido, int>> resultados() const {
        map<Partido, int> aux;
        for (const auto& itE : estados) {
            aux[itE.second.ganador] += itE.second.numCompromisarios;
        }
        vector<pair<Partido, int>> res;
        res.reserve(aux.size());
        for (const auto& par : aux) {
            res.emplace_back(par.first, par.second);
        }
        return res;
    }
};


bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    ConteoVotos elecciones;

    while (comando != "FIN") {
        try {
            if (comando == "nuevo_estado") {
                Estado estado;
                int num_compromisarios;
                cin >> estado >> num_compromisarios;
                elecciones.nuevo_estado(estado, num_compromisarios);
            }
            else if (comando == "sumar_votos") {
                Estado estado;
                Partido partido;
                int num_votos;
                cin >> estado >> partido >> num_votos;
                elecciones.sumar_votos(estado, partido, num_votos);
            }
            else if (comando == "ganador_en") {
                Estado estado;
                cin >> estado;
                Partido ganador = elecciones.ganador_en(estado);
                cout << "Ganador en " << estado << ": " << ganador << "\n";
            }
            else if (comando == "resultados") {
                for (const auto& par : elecciones.resultados()) {
                    cout << par.first << " " << par.second << "\n";
                }
            }
        }
        catch (std::exception& e) {
            cout << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
