// paula sierra luque
// gdv-eda70

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <list>
#include <unordered_map>

using namespace std;

using cancion = std::string;
using artista = std::string;

class iPud {
private:

   struct InfoCancion {
       artista art;
       int duracion;

       list<cancion>::iterator posPlaylist;
       list<cancion>::iterator posReproducidas; 
   };

   unordered_map<cancion, InfoCancion> canciones;

   list<cancion> playlist;
   list<cancion> reproducidas;

public:

   void addSong(const cancion& c, const artista& a, const int& d)
   {
       auto [it, in] = canciones.insert({ c, {a, d, playlist.end(), reproducidas.end()} });
       if (!in)
           throw invalid_argument("addSong");
   }

   void addToPlaylist(const cancion& s) 
   {
       auto it = canciones.find(s);
       if (it == canciones.end()) throw invalid_argument("addToPlaylist");

       /// ULTIMA VERSION (para implementar deleteSong) - O(1)
       if (it->second.posPlaylist == playlist.end()) 
       {
           playlist.push_back(s);
           it->second.posPlaylist = prev(playlist.end()); // iterador al elem anterior a end
       }

       /// VERSION INICIAL:
       // si no esta en la playlist la añadimos
       //bool found = false;
       //for (auto it = playlist.begin(); it != playlist.end() && !found; ++it) 
       //{
       //    if (*it == s) {
       //        found = true;
       //    }
       //}

       //if (!found)
       //    playlist.push_back(s);
   }

   cancion current() const
   {
       if (playlist.empty()) {
           throw invalid_argument("current");
       }

       return playlist.front();
   }

   void play() 
   {
       if (!playlist.empty()) 
       {
           cancion c = playlist.front();
           auto& infoC = canciones[c]; // {cancion, infoCancion} -> canciones[cancion] = infoCancion

           reproducidas.push_front(c);
           infoC.posReproducidas = reproducidas.begin(); // actualizamos iterador

           // sacamos de la playlist
           playlist.pop_front();
           infoC.posPlaylist = playlist.end(); // valor inicial
       }
   }

   int totalTime() 
   {
       int time = 0;
       for (auto it = playlist.begin(); it != playlist.end(); ++it) 
       {
           time += canciones.at(*it).duracion;
       }

       return time;
   }

   // o(n)
   list<cancion> recent(int n) 
   {
       unordered_map<cancion,int> aux;
       list<cancion> result;

       for (auto it = reproducidas.begin(); it != reproducidas.end() && aux.size() < n; ++it)
       {
           auto [_, in] = aux.insert({ *it,0 });

           if (in)
               result.push_back(*it);
       };

       return result;
   }

   // O(1) -> usar remove es O(n) porque recorre lista
   void deleteSong(const cancion& s) 
   {
       auto it = canciones.find(s);

       if (it != canciones.end())
       {
           const InfoCancion& infoC = it->second;

           // si esta en playlist borra:
           if (infoC.posPlaylist != playlist.end()) 
           {
               playlist.erase(infoC.posPlaylist);
           }

           // igual para reproducidas
           if (infoC.posReproducidas != reproducidas.end())
           {
               reproducidas.erase(infoC.posReproducidas);
           }

           // y borrar de canciones:
           canciones.erase(it);
       }
   }
};

bool resuelve() {
   string operacion;
   cin >> operacion;
   if (!cin)
       return false;
   cancion tit; artista aut; int dur;
   iPud ipud;
   while (operacion != "FIN") {
       try {
           if (operacion == "addSong") {
               cin >> tit >> aut >> dur;
               ipud.addSong(tit, aut, dur);
           }
           else if (operacion == "addToPlaylist") {
               cin >> tit;
               ipud.addToPlaylist(tit);
           }
           else if (operacion == "current") {
               tit = ipud.current();
           }
           else if (operacion == "play") {
               try {
                   string tocando = ipud.current();
                   ipud.play();
                   cout << "Sonando " << tocando << '\n';
               }
               catch (invalid_argument e) {
                   cout << "No hay canciones en la lista\n";
               }
           }
           else if (operacion == "totalTime") {
               cout << "Tiempo total " << ipud.totalTime() << '\n';
           }
           else if (operacion == "recent") {
               int N;
               cin >> N;
               auto lista = ipud.recent(N);
               if (lista.empty())
                   cout << "No hay canciones recientes\n";
               else {
                   cout << "Las " << lista.size() << " mas recientes\n";
                   for (auto const& s : lista)
                       cout << "    " << s << '\n';
               }
           }
           else if (operacion == "deleteSong") {
               cin >> tit;
               ipud.deleteSong(tit);
           }
           else {
               assert(false);
           }
       }
       catch (invalid_argument e) {
           cout << "ERROR " << e.what() << '\n';
       }
       cin >> operacion;
   }
   cout << "---\n";
   return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelve())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
