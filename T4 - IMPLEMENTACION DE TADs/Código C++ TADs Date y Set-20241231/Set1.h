
#include <algorithm>
#include <string>
#include <iostream>


#ifndef SET1_H
#define SET1_H


using namespace std;

//  Implementación del TAD Set con array dinámico no ordenado y con repeticiones
template <class T>
class Set1 {
protected:
    static const int TAM_INICIAL = 10; // tamaño inicial del array dinámico

    // número de elementos del array
    int nelems;

    // tamaño del array
    int capacidad;

    // puntero al array que contiene los datos (redimensionable)
    T* array;

public:

    // constructor: conjunto vacío
    Set1(int initCap = TAM_INICIAL) : nelems(0), capacidad(initCap), array(new T[capacidad]) {}

    // destructor
    ~Set1() {
        libera();
    }

    // constructor por copia
    Set1(Set1<T> const& other) {
        copia(other);
    }

    // operador de asignación
    Set1<T>& operator=(Set1<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // Añadir un elemento. O(1), salvo cuando redimensiona
    void add(T const& elem) {
        array[nelems] = elem;
        ++nelems;
        if (nelems == capacidad)
            amplia();
    }

    // Borrar elemento elem. O(n), n=nelems
    void remove(T const& elem){
        bool found;
        int pos;
        linSearch(elem,0,nelems,found,pos);
        while (found){
            --nelems;
            array[pos] = array[nelems];
            linSearch(elem,pos,nelems,found,pos);
        }
    }

    // Chequear pertenencia de e. O(n), n=nelems
    bool contains(T const& e) const {
        bool found;
        int pos;

        linSearch(e,0,nelems,found,pos);
        return found;
    }

    // Consultar si el conjunto está vacío
    bool empty() const {
        return nelems == 0;
    }

    // Consultar tamaño. O(n*log(n)), n = nelems
    int size() {
        sortRemoveDups(); // O(n*log(n)) con n = nelems
        return nelems;
    }

    // Relación de equivalencia. O(n*log(n)), n = nelems
    bool operator==(Set1<T>& other){
        this->sortRemoveDups();
        other.sortRemoveDups();
        if (nelems == other.nelems)
            return std::equal(array, array+nelems, other.array);
        else
            return false;
    }

    template <class E>
    friend ostream& operator<<(ostream& out, const Set1<E>& s);

protected:

    void libera() {
        delete[] array;
    }

    // this está sin inicializar
    void copia(Set1 const& other) {
        capacidad = other.nelems + TAM_INICIAL;
        nelems = other.nelems;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = other.array[i];
    }

    void amplia() {
        T * viejo = array;
        capacidad *= 2;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = std::move(viejo[i]);
        delete[] viejo;
    }

    void linSearch(T const& x, int left, int right, bool& found, int& pos) const {
        // P: array tiene al menos right elementos

        int i;

        if (left >= right) {
            found = false;
            pos = right;
        } else {
            found = false;
            i = left;
            while (!found && (i < right)) {
                found = array[i] == x;
                if (!found)
                    i++;
            }
            pos = i;
        }

        // Q :  found es true si existe un i en el intervalo left..right-1
        //        tal que array[i] == x
        //      si found es true entonces pos = el minimo i en
        //        el intervalo left..right-1 tal que array[i] == x
        //      si no found entonces pos == right
    }

    // Implementación de búsqueda lineal usando std::find de algorithm
    void linSearch2(T const& x, int left, int right, bool& found, int& pos) const {
        T* p = std::find(array+left, array+right, x);
        if (p == array+right){
            found = false;
            pos = right;
        } else {
            found = true;
            pos = p - array; // Aritmética de punteros
        }
    }

    void sortRemoveDups() { // O(nelems*log(nelems))
        std::sort(array, array + nelems);
        int pos = 0;
        for (int i = 0; i < nelems;) {
            array[pos] = array[i];
            ++i;
            while (i < nelems && array[i] == array[pos]) ++i;
            ++pos;
        }
        nelems = pos;
    }
};

template <class T>
ostream& operator<<(ostream& out, Set1<T> const& set) {
    out << "{";
    for (int i = 0; i < set.nelems-1; i++)
        out << set.array[i] << ",";
    if (set.nelems > 0) out << set.array[set.nelems-1];
    out << "}";
    return out;
}

#endif //SET1_H
