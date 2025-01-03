//
//  queue_eda.h
//
//  Implementación del TAD cola con nodos enlazados
//  y punteros al primero y al último nodo
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef queue_eda_h
#define queue_eda_h

#include <stdexcept>  // std::domain_error

template <class T>
class queue {
protected:
   
   /*
    Nodo que almacena internamente el elemento (de tipo T),
    y un puntero al nodo siguiente, que puede ser nullptr si
    el nodo es el último de la lista enlazada.
    */
   struct Nodo {
      Nodo() : sig(nullptr) {}
      Nodo(T const& el, Nodo * si = nullptr) : elem(el), sig(si) {}
      T elem;
      Nodo * sig;
   };
   
   // punteros al primer y último elemento
   Nodo * prim;
   Nodo * ult;
   
   // número de elementos en la cola
   int nelems;
   
public:
   
   // constructor: cola vacía
   queue() : prim(nullptr), ult(nullptr), nelems(0) {}
   
   // destructor
   ~queue() {
      libera();
   }
   
   // constructor por copia
   queue(queue<T> const& other) {
      copia(other);
   }
   
   // operador de asignación
   queue<T> & operator=(queue<T> const& other) {
      if (this != &other) {
         libera();
         copia(other);
      }
      return *this;
   }
   
   // añadir un elemento al final de la cola
   void push(T const& elem) {
      Nodo * nuevo = new Nodo(elem);
      
      if (ult != nullptr)
         ult->sig = nuevo;
      ult = nuevo;
      if (prim == nullptr) // la cola estaba vacía
         prim = nuevo;
      ++nelems;
   }
   
   // consultar el primero de la cola
   T const& front() const {
      if (empty())
         throw std::domain_error("la cola vacia no tiene primero");
      return prim->elem;
   }
   
   // eliminar el primero de la cola
   void pop() {
      if (empty())
         throw std::domain_error("eliminando de una cola vacia");
      Nodo * a_borrar = prim;
      prim = prim->sig;
      if (prim == nullptr) // la cola se ha quedado vacía
         ult = nullptr;
      delete a_borrar;
      --nelems;
   }
   
   // consultar si la cola está vacía
   bool empty() const {
      return nelems == 0;
   }
   
   // consultar el tamaño de la cola
   int size() const {
      return nelems;
   }

   // mueve al elemento b de su posicion a la posicion inmediatamente detras del elemento a
   // si b = 3, a = 1:
   // 1 2 3 4   --->   1 3 2 4
   // -   ^            - ^
   void cuela(const T& a, const T& b) 
   {
       Nodo* actual = prim;
       Nodo* aN = nullptr;
       Nodo* bN = nullptr;

       bool aFound = false;
       bool bFound = false;

       while (actual != ult && !bFound) // si actual es ult, entonces actual.sig es nullptr, y dara error *
       {
           if (actual->elem == a && !aFound) {
               aN = actual;
               aFound = true;
           }

           // si hemos encontrado a, buscamos b
           if (aFound && actual->sig->elem == b) // * aqui (actual.sig.elem es inaccesible)
           {
                bN = actual->sig;
                actual->sig = bN->sig;  

                bN->sig = aN->sig;
                aN->sig = bN;

                bFound = true;
           }
           actual = actual->sig; // avanza
       }
   }

protected:
   
   void libera() {
      while (prim != nullptr) {
         Nodo * a_borrar = prim;
         prim = prim->sig;
         delete a_borrar;
      }
      ult = nullptr;
   }
   
   // this está sin inicializar
   void copia(queue const& other) {
      if (other.empty()) {
         prim = ult = nullptr;
         nelems = 0;
      } else {
         Nodo * act = other.prim; // recorre la cola original
         Nodo * ant = new Nodo(act->elem); // último nodo copiado
         prim = ant;
         while (act->sig != nullptr) {
            act = act->sig;
            ant->sig = new Nodo(act->elem);
            ant = ant->sig;
         }
         ult = ant;
         nelems = other.nelems;
      }
   }
};

#endif // queue_eda_h
