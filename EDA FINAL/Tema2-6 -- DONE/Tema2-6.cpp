// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool elemento_situado(const vector<int>& v, int ini, int fin) {
    if (fin - ini == 0) return false;   // Caso base vacio
    if (fin - ini == 1) return v[ini] == ini;   // Caso base 1 elemento

    int mitad = (ini + fin) / 2;    // Varios elementos
	if (v[mitad] == mitad) return true; // Si el elemento esta situado
	else if (v[mitad] > mitad)  // Si el elemento es mayor que su indice, buscar en la mitad izquierda
        return elemento_situado(v, ini, mitad);
	else // Si el elemento es menor que su indice, buscar en la mitad derecha
        return elemento_situado(v, mitad + 1, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    cin >> n;
	vector<int> datos(n);
    for (int i = 0; i < n; ++i) {
        cin >> k;
		datos[i] = k;
    }

    bool sol = elemento_situado(datos, 0, n);
	if (sol) cout << "SI" << endl;
	else cout << "NO" << endl;
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