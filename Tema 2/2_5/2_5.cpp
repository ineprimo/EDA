
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int caucasico(vector<int>& sec, int ini, int fin, bool& cauc) {

    if (!cauc) return 0;
    else {
        //Casos base
        int elemts = fin - ini;
        int parIzq = 0;
        int parDer = 0;

        //if (elemts == 0)
        //{
        //    if (sec[ini] % 2 == 0) parIzq++;
        //    return parIzq;
        //}

        if (elemts == 1) {

            if (sec[ini] % 2 == 0) {
                parIzq++;    //Si devuelve true es par
            }

            if (sec[fin] % 2 == 0) {
                parDer++;   //Si devuelve true es par
            }
            return parIzq + parDer;
        }

        //Hacemos llamadas recursivas
        int mid = (ini + fin) / 2;

        parIzq = caucasico(sec, ini, mid, cauc);

        if (cauc) {
            //Si esta mitad no es caucasica no tenemos que hacer el resto
            parDer = caucasico(sec, mid + 1, fin, cauc);


            int resta = parDer - parIzq;
            cauc = (-2 <= resta) && (resta <= 2);
        }

        return parIzq + parDer;

    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    bool cauc = true;
    cin >> n;

    if (n == 0) return false;

    vector<int> sec(n);
    for (int& e : sec) cin >> e;

    caucasico(sec, 0, n - 1, cauc);

    cout << ( cauc ? "SI" : "NO") << endl;
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
    //system("PAUSE");
#endif

    return 0;
}