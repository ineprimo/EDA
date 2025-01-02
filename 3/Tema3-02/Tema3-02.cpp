// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esValida(vector<char>& soluc, int k, int n) {

    return soluc.size() == n;
}

bool esSoluc(vector<char>& soluc, int k, int n, vector<char> cand) {
    // mira que n o haya repetidos
    int i = 0;
    int isAlready = false;
    bool norep = true;


    while (norep && i < cand.size()) {
        for (char c : soluc) {
            if (c == cand[i]) {
                if (isAlready) norep = false;
                isAlready = true;
            }
        }
        isAlready = false;
        i++;
    }

    return norep;
}

void tratarSoluc(vector<char>& soluc) {

    // escribe la solucion
    for (char c : soluc) {
        cout << c;
    }
    cout << endl;
}

// función que resuelve el problema
void resolver(vector<char>& sol, int k, int n, vector<char> candidatos) {
    for (char c : candidatos) {
        sol.push_back(c);
        if (esValida(sol, k, n)) {
            if (esSoluc(sol, k, n, candidatos)) {
                tratarSoluc(sol);
            }
        }
        else if (k < n - 1) {
            resolver(sol, k + 1, n, candidatos);
        }
        sol.pop_back();
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    std::cin >> a;
    std::cin >> b;

    vector<char> chars;
    for (int i = 0; i < a; i++) {
        chars.push_back('a' + i);
    }

    if (!std::cin)
        return false;

    vector<char> sol;
    resolver(sol, 0, b, chars);

    cout << endl;

    // escribir sol


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