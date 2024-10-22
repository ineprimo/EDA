//
//  stack_eda.h
//
//  Implementación del TAD pila con array dinámico
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef stack_eda_h
#define stack_eda_h

#include <stdexcept>  // std::domain_error
#include <utility>    // std::move

template <class T>
class stack {
protected:
    static const int TAM_INICIAL = 10; // tamaño inicial del array dinámico
    
    // número de elementos en la pila
    int nelems;
    
    // tamaño del array
    int capacidad;
    
    // puntero al array que contiene los datos (redimensionable)
    T * array;
    
public:
    
    // constructor: pila vacía
    stack() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}
    
    // destructor
    ~stack() {
        libera();
    }
    
    // constructor por copia
    stack(stack<T> const& other) {
        copia(other);
    }
    
    // operador de asignación
    stack<T> & operator=(stack<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }
    
    // apilar un elemento
    void push(T const& elem) {
        array[nelems] = elem;
        ++nelems;
        if (nelems == capacidad)
            amplia();
    }
    
    // consultar la cima
    T const& top() const {
        if (empty())
            throw std::domain_error("la pila vacia no tiene cima");
        return array[nelems - 1];
    }
    
    // desapilar el elemento en la cima
    void pop() {
        if (empty())
            throw std::domain_error("desapilando de la pila vacia");
        --nelems;
    }
    
    // consultar si la pila está vacía
    bool empty() const {
        return nelems == 0;
    }
    
    // consultar el tamaño de la pila
    int size() const {
        return nelems;
    }
    
protected:
    
    void libera() {
        delete[] array;
    }
    
    // this está sin inicializar
    void copia(stack const& other) {
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
};

#endif // stack_eda_h
