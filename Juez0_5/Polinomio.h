#pragma once
#include <cmath>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using Monomio = std::pair<int, int>;

class Polinomio
{
	std::vector<Monomio> monomios;

public:
	Polinomio() = default;

	Polinomio(const std::vector<Monomio>& p) : monomios(p)
	{
	}

	void insertarMonomio(const Monomio m)
	{
		auto pos = lower_bound(
			monomios.begin(),
			monomios.end(),
			m
		);

		if (pos == monomios.end()) monomios.push_back(m);
		else if (pos->first == m.first) pos->second += m.second;
		else
		{
			monomios.push_back(m);
			int i = monomios.size() - 1;
			while (i > 0 && monomios[i - 1].first > m.first)
			{
				swap(monomios[i], monomios[i - 1]);
				i--;
			}
		}
	}

	int evaluar(const int& num) const
	{
		// asi no funciona??'
		//int resultado = 0;
		//for (const auto monomio : monomios)
		//	resultado += monomio.first * pow(num, monomio.second);
		//return resultado;


		int sol = 0, pot = 1;
		int exp = 0;

		for (const auto& monomio : monomios)
		{
			while (exp < monomio.first)
			{
				pot *= num;
				exp++;
			}
			sol += monomio.second * pot;
		}
		return sol;
	}
};

inline std::istream& operator>>(std::istream& in, Polinomio& p)
{
	int coef;
	int exp;
	auto pol = Polinomio();
	in >> coef >> exp;
	if (in)
	{
		while (coef != 0 || exp != 0)
		{
			pol.insertarMonomio({ exp, coef });
			in >> coef >> exp;
		}
		p = pol;
	}
	return in;
}