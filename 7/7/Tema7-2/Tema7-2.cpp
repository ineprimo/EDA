#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

using Diccionario = map<string, int>;


void leerDiccionario(Diccionario& diccionario) {
    char c;
    string clave;
    int valor;
    cin.get(c);
    while (c != '\n') {
        cin.unget();
        cin >> clave >> valor;

        // minusculas
        for (auto& a : clave) {
            a = tolower(a);
        }

        diccionario.insert({clave, valor});

        cin.get(c);
    }
}

void resolver(Diccionario& viejo, Diccionario& nuevo, map<int, vector<string>>& changes) {

    // changes:
    //  0: +
    //  1: -
    //  2: *

    Diccionario::iterator itv = viejo.begin();
    Diccionario::iterator itn = nuevo.begin();


    while (itv != viejo.end() && itn != nuevo.end()) {

        // si coinciden es que no ha cambiado nada (*/2)
        if (itv->first == itn->first) {
            changes[2].push_back(itv->first);

            itv++;
            itn++;
        }
        else {
            // si el viejo es menor (ej: b < c) es porque el nuevo no lo tiene
            if (itv->first < itn->first) {
                changes[1].push_back(itv->first);

                itv++;
            }
            else {
                changes[0].push_back(itv->first);

                itn++;
            }

        }
    }
}

void resuelveCaso() {
    Diccionario antiguo;
    Diccionario nuevo;
    leerDiccionario(antiguo);
    leerDiccionario(nuevo);

    // settea el mapa de cambios
    map<int, vector<string>> changes;
    vector<string>aux;
    for (int i = 0; i < 3; i++) {
        changes.insert({i, aux});
    }

    resolver(antiguo, nuevo, changes);

    // solucion

    if (changes[0].size() == 0 && changes[1].size() == 0 && changes[2].size() == 0)
        cout << "SIN CAMBIOS" << endl;
    else {
        for (auto t : changes) {
            if (t.first == 0) cout << "+ ";
            else if (t.first == 1) cout << "- ";
            else if (t.first == 2) cout << "* ";

            for (auto c : t.second) {
                cout << c << " ";
            }
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
