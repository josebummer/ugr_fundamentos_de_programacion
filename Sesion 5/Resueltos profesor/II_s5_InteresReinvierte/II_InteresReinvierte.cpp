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
   Calcular el total acumulado de un capital y los intereses correspondientes
   en varios a�os sucesivos.
   
Modifiquemos el ejercicio 6 del capital y los intereses de la primera relaci�n. Supon-
gamos ahora que se quiere reinvertir todo el dinero obtenido (el original C m�s los
intereses producidos) en otro plazo fijo a un a�o y as�, sucesivamente. Construid un
programa para que lea el capital, el inter�s y un n�mero de a�os N, y calcule e im-
prima todo el dinero obtenido durante cada uno de los N a�os, suponiendo que todo
lo ganado (incluido el capital original C) se reinvierte a plazo fijo durante el siguiente
a�o. El programa debe mostrar una salida del tipo:
Total en el a�o n�mero 1 = 240
Total en el a�o n�mero 2 = 288
Total en el a�o n�mero 3 = 345.6
*/

#include <iostream> 
using namespace std;  
   
int main(){    
   double interes, capital_inicial, capital_acumulado;
   int anios_transcurridos, numero_anios;
   
   cout << "Introduzca capital inicial --> ";
   cin >> capital_inicial;
   cout << "\nIntroduzca n�mero de a�os --> ";
   cin >> numero_anios;
   cout << "\nIntroduzca inter�s (como un %) --> ";
   cin >> interes;   
   
	/*
	Algoritmo (Capital a un inter�s varios a�os):

		Inicializar el capital obtenido al capital inicial

		Recorrer todos los a�os
			Acumular el capital del a�o anterior con el inter�s aplicado
	*/

   capital_acumulado = capital_inicial;
   anios_transcurridos  = 0; 
   
   while (anios_transcurridos < numero_anios){    
      capital_acumulado = capital_acumulado  +  capital_acumulado * interes / 100.0;   // valor nuevo = ciertas operaciones con valor antiguo 
      anios_transcurridos++;
		cout << "\nCapital obtenido transcurrido el a�o n�mero " << anios_transcurridos << " = " << capital_acumulado;   
   }

   cout << "\n\n";
}
