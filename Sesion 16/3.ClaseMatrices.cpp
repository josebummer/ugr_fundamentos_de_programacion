/*
Recupere la solución del ejercicio 28 de la Relación de Problemas IV. En este ejercicio
se pedía construir una matriz suavizada promedio. Se quiere hacer lo mismo pero
sobre una clase MatrizCuadradaReales, por lo que debe implementar el siguiente
método:
MatrizCuadradaReales SuavizadaPromedio(){
En decsai se encuentra el código principal de la clase, así como de la clase
SecuenciaReales y el programa principal. Complete el código implementando el
método SuavizadaPromedio y la llamada desde el main.
*/

#include <iostream>

using namespace std;

class MatrizCuadradaReales{
	private:
		static const int FILAS=50,COLUMNAS=30,CAPACIDAD=30;
		double matriz_privada[FILAS][COLUMNAS];
		int utilizados;
	public:
		MatrizCuadradaReales(){
			utilizados=0;
		}
		
		MatrizCuadradaReales(int util){
			if(util>=0 && util<CAPACIDAD)
				utilizados=util;
		}
		
		void MostrarMatriz(){
			for(int i=0;i<utilizados;i++){
				for(int j=0;j<utilizados;j++)
					cout << Elemento(i,j) << " ";
				cout << endl;
			}		
		}
		
		void SetUtilizados(int filas){
			if(filas>0 && filas<CAPACIDAD)
				utilizados=filas;
		}
		
		int GetUtilizados(){
			return utilizados;
		}
		
		int GetCapacidad(){
			return CAPACIDAD;
		}
		
		double Elemento(int fila, int columna){
			if((fila>=0 && fila<utilizados) && (columna>=0 && columna<utilizados))
				return matriz_privada[fila][columna];
		}
		
		void Aniade(double elemento, int fila, int columna){
			matriz_privada[fila][columna]=elemento;
		}
		
		MatrizCuadradaReales SuavizadaPromedio(){
			MatrizCuadradaReales suavizada(utilizados);
			int suma=0;
			
			for(int i=0;i<utilizados;i++)
				for(int j=0;j<utilizados;j++){
					if(i==j)
						suavizada.Aniade(Elemento(i,j),i,j);
					else if(i>j)
						suavizada.Aniade(0,i,j);
					else{
						for(int s=0;s<utilizados;s++)
							suma+=Elemento(i,s);
						suavizada.Aniade((suma-Elemento(i,j))/(utilizados-1),i,j);
						suma=0;
					}	
				}
			return suavizada;
		}
};

int main(){
	
	MatrizCuadradaReales original,suavizada;
	double dato;
	int filas;
	
	do{
	cout << "Introduce el numero de filas (la matriz sera simetrica): ";
	cin >> filas;
	}while(filas<=0 && filas<original.GetCapacidad());
	original.SetUtilizados(filas);
	
	
	for(int i=0;i<original.GetUtilizados();i++)
		for(int j=0;j<original.GetUtilizados();j++){
		
			cout << "Introduce el numero (fila:" << i << " columna:" << j << "): ";
			cin >> dato;
			
			original.Aniade(dato,i,j);
		}
		
		cout << "La matriz original es:\n";
		
		original.MostrarMatriz();

		cout << "\nVamos a calcular la matriz suavizada.\n";
		suavizada=original.SuavizadaPromedio();
		
		suavizada.MostrarMatriz();
		
		cout << "\n\n";

system("pause");
}
