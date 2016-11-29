/*Se dice que un número es triangular si se puede poner como la suma de los primeros
m valores enteros, para algún valor de m. Por ejemplo, 6 es triangular ya que 6 = 1 +
2 + 3. Se pide construir un programa que obtenga todos los números triangulares que
hay menores que un entero tope introducido desde teclado.*/

#include <iostream>

using namespace std;

bool NumeroTriangular(int numero){						//Creamos la funcion que comprueba si un numero es triangular

	bool triangular=false;									//Creamos las variables
	int i=1,suma=0;
	
	for(i=1;triangular==false && i<=numero/2+1;i++)			//Creamos un bucle que nos dira si el numero introducido es triangular.
		triangular=(suma+=i)==numero;
	
return triangular;
}

int main(){

	int n,i;																		//Creamos las variables
	bool triangulares=false;
	
	do{																														//Pedimos los datos de las variables
	cout << "Introduce un numero tope para sacar los numeros menores triangulares: ";
	cin >> n;
	}while(n<1);
	
	cout << "Numeros triangulares anteriores al tope:\n";													
	for(i=1;i<=n;i++){																			//Con este bucle comprobamos si son triangulares todos los numeros anteriores al tope introducido
		triangulares=NumeroTriangular(i);
		if(triangulares)
			cout << i << " ";															//Mostramos el resultado si el numero cumple ser triangular.
	}

cout << "\n\n";
system("pause");
}
