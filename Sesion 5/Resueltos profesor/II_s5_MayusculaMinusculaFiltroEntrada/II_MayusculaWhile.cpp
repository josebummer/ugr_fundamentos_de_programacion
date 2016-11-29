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
   Pasar un carácter de mayúscula a minúscula, pero leyendo el carácter
   con un filtro de entrada
   
Se pide leer un carácter desde teclado, obligando al usuario a que sea una letra ma-
yúscula. Para ello, habrá que usar una estructura repetitiva do while , de forma que
si el usuario introduce un carácter que no sea una letra mayúscula, se le volverá a
pedir otro carácter. Calculad la minúscula correspondiente e imprimidla en pantalla.
No pueden usarse las funciones tolower ni toupper de la biblioteca cctype 
*/

#include <iostream>
using namespace std;

int main(){
   const int DISTANCIA_MAY_MIN = 'a'-'A';             
   char letra_minuscula, letra_mayuscula;
   
   /*
   Algoritmo:
      Lee una letra, HASTA que sea una mayúscula,

      es decir, hasta que (letra_mayuscula >= 'A') && (letra_mayuscula <= 'Z')
      sea true

   Equivale a:
         
      Lee una letra, MIENTRAS que NO sea una mayúscula
      
      es decir, mientras que ! ((letra_mayuscula >= 'A') && (letra_mayuscula <= 'Z'))
      sea true
      es decir, mientras que !(letra_mayuscula >= 'A') || !(letra_mayuscula <= 'Z')
      sea true  (hemos aplicado las leyes de Morgan)
      es decir, mientras que (letra_mayuscula < 'A') || (letra_mayuscula > 'Z')
      sea true 
   
   */
	/*
   do{
      cout << "\nIntroduzca una letra mayúscula  --> ";
      cin >> letra_mayuscula;
   }while ((letra_mayuscula < 'A') || (letra_mayuscula > 'Z'));
	*/

	/*
		En este tipo de bucles, en los que la condición de continuación
		es del tipo "mientras NO sea válido", podemos usar un bool
		dentro del bucle que facilite la lectura del código.
		En cualquier caso, tanto la solución anterior como la siguiente
		son perfectamente válidas.
	*/

	
	bool es_mayuscula;

	do{
      cout << "\nIntroduzca una letra mayúscula  --> ";
      cin >> letra_mayuscula;
		es_mayuscula = (letra_mayuscula >= 'A') && (letra_mayuscula <= 'Z');
   }while (! es_mayuscula);
   
   letra_minuscula = letra_mayuscula + DISTANCIA_MAY_MIN ;
   
   cout << "\nEl carácter " << letra_mayuscula  
        << " pasado a minúscula es: " << letra_minuscula;
   
   cout << "\n\n";   
}
