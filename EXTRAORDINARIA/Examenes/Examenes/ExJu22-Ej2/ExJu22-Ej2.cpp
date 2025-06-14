// Ejercicio 2: CUELA (3 puntos)
// Tipo: TADs OP INTERNA (lista)

// Nieves Alonso Gilsanz
// EDA-GDV03

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;

template <class T>
class list_plus : public list<T> {
    using Nodo = typename list<T>::Nodo;

public:
    // pos -> posicion en la que comienza el segmento
    // lon -> longitud del segmento a desplazar
    // k -> posiciones a adelantar
    // ----
    // Si la posicion de origen o destino del segmento no es valida (incluye lista vacia), o si lon = 0 o k = 0 -> no tendra efecto
	// Si el segmento se sale de la lista, es decir, si pos + lon > n se tomara el segmento de los ultimos n − pos elementos
    void adelantar(int pos, int lon, int k)
    {
        if (this->empty() || lon == 0 || k == 0 || k > pos || k >= this->size() || pos >= this->size() || pos - k < 0)
            return;
	    
	    // se toma el segmento de los ultimos n − pos elementos
        if (pos + lon > this->size()) lon = this->size() - pos;

        Nodo* antDestino = this->fantasma;  // el anterior a la posicion a la que vas
        Nodo* antSegmento = this->fantasma->sig; // anterior al primero del segmento
        Nodo* ultSegmento = this->fantasma->sig; // ultimo del segmento
        int i = 0;

        while (i < this->size())
        {
            // el anterior a la posicion a la que vas
            if (i < (pos-k)) antDestino = antDestino->sig;

            // anterior al primero del segmento
            if (i < (pos-1)) antSegmento = antSegmento->sig;

            // ultimo del segmento
            if (i < (pos+(lon-1))) ultSegmento = ultSegmento->sig;

            ++i;
        }

        Nodo* sigDestino = antDestino->sig;
        Nodo* priSegmento = antSegmento->sig;
        Nodo* sigSegmento = ultSegmento->sig;

        antDestino->sig = priSegmento;
        priSegmento->ant = antDestino;

        sigDestino->ant = ultSegmento;
        ultSegmento->sig = sigDestino;

        antSegmento->sig = sigSegmento;
        sigSegmento->ant = antSegmento;
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    char e;
    int n, pos, lon, k;
    list_plus<char> l;

    // leer los datos de la entrada
    cin >> n >> pos >> lon >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> e;
        l.push_back(e);
    }

    l.adelantar(pos, lon, k);

    // Le damos una vuelta para comprobar que la lista está bien formada
    for (int i = 0; i < l.size(); ++i) {
        e = l.back();
        l.pop_back();
        l.push_front(e);
    }

    // Ahora imprimimos la lista y de paso la dejamos vacía (tb para probar su consistencia)
    while (!l.empty()) {
        cout << l.front() << " ";
        l.pop_front();
    }
    cout << endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}