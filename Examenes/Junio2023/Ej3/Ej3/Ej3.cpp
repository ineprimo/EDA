/*
Nombre completo:
DNI:
Usuario del juez:
Puesto de laboratorio:
Qué has conseguido hacer y qué no:
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;


#include <queue>
#include <unordered_map>


class Fecha {
	int _dia, _mes, _anio;

public:
	Fecha(int d = 0, int m = 0, int a = 0) : _dia(d), _mes(m), _anio(a) {}
	int dia() const { return _dia; }
	int mes() const { return _mes; }
	int anio() const { return _anio; }
	bool operator<(Fecha const& other) const {
		return _anio < other._anio ||
			(_anio == other._anio && _mes < other._mes) ||
			(_anio == other._anio && _mes == other._mes && _dia < other._dia);
	}
};

inline std::istream& operator>>(std::istream& entrada, Fecha& h) {
	int d, m, a; char c;
	std::cin >> d >> c >> m >> c >> a;
	h = Fecha(d, m, a);
	return entrada;
}

inline std::ostream& operator<<(std::ostream& salida, Fecha const& f) {
	salida << std::setfill('0') << std::setw(2) << f.dia() << '/';
	salida << std::setfill('0') << std::setw(2) << f.mes() << '/';
	salida << std::setfill('0') << std::setw(2) << f.anio();
	return salida;
}

using Codigo = string;
using Cliente = string;

using ColaEspera = std::queue<Cliente>; // Cola con clientes.
using ListaClientes = std::unordered_map <Codigo, ColaEspera>; // Codigo es la clave con una cola de clientes que quieren ese producto.

using Existencias = std::unordered_map<Codigo, int>; // Codigo es la clave e int es el numero de elementos.
using Adquisiciones = std::unordered_map <Codigo, std::vector<Fecha>>; // Codigo es la clave con un vector con las fechas.

class Tienda {
private:

	Existencias exis; // Mapa que contiene el numero de existencias de cada producto dado su codigo..
	Adquisiciones adq; // Mapa que contiene las fechas de los produtos dado su codigo.
	ListaClientes lEspera; // Mapa que contiene listas de espera de clientes para cada producto dado su codigo.

public:

	// Constructora por defecto de Tienda. Inicialmente esta vacia y sin cola de espera.
	Tienda()
	{

	}


	vector<Cliente> adquirir(Codigo const& cod, Fecha const& f, int cant)
	{
		// Comprobar si hay gente que quiere los productos recien adquiridos:

		std::vector<Cliente>clientesServidos; // Vector de gente servida.

		// Si no esta vacia vendemos.
		if (!lEspera[cod].empty())
		{
			int i = 0;
			while (!lEspera[cod].empty() && i < cant)
			{
				clientesServidos.push_back(lEspera[cod].front());
				lEspera[cod].pop();
				i++;
				cant--;
			}
		}


		// Gestion del almacen:
		// Cantidades.
		if (!exis.count(cod)) // Si el alamcen no tiene el elemento lo mete nuevo.
		{
			exis.insert({ cod, cant });
		}
		else exis[cod] += cant; // Y si ya lo tiene le suma la cantidad nueva.
		// Fechas.
		if (!adq.count(cod)) // Si no hay adquisiciones las mete.
		{
			std::vector<Fecha> fechas(cant);
			for (int i = 0; i < cant; i++)
			{
				fechas[i] = f;
			}
			adq.insert({ cod, fechas });
		}
		else  // Si ya esta mete mas fechas al vector ya existente.
		{
			for (int i = 0; i < cant; i++)
			{
				adq[cod].push_back(f);
			}
		}

		return clientesServidos;
	}

	pair<bool, Fecha> vender(Codigo const& cod, Cliente const& cli)
	{
		// Si hay existencias:
		if (exis[cod] > 0) // Si las hay sacamos la fecha mas baja de ese producto.
		{
			Fecha fechaVendido(INT_MAX, INT_MAX, INT_MAX);

			int indMenor = 0;
			exis[cod]--; // Quitar una existencia del almacen.
			for (size_t i = 0; i < adq[cod].size(); i++)
			{
				// Para saber que fecha es menor.
				if (adq[cod][i] < fechaVendido)
				{
					fechaVendido = adq[cod][i];
					indMenor = i;
				}
			}
			Fecha aux = adq[cod][adq[cod].size() - 1];
			adq[cod][adq[cod].size() - 1] = adq[cod][indMenor];
			adq[cod][indMenor] = aux;
			adq[cod].pop_back();

			return { true, fechaVendido };
		}
		else // Sino mete al cliente a la lista de espera.
		{
			if (!lEspera.count(cod)) // Si no hay lista de espera para ese producto la crea.
			{
				std::queue<Cliente> auxCola;
				auxCola.push(cli);
				lEspera.insert({ cod, auxCola });
			}
			else // Si si la hay meter al nuevo cliente detras.
			{
				lEspera[cod].push(cli);
			}

			return { false, { -1, -1, -1 } };
		}
	}

	int cuantos(Codigo const& cod) const
	{
		auto cant = (*exis.find(cod)).second;
		if (cant > 0)
		{
			return cant;
		}
		else
		{
			return 0;
		}
	}

	bool hay_esperando(Codigo const& cod) const
	{
		if (!exis.count(cod) || lEspera.count(cod) || (*lEspera.find(cod)).second.empty())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

bool resuelveCaso() {
	std::string operacion, cod, cli;
	Fecha f;
	int cant;
	std::cin >> operacion;
	if (!std::cin)
		return false;

	Tienda tienda;

	while (operacion != "FIN") {
		if (operacion == "adquirir")
		{
			cin >> cod >> f >> cant;
			vector<Cliente> clientes = tienda.adquirir(cod, f, cant);
			cout << "PRODUCTO ADQUIRIDO";
			for (auto c : clientes)
			{
				cout << ' ' << c;
			}
			cout << '\n';
		}
		else if (operacion == "vender")
		{
			cin >> cod >> cli;
			pair<bool, Fecha> venta = tienda.vender(cod, cli);
			if (venta.first)
			{
				cout << "VENDIDO " << venta.second << '\n';
			}
			else
				cout << "EN ESPERA\n";
		}
		else if (operacion == "cuantos")
		{
			cin >> cod;
			cout << tienda.cuantos(cod) << '\n';
		}
		else if (operacion == "hay_esperando")
		{
			cin >> cod;
			if (tienda.hay_esperando(cod))
				cout << "SI\n";
			else
				cout << "NO\n";
		}

		std::cin >> operacion;
	}
	std::cout << "---\n";
	return true;
}


//#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso())
		;

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
#endif

	return 0;
}