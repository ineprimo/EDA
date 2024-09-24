// Paula Alemany Rodríguez
// Eda 02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool complementario(int datos, int& num) {

    int d = 0;

    //Caso base -> Ya solo queda un digito
    if (datos < 10) 
    {
        num = 9 - datos; 
        //Tener cuidado por si influye si el número empieza en 0
        return false;
    }
    else {

        complementario(datos / 10, num);
        d = datos % 10;
        num = num * 10 + (9 - d);
        return d == 0;
    }
}

void inverso(int num, int& inv, bool cero) {

    if (num < 10 && !cero) {
        inv += num;
    }
    else if (num < 10 && cero) inv = (inv + num) * 10;
    else {

        inv += num % 10;
        inv *= 10;
        inverso(num / 10, inv, cero);
    }

}


// función que resuelve el problema
vector<int> resolver(int datos) {

    vector<int> sol;
    int num = 0;
    int inv = 0;

    //sol[0] -> Numeros complementarios al derecho
    bool cfinal = complementario(datos, num);
    sol.push_back(num);

    //sol[1] -> Numeros complementarios inversa
    inverso(num, inv, cfinal);
    sol.push_back(inv);

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int datos = 0;

    cin >> datos;

    vector<int> sol = resolver(datos);
    // escribir sol
    cout << sol[0] << " " << sol[1] << endl;

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