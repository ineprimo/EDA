#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
using namespace std;

using TablaRefs = map<string, list<int>>;

void referencias(int numLineas, TablaRefs& refs) {
    string palabra;
    char c;
    for (int numLinea = 1; numLinea <= numLineas; numLinea++) {
        cin.get(c);
        while (c != '\n') {
            cin.unget(); // Se vuelve a dejar c en cin (por si era la 1ª letra de la linea)
            cin >> palabra;

            //Solo tenemos en cuenta palabras mayores de 2
            if (palabra.size() > 2) {

                //Convertimos la palabra en minuscula
                for (auto& c : palabra)
                    c = tolower(c);

                //Vemos si la palabra está o no está en el mapa
                auto it = refs.find(palabra);

                if (it == refs.end()) { //si la palabra no está todavia, la insertamos
                    list<int> lis;
                    lis.push_back(numLinea);
                    refs.insert({ palabra, lis });
                }
                else {  //Si ya esta anadimos la linea a la lista
                    //Si el ultimo numero no es la linea actual anadimos
                    if(refs[palabra].back() != numLinea)
                    refs[palabra].push_back(numLinea);
                }
            }

            cin.get(c);
            
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    char c;
    cin >> n;
    cin.get(c); // Me salto el \n de detrás del N
    if (n == 0)
        return false;

    TablaRefs refs;
    referencias(n, refs);

    // escribir sol
    // par: <string, int>
    for (auto par : refs) {
        //Escribimos la palabra
        cout << par.first << " ";

        //Escribimos la lista de lineas
        for (auto lis : par.second) {
            cout << lis << " ";
        }

        //Hacemos salto de linea
        cout << "\n";
    }
        cout << "---\n";
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
#endif

    return 0;
}