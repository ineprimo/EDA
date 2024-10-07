//  Implementación del TAD Set con array dinámico ordenado y sin repeticiones

#ifndef SET_H
#define SET_H

#include <string>
#include <iostream>
using namespace std;

template <class T>
class Set
{
protected:
	static constexpr int TAM_INICIAL = 10; // tamaño inicial del array dinámico

	// número de elementos del array
	int nelems;

	// tamaño del array
	int capacidad;

	// puntero al array que contiene los elementos ordenados (redimensionable)
	T* array;

public:
	// constructor: conjunto vacío
	Set(int initCap = TAM_INICIAL) : nelems(0), capacidad(initCap), array(new T[capacidad])
	{
	}

	// destructor
	~Set()
	{
		libera();
	}

	// constructor por copia
	Set(const Set<T>& other)
	{
		copia(other);
	}

	// operador de asignación
	Set<T>& operator=(const Set<T>& other)
	{
		if (this != &other)
		{
			libera();
			copia(other);
		}
		return *this;
	}

	// Añadir un elemento. O(n), n=nelems
	void add(const T& elem)
	{
		bool found;
		int pos;
		binSearch(elem, found, pos);
		if (!found)
		{
			shiftRightFrom(pos + 1);
			array[pos + 1] = elem;
			++nelems;
			if (nelems == capacidad)
				amplia(capacidad * 2);
		}
	}

	// Borrar elemento elem. O(n), n=nelems
	void remove(const T& elem)
	{
		bool found;
		int pos;
		binSearch(elem, found, pos);
		if (found)
		{
			shiftLeftFrom(pos);
			--nelems;
		}
	}

	// Chequear pertenencia de e. O(log(n)), n=nelems
	bool contains(const T& x) const
	{
		bool found;
		int pos;
		binSearch(x, found, pos);
		return found;
	}

	// Consultar si el conjunto está vacío
	bool empty() const
	{
		return nelems == 0;
	}

	// Consultar tamaño. O(1)
	int size() const
	{
		return nelems;
	}

	// Relación de equivalencia. O(n), n = nelems
	bool operator==(Set<T>& other) const
	{
		if (nelems == other.nelems)
			return std::equal(array, array + nelems, other->array);
		return false;
	}

	template <class E>
	friend ostream& operator<<(ostream& out, const Set<E>& s);

protected:
	void libera()
	{
		delete[] array;
	}

	// this está sin inicializar
	void copia(const Set& other)
	{
		capacidad = other.nelems + TAM_INICIAL;
		nelems = other.nelems;
		array = new T[capacidad];
		for (int i = 0; i < nelems; ++i)
			array[i] = other.array[i];
	}

	void amplia(int nuevaCap)
	{
		T* viejo = array;
		capacidad = nuevaCap;
		array = new T[capacidad];
		for (int i = 0; i < nelems; ++i)
			array[i] = std::move(viejo[i]);
		delete[] viejo;
	}

	void binSearch(const T& x, bool& found, int& pos) const
	{
		// Pre: los size primeros elementos de array están ordenados
		//      size >= 0

		pos = binSearchAux(x, 0, nelems - 1);
		found = (pos >= 0) && (pos < nelems) && (array[pos] == x);

		// Post : devuelve el mayor índice i (0 <= i <= nelems-1) que cumple
		//        array[i] <= x
		//        si x es menor que todos los elementos de array, devuelve -1
		//        found es true si x esta en array[0..nelems-1]
	}

	int binSearchAux(const T& x, int a, int b) const
	{
		// Pre: array está ordenado entre 0 .. nelems-1
		//      ( 0 <= a <= nelems ) && ( -1 <= b <= nelems ) && ( a <= b+1 )
		//      todos los elementos a la izquierda de 'a' son <= x
		//      todos los elementos a la derecha de 'b' son > x

		int p, m;

		if (a == b + 1)
			p = a - 1;
		else if (a <= b)
		{
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

	void shiftRightFrom(int i)
	{
		for (int j = nelems; j > i; j--)
			array[j] = array[j - 1];
	}

	void shiftLeftFrom(int i)
	{
		for (; i < nelems - 1; i++)
			array[i] = array[i + 1];
	}
};

template <class T>
ostream& operator<<(ostream& out, const Set<T>& set)
{
	out << "{";
	for (int i = 0; i < set.nelems - 1; i++)
		out << set.array[i] << ",";
	if (set.nelems > 0) out << set.array[set.nelems - 1];
	out << "}";
	return out;
}


#endif //SET_H
