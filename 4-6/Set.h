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
	static constexpr int TAM_INICIAL = 5; // tamaño inicial del array dinámico

	// número de elementos del array
	int nelems;

	// tamaño del array
	int capacidad;

	// puntero al array que contiene los elementos ordenados (redimensionable)
	T* array;

public:
	// constructor: conjunto vacío
	Set() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad])
	{
	}

	// constructor: conjunto vacío reservando espacio para initCap elementos
	Set(int initCap) : nelems(0), capacidad(initCap), array(new T[capacidad])
	{
	}

	// destructor
	~Set()
	{
		libera();
	}

	// constructor por copia
	Set(const Set& other)
	{
		copia(other);
	}

	// operador de asignación
	Set& operator=(const Set& other)
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

		/* binSearch(elem,found,pos);
		if (!found){
		    shiftRightFrom(pos+1);
		    array[pos+1] = elem;
		    ++nelems;
		    if (nelems == capacidad)
		        amplia(capacidad*2);
		}*/

		// Usando busq. binaria de librería STL
		T* it = lower_bound(array, array + nelems, elem);
		if (it == array + nelems || *it != elem)
		{
			pos = it - array; // Aritmética de punteros
			shiftRightFrom(pos);
			array[pos] = elem;
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

		/*binSearch(elem,found,pos);
		if (found) {
		    shiftLeftFrom(pos);
		    --nelems;
		}*/

		// Usando busq. binaria de librería STL
		T* it = lower_bound(array, array + nelems, elem);
		if (it != array + nelems && *it == elem)
		{
			pos = it - array; // Aritmética de punteros
			shiftLeftFrom(pos);
			--nelems;
		}
	}

	// Chequear pertenencia de e. O(log(n)), n=nelems
	bool contains(const T& elem) const
	{
		bool found;
		int pos;

		/*binSearch(elem,found,pos);
		return found;*/

		// Usando busq. binaria de librería STL
		return binary_search(array, array + nelems, elem);
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

	// Consultr array. O(1)
	const T* toArray() const {
		return array;
	}

	// Consultar el maximo elemento. O(1)
	int getMax() const {
		return array[nelems - 1];
	}

	// O(log n) donde n es el n de eltos, es una busqueda binaria
	void removeMax() {
		remove(getMax());
	}

	// O(1)
	int getMin() const {
		return array[0];
	}

	// O(log n) donde n es el n de eltos, es una busqueda binaria
	void removeMin() {
		remove(getMin());
	}



	/// OPERATORS
	// Relación de equivalencia. O(n), n = nelems
	bool operator==(Set& other) const
	{
		if (nelems == other.nelems)
			return std::equal(array, array + nelems, other->array);
		return false;
	}

	Set operator||(const Set& other) const
	{
		//if (this == other)
		//	return this;

		Set uni(nelems + other.nelems);

		int i = 0, j = 0, k = 0;

		while (i < nelems && j < other.nelems)
		{
			if (array[i] < other.array[j])
			{
				uni.array[k] = array[i];
				i++;
				k++;
			}
			else if (array[i] > other.array[j])
			{
				uni.array[k] = other.array[j];
				j++;
				k++;
			}
			else
			{
				uni.array[k] = array[i];
				i++;
				j++;
				k++;
			}
			++uni.nelems;
		}

		while (i < nelems)
		{
			uni.array[k] = array[i];
			++uni.nelems;
			i++;
			k++;
		}

		while (j < other.nelems)
		{
			uni.array[k] = other.array[j];
			++uni.nelems;
			j++;
			k++;
		}

		return uni;
	}

	Set operator&&(const Set& other) const
	{
		Set intersec(min(nelems, other.nelems));

		int i = 0, j = 0, k = 0;

		while (i < nelems && j < other.nelems)
		{
			if (array[i] == other.array[j])
			{
				intersec.array[k] = array[i];
				i++;
				j++;
				k++;
				++intersec.nelems;
			}
			else if (array[i] < other.array[j]) i++;
			else if (array[i] > other.array[j]) j++;
		}

		return intersec;
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
	out << "";
	for (int i = 0; i < set.nelems - 1; i++)
		out << set.array[i] << " ";
	if (set.nelems > 0) out << set.array[set.nelems - 1];
	out << "";
	return out;
}


#endif //SET_H
