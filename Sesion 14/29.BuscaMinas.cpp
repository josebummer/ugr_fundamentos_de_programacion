/*
Examen Septiembre 2015) Buscaminas es un juego muy conocido cuyo objetivo es
encontrar todas las minas existentes en un tablero rectangular, sin abrir ninguna. Si el
jugador abre una mina, pierde la partida.
Se pide definir la clase TableroBuscaMinas conteniendo lo siguiente:
a) Para representar el tablero se trabajará con una matriz de datos 50x30 en la que
todas las filas tienen el mismo número de columnas y los datos son de tipo bool.
Contendrá un valor true en caso de haber una mina en la casilla especificada
y false en caso contrario. Esta matriz será un dato miembro de la clase y al
principio, todos los valores estarán a false.
b) Un método para incluir una mina en una determinada casilla.
c) Un método que reciba las coordenadas (i; j) de una casilla y devuelva un valor
entero que indique el número de minas que rodean a la misma (será un número
entre 0 y 8). En caso de que la casilla contenga una mina, se devolverá el valor -1.
Hay que tener especial cuidado con las casillas que hay en los bordes de la matriz
ya que la casilla en la posición [0][0], por ejemplo, sólo tiene tres vecinos
rodeándola.
Incluya un pequeño programa de prueba para asignar algunas minas y obtener las
minas que hay alrededor de algunas casillas.
*/
#include <iostream>

using namespace std;

class TableroBuscaMinas{														//Creamos la clase para el busca minas
	private:	
		static const int FILAS=50,COLUMNAS=30;								//Creamos las constantes que necesitemos
		bool tablero[FILAS][COLUMNAS];										//Creamos la matriz que va a ser el tablero
	public:
		TableroBuscaMinas(){														//Creamos un constructor por defecto que inicializa el tablero vacio.
			for(int i=0;i<FILAS;i++)
				for(int j=0;j<COLUMNAS;j++)
					tablero[i][j]=false;
		}
		
		void MeterMina(int fila, int columna){								//Creamos el metodo que indicando una fila y columna nos mete una mina.
			
			if((fila<FILAS && fila>=0) && (columna<COLUMNAS && columna>=0))
				tablero[fila][columna]=true;
		
		}
		
		int AbrirPosicion(int fila, int columna){										//Finalmente creamos el metodo que abre una casilla y nos dice si 
																									// a encontrado una bomba o el numero de bombas que hay alrededor.
			if((fila<FILAS && fila>=0) && (columna<COLUMNAS && columna>=0)){				//Primero comprobamos que los datos introducidos son correctos
				int bombas=0;
			
				if(tablero[fila][columna]==true)									//Comprobamos si la posicion que nos indican contiene una bomba
					bombas=-1;															// si es así, muestra un -1 que es el codigo de bomba.
				else{
					for(int i=fila-1;i<=fila+1;i++)								//En caso contrario miramos en la fila anterior hasta la fila siguiente
						if(i>=0 && i<FILAS)											// de la fila que nos han indicado
							for(int j=columna-1;j<=columna+1;j++)				//Para ello ahora miramos en las columnas que esta justo antes y despues
								if(j>=0 && j<COLUMNAS)								// de la columna indicada. Con esto lo que miramos es cuadrado que envuelve
									if(tablero[i][j]==true)							//a la casilla.
										bombas++;										//Como se puede comprobar revisamos que si la fila o columna se sale del
					}																		//tablero se ahorre mirar. Finalmente si encuentra bomba suma 1 al contador.
			return bombas;											//Devolvemos las bombas.
			}	
		}
		
		void Soluciones(){
			int sol[FILAS][COLUMNAS];
			
			for(int i=0;i<FILAS;i++)
				for(int j=0;j<COLUMNAS;j++)
					sol[i][j]=AbrirPosicion(i,j);
			
			for(int i=0;i<FILAS;i++){
				cout << "\n";
				for(int j=0;j<COLUMNAS;j++)
					cout << sol[i][j] << " ";
			}
		}
};

int main(){

	TableroBuscaMinas minas;													//Creamos el objeto
	int fila,columna;																//Creamos las variables de entrada
	
	minas.MeterMina(12,18);												//Metemos algunas minas aleatorias de prueba
	minas.MeterMina(0,2);
	minas.MeterMina(14,20);
	minas.MeterMina(36,18);
	minas.MeterMina(36,19);
	
	do{
	cout << "Indica la fila en el tablero Busca Minas: ";						//Indicamos en que fila se encuentra la posicion que queremos abrir
	cin >> fila;
	}while(fila<0);
	
	do{
	cout << "Indica la columna en el tablero Busca Minas: ";			//Indicamos la columna de esa fila para abrir el elemento correspondiente
	cin >> columna;
	}while(columna<0);

	cout << "\n\nRecibira el numero de minas que tiene alrededor o -1 en caso de contener mina:\n" << minas.AbrirPosicion(fila,columna) << "\n\n";
	//Mostramos el resultado
	
	cout << "Vamos a mostrar las soluciones del buscaminas:\n";
	minas.Soluciones();
	cout << "\n\n";
	
system("pause");
}
