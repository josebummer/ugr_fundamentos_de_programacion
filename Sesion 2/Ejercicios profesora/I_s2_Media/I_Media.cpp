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
   Programa que calcula e imprime la media muestral y la desviaci�n 
			t�pica de tres valores de altura 
   Entradas: los tres valores (altura1, altura2 y altura3) 
   Salidas:  El valor de la media y de la desviaci�n t�pica calculada 
			 mediante las expresiones conocidas: 

			(N es el n�mero de muestras)
 
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
							 
	// C�lculos	
	
	// La siguiente expresi�n para implementar la desviaci�n 
	// repite mucho c�digo, lo que es propenso a errores:

	desviacion = sqrt( ( pow( altura1 - ((altura1 + altura2 + altura3) / 3) , 2) +    // :-((
							   pow( altura2 - ((altura1 + altura2 + altura3) / 3) , 2) + 
							   pow( altura3 - ((altura1 + altura2 + altura3) / 3) , 2)
							 )
							 / 3
						  );

	// Guardamos la expresi�n que se repite en una variable, que en este caso, es la media aritm�tica:

	media = (altura1 + altura2 + altura3) / 3;    
	desviacion =  sqrt(  (  pow(altura1 - media , 2) +  
						         pow(altura2 - media , 2) + 
						         pow(altura3 - media , 2)
						      ) 
								/ 3
					      );

	// La soluci�n anterior es correcta, pero a�n podemos mejorarla un poco.
	// Como ya se indic� en el ejercicio de la Gaussiana,
	// pow es una funci�n potente pero poco eficiente en tiempo de c�mputo.
	// Para elevar una expresi�n al cuadrado, podemos usar variables 
	// para almacenar los c�mputos de las distancias de cada valor a la media:

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

	// �C�mo se resolver�a este problema si tuvi�semos que trabajar con 50 variables en vez de 3?
	// No es operativo la definici�n de 50 variables en el c�digo.
	// En el tema de vectores veremos c�mo podemos definir y trabajar con un conjunto de variables
	// de una forma compacta.
   
	// Salida
	cout << "\nMedia aritm�tica: "  << media;
	cout << "\nDesviaci�n t�pica: " << desviacion;
	cout << "\n\n";

	system("pause");
}

