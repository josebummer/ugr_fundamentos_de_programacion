/*Cread un programa que ofrezca en pantalla la siguiente salida:
123456
23456
3456
456
56
6
*/

#include <iostream>

using namespace std;

int main(){

	int f=1,c;								//Creamos las variables
	
	while(f<=6){							//Creamos un blucle que controla las filas
		c=f;
		while(c<=6){						//Este segundo bucle anidado controla las columnas de cada fila.
			cout << c << " ";
			c++;
		}
		cout << "\n";
		f++;
	}
cout << "\n";
system("pause");
}
