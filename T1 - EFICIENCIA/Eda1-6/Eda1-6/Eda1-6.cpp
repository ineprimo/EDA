// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// función que resuelve el problema
void resolver(const vector<string>& a, const vector<string>& b, 
    vector<string>& ambas, vector<string>& enA, vector<string>& enB) {

    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {

        if (a[i] < b[j]) {
            enA.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j]) {
            enB.push_back(b[j]);
            j++;
        }
        else {
            ambas.push_back(a[i]);
            i++;
            j++;
        }
    }

    // el resto de A
    while (i < a.size()) {
        enA.push_back(a[i]);
        i++;
    }

    // el resto de los de B
    while (j < b.size()) {
        enB.push_back(b[j]);
        j++;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
  
    vector<string> A(tam);

    for (int i = 0; i < tam; i++) {
        cin >> A[i];
    }

    int tam2;
    cin >> tam2;

    vector<string> B(tam2);

    for (int i = 0; i < tam2; i++) {
        cin >> B[i];
    }

    // creo vectores auxiliares
    vector<string> ambas;
    vector<string> enA;
    vector<string> enB;

    resolver(A, B, ambas, enA, enB);


    // escribir sol
    for (int i = 0; i < ambas.size(); i++) {
        cout << ambas[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < enA.size(); i++) {
        cout << enA[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < enB.size(); i++) {
        cout << enB[i] << " ";
    }
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