/*
(Examen Febrero 2015) En este ejercicio no hay que construir ninguna función o
clase. Todo se programará en el main. Defina dos matrices de reales original
y suavizada de tamaño 50 x 30. Lea desde teclado los valores de la matriz
original, obligando a que sea simétrica. Para ello, lea el número de filas n y a
continuación introduzca los n x n datos de la matriz.
Construya la matriz suavizada acorde a las siguientes indicaciones:
a) La tabla resultante será simétrica.
b) Los valores de la diagonal principal de la tabla resultante serán iguales a los de
la tabla original.
c) Los valores del triángulo superior de la tabla resultante se calculan de la siguiente
manera: si (i; j) es una posición en el triángulo superior de la tabla resultante,
su valor es el valor medio de los valores que ocupan las posiciones de
las columnas j; j + 1; : : : ; n .. 1 en la fila i de la tabla original.
*/
#include <iostream>

using namespace std;

int main(){

	double original[50][30],suavizada[50][30],dato,suma=0;						//Creamos las variables necesarias
	int filas;

	cout << "Introduce el numero de filas (la matriz sera simetrica): ";			//Pedimos llas filas de la matriz que va a ser n x n
	cin >> filas;

	for(int i=0;i<filas;i++)
		for(int j=0;j<filas;j++){
		
			cout << "Introduce el numero (fila:" << i << " columna:" << j << "): ";			//Empezamos a meter todos los datos de la matriz
			cin >> dato;
			
			original[i][j]=dato;
		}
		
		cout << "La matriz original es:\n";							//Mostramos el resultado de la matriz que acabamos de crear
		
		for(int i=0;i<filas;i++){
			for(int j=0;j<filas;j++){
			
			cout << original[i][j] << " ";
			
			}
			cout << endl;
		}
		
		for(int i=0;i<filas;i++)															//Empezamos a leer la matriz por filas
			for(int j=0;j<filas;j++){														//Y aqui por columnas de cada fila
			
				if(i==j)														//Comparamos para saber si el elemento en el que nos encontramos pertenece a 
					suavizada[i][j]=original[i][j];					// la diagonal de la matriz y si lo es, escribe el mismo valor de la matriz original
				else if(i>j)											// Aqui comparamos para saber si el elemento se encuentra en el triangulo inferior 	
					suavizada[i][j]=0;								// de la matriz, y si se encuentra lo pone a 0
				else{
					for(int s=0;s<filas;s++)						//Por ultimo si se encuentra en el triangulo superior recorremos todos elementos de esa
						suma+=original[i][s];						// fila para poder calcular la media y escribirla en la matriz suavizada
					suavizada[i][j]=(suma-original[i][j])/(filas-1);
					suma=0;
				}	
			}
		
		cout << "\n\nLa matriz suavizada es:\n";											//Mostramos la matriz suavizada
		
		for(int i=0;i<filas;i++){
			for(int j=0;j<filas;j++){
			
			cout << suavizada[i][j] << " ";
			
			}
			cout << endl;
		}

		cout << endl;
		
system("pause");
}
