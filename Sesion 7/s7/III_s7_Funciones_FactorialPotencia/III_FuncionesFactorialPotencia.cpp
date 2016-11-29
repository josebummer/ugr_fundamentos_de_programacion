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
   C�mputo del factorial y potencia de un n�mero, con funciones

   Factorial:
      n! = 1 si n=0
      n! = n(n-1)(n-2)...1 si n>=1
   Potencia:

      x^n = x x ... x  (n veces)
*/

#include <iostream>
#include <cmath>
using namespace std;


/*
	�Exigimos que se cumpla la precondici�n 0 <= n <= 20 en el par�metro n?
	�O lo comprobamos dentro de la funci�n?
	La respuesta depende de cada situaci�n/problema.
	A veces es recomendable comprobar la precondici�n y otras no.
	Los criterios m�s importantes a seguir son:
		- �Si se viola la precondici�n se pueden producir errores importantes?
			Una situaci�n l�mite ser�a que incluso el programa pudiese abortar.
			En este caso, las comprobaremos.
		- Si la respuesta a la anterior pregunta es que no.
			�Es una funci�n que va a ser llamada intensivamente dentro de bucles?
			�Es muy costoso el comprobar la precondici�n?
			En caso afirmativo, mejor no comprobamos la precondici�n.
	
	En el ejemplo que nos ocupa, no est� claro qu� decisi�n tomar.
	Tal vez, lo mejor ser�a optar por no comprobar la condici�n, ya que,
	en caso contrario, "solamente" se producir�a un desbordamiento aritm�tico.
*/	

///////////////////////////////////////////////////////////////////////////////////////


// Versi�n de factorial imponiendo la precondici�n.


// n! = n(n-1)(n-2)...1 si n>=1. 0! = 1
// Precondici�n: 0 <= n <= 20
long long Factorial(int n){
   long long factorial;
	int  multiplicando;

	factorial = 1;

	for (multiplicando = 2; multiplicando <= n ; multiplicando++)
		factorial = factorial * multiplicando;

	return factorial;
}


/*
///////////////////////////////////////////////////////////////////////////////////////

// Versi�n de factorial comprobando dentro la precondici�n.
//	Si nos pasan un valor fuera del rango, devolveremos un valor especial
//	que no sea el factorial de ning�n n�mero. Por ejemplo, 0 o -1.
// Es importante destacar que, en este caso, en el programa principal,
// tendr�amos que hacer la llamada en la siguiente forma:
// 
// if (Factorial(entero) == -1)
//		<desbordamiento> 
//		....
//
// Para no tener que comprobar SIEMPRE el valor devuelto por la funci�n (if funcion(..) == valor especial)
// lo mejor es usar EXCEPCIONES. (se ver� al final del cuatrimestre como Ampliaci�n)

// n! = n(n-1)(n-2)...1 si n>=1. 0! = 1

long long Factorial(int n){
   long long factorial;
	int  multiplicando;

	if (n < 0 || n > 20)
		factorial = -1;
	else{
		factorial = 1;

		for (multiplicando = 2; multiplicando <=n ; multiplicando++)
			factorial = factorial * multiplicando;
	}

	return factorial;
}
*/

///////////////////////////////////////////////////////////////////////////////////////

/*
   En este ejemplo queremos devolver el valor especial "Not a Number" aplicable
   a los reales (coma flotante), en el caso de que base y exponente sean ambos cero.
   Pero tambi�n ser�a perfectamente v�lido poner como precondici�n de Potencia que
   ambos par�metros no puedes ser nulos simult�neamente
*/

// Versi�n sin imponer la precondici�n de que ambos par�metros no sean nulos
//	Potencia de un real elevado a un entero cualquiera

double Potencia(double la_base, int el_exponente){
   
   //Observad que si exponente fuese cero, la variable potencia se quedar�a con 1,
   //lo que es correcto ya que base elevado a 0 es siempre 1	
   //
   //Y observad que este comentario va dentro de la funci�n ya que
   //es una descripci�n de la implementaci�n
   
	double provoca_indeterminacion = 0.0;
	double NaN = provoca_indeterminacion/provoca_indeterminacion;
	double potencia;
	int exponente_positivo;

	if (la_base == 0 && el_exponente == 0)
		potencia = NaN;				// Devuelve NaN (Indeterminaci�n)
	else{
		exponente_positivo = abs(el_exponente);
		potencia = 1;								   					

		for (int i = 1; i <= exponente_positivo; i++)
			potencia = potencia * la_base;
	}

	if (el_exponente < 0)
		potencia = 1/potencia;

	return potencia;
}

////////////////////////////////////////////////////////////////////////////////////////


// Versi�n imponiendo la precondici�n de que ambos par�metros no sean nulos

// Prec: la_base y e�_exponente no pueden ser cero simult�neamente
//	Potencia de un real elevado a un entero cualquiera

/*
double Potencia(double la_base, int el_exponente){
   
   //Observad que si exponente fuese cero, la variable potencia se quedar�a con 1,
   //lo que es correcto ya que base elevado a 0 es siempre 1	
   //
   //Y observad que este comentario va dentro de la funci�n ya que
   //es una descripci�n de la implementaci�n

	double potencia;
	int exponente_positivo;

	exponente_positivo = abs(el_exponente);
	potencia = 1;								   					

	for (int i = 1; i <= exponente_positivo; i++)
		potencia = potencia * la_base;


	if (el_exponente < 0)
		potencia = 1/potencia;

	return potencia;
}
*/

int main(){
   long long factorial;
	int n;

	cout << "\nIntroduzca un entero positivo: ";
	cin >> n;

	/////////////////////////////////////////////////////////////
	// Versi�n "no segura" de la funci�n factorial. 
	// Si no se cumple la precondici�n, se producir� un desbordamiento.
	// Esta soluci�n es completamente v�lida. 

	factorial = Factorial(n);

	cout << "\nEl factorial de " << n << " es " << factorial;

	/////////////////////////////////////////////////////////////
	// Versi�n "segura" de la funci�n factorial
	// Dentro de la propia funci�n se comprueba la validez de los par�metros
	// Como devolvemos un c�digo de error, la llamada implica usar un if
	// Esta soluci�n tambi�n es completamente v�lida. 
	// En cualquier caso, es mejor usar EXCEPCIONES que devolver c�digos de error.
	// Esto se ver� como ampliaci�n en el �ltimo tema. 
	
	factorial = Factorial(n);
	
	if (factorial == -1)
		cout << "\nEl factorial de " << n << " es " << factorial;
	else
		cout << "\nNo se puede calcular el factorial de " << n;
	
	/////////////////////////////////////////////////////////////
	
	double base;
	int exponente;
	double potencia;

	cout << "\n\nIntroduzca la base: ";
	cin >> base;
	cout << "\nIntroduzca el exponente: ";
	cin >> exponente;

	potencia = Potencia(base, exponente);

	cout << "\n" << base << " elevado a " << exponente << " es igual a " << potencia;
   cout << "\n\n";
	system("pause");
}
