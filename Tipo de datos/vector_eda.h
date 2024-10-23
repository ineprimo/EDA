//
//  vector_eda.h
//
//  Implementación del TAD vector con array dinámico
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2023 Miguel Gomez-Zamalloa
//

#ifndef vector_eda_h
#define vector_eda_h

#include <stdexcept>  // std::domain_error
#include <utility>    // std::move

template <class T>
class vector {
protected:
    static const int TAM_INICIAL = 10; // tamaño inicial por defecto del array dinámico

    // número de elementos reales del vector
    int nelems;

    // tamaño del array
    int capacidad;

    // puntero al array que contiene los datos (redimensionable)
    T* array;

public:

    // constructor: vector vacío
    vector() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}

    // constructor: vector con n elementos ocupados y capacidad n
    vector(int n) : nelems(n), capacidad(n), array(new T[capacidad]) {}

    // destructor
    ~vector() {
        libera();
    }

    // constructor por copia
    vector(vector<T> const& other) {
        copia(other);
    }

    // operador de asignación
    vector<T>& operator=(vector<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // añade un elemento al final. O(1) amortizado
    void push_back(T const& elem) {
        if (nelems == capacidad)
            amplia(capacidad*2);
        array[nelems] = elem;
        ++nelems;
    }

    // quita el último elemento. O(1)
    void pop_back() {
        if (nelems > 0) --nelems;
    }

    // devuelve referencia constante a elemento en posición i. O(1)
    const T& operator[](int i) const {
        if (i < 0 || i >= nelems) throw std::out_of_range("indice no valido");
        return array[i];
    }

    // devuelve referencia a elemento en posición i. O(1)
    T& operator[](int i){
        if (i < 0 || i >= nelems) throw std::out_of_range("indice no valido");
        return array[i];
    }

    // inserta e en posicion i desplazando para abrir hueco. O(nlems)
    void insert(const T& e, int i){
        if (i < 0 || i >= nelems) throw std::out_of_range("indice no valido");
        if (nelems == capacidad) amplia(capacidad*2);
        desplazaDchaDesde(i);
        array[i] = e;
        ++nelems;
    }

    // borra elemento de posición i desplazando para cerrar el hueco. O(nelems)
    void erase(int i){
        if (i < 0 || i >= nelems) throw std::out_of_range("indice no valido");
        desplazaIzdaDesde(i);
        --nelems;
    }

    // consulta si el vector es vacío. O(1)
    bool empty() const {
        return nelems == 0;
    }

    // consulta el tamaño del vector. O(1)
    int size() const {
        return nelems;
    }

    // cambia el tamaño del vector dando mas capacidad si es necesario. O(n)
    void resize(int n) {
        if (n < 0) throw std::out_of_range("parametro no valido");
        if (n <= nelems) nelems = n; // No se redimensiona hacia abajo, aunque se podría
        else {
            amplia(n);
            nelems = n;
        }
    }

protected:

    void libera() {
        delete[] array;
    }

    // this está sin inicializar
    void copia(vector const& other) {
        capacidad = other.nelems + TAM_INICIAL;
        nelems = other.nelems;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = other.array[i];
    }

    void amplia(int nuevaCapacidad) {
        T* viejo = array;
        capacidad = nuevaCapacidad;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = std::move(viejo[i]);
        delete[] viejo;
    }

    void desplazaDchaDesde(int i){
        for (int j = nelems; j > i; j--)
            array[j] = array[j-1];
    }

    void desplazaIzdaDesde(int i){
        for (; i < nelems-1; i++)
            array[i] = array[i+1];
    }

};

#endif // vector_eda_h
