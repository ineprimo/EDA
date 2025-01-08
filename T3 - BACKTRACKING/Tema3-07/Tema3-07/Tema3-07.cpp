// paula sierra luque
// eda gdv 70

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esValida(vector<int> combi, int n, int a, int r, int v)
{
    // tenemos fichas suficientes:
    int contA = 0, contR = 0, contV = 0;
    for (int i = 0; i < combi.size(); ++i) {
        if (combi[i] == 0) ++contA;
        if (combi[i] == 1) ++contR;
        if (combi[i] == 2) ++contV;
        if (contA > a || contR > r || contV > v) return false;
    }

    // las verdes no pueden superar azules
    if (contV > contA) return false;

    // las rojas deben ser mayores q la suma de azules y verdes
    if (contA + contV >= contR) return false;

    return combi.size() == n && n >= 2;
}

bool esSolucion(vector<int> combi, int k, int n) 
{    
    // si la base no es roja ya no vale
    if (combi[0] != 1) return false;

    // para que no haya dos verdes seguidas:
    for (int i = 0; i < combi.size(); ++i) { // 0, 0, 2
        if (combi[i] == 2 && i < combi.size() - 1 && combi[i] == combi[i + 1]) {
            return false;
        }
    }

    return true;
}

void tratarSolucion(vector<int> combi)
{   
    for (int i = 0; i < combi.size(); ++i) {
        if (combi[i] == 0) cout << "azul" << " ";
        if (combi[i] == 1) cout << "rojo" << " ";
        if (combi[i] == 2) cout << "verde" << " ";
    }
    cout << endl;
}

// función que resuelve el problema
void resolver(vector<int>& combi, vector<int> candidatos, int k, int n, int a, int r, int v, bool& haySol) 
{
    for (int i : candidatos) 
    {
        combi.push_back(i);

        if (esValida(combi, n, a, r, v))
        {
            if (esSolucion(combi, k, n))
            {
                haySol = true;
                tratarSolucion(combi);
            }
        }
        else if (k < n - 1) 
        {
            resolver(combi, candidatos, k + 1, n, a, r, v, haySol);
        }

        combi.pop_back();
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; // altura torre
    int a, r, v; // colores
    cin >> n >> a >> r >> v;

    if (n == 0 && a == 0 && r == 0 && v == 0)
        return false;

    vector<int> candidatos;
    for (int i = 0; i < 3; ++i) candidatos.push_back(i);

    vector<int> combis; 
    bool haySolucion = false;
    resolver(combis, candidatos, 0, n, a, r, v, haySolucion);

    // escribir sol
    if (!haySolucion) cout << "SIN SOLUCION" << endl;
    cout << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
