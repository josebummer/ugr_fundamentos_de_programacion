/*
Se quiere construir una clase para representar la tracci�n de una bicicleta, es decir, el
conjunto de estrella (engranaje delantero), cadena y pi��n (engranaje trasero). Supondremos
que la estrella tiene tres posiciones (numeradas de 1 a 3, siendo 1 la estrella
m�s peque�a) y el pi��n siete (numeradas de 1 a 7, siendo 1 el pi��n m�s grande).
La posici�n inicial de marcha es estrella = 1 y pi��n = 1.
La clase debe proporcionar m�todos para cambiar la estrella y el pi��n, sabiendo que
la estrella avanza o retrocede de 1 en 1 y los pi�ones cambian a saltos de uno o de
dos. Si ha llegado al l�mite superior (inferior) y se llama al m�todo para subir (bajar) la
estrella, la posici�n de �sta no variar�. Lo mismo se aplica al pi��n.
Cread un programa principal que lea desde un fichero externo los movimientos realizados
e imprima la situaci�n final de la estrella y pi��n. Los datos se leer�n en el
siguiente formato: tipo de plato (pi��n o estrella) seguido del tipo de movimiento. Para
codificar esta informaci�n se usar�n las siguientes letras: E indica una estrella, P un pi��n,
S para subir una posici�n, B para bajar una posici�n, T para subir dos posiciones
y C para bajar dos posiciones. T y C s�lo se aplicar�n sobre los pi�ones.
E S P S P S P S P C E S E B #
En este ejemplo los movimientos ser�an: la estrella sube, el pi��n sube en tres ocasiones
sucesivas, el pi��n baja dos posiciones de golpe, la estrella sube y vuelve a
bajar. Supondremos siempre que la posici�n inicial de la estrella es 1 y la del pi��n 1.
As� pues, la posici�n final ser� Estrella=1 y Pi��n=2.
Mejorad la clase para que no permita cambiar la marcha (con la estrella o el pi��n)
cuando haya riesgo de que se rompa la cadena. Este riesgo se produce cuando la
marcha a la que queremos cambiar es de la siguiente forma:
 Estrella igual a 1 y pi��n mayor o igual que 5
 Estrella igual a 2 y pi��n o bien igual a 1 o bien igual a 7
 Estrella igual a 3 y pi��n menor o igual que 3
 */

#include <iostream>

using namespace std;

class Bicicleta{
	private:
		int estrella, pinion;									//Creamos las variables privadas de la clase.
	public:
		Bicicleta(){												//Creamos un constructor por defecto
			estrella=1;
			pinion=1;
		}
		Bicicleta(int valorestrella, int valorpinion){		//Creamos otro constructor para dar valores iniciales al crear un objeto de la clase.
			estrella=valorestrella;
			pinion=valorpinion;
		}
		
		void SetEstrella(int valorestrella){					//Modulo para dar valor a la estrella de la bicicleta.
			estrella=valorestrella;
		}
		int GetEstrella(){											//Con esto podremos ver el valor de la estrella.
			return estrella;
		}
		
		void SetPinion(int valorpinion){							//Con este modulo damos valor al pi�on.
			pinion=valorpinion;
		}
		int GetPinion(){												//Con esto podremos ver el valor del pi�on
			return pinion;
		}
		
		void CambiarEstrella(char cambios){						//Con esto aplicaremos los cambios a la estrella controlando lo que el ejercicio pide
			switch (cambios){
				case 'S':
					if((estrella==1 && pinion==1) || (estrella==2 && pinion<=3))
						break;
					else if(estrella!=3)
						estrella++;
				break;
				case 'B':
					if((estrella==3 && pinion==7) || (estrella==2 && pinion>=5))
						break;
					else if(estrella!=1)
						estrella--;
				break;	
			}
		}
		
		void CambiarPinion(char cambios){						//Al igual que anteriormente pero esta vez para cambiar el pi�on
			switch (cambios){
				case 'S':
					if((estrella==1 && pinion==4) || (estrella==2 && pinion==6))
						break;
					else if(pinion!=7)
						pinion++;
				break;
				case 'B':
					if((estrella==2 && pinion==2) || (estrella==3 && pinion==4))
						break;
					else if(pinion!=1)
						pinion--;
				break;
				case 'T':
					if((estrella==1 && pinion>=3) || (estrella==2 && pinion==5))
						break;
					else if(pinion!=6 && pinion!=7)
						pinion+=2;
				break;
				case 'C':
					if((estrella==2 && pinion==3) || (estrella==3 && pinion<=5))
						break;
					else if(pinion!=1 && pinion!=2)
						pinion-=2;
				break;
			}
		}
		
		void CambiarMarcha(char opcion, char cambios){			//Llamaremos a esta funcion para cambiar la marcha y esta llamara a las que necesite para cambiar
																				//la estrella o el pi�on segun se indique.
			if(opcion=='E')
				CambiarEstrella(cambios);
			else
				CambiarPinion(cambios);
		}		
};

int main(){

	const char FIN='#';										//Creamos la variable de parada
	Bicicleta montania;										//Creamos el objeto de la clase
	char opcion, cambios;									//Creamos las variables de entrada
	
	do{
	cout << "Introduce si desea cambiar pi�on o estrella (# para salir): ";				//Pedimos los datos
	cin >> opcion;
	}while(opcion!='E' && opcion!='P' && opcion!=FIN);
	
	while(opcion!=FIN){
		do{
			cout << "Introduce el cambio a realizar en las marchas: ";
			cin >> cambios;
		}while(cambios!='S' && cambios!='B' && cambios!='T' && cambios!='C');
		
		montania.CambiarMarcha(opcion,cambios);										//Llamamos a cambiar marcha para que realice los cambios necesarios.
		
		do{
			cout << "Introduce si desea cambiar pi�on o estrella (# para salir): ";
			cin >> opcion;
		}while(opcion!='E' && opcion!='P' && opcion!=FIN);
	}
	
	cout << "\n\nEl resultado final de la bicicleta es:\n";							//Mostramos el resultado
	cout << "ESTRELLA: " << montania.GetEstrella() << "\n";
	cout << "PI�ON: " << montania.GetPinion() << "\n\n";
	
system("pause");
}
