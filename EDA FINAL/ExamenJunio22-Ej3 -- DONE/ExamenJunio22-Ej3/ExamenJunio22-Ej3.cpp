//// Javier Tirado Ríos
//// EDA-GDV72
//
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//
//#include <list>
//
//using namespace std;
//
//// función que resuelve el problema
//int resolver(list<int>& datos) {
//
//    auto itCons = datos.begin();
//    auto itAct = datos.begin();
//    ++itAct;
//    bool cadenaRota = false;
//
//    for (; itAct != datos.end() && !cadenaRota;) {
//        if (*itAct - *itCons == 1) {
//            ++itAct;
//            ++itCons;
//        }
//        else cadenaRota = true;
//    }
//
//    return *itCons;
//}
//
//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//void resuelveCaso() {
//    // leer los datos de la entrada
//    int n, aux;
//    cin >> n;
//
//    list<int> datos;
//
//    for (int i = 0; i < n; ++i) {
//        cin >> aux;
//        datos.push_back(aux);
//    }
//
//    int sol = resolver(datos);
//    cout << sol << endl;
//}
//
//int main() {
//    // Para la entrada por fichero.
//    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 
//
//
//    int numCasos;
//    std::cin >> numCasos;
//    for (int i = 0; i < numCasos; ++i)
//        resuelveCaso();
//
//
//    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif
//
//    return 0;
//}

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

using namespace std;

int resolver(const vector<int>& datos) {
    int ini = 0, 
        fin = datos.size() - 1;
    int primero = datos[0];
    int res = primero;

    while (ini <= fin) {
        int mid = (ini + fin) / 2;
        if (datos[mid] == primero + mid) {
            res = datos[mid];
            ini = mid + 1;
        }
        else {
            fin = mid - 1;
        }
    }
    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la configuración y escribiendo la respuesta
void resuelveCaso() {
    int n, aux;
    cin >> n;

    vector<int> datos(n);
    for (int i = 0; i < n; ++i) {
        cin >> datos[i];
    }

    int sol = resolver(datos);
    cout << sol << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // guardar buf antiguo y redirigir std::cin a datos.txt
#endif 

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}