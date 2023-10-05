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
Nodo *Lista = nullptr;
void menu();
void mostrarLista(Nodo *);
void insertarlista(Nodo *&, datosDeJugador);
void buscarJugador(Nodo *, datosDeJugador);
int main()
{
   system("cls");
   menu();
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
      actual = actual->siguiete;
   }
}
void buscarJugador(Nodo *lista, datosDeJugador JugadorR)
{
   bool condicion=false;
   Nodo *actual = new Nodo();
   actual = lista;

   while ((actual != nullptr) && (actual->jugadorx.nivel <= JugadorR.nivel))
   {
      if ((actual->jugadorx.nivel == JugadorR.nivel) && (actual->jugadorx.nombre == JugadorR.nombre))
      {
         condicion = true;
      }
      actual = actual->siguiete;
   }

   if (condicion == true)
   {
      cout << "\n el jugador " << JugadorR.nombre << " se encuentra participando";
   }
   else
   {
      cout << "\nNo hay nadie participando con ese nombre ";
   }
}
void menu()
{

   int opc;
   datosDeJugador Eliuth;
datosDeJugador missing;
   do
   {
      system("cls");
      cout << "\n Menu";
      cout << "\n1. Anadir jugadores";
      cout << "\n2. Mostrar participantes";
      cout << "\n3. Buscar Participantes ";
      cout << "\n4. Salir";
      cout << "\nIngrese Opcion";
      cin >> opc;

      switch (opc)
      {
      case 1:
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
         break;

      case 2:
         mostrarLista(Lista);
         system ("pause");
         break;

      case 3:
        
         cout<<"\nNombre del jugador ? ";cin>>missing.nombre;
         cout<<"\nNivel ? "; cin>>missing.nivel;
         cout<<"\nPersonaje? " ;cin>>missing.personaje;
         
         buscarJugador(Lista,missing);
         system ("pause");
         break;
         

      case 4:
   cout<<"bai...";
   break;
      default:
         cout << "\nErrooor";
         break;
      }
   } while (opc != 4);
}