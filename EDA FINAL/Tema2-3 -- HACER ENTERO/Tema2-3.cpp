// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Sol {
    bool ordenado;
    int max;
    int min;
};

Sol resolverRec(vector<int>& vec, int ini, int fin) {
    if (fin - ini == 1) {
        return { true, vec[ini], vec[ini] };
    }

    int mitad = (ini + fin) / 2;
    Sol solIzq = resolverRec(vec, ini, mitad);
    Sol solDer = resolverRec(vec, mitad, fin);

    bool derMax = solDer.max >= solIzq.max;
    bool izqMin = solIzq.min <= solDer.min;
    bool ordenado = solIzq.ordenado && solDer.ordenado && derMax && izqMin;

    return { ordenado, max(solIzq.max, solDer.max), min(solIzq.min, solDer.min) };
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0) return false;

    vector<int> datos;
    datos.push_back(n);
    while (cin >> n && n != 0) {
        datos.push_back(n);
    }

    Sol sol = resolverRec(datos, 0, datos.size());
    cout << (sol.ordenado ? "SI" : "NO") << endl;

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
