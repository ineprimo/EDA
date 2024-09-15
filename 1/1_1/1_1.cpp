// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//std::vector<int> mergesort(std::vector<int> datos, int ini, int fini) {
//    int mid;
//
//    // DIVIDE ET IMPERA
//    if (ini < fini - 1) // si longitud > 1 (si hay algo lmao)
//    {
//        mid = (ini+fini) / 2;
//        mergesort(datos, ini, mid);     // sort de la parte izquierda
//        mergesort(datos, mid, fini);    // sort de la parte derecha
//        merge(datos, ini, mid, fini);   // sort total
//    }
//
//}
//
//
//std::vector<int> merge(std::vector<int> datos, int ini, int mid, int fini) {
//
//    int nl = mid - ini;     // tamaño de la izq (l de left)
//    int nr = fini - mid;    // tamaño de la der (r de right)
//
//    std::vector<int> vl;    // vector izq
//    std::vector<int> vr;    // vector der
//
//    for (int i = 0; i < nl; i++)        // copia de los vectores
//        vl[i] = datos[ini + 1];
//    for (int i = 0; i < nr; i++)
//        vr[i] = datos[mid + 1];
//    
//
//    int i = 0, j = 0;
//   
//
//}




// función que resuelve el problema
bool resolver(std::vector<int> datos) {

    bool dalton = true;
    int i = 1, prev, post;

    // suponiendo que son los dalton, se buscan errores en el vector
    // aka mira en todas las posiciones si  siguien un orden ascendente o descendiente
    while (dalton && i < datos.size() - 1) {
        prev = datos[i - 1];
        post = datos[i + 1];
        if (!(prev < datos[i] < post ||
            prev > datos[i] > post))
            dalton = false;
        i++;
    }


    return dalton;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int size, a;
    std::cin >> size;

    std::vector<int> vec;
    for (int i = 0; i < size; i++) {
        std::cin >> a;
        vec.push_back(a);
    }

    bool sol = resolver(vec);

    // escribir sol
    if (sol) std::cout << "CONOCIDO";
    else std::cout << "DESCONOCIDO";

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