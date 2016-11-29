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
   Sobre la soluci�n del ejercicio 11 de esta relaci�n de problemas, se pide lo siguiente.
   Supondremos que s�lo pueden introducirse intereses enteros (1, 2, 3, etc). Se pide
   calcular el capital obtenido al t�rmino de cada a�o, pero realizando los c�lculos para
   todos los tipos de inter�s enteros menores o iguales que el introducido (en pasos de
   1). Por ejemplo, si el usuario introduce un inter�s de 5, y un n�mero de a�os igual a 3,
   hay que mostrar el capital ganado al t�rmino de cada uno de los tres a�os a un inter�s
   del 1 %; a continuaci�n, lo mismo para un inter�s del 2 %, y as� sucesivamente hasta
   llegar al 5 %. El programa debe mostrar una salida del tipo:

   C�lculos realizados al 1%:
   Dinero obtenido en el a�o n�mero 1 = 2020
   Dinero obtenido en el a�o n�mero 2 = 2040.2
   Dinero obtenido en el a�o n�mero 3 = 2060.6

   C�lculos realizados al 2%:
   Dinero obtenido en el a�o n�mero 1 = 2040
   Dinero obtenido en el a�o n�mero 2 = 2080.8
   Dinero obtenido en el a�o n�mero 3 = 2122.42
*/

#include <iostream>
using namespace std;

int main(){
	double interes, interes_actual, capital_inicial, capital_acumulado;
	int anios_transcurridos, numero_anios;

	cout << "Introduzca capital inicial --> ";
	cin >> capital_inicial;
	cout << "\nIntroduzca n�mero de a�os --> ";
	cin >> numero_anios;
	cout << "\nIntroduzca inter�s (como un %) --> ";
	cin >> interes; 

	/*
      Algoritmo:

         Recorrer los distintos valores de inter�s
            Reiniciar capital_acumulado al capital original
            Recorrer todos los a�os
               Acumular en capital_acumulado el total del a�o anterior 
               junto con los intereses.
   */

	for (interes_actual = 1 ; interes_actual <= interes ; interes_actual++){     
		cout << "\n\nResultados calculados para un inter�s del " << interes_actual << "% =\n";
		cout << "Capital inicial: " << capital_inicial;

		capital_acumulado = capital_inicial; 

		for (anios_transcurridos = 0 ; anios_transcurridos < numero_anios; anios_transcurridos++){     
			capital_acumulado = capital_acumulado + capital_acumulado * interes_actual / 100.0;
			cout << "\nCapital obtenido transcurrido el a�o n�mero " << anios_transcurridos + 1 << " = " << capital_acumulado;   
		}
	}

   /*
		Importante: Observad la asignaci�n
			capital_acumulado = capital_inicial; 
		Es necesario hacerlo, cada vez, antes de entrar al bucle for (anio ....
	*/
   
   cout << "\n\n";
   system("pause");
}
