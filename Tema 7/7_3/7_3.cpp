#include <iostream>
#include <fstream>
#include <cctype>
#include <map>
using namespace std;

map <string, int> resolver(string const& primerDeporte, ...) {
    map<string, int> listaD;
    map <string, string> alu;
    int cont = 0;
    string deporte, alumno;
    deporte = primerDeporte;

    while (deporte != "_FIN_") {
        
            cin >> alumno;
        while (!isupper(alumno[0]) && alumno != "_FIN_") {
            cont++;
               
                //anadimos el alumno a la lista de alumnos
                auto it = alu.find(alumno);

                if (it == alu.end()) {  //Si el alumno no esta en la lista lo anadimos
                    alu.insert({ alumno, deporte });
                }
                else {
                    //Si está en el mismo deporte no pasa nada pero si esta en un deporte distinto 
                    //Hay que quitarlo de ambos deportes

                    if (deporte == it->second) { cont--; }
                    else if (it->second != "Random") {  //Cuando los deportes son distintos eliminamos al alumno

                        //Si no se habia eliminado ya, lo eliminamos del deporte que se apunto primero
                        //Ponemos que el alumno estará en un deporte random
                        //Lo quitamos de la lista original

                        //Lo quitamos de la lista original
                        auto itD = listaD.find(it->second);

                        itD->second = itD->second - 1;

                        it->second = "Random";
                        cont--;
                    }
                    else {
                        cont--;
                    }
                    
                }

                cin >> alumno;
        }
        listaD.insert({ deporte, cont });
        cont = 0;
        deporte = alumno;
    }

    return listaD;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    string primerDeporte;
    cin >> primerDeporte;
    if (!cin) return false;

    map<string, int> sol = resolver(primerDeporte);

    //Guardamos el mapa al reves a lo mejor?? con el int primero?? aunque me haria falta un multimap
    multimap <int, string, greater<int>> solOrdenada;

    for (auto n : sol) {
        solOrdenada.insert({ n.second, n.first });
    }
    
    //Escribimos la solucion
    for (auto par : solOrdenada) {
        //Siendo size el numero de gente que hay en el deporte
        cout << par.second << " " << par.first << endl;
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