// Nieves Alonso Gilsanz

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

const int NUM_MONEDAS = 8;
const int valores[NUM_MONEDAS] = { 1, 2, 5, 10, 20, 50, 100, 200 };

// Tupla solucion: [M0, M1, M2, ..., Mn-1] n el numero total de monedas que se tienen 

// función que resuelve el problema
void resolver(vector<int>& soluc, int k, int suma, int precio, int monedas[NUM_MONEDAS], int mejorMonCount, const vector<int>& optimista)
{
    for(int i = 0; i < NUM_MONEDAS; i++) // va probando los valores -> 1, 2, 5, 10, 20, 50, 100, 200
    {
        soluc[k] = i; // sin usar lol xd mañana le doy otra vuelta otra round

        if(monedas[i] != 0) // si quedan monedas de ese tipo
        {
            suma += valores[i];

            // comprobacion de final de arbol
            // ?? -> si se ha llegado al precio a calcular
            if(suma == precio)
            {
                // las monedas usadas son el nivel del arbol
                // comprobacion de optimizacion
                // se esta usando el num max de monedas posibles
                if (k > mejorMonCount) mejorMonCount = k;
            }
            else // si no se llega al final -> poda -> recursion
            {
                // poda
                if(suma + optimista[k+1] > mejorMonCount)
                {
	                // recursion
	                resolver(soluc, k+1, suma, precio, monedas, mejorMonCount, optimista);
                }
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int precio;
    int monedas[NUM_MONEDAS];

    cin >> precio;
    for (int i = 0; i < NUM_MONEDAS; ++i)
        cin >> monedas[i];

    vector<int> optimista(NUM_MONEDAS);

    optimista[NUM_MONEDAS - 1] = monedas[NUM_MONEDAS - 1];
    for(int i = NUM_MONEDAS-2; i > 0; i--)
    {
        optimista[i] += i+1;
    }

    vector<int> soluc(NUM_MONEDAS);

    resolver(soluc, 0, 0, precio, monedas, -1, optimista);

    // Mostrar salida
    
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input1.txt");
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