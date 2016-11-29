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
Sobre el mismo ejercicio del capital y los intereses, construid un programa para cal-
cular cu�ntos a�os han de pasar hasta llegar a doblar, como m�nimo, el capital inicial.
Los datos que han de leerse desde teclado son el capital inicial y el inter�s anual.
*/

#include <iostream> 
using namespace std;  
   
int main(){    
   double interes, capital_inicial, capital_acumulado, cuantia_final_a_conseguir;
   int  anios_transcurridos;
   
   cout << "Introduzca capital inicial --> ";
   cin >> capital_inicial;
   cout << "\nIntroduzca inter�s (como un %) --> ";
   cin >> interes;   

   /*
	Algoritmo (Capital a un inter�s varios a�os hasta llegar a una cantidad):

		Inicializar el capital obtenido al capital inicial

		Ir recorriendo los a�os hasta llegar al capital objetivo
			Acumular el capital del a�o anterior con el inter�s aplicado
	*/

	/*
		Si ponemos:
			while (capital_acumulado < capital_inicial * 2)
		estamos evaluando la misma expresi�n capital_inicial * 2 cada vez que entremos al bucle.
		Como la expresi�n no var�a, mejor guardamos el valor en una variable antes de entrar al bucle:
	*/

   capital_acumulado = capital_inicial;
   anios_transcurridos = 0;
   cuantia_final_a_conseguir = capital_inicial * 2;

   while (capital_acumulado < cuantia_final_a_conseguir){             
      capital_acumulado = capital_acumulado  +  capital_acumulado * interes / 100.0;
		anios_transcurridos++;  
      cout << "\nDinero obtenido en el a�o n�mero " << anios_transcurridos << " = " << capital_acumulado;   
   }
   
   cout << "\n\nPara doblar la cantidad inicial han de pasar " << anios_transcurridos << " a�os";
   
   cout << "\n\n";
}
