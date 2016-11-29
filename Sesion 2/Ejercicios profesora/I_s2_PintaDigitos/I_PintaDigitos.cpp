////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
Programa que lee un entero de tres d�gitos y los muestra individualmente,
separ�ndolos por tres espacios.

Entradas: un entero
Salidas:  Los d�gitos del entero le�do.
*/
/*********************************************************************/


#include <iostream>
using namespace std;

int main()
{
   int numero_3dig;	// Dato de entrada: un entero de tres d�gitos
   int numero_2dig;
   int digito_centenas, digito_decenas, digito_unidades;

   // Entrada

   cout << "Introduce un entero de tres d�gitos: ";
   cin >> numero_3dig;

   // C�lculos
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
