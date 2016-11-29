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
Un número entero n se dice que es desgarrable (torn) si al dividirlo en dos partes
izda y dcha, el cuadrado de la suma de ambas partes es igual a n. Por ejemplo,
88209 es desgarrable ya que (88 + 209)^2 = 88209. Cread un programa que lea un
entero n e indique si es o no desgarrable
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	int izda, dcha, potencia, base;
	bool es_desgarrable;
	bool hay_digitos_izda;	
	
	// cout << "Introduzca un valor entero: ";
	// cin >> n;
	
	/*
	Idea:
	  Debemos ir dividiendo n por 1, 10, 100, etc
	  Lo podríamos hacer contando el número de dígitos del número
	  y luego entraríamos en un segundo bucle "for" tantas veces como dígitos tenga.
	  Pero también lo podemos hacer en un único bucle. Veámoslo:
	  
		n = 378
		
		/1  -> izda = 378
		%1  -> dcha = 0
		Probar la fórmula (el 0 y el 1 son desgarrables)
		
		/10 -> izda = 37
		%10 -> dcha = 8
		Probar la fórmula
		
		/100 -> izda = 3
		%100 -> dcha = 78
		Probar la fórmula
		
		/1000 -> izda = 0
		%1000 -> dcha = 378
		Termina
		
		Paramos cuando:
			- se cumpla la fórmula 
			- o cuando se hayan terminado las posibles divisiones.
				Para ello, o bien contamos al principio el número de dígitos
				y realizamos un bucle for con tantas iteraciones como indique num_digitos - 1
				o bien paramos cuando la parte izda sea cero (o dcha == n)
		
	Algoritmo (número desgarrable): 
			
		Ir partiendo el número n en dos partes (izda y dcha)
			Parar cuando la parte izda sea cero (o alternativamente dcha == n)
      	o cuando se satisfaga la condición de ser desgarrable 
   
   Como siempre queremos hacer al menos una vez la operación de dividir el número,
   usamos un bucle post-test do-while
	*/
	
	/*
	En esta versión imprimimos los desgarrables entre los 100 primeros números
	*/
	
   for (n = 0; n <= 100; n++){ 
   	potencia = 1;
	   izda = n;
	   dcha = 0;
	   
	   do{
         izda = n / potencia;
		   dcha = n % potencia;
		   base = izda + dcha; 	   			
			potencia = potencia * 10;	
			es_desgarrable = (base * base == n);
	  	   hay_digitos_izda = (izda != 0);	 
	   }while (!es_desgarrable && hay_digitos_izda);
	   
	   
	   /*
	   // Lo siguiente es opcional. Es otra implementación con while
	   
	   // versión con while:
	   
	   es_desgarrable = false;
	   hay_digitos_izda = true;
	   
	   while (!es_desgarrable && hay_digitos_izda){
         izda = n/potencia;
		   dcha = n%potencia;
		   base = izda + dcha;
	  	   es_desgarrable = (base * base == n);
	  	   hay_digitos_izda = (izda != 0);
		   potencia = potencia * 10;	      
	   }
	   */
	         
      /*
	   potencia = 1;
	   izda = n;
	   dcha = 0;
	   es_desgarrable = (n == 0);	  // <- Importante. No basta es_desgarrable = false; El 0 es desgarrable.
	   
	   while (!es_desgarrable && izda != 0){
         izda = n/potencia;
		   dcha = n%potencia;
		   base = izda + dcha;
	  	   es_desgarrable = (base * base == n);
		   potencia = potencia * 10;	      
	   }
	   */
	   
	   /*
	   // El siguiente algoritmo entraría con izda = 0, dcha = n 
	   // y también con izda = n, dcha = 0.
	   // La salida es correcta pero nos podíamos evitar una iteración.
	   
	   potencia = 1;
	   
	   do{
         izda = n/potencia;
		   dcha = n%potencia;
		   base = izda + dcha;
	  	   es_desgarrable = (base * base == n);
		   potencia = potencia * 10;
	   }while (!es_desgarrable && izda != 0);
	   */
	   
	   if (es_desgarrable)
	      cout << "\n" << n << " es desgarrable";
   }
   
   cout << "\n\n";
   system("pause");
}

