#include <iostream>
#include <fstream>
#include <cctype>
#include <map>
#include <list>
#include <vector>

using namespace std;


void resolver(const vector<string>& tablon)
{
    

    

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string primerDep;
    cin >> primerDep;
    if (!cin) return false;

    //map<string, list<string>> tablon;
    vector<string> tablon;

    
    

    resolver(tablon);

    for (const auto& par : tablon) {
        cout << par.first << " " << par.second.size() << endl;
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