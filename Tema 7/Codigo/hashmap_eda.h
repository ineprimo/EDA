//
//  hashmap_eda.h
//
//  Implementación de diccionarios <clave, valor> como tablas hash abiertas
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef hashmap_eda_h
#define hashmap_eda_h

#include <algorithm>
#include <functional>  // std::hash, std::equal_to
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <type_traits>  // std::conditional
#include <cmath>

template <class Clave, class Valor,
          class Hash = std::hash<Clave>,
          class Pred = std::equal_to<Clave>>
class unordered_map {
public:
   // parejas <clave, valor>
   /*struct clave_valor {
      const Clave clave;
      Valor valor;
      clave_valor(Clave const& c, Valor const& v = Valor()) : clave(c), valor(v) {};
   };*/
    using clave_valor = std::pair<const Clave, Valor>;
protected:
   using umap_t = unordered_map<Clave, Valor, Hash, Pred>;
   
   /*
    Clase nodo que almacena internamente la pareja <clave, valor>
    y un puntero al siguiente.
    */
   struct ListNode;
   using Link = ListNode *;
   struct ListNode {
      clave_valor cv;
      Link sig;
      ListNode(clave_valor const& e, Link s = nullptr) : cv(e), sig(s) {}
   };
   
   // vector de listas (el tamaño se ajustará a la carga)
   std::vector<Link> array;
   
   static const int TAM_INICIAL = 17; // tamaño inicial de la tabla
   static const int MAX_CARGA = 75;   // máxima ocupación permitida 75 %
   
   // número de parejas <clave, valor>
   int nelems;
   
   // objeto función para hacer el hash de las claves
   Hash hash;
   
   // objeto función para comparar claves
   Pred pred;
   
public:
   
   // constructor
   unordered_map(int n = TAM_INICIAL, Hash h = Hash(), Pred p = Pred()) :
       array(n, nullptr), nelems(0), hash(h), pred(p) {}
   
   // constructor por copia
   unordered_map(umap_t const& other) {
      copia(other);
   }
   
   // operador de asignación
   umap_t & operator=(umap_t const& that) {
      if (this != &that) {
         libera();
         copia(that);
      }
      return *this;
   }
   
   ~unordered_map() {
      libera();
   };
   
   bool insert(clave_valor const& cv) {
      int i = hash(cv.first) % array.size();
      Link ant, pos = array[i];
      if (localizar(cv.first, ant, pos)) { // la clave ya existe
         return false;
      } else {
         if (muy_llena()) {
            amplia();
            i = hash(cv.first) % array.size();
         }
         array[i] = new ListNode(cv, array[i]);
         ++nelems;
         return true;
      }
   }
   
   bool empty() const {
      return nelems == 0;
   }
   
   int size() const {
      return nelems;
   }
   
   int count(Clave const& c) const  {
      int i = hash(c) % array.size();
      Link ant, pos = array[i];
      return localizar(c, ant, pos) ? 1 : 0;
   }
   
   Valor const& at(Clave const& c) const {
      int i = hash(c) % array.size();
      Link ant, pos = array[i];
      if (localizar(c, ant, pos))
         return pos->cv.second;
      else
         throw std::out_of_range("La clave no se puede consultar");
   }
   
   Valor & operator[](Clave const& c) {
      int i = hash(c) % array.size();
      Link ant, pos = array[i];
      if (localizar(c, ant, pos)) {
         return pos->cv.second;
      } else {
         if (muy_llena()) {
            amplia();
            i = hash(c) % array.size();
         }
         array[i] = new ListNode(clave_valor(c,Valor()), array[i]);
         ++nelems;
         return array[i]->cv.second;
      }
   }
   
   bool erase(Clave const& c) {
      int i = hash(c) % array.size();
      Link ant, pos = array[i];
      if (localizar(c, ant, pos)) {
         if (ant == nullptr)
            array[i] = pos->sig;
         else
            ant->sig = pos->sig;
         delete pos;
         --nelems;
         return true;
      } else
         return false;
   }
   
protected:
   
   void copia(umap_t const& other) {
      array.resize(other.array.size());
      for (int i = 0; i < array.size(); ++i) {
         array[i] = nullptr;
         Link act = other.array[i];
         while (act != nullptr) {
            array[i] = new ListNode(act->cv, array[i]);
            act = act->sig;
         }
      }
      nelems = other.nelems;
      hash = other.hash;
      pred = other.pred;
   }
   
