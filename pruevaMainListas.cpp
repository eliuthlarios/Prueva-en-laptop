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

 void insertarlista(Nodo*&, datosDeJugador);
int main (){




   return 0;
}

void insertarlista(Nodo *& lista, datosDeJugador jugadorY){
   Nodo *nuevoNodo = new Nodo();
   nuevoNodo->jugadorx = jugadorY;

   Nodo *aux1= lista;
   Nodo *aux2;

   while ((aux1 != nullptr)&&(aux1->jugadorx < jugadorY)){
      aux2 =aux1;
      aux2 =aux1->siguiete;
   }
if(lista==aux1){
   lista = nuevoNodo;
   nuevoNodo->siguiete= aux1;
}else{
   aux2->siguiete = nuevoNodo;
}
nuevoNodo->siguiete = aux1;
}
 