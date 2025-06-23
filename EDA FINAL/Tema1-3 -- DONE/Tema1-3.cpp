// Javier Tirado Ríos
// 72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int> datos, int p) {
    int maxIzq = -51;
	int minDer = 61;

    for (int i = 0; i < datos.size(); ++i) {
        if (i <= p && datos[i] > maxIzq) {
			maxIzq = datos[i];
        }
        else if (i > p && datos[i] < minDer) {
			minDer = datos[i];
        }
    }
    return (maxIzq < minDer);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n, p;
	cin >> n >> p;
	vector<int> datos(n);
	for (int i = 0; i < n; ++i) {
		cin >> datos[i];
	}
	if (resolver(datos, p)) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
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