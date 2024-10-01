// PAULA SIERRA LUQUE
// EDA-GDV70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema

// queremos comp(4563) ... -> comp(456) con r=543 -> comp(45) -> comp(4)
// 
// r*10 = 5430 + comp(3) = 5436 (se pone en la derecha)

int complementario(int n) {

    // caso base -> solo hay 1 digito
    if (n <= 9) return 9 - n;

    // caso recursivo -> el numero es mayor que 10
    else {
        int r = complementario(n / 10);
        return r * 10 + 9 - (n % 10);
    }
}

// inverso(4563) -> inverso(345) con r = 345
// hay q ponerlo por la izquierda

// comp(3) * 1000 + r
// como sacamos 1000: bucle para q cada num que se encuentre multiplique *10

//int inverso(int n) {
//    // caso base -> solo hay 1 digito
//    if (n <= 9) return 9 - n;
//
//    // caso recursivo -> el numero es mayor que 10
//    else {
//        int r = inverso(n / 10);
//
//        // calcula *10^n donde n es el numero de cifras
//        for (...) ... pot *= 10;
//
//
//        return (9-n%10) * pot + r;
//    }
//}

//otra version
pair<int,int> inverso(int n) {

    // caso base -> solo hay 1 digito
    if (n <= 9) return {9-n, 10}; 

    // caso recursivo -> el numero es mayor que 10
    else {
        pair<int, int> par = inverso(n / 10); // [!] se puede hacer pair<int,int> [r, pot] para evitar usar .first y .second
        pair<int, int> res;
        
        res.first = (9 - n % 10) * par.second + par.first;
        res.second = par.second * 10;

        return res;
    }
}

pair<int, int> resolver(int n) {
    pair<int, int> sol;

    sol.first = complementario(n);
    sol.second = inverso(n).first;

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;

    // resuelvo
    pair<int,int> sol = resolver(num);
    
    // escribir sol
    cout << sol.first << " " << sol.second << endl;


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