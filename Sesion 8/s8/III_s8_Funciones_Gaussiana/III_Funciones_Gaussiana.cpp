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
	Gaussiana
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415927; 

/*
	Aunque es este ejemplo la única función que necesita conocer PI es la función 
	EvaluaGaussiana
	hemos optado por ponerla como una constante global ya que es de esperar que 
	se añadan otras funciones que también necesiten conocer el valor de PI
*/

/*
	Jamás escribiremos una función en la que, dentro de ella,
	se hagan a la misma vez E/S y Cómputos.
	Al hacerlo, estamos obligando a calcular siempre la gaussiana
	leyendo los datos con cin, pero éstos podrían venir de cualquier otra forma.
*/
/*
double GaussianaSUSPENSO(){
	double abscisa, ordenada, esperanza, desviacion;

   // Jamás incluiremos las siguientes sentencias de entrada de datos en esta función que lo
   // que hace es realizar un cómputo (la evaluación de la función en un punto)
   
	cout << "\nIntroduzca el valor del parámetro 'esperanza' : ";
	cin >> esperanza;                                                     // :-(
	cout << "\nIntroduzca el valor del parámetro 'desviacion' : ";
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
	cout << "\n\nEl valor de la función gaussiana  es " << ordenada;

	cout << "\n\n";
   system("pause");
}
*/

//	Potencia de un número elevado a un entero.
double Potencia(double la_base, int el_exponente){
	// Observad que si exponente fuese cero, la variable potencia se quedaría con 1,
	// lo que es correcto ya que base elevado a 0 es siempre 1	

	double potencia;
	int exponente_positivo;

	if (la_base == 0 && el_exponente == 0)
		potencia = sqrt (-1.0);						   // Devuelve NaN (Indeterminación)
	else{
		exponente_positivo = abs(el_exponente);
		potencia = 1;								   	// ¿Y si empezase con potencia = base?

		for (int i = 1; i <= exponente_positivo; i++)
			potencia = potencia * la_base;
	}

	if (el_exponente < 0)
		potencia = 1/potencia;

	return potencia;
}

// Valor de la función Gaussiana (o "Normal") en un punto abscisa
double EvaluaGaussiana(double esperanza, double desviacion, double x){ 
	double ordenada;

	ordenada = exp(-(pow( (x - esperanza)/desviacion  ,  2)) / 2.0) /
		(desviacion * sqrt(2*PI));

	return ordenada;
}

/*
   Para calcular el área hasta x, la aproximación que vamos a usar
   necesita saber x y el valor de la gaussiana en ese punto, es decir,
   gaussiana(x) o tal y como la hemos llamado EvaluaGaussiana(x)
   
   ¿Calculamos ese valor en el main y lo pasamos como parámetro?
   
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
   En caso de hacerlo así, tendríamos dos problemas:
   
   1. Siempre tendríamos que realizar la misma acción antes de llamar
      a la función AreaHasta, por lo que eso es repetir código
   2. Si pasamos un valor incorrectamente calculado, la función
      AreaHasta no tiene forma de saberlo, por lo que devolvería basura
   
   Este tipo de diseños incorrectos se detectan fácilmente porque 
   hay una dependencia obvia entre los parámetros.
   Si pasamos un valor concreto del parámetro x, estamos obligados a pasar 
   otro valor concreto del otro parámetro valor_en_x,
   es decir, valor_en_x depende obviamente de x.
   
   Dicho de otra forma, los parámetros deberían poder variar libremente
   sin que unos afectasen a otros.
   
   A la función AreaHasta le pasamos los datos básicos para que ella
   realice las tareas que tiene que resolver -> el valor de x y los 
   parámetros que determinan la distribución gaussiana.
*/

// Área hasta x que queda por debajo de la Gaussiana
double AreaHastaGaussiana(double esperanza, double desviacion, double x){
	// Aproximación dada por Zelen & Severo (1964) 
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

	cout << "\nIntroduzca el valor del parámetro 'esperanza' : ";
	cin >> esperanza;
	cout << "\nIntroduzca el valor del parámetro 'desviacion' : ";
	cin >> desviacion;	
	cout << "\nIntroduzca el número de puntos que va a considerar: ";
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
