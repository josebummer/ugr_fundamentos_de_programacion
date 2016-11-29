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
   Programa que pide los valores de dos datos y los intercambia.
   Entradas: los valores de los dos datos: edad_Pedro y edad_Juan
   Auxiliares: una variable para realizar el intercambio, que act�a 
			como almac�n temporal. 
   Salidas: los datos de entrada (sus valores deben ser diferentes)
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int edad_Pedro, edad_Juan;  // Datos de entrada/salida
	int copia;			  	       // Dato auxiliar

	// Entrada de datos

	cout << "\nIntroduzca la edad de Pedro: ";
	cin >> edad_Pedro;
	cout << "Introduzca la edad de Juan: ";
	cin >> edad_Juan;

	// C�mputos --> intercambio de valores empleando una variable auxiliar

	copia = edad_Juan;
	edad_Juan  = edad_Pedro;
	edad_Pedro = copia;

   /*
      Regla nemot�cnica:

      copia = uno      
      uno   = otro
      otro  = copia

      \/
      /\/
       /\
   */

	// Salida

	cout << "\nNueva edad de Pedro: " << edad_Pedro;
	cout << "\nNueva edad de Juan: " << edad_Juan;
	
	cout << "\n\n";	

	system("pause");
}