   void libera() {
      for (int i = 0; i < array.size(); ++i) {
         // liberamos los nodos de la lista array[i]
         Link act = array[i];
         while (act != nullptr) {
            Link a_borrar = act;
            act = act->sig;
            delete a_borrar;
         }
         array[i] = nullptr;
      }
   }
   
   bool localizar(Clave const& c, Link & ant, Link & pos) const {
      ant = nullptr;
      while (pos != nullptr) {
         if (pred(c, pos->cv.first))
            return true;
         else {
            ant = pos; pos = pos->sig;
         }
      }
      return false;
   }
   
   bool muy_llena() const {
      return 100.0 * nelems / array.size() > MAX_CARGA;
   }
   
   static int siguiente_primo(int a) {
      bool primo = false;
      while (!primo) {
         ++a;
         primo = true;
         for (int j = 2; j <= sqrt(a) && primo; ++j) {
            primo = a % j != 0;
         }
      }
      return a;
   }
   
   void amplia() {
      std::vector<Link> nuevo(siguiente_primo(array.size()*2), nullptr);
      for (int j = 0; j < array.size(); ++j) {
         Link act = array[j];
         while (act != nullptr) {
            Link a_mover = act;
            act = act->sig;
            int i = hash(a_mover->cv.first) % nuevo.size();
            a_mover->sig = nuevo[i];
            nuevo[i] = a_mover;
         }
      }
      swap(array, nuevo);
   }
   
protected:
   // iteradores que recorren los pares <clave, valor> de la tabla (no ordenados)
   template <bool is_const>
   class Iterador {
      using reference = typename std::conditional<is_const, clave_valor const&, clave_valor &>::type;
      using pointer = typename std::conditional<is_const, clave_valor const*, clave_valor *>::type;
      using pointer_tabla = typename std::conditional<is_const, umap_t const*, umap_t *>::type;
   public:
      reference operator*() const {
         if (act == nullptr)
            throw std::out_of_range("No hay elemento a consultar");
         return act->cv;
      }
      
      pointer operator->() const {
         return &operator*();
      }
      
      Iterador & operator++() {  // ++ prefijo
         next();
         return *this;
      }
      
      bool operator==(Iterador const& that) const {
         return act == that.act;
      }
      
      bool operator!=(Iterador const& that) const {
         return !(this->operator==(that));
      }
      
   protected:
      friend class unordered_map;
      pointer_tabla tabla;   // la tabla que se está recorriendo
      Link act;        // nodo actual
      int ind;      // índice de la lista actual
      
      // iterador al primer elemento o al último
      Iterador(pointer_tabla t, bool first = true) : tabla(t) {
         if (first) {
            ind = 0;
            while (ind < tabla->array.size() && tabla->array[ind] == nullptr) {
               ++ind;
            }
            act = (ind < tabla->array.size() ? tabla->array[ind] : nullptr);
         } else {
            act = nullptr;
            ind = tabla->array.size();
         }
      }
      
      // iterador a una clave
      Iterador(pointer_tabla t, Clave const& c) : tabla(t) {
         ind = tabla->hash(c) % tabla->array.size();
         Link ant;
         act = tabla->array[ind];
         if (!tabla->localizar(c, ant, act)) { // se devuelve iterador al final
            act = nullptr; ind = tabla->array.size();
         }
      }
      
      void next() {
         if (act == nullptr)
            throw std::out_of_range("El iterador no puede avanzar");
         act = act->sig;
         while (act == nullptr && ++ind < tabla->array.size()) {
            act = tabla->array[ind];
         }
      }
   };
   
public:
   // iterador que no permite modificar el elemento apuntado
   using const_iterator = Iterador<true>;
   
   const_iterator cbegin() const {
      return const_iterator(this);
   }
   const_iterator begin() const {
      return cbegin();
   }
   
   const_iterator cend() const {
      return const_iterator(this, false);
   }
   const_iterator end() const {
      return cend();
   }
   
   const_iterator find(Clave const& c) const {
      return const_iterator(this, c);
   }
   
   // iterador que sí permite modificar el elemento apuntado (su valor)
   using iterator = Iterador<false>;
   
   iterator begin() {
      return iterator(this);
   }
   
   iterator end() {
      return iterator(this, false);
   }
   
   iterator find(Clave const& c) {
      return iterator(this, c);
   }
   
};

#endif // hashmap_eda_h
