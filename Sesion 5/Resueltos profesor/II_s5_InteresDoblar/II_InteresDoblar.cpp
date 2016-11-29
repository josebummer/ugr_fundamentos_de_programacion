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
Sobre el mismo ejercicio del capital y los intereses, construid un programa para cal-
cular cuántos años han de pasar hasta llegar a doblar, como mínimo, el capital inicial.
Los datos que han de leerse desde teclado son el capital inicial y el interés anual.
*/

#include <iostream> 
using namespace std;  
   
int main(){    
   double interes, capital_inicial, capital_acumulado, cuantia_final_a_conseguir;
   int  anios_transcurridos;
   
   cout << "Introduzca capital inicial --> ";
   cin >> capital_inicial;
   cout << "\nIntroduzca interés (como un %) --> ";
   cin >> interes;   

   /*
	Algoritmo (Capital a un interés varios años hasta llegar a una cantidad):

		Inicializar el capital obtenido al capital inicial

		Ir recorriendo los años hasta llegar al capital objetivo
			Acumular el capital del año anterior con el interés aplicado
	*/

	/*
		Si ponemos:
			while (capital_acumulado < capital_inicial * 2)
		estamos evaluando la misma expresión capital_inicial * 2 cada vez que entremos al bucle.
		Como la expresión no varía, mejor guardamos el valor en una variable antes de entrar al bucle:
	*/

   capital_acumulado = capital_inicial;
   anios_transcurridos = 0;
   cuantia_final_a_conseguir = capital_inicial * 2;

   while (capital_acumulado < cuantia_final_a_conseguir){             
      capital_acumulado = capital_acumulado  +  capital_acumulado * interes / 100.0;
		anios_transcurridos++;  
      cout << "\nDinero obtenido en el año número " << anios_transcurridos << " = " << capital_acumulado;   
   }
   
   cout << "\n\nPara doblar la cantidad inicial han de pasar " << anios_transcurridos << " años";
   
   cout << "\n\n";
}
