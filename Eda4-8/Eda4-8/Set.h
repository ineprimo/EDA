//  Implementaci�n del TAD Set con array din�mico ordenado y sin repeticiones

#ifndef SET_H
#define SET_H

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Set {
protected:
    static const int TAM_INICIAL = 5; // tama�o inicial del array din�mico

    // n�mero de elementos del array
    int nelems;

    // tama�o del array
    int capacidad;

    // puntero al array que contiene los elementos ordenados (redimensionable)
    T* array;

public:

    // constructor: conjunto vac�o
    Set() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}

    // constructor: conjunto vac�o reservando espacio para initCap elementos
    Set(int initCap) : nelems(0), capacidad(initCap), array(new T[capacidad]) {}

    // destructor
    ~Set() {
        libera();
    }

    //4-8
    Set<T> operator-(const Set<T>& o) const 
    {
        Set<T> diff;

        for (int i = 0; i < nelems; i++)
        {
            if (!o.contains(array[i]))
            {
                // uso add de abajo
                diff.add(array[i]);
            }
        }

        return diff;
    }

    // constructor por copia
    Set(Set<T> const& other) {
        copia(other);
    }

    // operador de asignaci�n
    Set<T>& operator=(Set<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // A�adir un elemento. O(n), n=nelems
    void add(T const& elem) {
        bool found;
        int pos;

        /* binSearch(elem,found,pos);
        if (!found){
            shiftRightFrom(pos+1);
            array[pos+1] = elem;
            ++nelems;
            if (nelems == capacidad)
                amplia(capacidad*2);
        }*/

        // Usando busq. binaria de librer�a STL
        T* it = lower_bound(array, array + nelems, elem);
        if (it == array + nelems || *it != elem) {
            pos = it - array; // Aritm�tica de punteros
            shiftRightFrom(pos);
            array[pos] = elem;
            ++nelems;
            if (nelems == capacidad)
                amplia(capacidad * 2);
        }
    }

    // Borrar elemento elem. O(n), n=nelems
    void remove(T const& elem) {
        bool found;
        int pos;

        /*binSearch(elem,found,pos);
        if (found) {
            shiftLeftFrom(pos);
            --nelems;
        }*/

        // Usando busq. binaria de librer�a STL
        T* it = lower_bound(array, array + nelems, elem);
        if (it != array + nelems && *it == elem) {
            pos = it - array; // Aritm�tica de punteros
            shiftLeftFrom(pos);
            --nelems;
        }
    }

    // Chequear pertenencia de e. O(log(n)), n=nelems
    bool contains(T const& elem) const {
        bool found;
        int pos;

        /*binSearch(elem,found,pos);
        return found;*/

        // Usando busq. binaria de librer�a STL
        return binary_search(array, array + nelems, elem);
    }

    // Consultar si el conjunto est� vac�o
    bool empty() const {
        return nelems == 0;
    }

    // Consultar tama�o. O(1)
    int size() const {
        return nelems;
    }

    // Relaci�n de equivalencia. O(n), n = nelems
    bool operator==(Set<T>& other) const {
        if (nelems == other.nelems)
            return std::equal(array, array + nelems, other->array);
        else
            return false;
    }

    template <class E>
    friend ostream& operator<<(ostream& out, const Set<E>& s);

protected:

    void libera() {
        delete[] array;
    }

    // this est� sin inicializar
    void copia(Set const& other) {
        capacidad = other.nelems + TAM_INICIAL;
        nelems = other.nelems;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = other.array[i];
    }

    void amplia(int nuevaCap) {
        T* viejo = array;
        capacidad = nuevaCap;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = std::move(viejo[i]);
        delete[] viejo;
    }

    void binSearch(const T& x, bool& found, int& pos) const {
        // Pre: los size primeros elementos de array est�n ordenados
        //      size >= 0

        pos = binSearchAux(x, 0, nelems - 1);
        found = (pos >= 0) && (pos < nelems) && (array[pos] == x);

        // Post : devuelve el mayor �ndice i (0 <= i <= nelems-1) que cumple
        //        array[i] <= x
        //        si x es menor que todos los elementos de array, devuelve -1
        //        found es true si x esta en array[0..nelems-1]
    }

    int binSearchAux(const T& x, int a, int b) const {
        // Pre: array est� ordenado entre 0 .. nelems-1
        //      ( 0 <= a <= nelems ) && ( -1 <= b <= nelems ) && ( a <= b+1 )
        //      todos los elementos a la izquierda de 'a' son <= x
        //      todos los elementos a la derecha de 'b' son > x

        int p, m;

        if (a == b + 1)
            p = a - 1;
        else if (a <= b) {
            m = (a + b) / 2;
            if (array[m] <= x)
                p = binSearchAux(x, m + 1, b);
            else
                p = binSearchAux(x, a, m - 1);
        }
        return p;

        // Post: devuelve el mayor �ndice i (0 <= i <= nelems-1) que cumple
        //       array[i] <= x
        //       si x es menor que todos los elementos de array, devuelve -1
    }

    void shiftRightFrom(int i) {
        for (int j = nelems; j > i; j--)
            array[j] = array[j - 1];
    }

    void shiftLeftFrom(int i) {
        for (; i < nelems - 1; i++)
            array[i] = array[i + 1];
    }

};
template <class T>
ostream& operator<<(ostream& out, Set<T> const& set) 
{
    for (int i = 0; i < set.nelems - 1; i++) 
    {
        out << set.array[i] << " ";
    }

    if (set.nelems > 0)
    {
        out << set.array[set.nelems - 1];
    }
    
    return out;
}


#endif //SET_H
