// paula sierra luque
// eda gdv 70

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esValida(vector<int>& combi, int n, vector<int>& disponibles, vector<int>& usados)
{
    // tenemos fichas suficientes:
    int i = 0;
    while (i < disponibles.size()) {
        if (disponibles[i] < 0) return false;
        ++i;
    }

    // las verdes no pueden superar azules
    if (usados[2] > usados[0]) return false;

    // las rojas deben ser mayores q la suma de azules y verdes
    if (usados[0] + usados[2] >= usados[1]) return false;

    return combi.size() == n && n >= 2;
}

bool esSolucion(vector<int>& combi, int k, int n)
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

void tratarSolucion(vector<int>& combi)
{   
    for (int i = 0; i < combi.size(); ++i) {
        if (combi[i] == 0) cout << "azul" << " ";
        if (combi[i] == 1) cout << "rojo" << " ";
        if (combi[i] == 2) cout << "verde" << " ";
    }
    cout << endl;
}

// función que resuelve el problema
void resolver(vector<int>& combi, vector<int> candidatos, int k, int n, vector<int>& disponibles, vector<int>& usados, bool& haySol)
{
    for (int i : candidatos) 
    {
        disponibles[i]--;
        usados[i]++;

        combi.push_back(i);

        if (esValida(combi, n, disponibles, usados))
        {
            if (esSolucion(combi, k, n))
            {
                haySol = true;
                tratarSolucion(combi);
            }
        }
        else if (k < n - 1) 
        {
            resolver(combi, candidatos, k + 1, n, disponibles, usados, haySol);
        }

        combi.pop_back();
        
        disponibles[i]++;
        usados[i]--;
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

    vector<int> coloresDisponibles;
    coloresDisponibles.push_back(a);
    coloresDisponibles.push_back(r);
    coloresDisponibles.push_back(v);

    vector<int> coloresUsados { 0,0,0 };

    vector<int> candidatos;
    for (int i = 0; i < 3; ++i) candidatos.push_back(i);

    vector<int> combis; 
    bool haySolucion = false;
    resolver(combis, candidatos, 0, n, coloresDisponibles, coloresUsados, haySolucion);

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
