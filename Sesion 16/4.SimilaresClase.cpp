/*
Examen Febrero 2009) Recupere la solución del ejercicio 30 de la Relación de Problemas
IV (palabras similares).
Sobre la clase SecuenciaCaracteres, definid un método que compruebe si la secuencia
es similar a otra.
*/
#include <iostream>
#include <cctype>

using namespace std;

class SecuenciaCaracteres {											//Cojemos la clase de decsai
	private:
		static const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;
	public:
		SecuenciaCaracteres()
			:total_utilizados(0){
		}
		int TotalUtilizados(){
			return total_utilizados;
		}
		int Capacidad(){
			return TAMANIO;
		}
		void Aniade(char nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
		char Elemento(int indice){
			return vector_privado[indice];
		}
		void Elimina (int posicion){
			if (posicion >= 0 && posicion < total_utilizados){
				int tope = total_utilizados-1;
				for (int i = posicion ; i < tope ; i++)
					vector_privado[i] = vector_privado[i+1];
					total_utilizados--;
			}
		}
		string ToString(){
			string cadena;
			for (int i=0; i<total_utilizados; i++)
				cadena = cadena + vector_privado[i];
			return cadena;
		}
		bool EsPalindromo(){										//Nos devuelve true o false dependiendo si el vector es palindromo o no

			bool palindromo=true;
			int i,aux_utilizados=total_utilizados;
	
			for(i=0;i<aux_utilizados && palindromo;i++,aux_utilizados--)
				if(vector_privado[i]!=vector_privado[aux_utilizados-1])
					palindromo=false; 

		return palindromo;
		}
		void Invierte(){											//Invierte el vector

			char aux;
			int aux_utilizados=total_utilizados;
			int i;
	
			for(i=0;i<aux_utilizados;i++,aux_utilizados--){
				aux=vector_privado[i];
				vector_privado[i]=vector_privado[aux_utilizados-1];
				vector_privado[aux_utilizados-1]=aux;
			}
		}
		int NumeroMayusculas(){									//Nos devuelve el numero de mayusculas que tiene el vector

			int mayusculas=0,i;
	
			for(i=0;i<total_utilizados;i++){
				if(vector_privado[i]>='A' && vector_privado[i]<='Z')
					mayusculas++;
			}
		return mayusculas;
		}
		
		void EliminaMayusculas(){						//Creamos el metodo elimina mayusculas
			
			int posicion_lectura=0,posicion_escritura=0,tope=total_utilizados;
			
			for(int i=posicion_lectura;i<tope;i++)								//Recorremos el vector
				if(islower(vector_privado[i])){									//Comprobamos si la letra en la que nos encontramos es minuscula
					vector_privado[posicion_escritura]=vector_privado[i];	// Si es minuscula la escribimos en la posicion de escritua y pasamos a la siguiente
					posicion_escritura++;
				}
				else																		//Si la letra es mayusucla no la escribimos para borrarla y quitamos 1 a utilizados
					total_utilizados--;
		}
		
		bool Similar(SecuenciaCaracteres otro){
			bool similares=true,encontrada;
			
			if(Elemento(0)==otro.Elemento(0) && Elemento(total_utilizados-1)==otro.Elemento(otro.TotalUtilizados()-1) && total_utilizados==otro.TotalUtilizados()){
				int tope=total_utilizados-1;
		// Comrpobamos en el if que la primera letra y la ultima son iguales y que el tamaño de los dos vectores es el mismo.
				for(int i=1;i<tope && similares;i++){				//Recorremos el vector cojiendo cada letra
					encontrada=false;
					for(int j=1;j<tope && !encontrada;j++)					
						if(Elemento(i)==otro.Elemento(j))					//Si la encuentra, salimos y pasamos a la siguiente letra
							encontrada=true;
				if(!encontrada)														//Si termina y no la ha encontrado ya tenemos que no son similares.
					similares=false;
		}
	}
	else
		similares=false;
			
		return similares;
		}
};

int main(){

	SecuenciaCaracteres vector,vector2;
	
	vector.Aniade('c');												//Metemos en cada vector 2 palabras cuales quiera para comprobaciones
	vector.Aniade('o');
	vector.Aniade('c');
	vector.Aniade('o');
	vector.Aniade('d');
	vector.Aniade('r');
	vector.Aniade('i');
	vector.Aniade('l');
	vector.Aniade('o');
	
	vector2.Aniade('c');
	vector2.Aniade('o');
	vector2.Aniade('d');
	vector2.Aniade('o');
	vector2.Aniade('c');
	vector2.Aniade('i');
	vector2.Aniade('r');
	vector2.Aniade('l');
	vector2.Aniade('o');
	
	if(vector.Similar(vector2))
		cout << "\n\nEstas palabras son similares.\n\n";
	else
		cout << "\n\nEstas palabras no son similares.\n\n";
		

system("pause");
}
