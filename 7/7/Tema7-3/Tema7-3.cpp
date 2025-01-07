#include <iostream>
#include <fstream>
#include <cctype>
#include <map>

using namespace std;

multimap<int, string, greater<int>> resolver(string const& primerDeporte, map<string, int>& deportes, map<string, pair<string, bool>>& estudiantes) {
    string deporte, alumno;
    deporte = primerDeporte;

    while (deporte != "_FIN_") {
        deportes.insert({deporte, 0});
        cin >> alumno;
        while (!isupper(alumno[0]) && alumno != "_FIN_") {

            // si el alumno no tiene deporte
            if (estudiantes.find(alumno) == estudiantes.end()) {
                estudiantes.insert({ alumno, {deporte, false} });
                deportes.find(deporte)->second++;
            }
            else {
                if (estudiantes[alumno].first != deporte) {
                    if (!estudiantes[alumno].second) {
                        deportes[estudiantes[alumno].first]--;
                        estudiantes[alumno].second = true;
                    }

                }
            }
            cin >> alumno;

        }
        deporte = alumno;
    }

    // ordenacion
    multimap<int, string, greater<int>> ordenado;
    for (auto d : deportes) {
        ordenado.insert({d.second, d.first});
    }

    return ordenado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string primerDeporte;
    cin >> primerDeporte;
    if (!cin) return false;
    // 
    map<string, int> deportes;      // mapa con el recuento por deporte
    map<string, pair<string, bool>> estudiantes;    // mapa con el recuento por alumnos

    multimap<int, string, greater<int>> ordenado = resolver(primerDeporte, deportes, estudiantes);

    for (auto d : ordenado) {
        cout << d.second << " " << d.first << endl;
    }
        cout << "---\n";
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
#endif

    return 0;
}