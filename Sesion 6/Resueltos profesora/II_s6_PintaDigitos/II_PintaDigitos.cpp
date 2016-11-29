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
Programa que lee un entero y los muestra individualmente,
separ�ndolos por varios espacios.

Entradas: un entero
Salidas:  Los d�gitos del entero le�do.
*/
/*********************************************************************/


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int numero, numero_copia, num_digitos, potencia, digito;

   cout << "Introduce un entero cualquiera: ";
   cin >> numero;

   
   /*
	Idea:
	
      n = 375
      potencia = 100
      /potencia -> Imprime 3
      %potencia -> 75
      
      n = 75
      potencia = 10
      /potencia -> Imprime 7
      %potencia -> 5
      
      n = 5 
      potencia = 1
      /potencia  -> Imprime 5
      %potencia  -> 0
      
      n = 0
      potencia = 0
      TERMINA
   */
   
   /*
   Algoritmo (Pintar d�gitos de un entero):
      
      Contar el n�mero de d�gitos del n�mero -> num_dig      
      Inicializar potencia a 10^(num_dig - 1) 
      
      Repetir lo siguiente hasta llegar a una �nica cifra:         
         Imprimir la primera difra de n (n / potencia)
         Remplazar n por n % potencia
         Pasar a la anterior potencia de 10      
   */
   
   /*
   Detalles:
   
   �Cu�ndo paramos?
   
      �Cuando n==0? NO
      Si lo hacemos cuando n sea cero, el algoritmo parar�a antes
      de tiempo con un valor de n = 10000 por ejemplo, ya que al hacer
      n%1000, el resultado ser�a cero, pero todav�a no nos debemos salir.
      
      La soluci�n pasa por salirse cuando potencia sea 0
         
   En cada iteraci�n tenemos que dividir por 10^i
   �C�mo calculamos 10^i?
         
      �Hacemos lo siguiente EN CADA iteraci�n?
   		potencia = pow(10,i);
   		i--;
   	El uso de pow es costoso y podemos evitarlo.
   	
   	En vez de calcular la potencia, nos preguntamos si podemos aprovechar
   	los c�mputos que hemos realizados en una iteraci�n, para la siguiente.
   	
      Efectivamente:
   	   Dado un valor de potencia (10000 por ejemplo) basta hacer lo siguiente:
   		    potencia = potencia / 10;	  (de 10000 pasamos a 1000, de 1000 a 100 ...)
   
   Por �ltimo, debemos inicializar potencia a 10^(num_dig - 1)
      Podemos hacerlo con
   	  potencia = pow(10,num_digitos-1);
      Pero siguiendo el mismo consejo de antes, tambi�n podr�amos hacerlo en el mismo bucle
      que hemos usado para realizar el c�mputo del n�mero de d�gitos.
   */
   
   numero_copia = numero;
   num_digitos = 1;
   potencia = 1;
   
   while (numero_copia > 9){
      numero_copia = numero_copia / 10;
      num_digitos++;
      potencia = potencia * 10;
   }
   
   numero_copia = numero;
      
	while (potencia >= 1){
	   digito = numero_copia / potencia;
      cout << digito << " ";
      numero_copia = numero_copia % potencia;
      potencia = potencia / 10;
   }
   
   cout << "\n\n";
   system ("pause");
}
