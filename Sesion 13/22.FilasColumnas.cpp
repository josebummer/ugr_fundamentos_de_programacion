/*
En este ejercicio, no hay que construir ninguna clase ni función. Es un ejercicio sobre
recorridos de una matriz declarada directamente en el main.
Leed desde teclado dos variables util_filas y util_columnas y leed los datos
de una matriz de enteros de tamaño util_filas x util_columnas. Sobre dicha
matriz, se pide lo siguiente:
a) Calcular la traspuesta de la matriz, almacenando el resultado en otra matriz.
d) Leer los datos de otra matriz y multiplicar ambas matrices (las dimensiones de la
segunda matriz han de ser compatibles con las de la primera para poder hacer la
multiplicación)
*/
#include <iostream>

using namespace std;

int main(){

	int util_filas,util_columnas,numero,filas_traspuesta,columnas_traspuesta;

	do{
	cout << "Introduce el numero de filas: ";
	cin >> util_filas;
	}while(util_filas<1);
	
	do{
	cout << "Introduce el numero de columnas: ";
	cin >> util_columnas;
	}while(util_columnas<1);
	int matriz[util_filas][util_columnas];
	
	for(int i=0;i<util_filas;i++)
		for(int j=0;j<util_columnas;j++){
			cout << "Introduce un numero (fila:" << i << " columna:" << j << "): ";
			cin >> numero;
			matriz[i][j]=numero;
		}
		
	cout << "\n\nLa matriz es: \n";
	
	for(int i=0;i<util_filas;i++){
		for(int j=0;j<util_columnas;j++)
			cout << matriz[i][j] << " ";
		cout << endl;
	}
	
	cout << "\n\nVamos a calcular ahora la matriz traspuesta:\n";
	filas_traspuesta=util_columnas;
	columnas_traspuesta=util_filas;
	int traspuesta[filas_traspuesta][columnas_traspuesta];
	
	for(int i=0;i<filas_traspuesta;i++){
		for(int j=0;j<columnas_traspuesta;j++)
			traspuesta[i][j]=matriz[j][i];
	}
	
	for(int i=0;i<filas_traspuesta;i++){
		for(int j=0;j<columnas_traspuesta;j++)
			cout << traspuesta[i][j] << " ";
		cout << endl;
	}
	
	cout << "\n";

system("pause");
}
