#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>

//Función para calcular el inverso del complementario
int inverso(int comp) {

    int inverso = 0;

    return 0;
}


// función que resuelve el problema
int resolver(int n) {

    int fin = 0;
    int cifras = 0;
  
    while (n / pow(10, cifras) > 10) {

        int comp1 = pow(10, cifras + 1);

        fin += pow(10, cifras) * (9 - (n % comp1));

        cifras++;

    }
    
    return fin;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    int comp = resolver(n);
    // escribir sol

    std::cout << comp << " " << inverso(comp) << std::endl;

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