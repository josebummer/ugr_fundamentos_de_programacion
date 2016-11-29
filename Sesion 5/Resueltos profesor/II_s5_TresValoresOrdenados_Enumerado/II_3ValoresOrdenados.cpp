///////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Juan Carlos Cubero
//
///////////////////////////////////////////////////////

/*
 Modificad el ejercicio 5 para que el programa nos diga si los tres valores leídos es-
tán ordenados de forma ascendente, ordenados de forma descendente o no están
ordenados. Para resolver este problema, se recomienda usar una variable de tipo
enumerado.
*/

#include <iostream>
using namespace std;

enum class TipoOrden {creciente, decreciente, desordenado};

int main(){
   int a, b, c;  // Jamás usaremos nombres tan cortos. Este programa, por su sencillez, es una excepción.
   TipoOrden tipo_de_orden;
   
   cout << "\nIntroduzca tres enteros:\n";
   cin >> a;  
   cin >> b;
   cin >> c;
   
   if (a <= b && b <= c)
      tipo_de_orden = TipoOrden::creciente;
   else{
      if (a >= b && b >= c)
         tipo_de_orden = TipoOrden::decreciente;
      else 
         tipo_de_orden = TipoOrden::desordenado;
   }
   
   if (tipo_de_orden == TipoOrden::creciente)
      cout << "\nHas introducido los valores de forma ordenada creciente";   
   else {
      if (tipo_de_orden == TipoOrden::decreciente)
         cout << "\nHas introducido los valores de forma ordenada decreciente";   
      else
         cout << "\nNo has introducido los valores de forma ordenada";  
   }
   
   cout << "\n\n";   
}
