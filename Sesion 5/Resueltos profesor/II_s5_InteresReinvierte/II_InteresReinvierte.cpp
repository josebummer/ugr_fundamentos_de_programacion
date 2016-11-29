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
   Calcular el total acumulado de un capital y los intereses correspondientes
   en varios años sucesivos.
   
Modifiquemos el ejercicio 6 del capital y los intereses de la primera relación. Supon-
gamos ahora que se quiere reinvertir todo el dinero obtenido (el original C más los
intereses producidos) en otro plazo fijo a un año y así, sucesivamente. Construid un
programa para que lea el capital, el interés y un número de años N, y calcule e im-
prima todo el dinero obtenido durante cada uno de los N años, suponiendo que todo
lo ganado (incluido el capital original C) se reinvierte a plazo fijo durante el siguiente
año. El programa debe mostrar una salida del tipo:
Total en el año número 1 = 240
Total en el año número 2 = 288
Total en el año número 3 = 345.6
*/

#include <iostream> 
using namespace std;  
   
int main(){    
   double interes, capital_inicial, capital_acumulado;
   int anios_transcurridos, numero_anios;
   
   cout << "Introduzca capital inicial --> ";
   cin >> capital_inicial;
   cout << "\nIntroduzca número de años --> ";
   cin >> numero_anios;
   cout << "\nIntroduzca interés (como un %) --> ";
   cin >> interes;   
   
	/*
	Algoritmo (Capital a un interés varios años):

		Inicializar el capital obtenido al capital inicial

		Recorrer todos los años
			Acumular el capital del año anterior con el interés aplicado
	*/

   capital_acumulado = capital_inicial;
   anios_transcurridos  = 0; 
   
   while (anios_transcurridos < numero_anios){    
      capital_acumulado = capital_acumulado  +  capital_acumulado * interes / 100.0;   // valor nuevo = ciertas operaciones con valor antiguo 
      anios_transcurridos++;
		cout << "\nCapital obtenido transcurrido el año número " << anios_transcurridos << " = " << capital_acumulado;   
   }

   cout << "\n\n";
}
