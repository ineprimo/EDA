// Plantilla para el ejercicio del Consultorio Médico

#include <iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>

#include <set>
using namespace std;

using medico = string;
using paciente = string;


struct fecha {
    int dia = 0;
    int hora = 0;
    int min = 0;
};

class consultorio {
private:
    medico med;

    

    set<medico> medicos;

public:

    void nuevoMedico(medico m) {
        medicos.insert(m);  //El propio set solo lo anade si no esta
    }

    void pideConsulta(paciente p, medico m, fecha f) {

        if (medicos.count(m) != 0) {

            //Si tiene la fecha ya ocupada se lanza la excepcion
            //throw exception("Fecha existente");
        }
        else throw exception("Medico no existente");
    }

};

int casos = 0;
bool resuelve() {

    int N;
    cin >> N;
    if (!cin) return false;

    string inst; medico med; paciente pac; int d, h, m; char c;
    Consultorio con;

    for (int i = 0; i < N; ++i) {
        try {
            cin >> inst;
            if (inst == "nuevoMedico") {
                cin >> med;
                con.nuevoMedico(med);
            }
            else if (inst == "pideConsulta") {
                cin >> pac >> med >> d >> h >> c >> m;
                con.pideConsulta(pac, med, fecha(d, h, m));
            }
            else if (inst == "siguientePaciente") {
                cin >> med;
                pac = con.siguientePaciente(med);
                cout << "Siguiente paciente doctor " << med << '\n';
                cout << pac << '\n';
            }
            else if (inst == "atiendeConsulta") {
                cin >> med;
                con.atiendeConsulta(med);
            }
            else if (inst == "listaPacientes") {
                cin >> med >> d;
                auto vec = con.listaPacientes(med, fecha(d, 0, 0));
                cout << "Doctor " << med << " dia " << d << '\n';
                for (auto p : vec) {
                    cout << p.second << ' ' << p.first << '\n';
                }
            }
            else
                assert(false);
        }
        catch (invalid_argument e) { cout << e.what() << '\n'; }
    }
    cout << "---\n";

    return true;
}

int main() {
    while (resuelve());

    return 0;
}
