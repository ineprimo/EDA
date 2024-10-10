#pragma once
#include "Hora.h"

class Pelicula
{
	Hora hora, duracion, fin;
	std::string titulo;

public:
	Pelicula() = default;
	Pelicula(const Hora& hora, const Hora& duracion, std::string& titulo)
		: hora(hora), duracion(duracion), titulo(titulo)
	{
		fin = hora + duracion;
	}
	Pelicula(const Pelicula& pelicula) = default;
	~Pelicula() = default;

	Hora getHora() const { return hora; }
	Hora getDuracion() const { return duracion; }
	Hora getFin() const { return fin; }
	std::string getTitulo() { return titulo; }

	bool operator<(const Pelicula& p) const { // ordenados por quien acaba antes y alfabeticamente en defecto
		return fin < p.fin || (fin == p.fin && titulo < p.titulo);
	}
};
