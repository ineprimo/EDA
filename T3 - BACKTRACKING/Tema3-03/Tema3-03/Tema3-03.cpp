// paula sierra
// edagdv70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void tratarSolucion(int& maneras) 
{
    ++maneras;
}

bool esSolucion(vector<int>& sol, int k, int n) 
{
    return k == n - 1; // 0 == 1
}

bool esValido(vector<int>& combi, int k, int n) 
{
    bool valido = true;

    int i = 0;
    while (valido && i < k)  // 0 < 2
    { // {1,0}  
        if (combi[k] == combi[i] || (k - i == abs(combi[k] - combi[i]))) {
            valido = false;
        }

        ++i;
    }

    return valido;
}

// función que resuelve el problema
void resolver(vector<int>& combi, int n, int k, vector<int> candidatos, int& maneras) {

    for (int i : candidatos) 
    {
        combi.push_back(i); // combi: {1,1} // k=2

        if (esValido(combi, k, n)) 
        {
            if (esSolucion(combi, k, n)) 
            {
                tratarSolucion(maneras);
            }
            else if (k < n - 1) // 1 < 1
            {
                resolver(combi, n, k + 1, candidatos, maneras);
            }
        }

        combi.pop_back();
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    vector<int> candidatos; // si n = 3: {0,1,2}
    for (int i = 0; i < n; ++i) 
    {
        candidatos.push_back(i);
    }

    //maneras de colocar las reinas
    int maneras = 0;

    // {0,1,2}, {1,0,2}
    vector<int> combinaciones;

    resolver(combinaciones, n, 0, candidatos, maneras);

    // escribir sol
    cout << maneras << endl;
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