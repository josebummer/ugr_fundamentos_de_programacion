////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
Programa que lee un entero de tres dígitos y los muestra individualmente,
separándolos por tres espacios.

Entradas: un entero
Salidas:  Los dígitos del entero leído.
*/
/*********************************************************************/


#include <iostream>
using namespace std;

int main()
{
   int numero_3dig;	// Dato de entrada: un entero de tres dígitos
   int numero_2dig;
   int digito_centenas, digito_decenas, digito_unidades;

   // Entrada

   cout << "Introduce un entero de tres dígitos: ";
   cin >> numero_3dig;

   // Cálculos
   /*
   numero_3dig = 375
   /100 -> 3
   %100 -> 75
   Como vamos a trabajar con 75, lo almacenamos en otra variable numero_2dig
   numero_2dig = 75
   /10 -> 7
   %10 -> 5
   */
   
   digito_centenas = numero_3dig / 100;
   numero_2dig     = numero_3dig % 100;    // Las dos cifras menos significativas
   
   digito_decenas  = numero_2dig / 10;
   digito_unidades = numero_2dig % 10;

   // Salida

   cout << digito_centenas << "   " << digito_decenas << "   "  << digito_unidades << "\n";

   system ("pause");
}
