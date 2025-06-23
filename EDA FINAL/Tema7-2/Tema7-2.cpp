#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
using Diccionario = map<string, int>;

struct misCambios {
public:
    vector<string> nuevos;
    vector<string> eliminados;
    vector<string> cambiados;
};

void leerDiccionario(Diccionario& diccionario) {
    char c;
    string clave;
    int valor;
    cin.get(c);
    while (c != '\n') {
        cin.unget();
        cin >> clave >> valor;
        
        for (auto& l : clave) {
            l = tolower(l);
        }

        diccionario.insert({ clave, valor });

        cin.get(c);
    }
}

void resuelveCaso() {
    Diccionario antiguo;
    Diccionario nuevo;
    leerDiccionario(antiguo);
    leerDiccionario(nuevo);

    auto itAntiguo = antiguo.begin();
    auto itNuevo = nuevo.begin();

    misCambios cam;

    while (itAntiguo != antiguo.end() && itNuevo != nuevo.end()) {
        if (itAntiguo->first == itNuevo->first) {
            if (itAntiguo->second != itNuevo->second) cam.cambiados.push_back(itAntiguo->first);
            ++itAntiguo;
            ++itNuevo;
        }
        else if (itNuevo->first > itAntiguo->first) {
            cam.eliminados.push_back(itAntiguo->first);
            ++itAntiguo;
        }
        else if (itAntiguo->first > itNuevo->first) {
            cam.nuevos.push_back(itNuevo->first);
            ++itNuevo;
        }

    }
    
    // Sobrantes
    while (itAntiguo != antiguo.end()) {
        cam.eliminados.push_back(itAntiguo->first);
        ++itAntiguo;
    }

    while (itNuevo != nuevo.end()) {
        cam.nuevos.push_back(itNuevo->first);
        ++itNuevo;
    }

    if (cam.nuevos.empty() && cam.eliminados.empty() && cam.cambiados.empty()) {
        cout << "Sin cambios" << endl;
    }
    else {
        if (!cam.nuevos.empty()) {
            cout << "+ ";
            for (int i = 0; i < cam.nuevos.size(); ++i) cout << cam.nuevos[i] << " ";
            cout << endl;
        }
        if (!cam.eliminados.empty()) {
            cout << "- ";
            for (int i = 0; i < cam.eliminados.size(); ++i) cout << cam.eliminados[i] << " ";
            cout << endl;
        }
        if (!cam.cambiados.empty()) {
            cout << "* ";
            for (int i = 0; i < cam.cambiados.size(); ++i) cout << cam.cambiados[i] << " ";
            cout << endl;
        }
    }
    cout << "---" << endl;

}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos; char c;
    std::cin >> numCasos;
    cin.get(c);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
