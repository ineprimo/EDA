//
//  bintree_eda.h
//
//  Implementación de árboles binarios (con compartición de nodos)
//  con recorridos en profundidad y por niveles
//  e iterador para recorrer en inorden (basado en una pila de
//  antecesores pendientes)
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2023 Alberto Verdejo y Miguel G-Zamalloa
//

#ifndef bintree_eda_h
#define bintree_eda_h

#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>

template <class T>
class bintree {
protected:
   /*
    Nodo que almacena internamente el elemento (de tipo T),
    y punteros al hijo izquierdo y derecho, que pueden ser
    nullptr si el hijo es vacío (no existe).
    */
   struct TreeNode;
   using Link = std::shared_ptr<TreeNode>;
   struct TreeNode {
      TreeNode(Link const& l, T const& e, Link const& r) : elem(e), left(l), right(r) {};
      T elem;
      Link left, right;
   };
   
   // puntero a la raíz del árbol
   Link raiz;
   
   // constructora privada
   bintree(Link const& r) : raiz(r) {}
   
public:
   // árbol vacío
   bintree() : raiz(nullptr) {}
   
   // árbol hoja
   bintree(T const& e) :
           raiz(std::make_shared<TreeNode>(nullptr, e, nullptr)) {}
   
   // árbol con dos hijos
   bintree(bintree<T> const& l, T const& e, bintree<T> const& r) :
           raiz(std::make_shared<TreeNode>(l.raiz, e, r.raiz)) {}
   
   // constructora por copia, operador de asignación y destructora por defecto
   
   // consultar si el árbol está vacío
   bool empty() const {
      return raiz == nullptr;
   }
   
   // consultar la raíz
   T const& root() const {
      if (empty()) throw std::domain_error("El arbol vacio no tiene raiz.");
      else return raiz->elem;
   }
   
   // consultar el hijo izquierdo
   bintree<T> left() const {
      if (empty()) throw std::domain_error("El arbol vacio no tiene hijo izquierdo.");
      else return bintree<T>(raiz->left);
   }
   
   // consultar el hijo derecho
   bintree<T> right() const {
      if (empty()) throw std::domain_error("El arbol vacio no tiene hijo derecho.");
      else return bintree(raiz->right);
   }

   ///Datos del arbol
   //Devuelve el numero de nodos que tiene el arbol
   int nodos() {
       int _nodos = 0;
       //Primero comprobamos si es vacio
       if (empty()) { }
       else {   //Si no es vacío empezamos a recorrerlo
           nodo(raiz, _nodos);
       }
       return _nodos;
   }

   int hojas() {

       int _hojas = 0;
       if (!empty()) { hoja(raiz, _hojas); }
       return _hojas;
   }

   int altura() {

       int _altura = 1; //1 obligatorio por la raiz
       int _max = 0;
       if (!empty()) { alt(raiz, _altura, _max); }
       else _altura--;
       return _altura;
   }

   bool operator==(const bintree<T>& rhs) const {
       return compara(raiz, rhs.raiz);
   }

   bool operator!=(const bintree<T>& rhs) const {
       return !(*this == rhs);
   }
   
   // recorridos
   
   std::vector<T> preorder() const {
      std::vector<T> pre;
      preorder(raiz, pre);
      return pre;
   }
   
   std::vector<T> inorder() const {
      std::vector<T> in;
      inorder(raiz, in);
      return in;
   }
   
   std::vector<T> postorder() const {
      std::vector<T> post;
      postorder(raiz, post);
      return post;
   }
   
   std::vector<T> levelorder() const {
      std::vector<T> levels;
      if (!empty()) {
         std::queue<Link> pendientes;
         pendientes.push(raiz);
         while (!pendientes.empty()) {
            Link sig = pendientes.front();
            pendientes.pop();
            levels.push_back(sig->elem);
            if (sig->left != nullptr)
               pendientes.push(sig->left);
            if (sig->right != nullptr)
               pendientes.push(sig->right);
         }
      }
      return levels;
   }

   std::vector<T> frontera() {

       std::vector<T> frontera;

       if (!empty()) { front(raiz, frontera); }

       return frontera;
   }
   
protected:

    void nodo(Link a, int& n) {
        //Recorremos los hijos del nodo
        //Primero el izquierdo y luego el derecho
        if (a != nullptr) {
            n++;
            nodo(a->left, n);
            nodo(a->right, n);
        }
    }

