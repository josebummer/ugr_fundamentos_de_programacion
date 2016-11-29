/*Cread un programa que ofrezca en pantalla la siguiente salida:
123456
234567
345678
456789
5678910
67891011
*/

#include <iostream>

using namespace std;

int main(){

	int f=1,c,d;								//Introducimos los datos
	
	while(f<=6){								//Creamos el bucle que va a controlar las filas.
		c=1;
		d=f;
		while(c<=6){							//Creamos el bucle anidado para controlar las columnas. 
			cout << d << " ";
			d++;
			c++;
		}
		cout << "\n";
		f++;
	}
cout << "\n";

system("pause");
}
