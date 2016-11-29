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
Declare un vector de caracteres de tama�o 100. Lea las componentes consideran-
do como terminador el car�cter # (�ste no forma parte de la secuencia) y que no se
introduzcan m�s de 100 caracteres. Las componentes le�das ocupar�n las primeras
posiciones contiguas del vector. El resto de las posiciones se quedar�n con el valor
indeterminado (basura) que el compilador le asignase al principio. Para conocer cu�n-
tas componentes se est�n utilizando, utilice una variable total_utilizados (que,
obviamente, deber� ser menor de 100 en todo momento)

Implemente algoritmos para realizar las siguientes tareas:

a) Comprobar si el vector es un pal�ndromo, es decir, que se lee igual de izquierda a
derecha que de derecha a izquierda. Por ejemplo, {'a','b','b','a'} ser�a
un pal�ndromo, pero {'a','c','b','a'} no lo ser�a. Si la secuencia tiene un
n�mero impar de componentes, la que ocupa la posici�n central es descartada,
por lo que {'a','b','j','b','a'} ser�a un pal�ndromo.

b) Invertir el vector. Si �ste conten�a, por ejemplo, los caracteres
{'m','u','n','d','o'} , despu�s de llamar al m�todo se quedar� con
{'o','d','n','u','m'} .

c) Contar el n�mero de may�sculas que contiene.
*/

#include <cctype>
#include <iostream>
using namespace std;


int main(){
   const int  TAMANIO    =  100;
   const char TERMINADOR = '#';
   char vector[TAMANIO];
   char caracter;
   int  total_introducidos;
   int  numero_mayusculas;
   
   bool es_palindromo;
   int  izda, dcha;

   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:
   
   total_introducidos = 0;
   caracter = cin.get();
   
   while (caracter != TERMINADOR && total_introducidos < TAMANIO){
      vector[total_introducidos] = caracter;
      total_introducidos++;
      caracter = cin.get();
   }

   
   //////////////////////////////////////////////////////////////////
   // N�mero de may�sculas:
   
   numero_mayusculas = 0;
   
   for (int i = 0; i < total_introducidos; i++)
      if (isupper(vector[i]))
         numero_mayusculas++;  
         
   cout << "\n\nHay un total de " << numero_mayusculas << " may�sculas";
            
   
   //////////////////////////////////////////////////////////////////
   // Pal�ndromo:

   es_palindromo = true;
   izda = 0;
   dcha = total_introducidos - 1;

   while (izda < dcha && es_palindromo){
      if (vector[izda] != vector[dcha])
         es_palindromo = false;
      else{
         izda++;
         dcha--;
      }
   }

	/*
   El siguiente bucle no funciona correctamente:
     
	for (int i = 0; i < total_introducidos; i++){
		es_palindromo = 
         vector_privado[i] == vector_privado[total_introducidos- 1 - i];


   1. No hay que llegar hasta total_utilizados sino hasta total_introducidos/2
   2. Al no salirse del bucle cuando ha encontrado dos componentes distintas,
      al final la variable es_palindromo se queda con el resultado de comparar
      las dos �ltimas posiciones centrales
   
   Lo siguiente s� ser�a correcto:
   
   tope = total_introducidos / 2;
   
   for (int i = 0; i < tope && es_palindromo; i++){
		 es_palindromo = 
         vector_privado[i] == vector_privado[total_introducidos - 1 - i];
   */
   
   if (es_palindromo)
      cout << "\nEs un pal�ndromo";
   else
      cout <<"\nNo es un pal�ndromo";
  
   
   //////////////////////////////////////////////////////////////////
   // Invierte:
   
   char copia;
   
	izda = 0;
	dcha = total_introducidos - 1;

	while (izda < dcha){
		copia = vector[izda];
      vector[izda]  = vector[dcha];
      vector[dcha]  = copia;
		izda++;
		dcha--;
	}
	
	/*
	// �Qu� har�a el siguiente c�digo?
	
	int su_simetrico;
	
   for (int i=0; i < total_utilizados; i++){
      su_simetrico = total_utilizados - i - 1;
      copia = vector[i];
      vector[i]  = vector[su_simetrico]; 
      vector[su_simetrico]  = copia;   
   }	
   
   // Dejar�a la cadena igual que estaba!!  
	*/
	
   cout << "\nComponentes del vector despu�s de invertirlo: < ";
   
   for (int i = 0; i < total_introducidos; i++)
      cout  << vector[i] << " ";
   
   cout << ">\n";      
}

