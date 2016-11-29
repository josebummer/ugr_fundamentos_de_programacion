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
   Programa que calcula e imprime la media muestral y la desviación 
			típica de tres valores de altura 
   Entradas: los tres valores (altura1, altura2 y altura3) 
   Salidas:  El valor de la media y de la desviación típica calculada 
			 mediante las expresiones conocidas: 

			(N es el número de muestras)
 
			         1    N 
			media = --- suma (x_i)
			         N   i=1
			                ________________________________
			               /   1     N  (                 )
			desviacion =  / ( ---  suma ( (x_i - media)^2 )
			             V     N    i=1 (                 )
*/
/*********************************************************************/


#include <iostream>
#include <cmath>
#include <string>    //  <- Es necesario para poder imprimir un string con cout

using namespace std;

int main(){
	const string MENSAJE_ENTRADA_DATOS = "\nIntroduzca una altura en cm --> ";

	double altura1, altura2, altura3;	// Datos de entrada
	double media, desviacion;			   // Datos de salida (Resultados)

	// Entrada
	cout << MENSAJE_ENTRADA_DATOS;
	cin  >> altura1;
	cout << MENSAJE_ENTRADA_DATOS;
	cin  >> altura2;   
	cout << MENSAJE_ENTRADA_DATOS;
	cin  >> altura3;
							 
	// Cálculos	
	
	// La siguiente expresión para implementar la desviación 
	// repite mucho código, lo que es propenso a errores:

	desviacion = sqrt( ( pow( altura1 - ((altura1 + altura2 + altura3) / 3) , 2) +    // :-((
							   pow( altura2 - ((altura1 + altura2 + altura3) / 3) , 2) + 
							   pow( altura3 - ((altura1 + altura2 + altura3) / 3) , 2)
							 )
							 / 3
						  );

	// Guardamos la expresión que se repite en una variable, que en este caso, es la media aritmética:

	media = (altura1 + altura2 + altura3) / 3;    
	desviacion =  sqrt(  (  pow(altura1 - media , 2) +  
						         pow(altura2 - media , 2) + 
						         pow(altura3 - media , 2)
						      ) 
								/ 3
					      );

	// La solución anterior es correcta, pero aún podemos mejorarla un poco.
	// Como ya se indicó en el ejercicio de la Gaussiana,
	// pow es una función potente pero poco eficiente en tiempo de cómputo.
	// Para elevar una expresión al cuadrado, podemos usar variables 
	// para almacenar los cómputos de las distancias de cada valor a la media:

	double distancia_a_media_1, distancia_a_media_2, distancia_a_media_3;

	distancia_a_media_1 = altura1 - media;
	distancia_a_media_2 = altura2 - media;
	distancia_a_media_3 = altura3 - media;

	desviacion = sqrt(	(	distancia_a_media_1 * distancia_a_media_1 +
									distancia_a_media_2 * distancia_a_media_2 +
									distancia_a_media_3 * distancia_a_media_3 
								) 
								/ 3
					      );

	// ¿Cómo se resolvería este problema si tuviésemos que trabajar con 50 variables en vez de 3?
	// No es operativo la definición de 50 variables en el código.
	// En el tema de vectores veremos cómo podemos definir y trabajar con un conjunto de variables
	// de una forma compacta.
   
	// Salida
	cout << "\nMedia aritmética: "  << media;
	cout << "\nDesviación típica: " << desviacion;
	cout << "\n\n";

	system("pause");
}

