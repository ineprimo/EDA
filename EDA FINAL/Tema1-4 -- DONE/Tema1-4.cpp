// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<long long int> resolver(vector<long long int>& datos) {
    int j = 0;
    for (int i = 0; i < datos.size(); ++i) {
        if (datos[i] % 2 == 0) {
			datos[j] = datos[i];
			++j;
        }
    }
	datos.resize(j);
	return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	vector<long long int> datos;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long int x;
		cin >> x;
		datos.push_back(x);
    }
	vector<long long int> sol = resolver(datos);
	for (int i = 0; i < sol.size(); ++i) {
		cout << sol[i] << " ";
	}
	cout << endl;
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