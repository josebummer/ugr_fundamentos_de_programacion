////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

// Combinatorio

/*
	Este ejercicio pone de manifiesto que antes de implementar una f�rmula,
	debemos intentar re-escribirla para optimizar el rendimiento en su implementaci�n
	en un lenguaje de programaci�n.
*/

#include <iostream> 
using namespace std;  
   
int main(){    
	int total_a_elegir, elegidos;
	long long factorial_total_a_elegir, factorial_elegidos, factorial_diferencia, combinatorio;

	cout << "\n\nIntroduzca total de elementos: ";
	cin >> total_a_elegir;
	cout << "\nIntroduzca cu�ntos va a elegir del total: ";
	cin >> elegidos;

	/*
		El combinatorio de n sobre m nos da las formas posibles de elegir m elementos
		de un total de n, sin repetici�n y sin importar el orden.
		El ejemplo t�pico es la loter�a primitiva.

		La siguiente soluci�n aplica la f�rmula del combinatorio directamente,
		es decir, calculando n! / (m! (n-m)!)
	*/

	/*
	factorial_total_a_elegir = 1;

	for (i = 2; i <= total_a_elegir; i++)
		factorial_total_a_elegir = factorial_total_a_elegir * i;

	factorial_elegidos = 1;

	for (i = 2; i <= elegidos; i++)
		factorial_elegidos = factorial_elegidos * i;

	factorial_diferencia = 1;

	for (i = 2; i <= total_a_elegir - elegidos; i++)
		factorial_diferencia = factorial_diferencia * i;

	combinatorio = factorial_total_a_elegir / (factorial_elegidos * factorial_diferencia);

	cout << "\nCombinaciones de " << total_a_elegir << " elementos ";
	cout << "tomados de " << elegidos << " en " << elegidos;
	cout << " = " << combinatorio;
	*/

	/*
		La anterior aproximaci�n puede producir desbordamiento incluso utilizando
		un tipo entero tan grande como long long.
		Comprobadlo con 49 y 6 (combinaciones posibles en la loter�a primitiva)
		http://www.wolframalpha.com/examples/Combinatorics.html

		49! -> Tiene 63 cifras
      49! = 608281864034267560872252163321295376887552831379210240000000000
		43! = 60415263063373835637355132068513997507264512000000000

		De hecho, el m�ximo factorial representable en un long long es el de 20.

		Con un double tampoco valdr�a ya que, aunque le cupiese y no hubiese desbordamiento,
		s�lo habr�a 16 cifras de precisi�n.

		Sin embargo, podemos optimizar la f�rmula y simplificar la expresi�n del c�lculo del combinatorio:
		n! / (m! (n-m)!)  =   n(n-1)...(n-m+1) / m!

		�Hemos pasado a tener �nicamente m multiplicaciones en el numerador y denominador!

		total_a_elegir (total_a_elegir-1) ... (total_a_elegir - elegidos + 1) / elegidos!

		Ahora s� podemos calcular, al menos, la probabilidad de ganar en la primitiva
		(que, por cierto, no son muchas = 1 / combinaciones de 49 tomados de 6 en 6) = 1 entre 13.983.816
	*/

	/*
		En la siguiente soluci�n calculamos el numerador recorriendo todos
		los factores que hay entre total_a_elegir y total_a_elegir - elegidos + 1
	*/
	/*
	long long numerador;

	factorial_elegidos = 1;
	numerador = 1;

	for (i = 2; i <= elegidos; i++)
		factorial_elegidos = factorial_elegidos * i;

	for (i = total_a_elegir - elegidos + 1 ; i <= total_a_elegir ; i++)
		numerador = numerador * i;
	*/

	/*
		En la siguiente soluci�n realizamos el recorrido de los factores
		del numerador y denominador dentro del mismo bucle.
	*/

	long long numerador, denominador;
	int diferencia;

	denominador = 1;
	numerador = 1;
	
	for (int i = 1 ; i <= elegidos ; i++){    
		denominador = denominador * i;
   	numerador = numerador * (total_a_elegir - elegidos + i);
	}	
	
	/* 
		Cuando el valor de elegidos est� pr�ximo a total_a_elegir (su doble lo supera)
		podemos realizar el mismo razonamiento y simplificar el c�mputo de los factoriales
	*/
	
	/*
	if (total_a_elegir > 2 * elegidos){
		for (int i = 1 ; i <= elegidos ; i++){    
			denominador = denominador * i;
	   	numerador = numerador * (total_a_elegir - elegidos + i);
		}
   }
   else{
   	diferencia = total_a_elegir - elegidos;
   	
   	for (int i = 1 ; i <= diferencia ; i++){       		
   		denominador = denominador * i;
      	numerador = numerador * (elegidos + i);
   	}
   }
   */
   
   /*
   	Y nos damos cuenta que se puede unificar el c�digo en el siguiente:
   */
   
   int tope, factor_numerador;
   
   if (total_a_elegir > 2 * elegidos){
   	tope = elegidos;
   	factor_numerador = total_a_elegir - elegidos;
	}
	else{
		tope = total_a_elegir - elegidos;
		factor_numerador = elegidos;
	}	

  	denominador = 1;
	numerador = 1;
	

   for (int i = 1 ; i <= tope ; i++){       		
   	denominador = denominador * i;
      numerador = numerador * (factor_numerador + i);
   }


	combinatorio = numerador/denominador;

	cout << "\nCombinaciones de " << total_a_elegir << " elementos ";
	cout << "tomados de " << elegidos << " en " << elegidos;
	cout << " = " << combinatorio;

   cout << "\n\n";
	system("pause");
}
