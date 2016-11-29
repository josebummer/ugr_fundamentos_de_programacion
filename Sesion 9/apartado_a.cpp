/*Definición de la clase y creación de objetos
Defina la clase Recta. En este apartado utilice únicamente datos miembro públicos.
Cree un programa principal que haga lo siguiente:
 Defina dos objetos de la clase Recta.
 Lea seis reales desde teclado.
 Le asigne los tres primeros a los coeficientes de una recta y los otros tres a
la segunda recta.
 Calcule e imprima la pendiente de cada recta aplicando la fórmula:
pendiente = - A / B
*/

#include <iostream>

using namespace std;

class Recta{				//Creamos la clase recta que solo va a contener las 3 variables de la recta de tipo public
	public:
		
		double A,B,C;
};

int main(){

	static const int TAMANIO=6;									//Creamos una variable costante que en mi caso para utilizar un vector la necesito.
	Recta uno,dos;														//Creamos los dos objetos de la clase
	double reales[TAMANIO],pendienteuno,pendientedos;		//Creamos el vector y las demas variables que vamos a utilizar
	int i;

	for (i=0;i<6;i++){												//Creamos un bucle que nos va a pedir los 6 valores de A, B y C
	
		cout << "Introduce el " << i+1 << " numero: ";
		cin >> reales[i];
	
	}
	
	uno.A=reales[0];													//Asignamos los valores a sus correspondientes cajas
	uno.B=reales[1];
	uno.C=reales[2];	
	dos.A=reales[3];
	dos.B=reales[4];
	dos.C=reales[5];
	
	pendienteuno=-uno.A/uno.B;										//Calculamos la pendiente ejecutando la formula que nos dice el ejercicio
	pendientedos=-dos.A/dos.B;
	
	cout << "\nLa pendiente de la recta uno es: " << pendienteuno << ".\nY la pendiente de la recta dos es: " << pendientedos << "\n\n";	//Mostramos el resultado

system("pause");
}
