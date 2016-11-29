/*
Se quiere construir una clase para representar la tracción de una bicicleta, es decir, el
conjunto de estrella (engranaje delantero), cadena y piñón (engranaje trasero). Supondremos
que la estrella tiene tres posiciones (numeradas de 1 a 3, siendo 1 la estrella
más pequeña) y el piñón siete (numeradas de 1 a 7, siendo 1 el piñón más grande).
La posición inicial de marcha es estrella = 1 y piñón = 1.
La clase debe proporcionar métodos para cambiar la estrella y el piñón, sabiendo que
la estrella avanza o retrocede de 1 en 1 y los piñones cambian a saltos de uno o de
dos. Si ha llegado al límite superior (inferior) y se llama al método para subir (bajar) la
estrella, la posición de ésta no variará. Lo mismo se aplica al piñón.
Cread un programa principal que lea desde un fichero externo los movimientos realizados
e imprima la situación final de la estrella y piñón. Los datos se leerán en el
siguiente formato: tipo de plato (piñón o estrella) seguido del tipo de movimiento. Para
codificar esta información se usarán las siguientes letras: E indica una estrella, P un piñón,
S para subir una posición, B para bajar una posición, T para subir dos posiciones
y C para bajar dos posiciones. T y C sólo se aplicarán sobre los piñones.
E S P S P S P S P C E S E B #
En este ejemplo los movimientos serían: la estrella sube, el piñón sube en tres ocasiones
sucesivas, el piñón baja dos posiciones de golpe, la estrella sube y vuelve a
bajar. Supondremos siempre que la posición inicial de la estrella es 1 y la del piñón 1.
Así pues, la posición final será Estrella=1 y Piñón=2.
Mejorad la clase para que no permita cambiar la marcha (con la estrella o el piñón)
cuando haya riesgo de que se rompa la cadena. Este riesgo se produce cuando la
marcha a la que queremos cambiar es de la siguiente forma:
 Estrella igual a 1 y piñón mayor o igual que 5
 Estrella igual a 2 y piñón o bien igual a 1 o bien igual a 7
 Estrella igual a 3 y piñón menor o igual que 3
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
		
		void SetPinion(int valorpinion){							//Con este modulo damos valor al piñon.
			pinion=valorpinion;
		}
		int GetPinion(){												//Con esto podremos ver el valor del piñon
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
		
		void CambiarPinion(char cambios){						//Al igual que anteriormente pero esta vez para cambiar el piñon
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
																				//la estrella o el piñon segun se indique.
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
	cout << "Introduce si desea cambiar piñon o estrella (# para salir): ";				//Pedimos los datos
	cin >> opcion;
	}while(opcion!='E' && opcion!='P' && opcion!=FIN);
	
	while(opcion!=FIN){
		do{
			cout << "Introduce el cambio a realizar en las marchas: ";
			cin >> cambios;
		}while(cambios!='S' && cambios!='B' && cambios!='T' && cambios!='C');
		
		montania.CambiarMarcha(opcion,cambios);										//Llamamos a cambiar marcha para que realice los cambios necesarios.
		
		do{
			cout << "Introduce si desea cambiar piñon o estrella (# para salir): ";
			cin >> opcion;
		}while(opcion!='E' && opcion!='P' && opcion!=FIN);
	}
	
	cout << "\n\nEl resultado final de la bicicleta es:\n";							//Mostramos el resultado
	cout << "ESTRELLA: " << montania.GetEstrella() << "\n";
	cout << "PIÑON: " << montania.GetPinion() << "\n\n";
	
system("pause");
}
