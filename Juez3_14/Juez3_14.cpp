//Denisa Juarranz Berindea
//Usuario del juez: EDA_GDV37

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

//Tupla solución: [m0, m1, m2, m3, m4, m5, m6, m7], donde mi es la cantidad de cada tipo de moneda necesarias para alcanzar el precio determinado.
//Hacemos la poda de tal manera que si no hay monedas, o sale un resultado mayor al que debería, regresamos por la rama a otra situación.

const int NUM_MONEDAS = 8;
const int valores[NUM_MONEDAS] = { 1,2,5,10,20,50,100,200 };

// función que resuelve el problema
void resolver(int monedas[NUM_MONEDAS], int& monMax, int index, int precioAct, int monAct, int& precioFinal) {
    if (index >= NUM_MONEDAS) return;

    for (int i = 0; i <= monedas[index]; i++) {

        int precioAux = precioAct;
        precioAux += valores[index] * i;

        if (precioAux == precioFinal) {
            if (monMax < monAct + i) {
                monMax = monAct + i;
            }    
            return;
        }

        if (precioAux > precioFinal) {
            return;
        }

        resolver(monedas, monMax, index + 1, precioAux, monAct + i, precioFinal);
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int precio;
    int monedas[NUM_MONEDAS];
    cin >> precio;
    for (int i = 0; i < NUM_MONEDAS; ++i)
        cin >> monedas[i];
    //vector<int> soluc(NUM_MONEDAS);
    int monMax = 0; //Número de monedas máximas usadas
    resolver(monedas, monMax, 0, 0, 0, precio);
    // Mostrar salida
    if (monMax == 0) {
        if (precio == 0) {
            cout << 0 << endl;
        }
        else {
            cout << "IMPOSIBLE" << endl;
        }
    }     
    else {
        cout << monMax << "\n";
    }
       
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
