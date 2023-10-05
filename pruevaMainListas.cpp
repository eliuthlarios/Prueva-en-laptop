#include <iostream>
using namespace std;
#include <string.h>

struct datosDeJugador
{
   string nombre;
   string personaje;
   int nivel;
};

struct Nodo
{
   datosDeJugador jugadorx;
   Nodo *siguiete;
};
void mostrarLista(Nodo *);
void insertarlista(Nodo *&, datosDeJugador);

int main()
{
   system("cls");
   Nodo *Lista = nullptr;
   datosDeJugador Eliuth;
   char continuar;
   do
   {
      cout << "\ninsertar datos del jugador ";
      cin >> Eliuth.nombre;
      cout << "\n jugador a usar ";
      cin >> Eliuth.personaje;
      cout << "\n que nivel? ";
      cin >> Eliuth.nivel;

      insertarlista(Lista, Eliuth);

      cout << "\n desea anadir otro user? s/n ";
      cin >> continuar;
   } while (continuar == 's');

   mostrarLista(Lista);

   return 0;
}

void insertarlista(Nodo *&lista, datosDeJugador jugadorY)
{
   Nodo *nuevoNodo = new Nodo();
   nuevoNodo->jugadorx = jugadorY;

   Nodo *aux1 = lista;
   Nodo *aux2;

   while ((aux1 != nullptr) && (aux1->jugadorx.nivel < jugadorY.nivel))
   {
      aux2 = aux1;
      aux1 = aux1->siguiete;
   }
   if (lista == aux1)
   {
      lista = nuevoNodo;
      nuevoNodo->siguiete = aux1;
   }
   else
   {
      aux2->siguiete = nuevoNodo;
   }
   nuevoNodo->siguiete = aux1;

   cout << "\n el jugador " << jugadorY.nombre << " con personaje " << jugadorY.personaje << " se agrego correctamente a la lista";
}
void mostrarLista(Nodo *Lista)
{
   Nodo *actual = new Nodo();
   actual = Lista;

   while (actual != nullptr)
   {
      cout << "\nel jugador " << actual->jugadorx.nombre << " con personaje " << actual->jugadorx.personaje 
      << " con nivel: " << actual->jugadorx.nivel << endl;
      actual =actual->siguiete;
   }
}
