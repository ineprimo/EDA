#pragma once

class Horas {
public:
	//operator <

	Horas() {

		horas = 0;
		min = 0;
		seg = 0;
	}

	Horas(int h, int m, int s) {

		if (0 <= h <= 23 && 0 <= m <= 59 && 0 <= s <= 59)
		{
			horas = h;
			min = m;
			seg = s;
		}
		else throw "La hora no es adecuada";
	}

	const bool operator< (const Horas otro) {

		//Si tiene menos horas directamente es menor
		if (horas <= otro.horas) {

			//Si tienen las mismas horas miramos los minutos
			if (horas == otro.horas && min <= otro.min) {

				if (min == otro.min && seg <= otro.seg) {

					return seg == otro.seg;
				}
				else return true;
			}
			else return true;

		}
		else return false;
		
	}


protected:

	int horas;
	int min;
	int seg;

};
