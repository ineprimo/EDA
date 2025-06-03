#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>


class ConteoVotos {

private:
   ...

public:

    void nuevo_estado(const Estado &nombre, int num_compromisarios) {}  
    
    void sumar_votos(const Estado &estado, const Partido &partido, int num_votos) {}

    Partido ganador_en(const Estado &estado) const {}

    vector<pair<Partido,int>> resultados() const {}

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
            } else if (comando == "sumar_votos") {
                Estado estado;
                Partido partido;
                int num_votos;
                cin >> estado >> partido >> num_votos;
                elecciones.sumar_votos(estado, partido, num_votos);
            } else if (comando == "ganador_en") {
                Estado estado;
                cin >> estado;
                Partido ganador  = elecciones.ganador_en(estado);
                cout << "Ganador en " << estado << ": " << ganador << "\n";
            } else if (comando == "resultados") {
                for (const auto &par : elecciones.resultados()) {
                    cout << par.first << " " << par.second << "\n";
                }
            }
        } catch (std::exception &e) {
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

    while(resuelveCaso()) { }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
