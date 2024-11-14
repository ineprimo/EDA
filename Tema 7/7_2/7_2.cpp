#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

using Diccionario = map<string, int>;

struct sol {
    vector<string> anadidas;
    vector<string> quitadas;
    vector<string> cambiadas;
};

void leerDiccionario(Diccionario& diccionario) {
    char c;
    string clave;
    int valor;
    cin.get(c);
    while (c != '\n') {
        cin.unget();
        cin >> clave >> valor;
        
        //Anadimos las palabras al diccionario
        diccionario.insert({ clave, valor });
        cin.get(c);
    }
}

sol compDiccionario(Diccionario antiguo, Diccionario nuevo) {

    //recorremos los mapas comparando?
    auto i = antiguo.begin();
    auto j = nuevo.begin();
    sol solucion;

    while (i != antiguo.end() && j != nuevo.end()) {

        if (i ->first == j ->first) {   //Son iguales asi que simplemente aumentamos el it

            if (i->second != j->second) solucion.cambiadas.push_back(i->first); //El elemento a cambiado de valor

            i++;
            j++;
        }
        else
        {
            //Vemos cual es mayor
            if (i->first < j->first) { //Si el nuevo es mayor se ha quitado un elemento
                solucion.quitadas.push_back(i->first);
                i++;
            }
            else { //Si el viejo es mayor se ha anadido un elemento
                solucion.anadidas.push_back(j->first);
                j++;
            }
            
        }
    }

    //Anadimos los datos que faltan por comprobar
    if (i != antiguo.end()) {   
        //Si el primero no ha llegado al final 
        // significa que es mayor que el ultimo nuevo i->first > j->first

        //Anadimos las quitadas hasta que termine
        while (i != antiguo.end()) {
            solucion.quitadas.push_back(i->first);
            i++;
        }
    }
    else {
        //Si es el segundo el que no ha llegado al final
        //significa que i es menor que el ultimo nuevo i->first < j->first

        //anadimos anadidas hasta que termine
        while (j != nuevo.end()) {
            solucion.anadidas.push_back(j->first);
            j++;
        }

    }

    return solucion;
    
}

void resuelveCaso() {

    Diccionario antiguo;
    Diccionario nuevo;

    leerDiccionario(antiguo);
    leerDiccionario(nuevo);

    sol Solucion = compDiccionario(antiguo, nuevo);


    if (Solucion.anadidas.size() == 0 &&
        Solucion.quitadas.size() == 0 &&
        Solucion.cambiadas.size() == 0)
        cout << "SIN CAMBIOS";
    else {
        //Escribimos la solucion
        if (Solucion.anadidas.size() > 0) {
            cout << "+";

            for (auto e : Solucion.anadidas) {
                cout << " " << e;
            }
        }

        if (Solucion.quitadas.size() > 0) {
            cout << "\n-";

            for (auto e : Solucion.quitadas) {
                cout << " " << e;
            }
        }

        if (Solucion.cambiadas.size() > 0) {
            cout << "\n*";

            for (auto e : Solucion.cambiadas) {
                cout << " " << e;
            }
        }
    }
    cout << "\n---\n";
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos; char c;
    std::cin >> numCasos;
    cin.get(c);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
