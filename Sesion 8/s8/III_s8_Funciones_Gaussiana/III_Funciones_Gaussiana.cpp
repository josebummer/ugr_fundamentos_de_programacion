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
	Gaussiana
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415927; 

/*
	Aunque es este ejemplo la �nica funci�n que necesita conocer PI es la funci�n 
	EvaluaGaussiana
	hemos optado por ponerla como una constante global ya que es de esperar que 
	se a�adan otras funciones que tambi�n necesiten conocer el valor de PI
*/

/*
	Jam�s escribiremos una funci�n en la que, dentro de ella,
	se hagan a la misma vez E/S y C�mputos.
	Al hacerlo, estamos obligando a calcular siempre la gaussiana
	leyendo los datos con cin, pero �stos podr�an venir de cualquier otra forma.
*/
/*
double GaussianaSUSPENSO(){
	double abscisa, ordenada, esperanza, desviacion;

   // Jam�s incluiremos las siguientes sentencias de entrada de datos en esta funci�n que lo
   // que hace es realizar un c�mputo (la evaluaci�n de la funci�n en un punto)
   
	cout << "\nIntroduzca el valor del par�metro 'esperanza' : ";
	cin >> esperanza;                                                     // :-(
	cout << "\nIntroduzca el valor del par�metro 'desviacion' : ";
	cin >> desviacion;                                                    // :-(
	cout << "\nIntroduzca el valor de la abscisa: ";
	cin >> abscisa;                                                       // :-(
   
	ordenada = exp(-(pow( (abscisa - esperanza)/desviacion  ,  2)) / 2) /
	          (desviacion * sqrt(2*PI));
	
	return ordenada;
}

int main(){
	double ordenada;

	ordenada = Gaussiana();   // :-(
	cout << "\n\nEl valor de la funci�n gaussiana  es " << ordenada;

	cout << "\n\n";
   system("pause");
}
*/

//	Potencia de un n�mero elevado a un entero.
double Potencia(double la_base, int el_exponente){
	// Observad que si exponente fuese cero, la variable potencia se quedar�a con 1,
	// lo que es correcto ya que base elevado a 0 es siempre 1	

	double potencia;
	int exponente_positivo;

	if (la_base == 0 && el_exponente == 0)
		potencia = sqrt (-1.0);						   // Devuelve NaN (Indeterminaci�n)
	else{
		exponente_positivo = abs(el_exponente);
		potencia = 1;								   	// �Y si empezase con potencia = base?

		for (int i = 1; i <= exponente_positivo; i++)
			potencia = potencia * la_base;
	}

	if (el_exponente < 0)
		potencia = 1/potencia;

	return potencia;
}

// Valor de la funci�n Gaussiana (o "Normal") en un punto abscisa
double EvaluaGaussiana(double esperanza, double desviacion, double x){ 
	double ordenada;

	ordenada = exp(-(pow( (x - esperanza)/desviacion  ,  2)) / 2.0) /
		(desviacion * sqrt(2*PI));

	return ordenada;
}

/*
   Para calcular el �rea hasta x, la aproximaci�n que vamos a usar
   necesita saber x y el valor de la gaussiana en ese punto, es decir,
   gaussiana(x) o tal y como la hemos llamado EvaluaGaussiana(x)
   
   �Calculamos ese valor en el main y lo pasamos como par�metro?
   
   double AreaHastaGaussianaIncorrecto(double x, double valor_en_x){
   	const double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782, 
   		          b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
   	double area_hasta;
   	double t;
   
   	t = 1 / (1 + b0 * x);
   	area_hasta = 1 -  valor_en_x 
   							* 
   							(b1*t + b2*Potencia(t,1) + b3*Potencia(t,3) + 
                         b4*Potencia(t,4) + b5*Potencia(t,5));
   
   	return area_hasta;
   }

   La respuesta es que no.
   En caso de hacerlo as�, tendr�amos dos problemas:
   
   1. Siempre tendr�amos que realizar la misma acci�n antes de llamar
      a la funci�n AreaHasta, por lo que eso es repetir c�digo
   2. Si pasamos un valor incorrectamente calculado, la funci�n
      AreaHasta no tiene forma de saberlo, por lo que devolver�a basura
   
   Este tipo de dise�os incorrectos se detectan f�cilmente porque 
   hay una dependencia obvia entre los par�metros.
   Si pasamos un valor concreto del par�metro x, estamos obligados a pasar 
   otro valor concreto del otro par�metro valor_en_x,
   es decir, valor_en_x depende obviamente de x.
   
   Dicho de otra forma, los par�metros deber�an poder variar libremente
   sin que unos afectasen a otros.
   
   A la funci�n AreaHasta le pasamos los datos b�sicos para que ella
   realice las tareas que tiene que resolver -> el valor de x y los 
   par�metros que determinan la distribuci�n gaussiana.
*/

// �rea hasta x que queda por debajo de la Gaussiana
double AreaHastaGaussiana(double esperanza, double desviacion, double x){
	// Aproximaci�n dada por Zelen & Severo (1964) 
	// -ver Wikipedia (Normal distribution) para otras aproximaciones-		
	const double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782, 
		          b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
	double area_hasta;
	double t;

	t = 1 / (1 + b0 * x);
	area_hasta = 1 -  EvaluaGaussiana(esperanza, desviacion, x) 
							* 
							(b1*t + b2*Potencia(t,1) + b3*Potencia(t,3) + 
                      b4*Potencia(t,4) + b5*Potencia(t,5));

	return area_hasta;
}


int main(){
	double abscisa, ordenada;
	double esperanza, desviacion;
	double area;
	int numero_puntos;

	cout << "\nIntroduzca el valor del par�metro 'esperanza' : ";
	cin >> esperanza;
	cout << "\nIntroduzca el valor del par�metro 'desviacion' : ";
	cin >> desviacion;	
	cout << "\nIntroduzca el n�mero de puntos que va a considerar: ";
	cin >> numero_puntos;
	cout << "\nIntroduzca los " << numero_puntos << " valores de la abscisa: ";
		
	for (int i=0; i<numero_puntos; i++){
	   cin >> abscisa;	
      ordenada = EvaluaGaussiana(esperanza, desviacion, abscisa);
      area	= AreaHastaGaussiana(esperanza, desviacion, abscisa);
      cout << "\ngaussiana(" << abscisa << ")= " << ordenada;
      cout << "\nCDF(" << abscisa << ")= " << area;
      cout << "\n";
   }
}
