// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>

using namespace std;

struct datos
{
    int n = 0,
        pos = 0,
        lon = 0,
        k = 0;

    list<char>::iterator posIt;
    list<char>::iterator posK;
};


///Complejidad de la funcion O(n + lon) siendo n el numero de elementos de la lista
// función que resuelve el problema
list<char> resolver(list<char> datos, struct datos d) {
    list<char> seg;
    list<char> sol;

    if (d.lon == 0 || d.k == d.n - 1 || d.pos >= d.n ) {
        sol = datos;
        return sol;
    }

    list<char>::iterator it = d.posIt;  //Principio del segmento
    list<char>::iterator cont;  //Continuacion

    //Guardamos el segmento que queremos recorriendo unicamente la longitud lon
    for (int i = 0; i < d.lon; i++) {
        seg.emplace_back(*it);
        it++;
    }
    cont = it;
    list<char>::iterator segit = seg.begin();  //Principio del segmento

    it = datos.begin(); //Vamos a recorrer la lista
    //ponemos las que no cambian
    while (it != datos.end() && *it != *d.posK) {
        sol.emplace_back(*it);
        it++;
    }

    //añadimos el segmento
    if (it != datos.end()) 
    { 
        while (segit != seg.end()) {
            sol.emplace_back(*segit);
            segit++;
        }

        //Nos saltamos las referentes al segmento
        //Ponemos las faltantes (Sin repetir las del segmento)
        while (*it != *d.posIt) {
            sol.emplace_back(*it);
            it++;
        }

        int f = d.n - (d.pos + d.lon);
        if (d.pos + d.lon < d.n) {  //Aun quedan elementos

            for (int i = 0; i < f; i++) {
                sol.emplace_back(*cont);
                cont++;
            }
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    datos d;
    list<char> datos;
    char l;
    int k = 0;

    //Guardamos todos los datos de la lista
    cin >> d.n;
    cin >> d.pos;
    cin >> d.lon;
    cin >> k;

    d.k = d.pos + d.lon - 1;

    //Posicion de la k en la lista = pos + k - n
    if (d.pos + d.lon > d.n) {
        d.k = d.pos - 1; //Menos dos porque guardamos la posicion a insertar
        d.lon = d.n - d.pos;
    }
    else {
        for (int i = 0; i < k; i++) {
            if (d.k == d.n - 1) d.k = -1;
            d.k++;
        }
    }

    for (int i = 0; i < d.n; i++) {
        cin >> l;
        datos.push_back(l);

        if (i == d.pos) d.posIt = --datos.end();    //Guardamos un iterador a pos
        if (i == d.k) d.posK = --datos.end();        //Guardamos un it a la posicion donde hay que insertar
    }


    list<char> sol = resolver(datos, d);
    
    for (auto s : sol) cout << s << " ";

    cout << endl;

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