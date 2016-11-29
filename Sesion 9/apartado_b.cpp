/*Métodos públicos
En vez de calcular la pendiente en el programa principal, vamos a ponerlo como
un método de la clase y así lo reutilizaremos todas las veces que necesitemos.
Añada un método para el cálculo de la pendiente y modificad el main para tener
en cuenta este cambio.
¿Añadimos pendiente como dato miembro de la recta? La respuesta es que
no ¿Por qué?
Añadir también los siguiente métodos:
 Obtener la ordenada (y) dado un valor de abscisa x, aplicando la fórmula:
(-C -xA) / B
 Obtener la abscisa (x) dado un valor de ordenada y, aplicando la fórmula:
(-C -yB) / A
En la función main leed un valor de abscisa e imprimir la ordenada según la recta
y leed un valor de ordenada e imprimid la abscisa que le corresponde. Hacedlo
sólo con la primera recta.
*/

#include <iostream>

using namespace std;

class Recta{																		//Creamos la clase como anteriormente.
	public:
		double A,B,C;
	
	double ObtenerOrdenada(double x){										//Creamos una funcion que nos calcula la ordenada de una recta
	
	return (-C -x*A)/B;
	
	}
	
	double ObtenerAbcisa(double y){											//Creamos una funcion que nos calcula la abcisa de una recta
	
	return (-C -y*B)/A;
	
	}
	
	double Pendiente(){															//Creamos esta funcion que nos va a mostrar la pendiente de la recta.
	
	return (-A)/B;				//No añadimos la variable pendiente porque podemos devolver el valor directamente.
	}
	
};

int main(){

static const int TAMANIO=6;											//Creamos las variables como anteriormente
	Recta uno,dos;
	double reales[TAMANIO],ordenada,abcisa;
	int i;

	for (i=0;i<6;i++){															//Pedimos los valores
	
		cout << "Introduce el " << i+1 << " numero: ";
		cin >> reales[i];
	
	}
	
	cout << "\nLOS TRES PRIMEROS VALORES VAN PARA LA PRIMERA RECTA, Y EL RESTO PARA LA SEGUNDA.\n";
	uno.A=reales[0];																														//Introducimos los valores en sus correspondientes
	uno.B=reales[1];																														// cajas
	uno.C=reales[2];	
	dos.A=reales[3];
	dos.B=reales[4];
	dos.C=reales[5];
	
	cout << "\nLa pendiente de la recta uno es: " << uno.Pendiente() << ".\nY la pendiente de la recta dos es: " << dos.Pendiente() << "\n\n"; 
			//Mostramos los valores de las pendientes como en el apartado a, pero esta vez llamando a la funcion que hemos creado en la clase
	
	cout << "Introduce la abcisa de la primera recta: ";															//Pedimos el valor de la abcisa para calcular la ordenada
	cin >> abcisa;
	
	cout << "\nLa ordenada que correspondiente a esa abcisa en la recta 1 es: " << uno.ObtenerOrdenada(abcisa) << "\n\n";			//Mostramos el valor de la ordenada
	
	cout << "Introduce la ordenada de la primera recta: ";														//Pedimos los datos de la ordenada
	cin >> ordenada;
	
	cout << "\nLa abcisa que correspondiente a esa ordenada en la recta 1 es: " << uno.ObtenerAbcisa(ordenada) << "\n\n";		//Mostramos el valor de la abcisa

system("pause");
}