    Link hoja(Link a, int& h) {

        //Vamos recorriendo el arbol, 
        //cuando no tenga hijo izquierdo ni hijo derecho aumentamos el contador
        if (a != nullptr) {

            Link iz = hoja(a->left, h);
            Link der = hoja(a->right, h);

            if (iz == nullptr && der == nullptr) h++;
        }

        return a;
    }

    Link alt(Link r, int& a, int& nivel) {

        int b = 0;
        //Vamos recorriendo el arbol
        //Cada vez que un hijo tenga un hijo aumentamos el contador?

        if (r != nullptr) {

            nivel++;  //Esto es para contar los niveles que llevamos bajados
            Link izq = alt(r->left, a, nivel);
            Link der = alt(r->right, a, nivel);

            //Si llegamos a una hora comparamos el nivel en el que estamos con la altura
            //Si el nivel es mayor que la altura decimos que esa es la nueva altura
            if (izq == nullptr && der == nullptr) {
                if (nivel > a) a = nivel;
            }

            nivel--;  //Cuando vamos subiendo lo deshacemos para saber en que nivel estamos 
        }

        return r;
    }

    Link front(Link a, std::vector<T>& fron) {

        //Vamos recorriendo el arbol, 
        //cuando no tenga hijo izquierdo ni hijo derecho aumentamos el contador
        if (a != nullptr) {

            Link iz = front(a->left, fron);
            Link der = front(a->right, fron);

            if (iz == nullptr && der == nullptr) fron.push_back(a->elem);
        }

        return a;
    }
   static void preorder(Link a, std::vector<T> & pre) {
      if (a != nullptr) {
         pre.push_back(a->elem);
         preorder(a->left, pre);
         preorder(a->right, pre);
      }
   }
   
   static void inorder(Link a, std::vector<T> & in) {
      if (a != nullptr) {
         inorder(a->left, in);
         in.push_back(a->elem);
         inorder(a->right, in);
      }
   }
   
   static void postorder(Link a, std::vector<T> & post) {
      if (a != nullptr) {
         postorder(a->left, post);
         postorder(a->right, post);
         post.push_back(a->elem);
      }
   }

    /** Compara dos estructuras jerárquicas de nodos, dadas sus raices (que pueden ser nullptr). */
    static bool compara(Link r1, Link r2) {
        if (r1 == r2)
            return true;
        else if ((r1 == nullptr) || (r2 == nullptr))
            // En el if anterior nos aseguramos de que r1 != r2. Si uno es nullptr, el
            // otro entonces no lo será, luego son distintos.
            return false;
        else {
            return (r1->elem == r2->elem) &&
                   compara(r1->left, r2->left) &&
                   compara(r1->right, r2->right);
        }
    }
   
public:
   // iterador que recorre el árbol en inorden
   class const_iterator {
   public:
      T const& operator*() const {
         if (ptr == nullptr) throw std::out_of_range("fuera del arbol");
         return ptr->elem;
      }
      
      T const* operator->() const {
         return &operator*();
      }
      
      bool operator==(const_iterator const& other) const {
         return ptr == other.ptr;
      }
      bool operator!=(const_iterator const& other) const {
         return !(*this == other);
      }
      
      const_iterator & operator++() {  // ++ prefijo
         next();
         return *this;
      }
      
   private:
      friend class bintree;
      Link ptr;
      std::stack<Link> ancestros;
      
      // constructores privados
      // construye el iterador al primero
      const_iterator(Link raiz) { ptr = first(raiz); }
      
      // construye el iterador al último
      const_iterator() : ptr(nullptr) {}

      Link first(Link act) {
         if (act == nullptr) {
            return nullptr;
         } else {
            while (act->left != nullptr) {
               ancestros.push(act);
               act = act->left;
            }
            return act;
         }
      }
      
      void next() {
         if (ptr == nullptr) {
            throw std::range_error("El iterador no puede avanzar");
         } else if (ptr->right != nullptr) { // primero del hijo derecho
            ptr = first(ptr->right);
         } else if (ancestros.empty()) { // hemos llegado al final
            ptr = nullptr;
         } else { // podemos retroceder
            ptr = ancestros.top();
            ancestros.pop();
         }
      }
      
   };
   
   const_iterator begin() const {
      return const_iterator(raiz);
   }
   const_iterator end() const {
      return const_iterator();
   }
   
};

// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree<T> leerArbol(T vacio) {
   T raiz;
   std::cin >> raiz;
   if (raiz == vacio) { // es un árbol vacío
      return {};
   } else { // leer recursivamente los hijos
      auto iz = leerArbol(vacio);
      auto dr = leerArbol(vacio);
      return {iz, raiz, dr};
   }
}

#endif // bintree_eda_h
