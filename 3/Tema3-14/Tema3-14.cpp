

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

const int NUM_MONEDAS = 8;
const int valores[NUM_MONEDAS] = { 1,2,5,10,20,50,100,200 };


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
void resolver(vector<int>& soluc, int k, int n, const int* monedas, int valor, int valorFinal, int monedasUsadas, int& maxUsadas, vector<int>& mejorSol) {
    for (int j = 0; j <= monedas[k]; j++) {
       
        // "marca"
        soluc[k] = j;                         // suma la moneda
        valor += valores[k] * j;            // 
        monedasUsadas += j;                    // 
        
        // si es valido
        if (soluc[k] <= monedas[k] && valor <= valorFinal) {     // mira si tenemos monedas
            if (valor == valorFinal) {                          // mira si es solucion
                if (monedasUsadas > maxUsadas) {
                    maxUsadas = monedasUsadas;
                    mejorSol = soluc;
                }
            }
            else if (k < n - 1) {
                // poda
                // calcula el numero de monedas del siguiente tipo que harian falta, es optimista porque cuanto mas bajo sea el valor
                // de la moneda mas haran falta

                // un poco guarro pero va mirando hasta que encuentre unas que si tenga
                int acc = 1;
                int m = 0;
                while (m == 0) {
                    m = monedas[k + acc];// esto puede dar 0 y joderte la vida
                    acc++;
                }

                // calculo de la estimacion
                int estimacionOptimista = (valorFinal - valor) / m;   

                //
                if (valor + estimacionOptimista > maxUsadas) {      // si el valor actual + el siguiente tipo de moneda es menor sigue
                    resolver(soluc, k + 1, NUM_MONEDAS, monedas, valor, valorFinal, monedasUsadas, maxUsadas, mejorSol);
                }

            }
        }

        // "desmarca"
        valor -= valores[k] * j;                    // 
        monedasUsadas -= j;
    }
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
    vector<int> mejorsoluc(NUM_MONEDAS);
    int maxusadas = 0;
    resolver(soluc, 0, NUM_MONEDAS, monedas, 0, precio, 0, maxusadas, mejorsoluc);
    
    if (maxusadas == 0)
        cout << "IMPOSIBLE" << endl;
    else
        cout << maxusadas << endl;

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
