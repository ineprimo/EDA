// paula sierra luque
// gdv eda 70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& datos, const int k, int ini, int fin) 
{
    if (fin - ini == 0) return true; // si esta vacio valido
    if (fin - ini == 1) return abs(datos[fin] - datos[ini]) >= k;
    if (abs(datos[fin] - datos[ini]) < k) return false; // extremos

    int mitad = (ini + fin) / 2;

    return (resolver(datos, k, ini, mitad) && resolver(datos, k, mitad + 1, fin));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, // n tiradas
        k; // k valor dispersion
    cin >> n >> k;

    if (!std::cin)
        return false;

    vector<int> nums;

    int aux;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        nums.push_back(aux);
    }

    bool sol = resolver(nums, k, 0, n-1);

    // escribir sol
    if (sol) cout << "SI" << endl;
    else cout << "NO" << endl;

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
    system("PAUSE");
#endif

    return 0;
}