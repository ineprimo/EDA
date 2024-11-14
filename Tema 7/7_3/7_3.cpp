#include <iostream>
#include <fstream>
#include <cctype>
#include <map>
using namespace std;

map <string, int> resolver(string const& primerDeporte, ...) {
    map<string, int> lista;
    int cont = 0;
    string deporte, alumno;
    deporte = primerDeporte;
    while (deporte != "_FIN_") {
        
            cin >> alumno;
        while (!isupper(alumno[0]) && alumno != "_FIN_") {
            cont++;
                cin >> alumno;
        }
        lista.insert({ deporte, cont });
        cont = 0;
        deporte = alumno;
    }

    return lista;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    string primerDeporte;
    cin >> primerDeporte;
    if (!cin) return false;

    map<string, int> sol = resolver(primerDeporte);
    
    //Escribimos la solucion
    for (auto par : sol) {
        cout << par.first << " " << par.second << endl;
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