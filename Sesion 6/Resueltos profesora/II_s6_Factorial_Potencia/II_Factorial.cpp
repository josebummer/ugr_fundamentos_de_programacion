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
   C�mputo del factorial y potencia de un n�mero.
   Factorial:
      n! = 1 si n=0
      n! = n(n-1)(n-2)...1 si n>=1
   Potencia:
      x^n = x x ... x  (n veces)
*/

/*
	El m�ximo entero representable con un int de 32 bits con signo es 4 294 967 295
	Factorial de 12 = 479 001 600
	Factorial de 13 = 6 227 020 800
	=> Usando un int 32 bits con signo, el m�ximo n aceptable es 12.

	El m�ximo entero representable con un long long de 64 bits con signo es 9,223,372,036,854,775,807
	Factorial de 20 = 2 432 902 008 176 640 000 
	=> Usando un long long 64 bits con signo, el m�ximo n aceptable es 20.

	Consultad esta web para realizar c�mputos de factoriales con n�meros grandes:
	http://www.wolframalpha.com/examples/Combinatorics.html
	http://www.nitrxgen.net/factorialcalc.php
*/

#include <iostream> 
using namespace std;  
   
int main(){    
   long long factorial;
	int n;
	int multiplicando;

	cout << "\nIntroduzca un entero entre 0 y 20: ";
	cin >> n;

	/*
	Algoritmo (Factorial de n):

		Inicializar factorial a 1

		Recorrer los enteros entre 2 y n
			Acumular el producto de cada entero en factorial
	*/

	factorial = 1;

	for (multiplicando = 2; multiplicando <= n ; multiplicando++)    
		factorial = factorial * multiplicando;

	cout << "\nEl factorial de " << n << " es " << factorial;

	/////////////////////////////////////////////////////////////

	double base;
	int exponente, i;
	double potencia;

	cout << "\n\nIntroduzca la base: ";
	cin >> base;
	cout << "\nIntroduzca el exponente: ";
	cin >> exponente;

	/*
	Algoritmo (Potencia: base^exponente):

		Inicializar potencia a 1 (base ^ 0 = 1)

		Repetir tantas veces como diga el exponente
			Acumular el producto de base en potencia 
	*/

	potencia = 1.0;

	for (i = 1; i <= exponente; i++)    
		potencia = potencia * base;

	cout << "\n" << base << " elevado a " << exponente << " es igual a " << potencia;

	// Observad que si exponente fuese cero, la variable potencia se quedar�a con 1,
	// lo que es correcto ya que base elevado a 0 es siempre 1

   cout << "\n\n";
	system("pause");
}
