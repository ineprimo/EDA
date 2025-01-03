

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

const int NUM_MONEDAS = 8;
const int valores[NUM_MONEDAS] = { 1,2,5,10,20,50,100,200 };

bool isValid(vector<int>& soluc, int pos, int* monedas) {
    return soluc[pos] < monedas[pos];
}

bool isSolution(vector<int>& soluc, int precio) {
    int sum = 0;
    for (int n = 0; n < NUM_MONEDAS; n++) {
        sum += soluc[n] * valores[n];
    }
    return sum == precio;
}

bool isBetter() {
    return true;
}

// función que resuelve el problema
void resolver(vector<int>& soluc, int k, int n, int* monedas, int cantActual, int cantFinal, int monedasUsadas, int& maxUsadas) {
    for (int j = 0; j <= soluc[k]; j++) {
       
        int cant = cantActual + valores[k] * j;     // 
        int usadas = monedasUsadas + j;             // 
        
        if (isValid(soluc, k, monedas)) {       // mira si tenemos monedas
            if (isSolution(soluc, cantFinal)) {    // mira si es solucion
                if (isBetter()) {               // lmfao
                    
                }
            }
            else if (k < n - 1) {
                // falta la poda
                int poda = 0;

                resolver(soluc, k + 1, NUM_MONEDAS, monedas, cantActual, cantFinal, 0, maxUsadas);
            }
        }
        
    }


    // ------------------
    //for (int i = 0; i <= soluc[k]; i++)
    //{
    //    int cant = cantAct + valores[k] * i;
    //    int usadas = monedasUsadas + i;

    //    if (cant > cantFin) continue; // Poda si nos hemos pasado pasamos al siguiente
    //    else { // no nos hemos pasado
    //        if (cant == cantFin) // si hemos llegado al precio
    //        {
    //            if (usadas > maxUsadas) // si por este camino hemos usado mas monedas, se convierte en el nuevo maximo
    //                maxUsadas = usadas;
    //        }
    //        else if (k + 1 < NUM_MONEDAS) // si no hemos llegado al maximo de monedas usables
    //        {
    //            resolver(soluc, k + 1, cant, cantFin, usadas, maxUsadas);
    //        }
    //    }
    //}


}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int precio;
    int monedas[NUM_MONEDAS];
    cin >> precio;
    for (int i = 0; i < NUM_MONEDAS; ++i)
        cin >> monedas[i];
    vector<int> soluc(NUM_MONEDAS);
    int maxusadas = 0;
    resolver(soluc, 0, NUM_MONEDAS, monedas, precio, 0, 0, maxusadas);
    
    // Mostrar salida

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
