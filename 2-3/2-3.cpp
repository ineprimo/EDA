// Nombre del alumno ..... Cynthia Tristán
// Usuario del Juez ...... EDA-GDV73 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct Sol {
    bool parcialmenteOrdenado;
    int mayor;
    int menor;
};
// función que resuelve el problema
Sol resolver(vector<int>& datos, int ini, int fin) {
    if (ini == fin) {
        return { true, 0 };
    }
    else if (fin - ini == 1) {
        if (datos[fin] >= datos[ini]) return { true,  datos[fin], datos[ini] };
    }
    else {
        int mitad = (ini + fin) / 2;
        Sol solIzq = resolver(datos, ini, mitad);
        Sol solDer = resolver(datos, mitad + 1, fin);
        if(solDer.mayor >= solIzq.mayor && solIzq.menor <= solDer.menor && solIzq.parcialmenteOrdenado && solDer.parcialmenteOrdenado)
            return {true, 0, 0};
    }
    return { false, 0, 0 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    vector<int> datos;
    datos.push_back(n);
    cin >> n;
    while (n != 0) {
        datos.push_back(n);
        cin >> n;
    }

    Sol sol = resolver(datos, 0, datos.size() - 1);

    // escribir sol
    sol.parcialmenteOrdenado ? cout << "SI\n" : cout << "NO\n";

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
