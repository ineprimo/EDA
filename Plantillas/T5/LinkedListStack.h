//
//  LinkedListStack.h
//
//  Implementación del TAD stack con nodos enlazados
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2023 Marco Antonio Gómez Martín y Miguel Gomez-Zamalloa
//

#ifndef __PILA_LISTA_ENLAZADA_H
#define __PILA_LISTA_ENLAZADA_H

#include <iostream>
#include <iomanip>

template <class T>
class LinkedListStack {
protected:
    /*
     Nodo que almacena internamente el elemento (de tipo T),
     y un puntero al nodo siguiente, que puede ser nullptr si
     el nodo es el último de la lista enlazada.
     */
    class Nodo {
    public:
        Nodo() : sig(nullptr) {}
        Nodo(const T& elem) : elem(elem), sig(nullptr) {}
        Nodo(const T& elem, Nodo *sig) : elem(elem), sig(sig) {}
        T elem;
        Nodo* sig;
    };

    // Puntero al primer elemento
    Nodo* cima;

    // numero de elementos en la cola
    int nelems;

public:

    // constructor: pila vacía
	LinkedListStack() : cima(nullptr), nelems(0) {}

    // destructor
    ~LinkedListStack() {
		libera();
        cima = nullptr;
	}

    // constructor por copia
    LinkedListStack(const LinkedListStack<T> &other) : cima(nullptr) {
        copia(other);
    }

    // operador de asignación
    LinkedListStack<T> &operator=(const LinkedListStack<T> &other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // apilar un elemento
    void push(const T &elem) {
        cima = new Nodo(elem, cima);
		nelems++;
	}

    // desapilar
    void pop() {
		if (empty())
			throw std::domain_error("Desapilando de la pila vacia");
		Nodo* aBorrar = cima;
        cima = cima->sig;
		delete aBorrar;
		--nelems;
	}

    // consultar la cima
    const T& top() const {
		if (empty())
			throw std::domain_error("La pila vacia no tiene cima");
		return cima->elem;
	}

    // consultar si la pila está vacía
    bool empty() const {
		return cima == nullptr;
	}

    // consultar el tamaño de la pila
    int size() const {
		return nelems;
	}

    // relación de equivalencia
	bool operator==(const LinkedListStack<T>& other) const {
		if (nelems != other.nelems)
			return false;
		bool iguales = true;
		Nodo* cima1 = cima;
		Nodo* cima2 = other.cima;
		while ((cima1 != nullptr) && (cima2 != nullptr) && iguales) {
			if (cima1->elem != cima2->elem)
				iguales = false;
			else {
				cima1 = cima1->sig;
				cima2 = cima2->sig;
			}
		}
		return iguales;
	}

	bool operator!=(const LinkedListStack<T>& rhs) const {
		return !(*this == rhs);
	}

protected:

	void libera() {
        while (cima != nullptr) {
            Nodo* aux = cima;
            cima = cima->sig;
            delete aux;
        }
	}

	void copia(const LinkedListStack& other) {
		if (other.empty()) {
            cima = nullptr;
            nelems = 0;
		} else {
			Nodo* act = other.cima;
			Nodo* ant;
            cima = new Nodo(act->elem);
			ant = cima;
			while (act->sig != nullptr) {
				act = act->sig;
				ant->sig = new Nodo(act->elem);
				ant = ant->sig;
			}
            nelems = other.nelems;
		}
	}
};


#endif // __PILA_LISTA_ENLAZADA_H
