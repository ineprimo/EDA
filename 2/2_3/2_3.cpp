// INES PRIMO
// GDV61


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct sol {
    bool ord;
    int min;
    int max;

};

sol parcialmenteOrdenados(const std::vector<int>& datos,int ini, int fin ) {
    if (fin - ini == 0) 
        return {true, 0, 0};
    else if (fin - ini == 1) {
        if (datos[ini] <= datos[fin])
            return { true, ini, fin };
    }
    else {
        int mid = (ini + fin) / 2;
        sol izq = parcialmenteOrdenados(datos, ini, mid);
        sol der = parcialmenteOrdenados(datos, mid + 1, fin);

        // compara maximos y minimos y los booleanos
        if (datos[izq.max] <= datos[der.max]
            && datos[izq.min] <= datos[der.min]
            && izq.ord && der.ord)
            return { true, izq.min, der.max };
    }

    return {false, 0, 0};

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int a;
    std::cin >> a;

    if (a == 0)
        return false;

    std::vector<int> datos;

    while (a > 0) {
        datos.push_back(a);
        std::cin >> a;
    }

    sol sol1 = parcialmenteOrdenados(datos, 0, datos.size()-1);

    // escribir sol
    if (sol1.ord)
        std::cout << "SI" << std::endl;
    else
        std::cout << "NO" << std::endl;

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
