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
   Pasar un car�cter de may�scula a min�scula, pero leyendo el car�cter
   con un filtro de entrada
   
Se pide leer un car�cter desde teclado, obligando al usuario a que sea una letra ma-
y�scula. Para ello, habr� que usar una estructura repetitiva do while , de forma que
si el usuario introduce un car�cter que no sea una letra may�scula, se le volver� a
pedir otro car�cter. Calculad la min�scula correspondiente e imprimidla en pantalla.
No pueden usarse las funciones tolower ni toupper de la biblioteca cctype 
*/

#include <iostream>
using namespace std;

int main(){
   const int DISTANCIA_MAY_MIN = 'a'-'A';             
   char letra_minuscula, letra_mayuscula;
   
   /*
   Algoritmo:
      Lee una letra, HASTA que sea una may�scula,

      es decir, hasta que (letra_mayuscula >= 'A') && (letra_mayuscula <= 'Z')
      sea true

   Equivale a:
         
      Lee una letra, MIENTRAS que NO sea una may�scula
      
      es decir, mientras que ! ((letra_mayuscula >= 'A') && (letra_mayuscula <= 'Z'))
      sea true
      es decir, mientras que !(letra_mayuscula >= 'A') || !(letra_mayuscula <= 'Z')
      sea true  (hemos aplicado las leyes de Morgan)
      es decir, mientras que (letra_mayuscula < 'A') || (letra_mayuscula > 'Z')
      sea true 
   
   */
	/*
   do{
      cout << "\nIntroduzca una letra may�scula  --> ";
      cin >> letra_mayuscula;
   }while ((letra_mayuscula < 'A') || (letra_mayuscula > 'Z'));
	*/

	/*
		En este tipo de bucles, en los que la condici�n de continuaci�n
		es del tipo "mientras NO sea v�lido", podemos usar un bool
		dentro del bucle que facilite la lectura del c�digo.
		En cualquier caso, tanto la soluci�n anterior como la siguiente
		son perfectamente v�lidas.
	*/

	
	bool es_mayuscula;

	do{
      cout << "\nIntroduzca una letra may�scula  --> ";
      cin >> letra_mayuscula;
		es_mayuscula = (letra_mayuscula >= 'A') && (letra_mayuscula <= 'Z');
   }while (! es_mayuscula);
   
   letra_minuscula = letra_mayuscula + DISTANCIA_MAY_MIN ;
   
   cout << "\nEl car�cter " << letra_mayuscula  
        << " pasado a min�scula es: " << letra_minuscula;
   
   cout << "\n\n";   
}
