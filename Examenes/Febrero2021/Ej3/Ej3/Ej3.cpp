#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
// Buenos dias Nieves.
const int NUM_MONEDAS = 8;
const int valores[NUM_MONEDAS] = { 1, 2, 5, 10, 20, 50, 100, 200 };

// Tupla solucion: [M0, M1, M2, ..., M7] Mi el numero total de monedas que se tienen de valor valores[i]

// Exploracion: En cada etapa / nivel del arbol decidir cuantas monedas de cada tipo voy a elegir
// ej: k = 0 -> cuantas monedas de 1 cent voy a utilizar (probar todas las opciones: 0 -> num monedas 1 cent)

// función que resuelve el problema
// parametros:
// --- entrada
// soluc    -> vector solucion
// k        -> candidatos que se van probando
// n        -> NUM_MONEDAS
// monedas  -> numero de monedas de cada tipo que tengo
// precio   -> valor al que tengo que llegar
// --- marcadores
// numMonedas -> cuantas monedas llevo guardadas en el vector solucion
// suma       -> suma acumulada de dinero actual
void resolver(vector<int>& soluc, int k, int n, int monedas[NUM_MONEDAS], int precio, int numMonedas, int suma, int& maxNumMonedas)
{
    // ---- ESQUEMA DE BACKTRACKING ----

    // !!!! marcar en el mismo ambito en el que se desmarca

    // 1) for de candidatos     -> candidatos = num de monedas de valor k
    // --- 2) guardar el indice del for que se va probando en el vect solucion
    // --- 3) if esValida       -> ver si lo que acabas de guardar ha sido una eleccion valida
    // ------ 4) if esSolucion  -> se ha llegado al precio a calcular
    // --------- 5) if esMejor  -> si la cantidad de monedas que estoy usando es mayor que la ultima mayor cantidad
    // ------ 6) else noSolucion
    // --------- 7) if poda     -> si las monedas que llevo + la estimacion supera el num max de monedas hasta ahora
    // ------------ 8) llamada recursiva k+1

    // va probando cada cantidad de monedas del tipo k-esimo (0 -> num monedas monedas[k])
    // cant -> cantidad de monedas que estas eligiendo en esa vuelta
    for (int cant = 0; cant <= monedas[k]; ++cant)
    {
        soluc[k] = cant; // la cantidad que coges en esta vuelta la guardas en la solucion

        // MARCAR
        // actualizar nuestras variables marcador
        suma += cant * valores[k];
        numMonedas += cant;

        // comprobar que es valida (que no te estas pasando del valor a llegar)
        if (suma <= precio) // valida si el dinero que has guardado en el vector solucion no se pasa del dinero a gastar
        {
            // comprobar que es solucion
            // si se ha llegado al precio a calcular
            if (suma == precio)
            {
                // comprobar que es mejor
                // si la cantidad de monedas que estoy usando es mayor que la ultima mayor cantidad
                if (numMonedas > maxNumMonedas) maxNumMonedas = numMonedas; // actualizar mejor num
            }
            // poner else if si la condicion de solucion es distinta a k == n-1 (llegar al final del arbol)
            // si no esto es solo un else
            else if (k < n - 1) // condicion para no salirse del array
            {
                // estimacion optimista
                // si lo que me queda por pagar se puede pagar con todas las monedas del siguiente tipo a evaluar
                // ej: me quedan 100 cent por pagar y k = 0
                // 100 cent a pagar con monedas de 2 cent -> 100/2 = 50
                int estimacionOpt = (precio - suma) / valores[k + 1];

                // poda
                // si las monedas que llevo + la estimacion supera el num max de monedas hasta ahora
                if (numMonedas + estimacionOpt > maxNumMonedas)
                {
                    // llamada recursiva con k+1
                    resolver(soluc, k + 1, n, monedas, precio, numMonedas, suma, maxNumMonedas);
                }
            }
        }

        // DESMARCAR (en el mismo ambito en el que has marcado)
        suma -= cant * valores[k];
        numMonedas -= cant;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    int precio, maxNumMonedas = -1; // inicializar a -1 cuando es un valor que debe actualizarse
    int monedas[NUM_MONEDAS];

    // leer los datos de la entrada
    cin >> precio;
    for (int i = 0; i < NUM_MONEDAS; ++i)
        cin >> monedas[i];

    // resolver
    vector<int> soluc(NUM_MONEDAS);
    resolver(soluc, 0, NUM_MONEDAS, monedas, precio, 0, 0, maxNumMonedas);

    // mostrar salida
    if (maxNumMonedas >= 0) cout << maxNumMonedas << endl;
    else cout << "IMPOSIBLE" << endl;
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