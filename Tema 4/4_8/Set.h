//  Implementación del TAD Set con array dinámico ordenado y sin repeticiones

#ifndef SET_H
#define SET_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
class Set {
protected:
    static const int TAM_INICIAL = 10; // tamaño inicial del array dinámico

    // número de elementos del array
    int nelems;

    // tamaño del array
    int capacidad;

    // puntero al array que contiene los elementos ordenados (redimensionable)
    T* array;

public:

    // constructor: conjunto vacío
    Set(int initCap = TAM_INICIAL) : nelems(0), capacidad(initCap), array(new T[capacidad]) {}

    // destructor
    ~Set() {
        libera();
    }

    // constructor por copia
    Set(Set<T> const& other) {
        copia(other);
    }

    // operador de asignación
    Set<T>& operator=(Set<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // Añadir un elemento. O(n), n=nelems
    void add(T const& elem) {
        bool found;
        int pos;
        binSearch(elem,found,pos);
        if (!found){
            shiftRightFrom(pos+1);
            array[pos+1] = elem;
            ++nelems;
            if (nelems == capacidad)
                amplia(capacidad*2);
        }
    }

    // Borrar elemento elem. O(n), n=nelems
    void remove(T const& elem){
        bool found;
        int pos;
        binSearch(elem,found,pos);
        if (found) {
            shiftLeftFrom(pos);
            --nelems;
        }
    }

    // Chequear pertenencia de e. O(log(n)), n=nelems
    bool contains(T const& x) const {
        bool found;
        int pos;
        binSearch(x,found,pos);
        return found;
    }

    // Consultar si el conjunto está vacío
    bool empty() const {
        return nelems == 0;
    }

    // Consultar tamaño. O(1)
    int size() const {
        return nelems;
    }

    //Tal vez estos metodos deberian ser protegidos?
    //Toma el dato mas grande 0(1)
    T getMax(vector<T> serie) {
        T max;
        max = serie[0];

        for (int i = 1; i < serie.size(); i++) {
            if (serie[i] < max) max = serie[i];
        }

        return max;
    }

    //Tiene la misma complejidad que el remove
    void removeMax(vector<T> serie) {
        remove(getMax(serie));
    }

    //Toma el dato mas pequeño del vector O(n) -> n elementos del vector
    int getMin(vector<T> serie) {
        //Devolvemos el indice mejor
        int min;
        min = 0;

        for (int i = 1; i < serie.size(); i++) {
            if (serie[i] < serie[min]) min = i;
        }

        return min;
    }

    //Son iguales y simplemente llama al remove
    void removeMin(vector<T>& serie) {
        
        //Deberiamos quitar las repeticiones del numero tambien
        //El indice que nos dan es de la primera aparicion
        
        //Es el indice del menor
        int min = getMin(serie);
        T aux = serie[min];

        int tam = serie.size() - 1;

        //Comprobamos si tiene repeticiones
        //Lo ponemos al final
        serie[min] = serie[tam];
        serie[tam] = aux;

        //Si tiene repeticiones las quitamos tambien
        for (int i = min; i < tam; i++) {
            if (serie[i] == aux) {
                tam--;
                serie[i] = serie[tam];
                serie[tam] = aux;
            }
        }

        if (serie[tam - 1] == serie[tam]) tam--;

        //Hacemos un resize y lo eliminamos
        serie.resize(tam);
    }

    // Relación de equivalencia. O(n), n = nelems
    bool operator==(Set<T>& other) const {
        if (nelems == other.nelems)
            return std::equal(array, array + nelems, other->array);
        else
            return false;
    }
    Set<T> operator||(const Set<T>& other) const; // Union de conjuntos 
    Set<T> operator&&(const Set<T>& other) const; // Interseccion de conjuntos
    Set<T> operator-(const Set<T>& other) const; // Diferencia de conjuntos

    template <class E>
    friend ostream& operator<<(ostream& out, const Set<E>& s);

protected:

    void libera() {
        delete[] array;
    }

    // this está sin inicializar
    void copia(Set const& other) {
        capacidad = other.nelems + TAM_INICIAL;
        nelems = other.nelems;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = other.array[i];
    }

    void amplia(int nuevaCap) {
        T * viejo = array;
        capacidad = nuevaCap;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = std::move(viejo[i]);
        delete[] viejo;
    }

    void binSearch(const T& x, bool& found, int& pos) const {
        // Pre: los size primeros elementos de array están ordenados
        //      size >= 0

        pos = binSearchAux(x, 0, nelems - 1);
        found = (pos >= 0) && (pos < nelems) && (array[pos] == x);

        // Post : devuelve el mayor índice i (0 <= i <= nelems-1) que cumple
        //        array[i] <= x
        //        si x es menor que todos los elementos de array, devuelve -1
        //        found es true si x esta en array[0..nelems-1]
    }

    int binSearchAux(const T& x, int a, int b) const {
        // Pre: array está ordenado entre 0 .. nelems-1
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

        // Post: devuelve el mayor índice i (0 <= i <= nelems-1) que cumple
        //       array[i] <= x
        //       si x es menor que todos los elementos de array, devuelve -1
    }

    void shiftRightFrom(int i){
        for (int j = nelems; j > i; j--)
            array[j] = array[j-1];
    }

    void shiftLeftFrom(int i){
        for (; i < nelems-1; i++)
            array[i] = array[i+1];
    }

};

template <class T>
ostream& operator<<(ostream& out, Set<T> const& set) {
    //out << "{";
    for (int i = 0; i < set.nelems - 1; i++)
        out << set.array[i] << " ";
    if (set.nelems > 0) out << set.array[set.nelems-1];
    //out << "}";
    return out;
}


//La complejidad es O(n) siendo n nelems + other.nelems
template<class T>
inline Set<T> Set<T>::operator||(const Set<T>& other) const
{
    //Hay que comprobar si los conjuntos son vacios?
    Set<T> uni;

    //Ya está ordenado así que vamos a recorrer ambos arrays a la vez
    int i = 0;
    int j = 0;

    //Si son iguales simplemente es igual
    if (array == other.array) {
        uni = other;
    }
    else {
        //Tal vez es un &&
        while (i < nelems && j < other.nelems) {

            if (array[i] == other.array[j]) {
                //Debemos comprobar que no esté contenido si no me equivoco
                //Aunque ese calculo ya lo hace el add se podria evitar hacer el add que es lineal?
                uni.add(array[i]);
                i++;
                j++;
            }
            else if (array[i] > other.array[j]) {
                uni.add(array[i]);
                uni.add(other.array[j]);
                j++;
            }
            else {
                uni.add(array[i]);
                uni.add(other.array[j]);
                i++;
            }
        }

        //Los numeros que no se hayan añadido se añaden directamente
        if (i < nelems) {   //Añadimos los del primer array

            while (i < nelems) { uni.add(array[i]), i++; }
        }
        else if (j < other.nelems) {
            while (j < other.nelems) { uni.add(other.array[j]), j++; }
        } 
    }

    return uni;
}

//La complejidad es O(n), siendo n el numero de elementos del array mas pequeno
template<class T>
inline Set<T> Set<T>::operator&&(const Set<T>& other) const
{
    //Hay que comprobar si los conjuntos son vacios?
    Set<T> inter;

    //Ya está ordenado así que vamos a recorrer ambos arrays a la vez
    int i = 0;
    int j = 0;

    //Tal vez es un &&
    while (i < nelems && j < other.nelems) {

        if (array[i] == other.array[j]) {
            //Debemos comprobar que no esté contenido si no me equivoco
            //Aunque ese calculo ya lo hace el add se podria evitar hacer el add que es lineal?
            inter.add(array[i]);
            i++;
            j++;
        }
        else if (array[i] > other.array[j]) { j++; }
        else { i++; }
    }

    return inter;
}

//La complejidad es O(n + m) siendo esta la suma de numeros de un conjunto y otro
template<class T>
inline Set<T> Set<T>::operator-(const Set<T>& other) const
{
    Set<T> sol(nelems);

    int i = 0, j = 0, k = 0;

    //Esto sirve si el conjunto es vacio
    while (i < nelems && j < other.nelems) //O(n + m) la suma de las longitudes
    {
        if (array[i] < other.array[j]) {
            sol.array[k] = array[i];
            i++;
            k++;
        }
        else if (array[i] == other.array[j]){
            i++; j++;
        }
        else { j++; }
        
    }   

    while (i < nelems) { //O(nelems)
        sol.array[k] = array[i];
        k++;
        i++;
    }

    sol.nelems = k;

    return sol;
}


#endif //SET_H
