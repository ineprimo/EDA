// Daniel Zhu
// EDA-GDV79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
bool resolver(vector<int> datos, int p) {

    int left = datos[0];
    int right = datos[datos.size() - 1];

    if (p >= 0 && p < datos.size() - 1) {
        int i = 0;

        while (i <= p) {
            if (datos[i] > left)
                left = datos[i];
            ++i;
        }

        while (i < datos.size()) {
            if (datos[i] < right)
                right = datos[i];
            ++i;
        }
    }
    else
        return true;
    

    if (left < right)
        return true;
    else
        return false;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada


    int num, p;
    cin >> num;
    cin >> p;

    vector<int> v(num);
    for (int i = 0; i < num; ++i) {
        cin >> v[i];
    }


    bool sol = resolver(v, p);
    // escribir sol
    if (sol)
        cout << "SI" << endl;
    else {
        cout << "NO" << endl;
    }


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}