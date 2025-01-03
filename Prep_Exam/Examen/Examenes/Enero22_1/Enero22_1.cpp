#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "list_eda.h"
using namespace std;

vector<char> extraerLista(list<char>& lista, int pos, int lon) {
	vector<char> segmento(lon);
	list<char> aux;
	int elemPrincipio = 0;
	for (int i = 0; i < pos; i++) {
		aux.push_back(lista.front());
		elemPrincipio++;
		lista.pop_front();
	}

	for (int j = 0; j < lon; j++)
	{
		segmento[j] = lista.front();
		lista.pop_front();
	}

	for (int k = 0; k < elemPrincipio; k++) 
	{
		lista.push_front(aux.back());
		aux.pop_back();
	}

	return segmento;
}

void insertarLista(list<char>& lista, int pos, vector<char>segmento) {

	list<char>::iterator it = lista.begin();
	for (int i = 0; i < pos; i++)
	{
		it++;
	}

	for (int i = 0; i < segmento.size(); i++)
	{

		lista.insert(it, segmento[i]);
	}

}

// función que resuelve el problema
void resolver(list<char>& lista, int n, int pos, int lon, int k) {

	//Se hace cuando: no esté vacía, origen correcto, destino correcto
	if (n != 0 && k != 0 && lon != 0 && pos < n && pos - k >= 0) 
	{
		//Si además, se da el caso de que el segmento se sale de la lista
		if (pos + lon > n) {
			lon = n - pos;
		}

		//La nueva posición en la que se insertará el segmento será pos - k;
		int nuevaPos = pos - k;
		//Insertamos el segmento extraído en la nueva posición
		insertarLista(lista, nuevaPos, extraerLista(lista, pos, lon));

	}
	//else no hace nada

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	int n = 0, pos = 0, lon = 0, k = 0;
	std::cin >> n >> pos >> lon >> k;

	// creamos la lista y la rellenamos con los n elementos
	list<char> lista;
	char elem = ' ';
	for (int i = 0; i < n; i++) 
	{
		std::cin >> elem;
		lista.push_back(elem);
	}

	resolver(lista, n, pos, lon, k);

	// escribir sol (y de paso la vacíamos, para optimizar)
	//Primer elemento
	if (!lista.empty()) {
		cout << lista.front();
		lista.pop_front();
	}
	//Siguientes
	while (!lista.empty()) {
		cout << " " << lista.front();
		lista.pop_front();
	}
	cout << endl;
}

int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}