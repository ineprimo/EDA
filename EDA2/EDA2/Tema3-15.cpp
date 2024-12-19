

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

const int NUM_MONEDAS = 8;
const int valores[NUM_MONEDAS] = { 1,2,5,10,20,50,100,200 };


// vamos viendo cuantas monedas de cada tipo pueden entrar para llegar al precio
void resolver(vector<int>& soluc, int k, int cantAct, int cantFin, int monedasUsadas, int& maxUsadas) {
	for (int i = 0; i <= soluc[k]; i++)
	{
		int cant = cantAct + valores[k] * i;
		int usadas = monedasUsadas + i;

		if (cant > cantFin) continue; // Poda hemos llegado al precio
		if ((cantFin - cant) / valores[k] <= maxUsadas - usadas) continue; // si la cantidad de monedas de este valor necesarias para llegar al 
		else { // no nos hemos pasado
			if (cant == cantFin) // si hemos llegado al precio
			{
				if (usadas > maxUsadas) // si por este camino hemos usado mas monedas, se convierte en el nuevo maximo
					maxUsadas = usadas;
			}
			else if (k + 1 < NUM_MONEDAS) // si no hemos llegado al maximo de monedas usables
			{
				resolver(soluc, k + 1, cant, cantFin, usadas, maxUsadas);
			}
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int precio;
	vector<int> soluc(NUM_MONEDAS);
	cin >> precio;
	for (int i = 0; i < NUM_MONEDAS; ++i)
		cin >> soluc[i];
	int maxusadas = 0;
	resolver(soluc, 0, 0, precio, 0, maxusadas);
	// Mostrar salida
	cout << (maxusadas == 0 ?
		"IMPOSIBLE" : std::to_string(maxusadas)) << endl;
}

//#define DOMJUDGE
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
	//system("PAUSE");
#endif

	return 0;
}
