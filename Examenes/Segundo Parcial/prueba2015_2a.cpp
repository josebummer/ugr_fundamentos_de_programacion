/*
Se decide informatizar el acta de un partido de baloncesto para saber qué equipo es el
ganador de un partido. El acta contiene una serie de anotaciones formadas por una pareja
de números cada una, con el dorsal del jugador y el número de puntos conseguidos
teniendo en cuenta que la última anotación es un valor -1
1 2 4 1 4 1 2 3 6 2 3 2 5 2 5 1 1 3 -1
Implemente una clase para la gestión del acta del partido con los métodos necesarios para
manejar un vector en el que se almacenarán los datos:
a) Constructor de la clase
b) Método que devuelva el total de elementos utilizados
c) Método que devuelva la capacidad
d) Método para añadir un jugador con su puntuación
e) Método que dado un índice devuelva los valores asociados a al jugador y su puntuación.
f) Método que devuelva el dorsal del jugador que más puntuación ha hecho en un partido.
*/
#include <iostream>

using namespace std;

class Acta{
	private:
		static const int TAMANIO=50;
		int total_utilizados;
		int dorsales_privado[TAMANIO],puntos_privado[TAMANIO];
	public:
		Acta(){
			total_utilizados=0;
			for(int i=0;i<TAMANIO;i++)
				puntos_privado[i]=0;
		}
		
		int TotalUtilizados(){
			return total_utilizados;
		}
		
		int Capacidad(){
			return TAMANIO;
		}
		
		void Aniade(int dorsal, int puntos){
			bool existe=false;
			int posicion=0;
			
			if(dorsal>0 && puntos>0){
				for(int i=0;i<total_utilizados && !existe;i++)
					if(dorsales_privado[i]==dorsal){
						existe=true;
						posicion=i;
					}
				if(existe)
					puntos_privado[posicion]+=puntos;
				else
					if(total_utilizados<TAMANIO){
						dorsales_privado[total_utilizados]=dorsal;
						puntos_privado[total_utilizados]=puntos;
						total_utilizados++;
					}
			}
		}
		
		int DorsalJugador(int indice){
		
			if(indice>=0 && indice<total_utilizados)
				return dorsales_privado[indice];
		}
		
		int CuantosPuntos(int indice){
			
			if(indice>=0 && indice<total_utilizados)
				return puntos_privado[indice];
		}
		
		int DorsalMaxPuntos(){
			int posicion=0,puntos_max=0;
			
			for(int i=0;i<total_utilizados;i++)
				if(puntos_privado[i]>puntos_max){
					puntos_max=puntos_privado[i];
					posicion=i;
				}
		
		return dorsales_privado[posicion];
		}
};

int main(){

	Acta prueba;
	int indice,puntos,dorsal;
	
	cout << "Introduce el dorsal(-1 para salir): ";
	cin >> dorsal;
	
	while(dorsal!=-1){
		cout << "Introduce los puntos: ";
		cin >> puntos;
		
		prueba.Aniade(dorsal,puntos);
		
		cout << "Introduce el dorsal(-1 para salir): ";
		cin >> dorsal;
	}
	
	cout << "Introduce el indice para calcular unos puntos respecto a un jugador: ";
	cin >> indice;
	
	cout << "\n\nEl dorsal " << prueba.DorsalJugador(indice) << " tiene " << prueba.CuantosPuntos(indice) << " puntos.\n";
	
	cout << "\nEl dorsal " << prueba.DorsalMaxPuntos() << " es el dorsal con mas puntos reunidos.\n\n";
	
system("pause");
}
