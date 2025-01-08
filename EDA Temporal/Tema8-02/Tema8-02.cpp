// Javier Tirado Ríos
// EDA-GDV72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>

using namespace std;
using Medico = string;
using Paciente = string;

class consultorio {
private:
    struct fecha
    {
        int dia;
        int hora;
        int minuto;
    };

    struct pacienteInfo {
        Paciente nombre;
        fecha fecha;
    };

    struct medicoInfo {
        pacienteInfo pInfo;
        fecha fecha;
    };

    unordered_map<Medico, medicoInfo> medicos;

public:
    void nuevoMedico(const Medico& m) {
        medicos.insert({m, medicoInfo()});
    }

    void pideConsulta(const Paciente& p, const Medico& m, fecha fecha) {

    }

};

// función que resuelve el problema
TipoSolucion resolver(TipoDatos datos) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada


    TipoSolucion sol = resolver(datos);
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}