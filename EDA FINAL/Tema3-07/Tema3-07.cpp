// Javier Tirado Ríos
// GDV-EDA72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void tratarSolucion(vector<int>& sol, bool& tieneSolucion) {
    for (int i = 0; i < sol.size(); ++i) {
        if (sol[i] == 0) cout << "azul ";
        else if (sol[i] == 1) cout << "rojo ";
        else cout << "verde ";
    }
    cout << endl;
}

bool esSolucion(vector<int>& sol, int n, int k, vector<int>& coloresUsados) { 
    bool numeroBienContado = k == n - 1;
    bool primeraPiezaRoja = sol[0] == 1;
    bool masPiezasRojasQueRestoJuntas = coloresUsados[1] > coloresUsados[0] + coloresUsados[2];
    bool minDosPiezas = n >= 2;

    return numeroBienContado && primeraPiezaRoja && masPiezasRojasQueRestoJuntas && minDosPiezas;
}

bool esValido(vector<int>& sol, vector<int>& coloresUsados, vector<int>& coloresUsables) {

    // DEMASIADAS PIEZAS
    bool piezasBienContadas = true;
    int j = 0;
    while(piezasBienContadas && j < coloresUsables.size()){
        if (coloresUsables[j] < 0) piezasBienContadas = false;
        ++j;
    }

    // MENOR O IGUALE NUMERO DE VERDES QUE AZULES
    bool verdeMenorQueAzul = true;
    if (coloresUsados[2] > coloresUsados[0]) verdeMenorQueAzul = false;

    // DOS VERDES SEGUIDOS
    bool verdeRepe = false;
    int i = 0;

    while (!verdeRepe && i < sol.size() - 1) {
        if (sol[i] == 2 && sol[i + 1] == 2) verdeRepe = true;
        ++i;
    }
    return !verdeRepe && verdeMenorQueAzul && piezasBienContadas;   // Comprobacion Repeticion de Verde Antes y Rojo al Principio
}

// función que resuelve el problema
void resolver(vector<int>& sol, int n, int k, vector<int>& candidatos,
    vector<int>& coloresUsables, vector<int>& coloresUsados, bool& tieneSolucion) {

    for (int c : candidatos) {
        int auxNum = c;
        if (auxNum == 0) {
            coloresUsables[0]--; 
            coloresUsados[0]++;
        }
        else if (auxNum == 1) {
            coloresUsables[1]--;
            coloresUsados[1]++;
        }
        else if (auxNum == 2) {
            coloresUsables[2]--;
            coloresUsados[2]++;
        }

        sol.push_back(c);
        if (esValido(sol, coloresUsados, coloresUsables)) {
            if (esSolucion(sol, n, k, coloresUsados)) {
                tratarSolucion(sol, tieneSolucion);
                tieneSolucion = true;
            }
            else if (k < n - 1) resolver(sol, n, k + 1, candidatos, coloresUsables, coloresUsados, tieneSolucion);
        }

        if (auxNum == 0) {
            coloresUsables[0]++;
            coloresUsados[0]--;
        }
        else if (auxNum == 1) {
            coloresUsables[1]++;
            coloresUsados[1]--;
        }
        else if (auxNum == 2) {
            coloresUsables[2]++;
            coloresUsados[2]--;
        }
        sol.pop_back();
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;

    int c;
    vector<int> colores;
    vector<int> coloresUsados{ 0,0,0 };
    for (int i = 0; i < 3; ++i) {
        cin >> c;
        colores.push_back(c);
    }

    // {0 --> AZUL // 1 --> ROJO // 2 --> VERDE}

    vector<int> candidatos{ 0,1,2 };
    vector<int> sol;
    bool tieneSolucion = false;
    resolver(sol, n, 0, candidatos, colores, coloresUsados, tieneSolucion);

    if (!tieneSolucion) cout << "SIN SOLUCION" << endl;
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