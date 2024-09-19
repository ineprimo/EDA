// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<std::vector<char>> resolver(std::vector<char> lista1, std::vector<char> lista2) {
   
    std::vector<std::vector<char>> sol;

    std::vector<char> ambos;
    std::vector<char> eda; // 1
    std::vector<char> tpv; // 2

    int i = 0,  // indice para lista1
        j = 0;  // indice para lista2


    while (i < lista1.size() && j < lista2.size()) {
        
        if (lista1[i] == lista2[j])     // si esta en ambas
        {
            // lo añade a la lista de ambas
            ambos.push_back(lista1[i]);

            // suma ambos contadores
            i++;
            j++;
        }
        else if(lista1[i] < lista2[j])  // es de la lista eda
        {
            eda.push_back(lista1[i]);

            i++;
        }
        else                            // es de la lista tpv
        {
            tpv.push_back(lista2[j]);

            j++;
        }

    }

    // rellena lo que falte
    while (i < lista1.size()) {
        eda.push_back(lista1[i]);

        i++;
    }    
    while (j < lista2.size()) {
        tpv.push_back(lista2[j]);

        j++;
    }

    sol.push_back(ambos);
    sol.push_back(eda);
    sol.push_back(tpv);


    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::vector<char> list1;
    std::vector<char> list2;
    int a, b;
    char aux;
    std::cin >> a;
    for (int i = 0; i < a; i++) {
        std::cin >> aux;
        list1.push_back(aux);
    }

    std::cin >> b;
    for (int i = 0; i < b; i++) {
        std::cin >> aux;
        list2.push_back(aux);
    }


    std::vector<std::vector<char>> sol = resolver(list1, list2);
    // escribir sol
    for (int i = 0; i < sol.size(); i++) {
        for (int j = 0; j < sol[i].size(); j++) {
            std::cout << sol[i][j] << " ";
        }
        std::cout << std::endl;
    }


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