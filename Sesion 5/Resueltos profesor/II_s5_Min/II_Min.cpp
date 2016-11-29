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
   Calcular el mínimo de varios valores leídos desde teclado, contando el número de introducidos
   Terminador de entrada de datos: 0
*/

#include <iostream> 
#include <string>  
using namespace std;    
    
int main(){     
   const int TERMINADOR = 0;
	double dato, min;
   int validos_introducidos;
   const string MENSAJE_ENTRADA = "\nIntroduzca un valor real: ";

	/*
	Algoritmo:
		min contendrá el mínimo hasta ese momento

		Leer datos hasta llegar al terminador 
			Actualizar el contador de valores introducidos
			Actualizar, en su caso, min
	*/
	/*
	while (dato != TERMINADOR){     
		validos_introducidos++;
      
		if (dato < min)           
			min = dato;
	}
	*/

	// ¿Qué valor le damos a min la primera vez?

	/*
	   Algo que NUNCA haremos será inicializar min a un literal:
      Por ejemplo, si suponemos que los datos leídos fuesen enteros, 
      plantemos inicializar min al máximo posible de todos ellos:
	*/
	/*
	cin >> dato;
	min = 32768;

	while (dato != TERMINADOR){     
		validos_introducidos++;
      
		if (dato < min)           
			min = dato;
		
		cin >> dato;
	}
	*/
	/*
	   Pero 32768 puede que sea el mínimo entero en un compilador 
	   que use 16 bits para su representación,
	   PERO en otro compilador que use 32 bits, el mínimo entero es mucho más pequeño.
	   Si todos los valores leídos desde teclado están por encima de la constante anterior,
	   el programa ya no funcionará correctamente, ya que dará como salida 32768
	*/

	/*
		Solución: Inicializamos min al PRIMER valor leído --> Lectura anticipada
		
		Es muy intuitivo: Leemos un primer valor y ese es el mínimo hasta ese momento.
		Si el primer valor fuese ya el terminador, podemos dejar sin asignar la variable min
		o asignarle el mismo valor terminador. 
		En cualquier caso, identificamos esta posibilidad asignando a validos_introducidos el valor 0
	*/

	/*
	Algoritmo:
      Nota: Usamos una variable min, que contendrá el mínimo hasta ese momento
      
		Leer un primer dato e inicializar min a dicho valor.

		Leer datos hasta llegar al terminador
			Actualizar el contador de valores introducidos
			Actualizar, en su caso, min
	*/

	cout << MENSAJE_ENTRADA;

   cin >> dato;               
   min = dato;                  
   validos_introducidos = 0;     
     
   while (dato != TERMINADOR){     
      validos_introducidos++;
      
      if (dato < min)           // La primera vez, dato es igual a min => false
         min = dato;
         
      cin >> dato;
   }
   
   if (validos_introducidos > 0){
      cout << "\nNúmero de valores introducidos = " << validos_introducidos;
      cout << "\nMínimo = " << min;
   }
   else
      cout << "\nNo se introdujo ningún valor";
      
   cout << "\n\n";
   system("pause");
}
