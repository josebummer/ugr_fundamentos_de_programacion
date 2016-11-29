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
	Progresi�n geom�trica
*/

#include <iostream>
#include <cmath>
using namespace std;

//	Potencia de un real elevado a un entero cualquiera
double Potencia(double la_base, int el_exponente){
	/*
		Observad que si exponente fuese cero, la variable potencia se quedar�a con 1,
		lo que es correcto ya que base elevado a 0 es siempre 1	
		
		Y observad que este comentario va dentro de la funci�n ya que
		es una descripci�n de la implementaci�n
	*/
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



/////////////////////////////////////////////////////////////////////////////
// Suma  de los t�rminos de la progresi�n hasta el t�rmino k. Versi�n 1.

double SumaProgresionGeometrica (double primer_termino, double razon, double k){
	double suma_total, termino_n;
	int n;

	termino_n = primer_termino;
	suma_total = termino_n; 

	for (n=2; n <= k ; n++){
		termino_n = termino_n * razon;
		suma_total = suma_total +  termino_n;		
	}

	return suma_total;
}


/*
	Suma  de los t�rminos de la progresi�n hasta el t�rmino k. Versi�n 2. 
   Igual de v�lida que la versi�n 1. 
   Habr�a que comprobar emp�ricamente si es m�s r�pido realizar la llamada a la funci�n pow -versi�n 2-
   que realizar el bucle que va sumando los t�rminos -versi�n 1-.
*/

/*
double SumaProgresionGeometrica (double primer_termino, double razon, int k){
	return primer_termino * (pow(razon, k) - 1) / (razon - 1);
	// return primer_termino * (Potencia(razon, k) - 1) / (razon - 1);
}
*/


/////////////////////////////////////////////////////////////////////////////
// Producto de los t�rminos de la progresi�n hasta el t�rmino tope


/*
	La f�rmula del producto de los t�rminos de la progresi�n hasta el k-�simo t�rmino es:
		raiz_cuadrada_de ( (a1 * ak) elevado a k)
		
	�Definir�amos la siguiente funci�n?
	
	ProductoHastaProgresionGeometrica (double a1, double ak, int k){
	  return sqrt( pow(a1 * ak, k));
	}
		
	No ser�a una funci�n bien dise�ada ya que, para que realice su cometido,
	debe recibir el c�mputo correcto de ultimo_termino (que depende de los otros dos par�metros)
	�Y si le pasamos un valor incorrectamente calculado?
	La funci�n no funcionar�a correctamente.
	
	Estar�amos creando una dependencia entre los par�metros.
	Si bien primer_termino y k pueden variar "libremente", el otro par�metro ultimo_termino
	no puede variar. S�lo es correcto un valor espec�fico para cada combinaci�n
	de los otros dos par�metros.


	MUY IMPORTANTE:
	
		La funci�n debe ocuparse de realizar los c�mputos que ella necesite
		y no delegar la realizaci�n de dichos c�mputos en la llamada.
	
	
	La cabecera de la funci�n debe ser:
	
		double ProductoHastaProgresionGeometrica (double a1, double r, int k)
	
	///////////////////////////////////////////////////////////////////////////
	
	Ahora, �c�mo ser�a la implementaci�n?
	
      double ProductoHastaProgresionGeometricaRepiteCodigo 
         (double primer_termino, double razon, int k){
            
      	double ultimo_termino;
      
      	ultimo_termino = primer_termino * pow (razon, k-1);
      
      	return sqrt( pow(primer_termino * ultimo_termino , k));
      }
   
   La tarea de calcular el t�rmino k-�simo debe ir en una funci�n aparte
   ya que es seguro que la necesitaremos en otros sitios.
   Definimos por tanto la funci�n Termino y la llamamos d�nde sea necesario:
*/


double TerminoProgresionGeometrica(double primer_termino, double razon, int k){
	double termino;

	termino = primer_termino * pow(razon, k-1);

	return termino;
}

double ProductoHastaProgresionGeometrica (double primer_termino, double razon, int k){
	double ultimo_termino;

	ultimo_termino = TerminoProgresionGeometrica(primer_termino, razon, k);

	return sqrt( pow(primer_termino * ultimo_termino , k));
}

	




/////////////////////////////////////////////////////////////////////////////
// Suma  de los t�rminos de la progresi�n hasta infinito. 
double SumaHastaInfinitoProgresionGeometrica (double primer_termino, double razon){
	double suma;
	double denominador = 0.0;

	if (abs(razon) < 1)
		suma = primer_termino /(1 - razon);
	else
		suma = 1.0/denominador;    // <- Devuelve infinito

	return suma;
}



/////////////////////////////////////////////////////////////////////////////
int main(){
	double primer_termino, razon;   
	int tope;
	double suma, producto, suma_infinito;

	cout << "\nIntroduzca el primer t�rmino de la progresi�n ";
	cin >> primer_termino;
	cout << "\nIntroduzca la raz�n de la progresi�n ";
	cin >> razon;
	cout << "\nIntroduzca el tope hasta el que quiere sumar ";
	cin >> tope;

	suma =			 SumaProgresionGeometrica(primer_termino, razon, tope);
	producto =		 ProductoHastaProgresionGeometrica(primer_termino, razon, tope);
	suma_infinito = SumaHastaInfinitoProgresionGeometrica(primer_termino, razon);

	cout << "\nSuma hasta " << tope << " = " << suma;
	cout << "\nProducto hasta " << tope << " = " << producto;
	cout << "\nSuma hasta infinito: " << suma_infinito;

	cout << "\n\n";
	system("pause");
}
