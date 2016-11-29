/*
(Examen Septiembre 2014) Recupere la solución del ejercicio 32 de la Relación
de Problemas IV (Replace). Defina sobre la clase SecuenciaCaracteres el
método Replace para que haga la tarea pedida. Tendrá que pasarle al método
la posición inicial, el número de caracteres a eliminar y el objeto de la clase
SecuenciaCaracteres conteniendo la secuencia de caracteres de reemplazo.
*/
#include <iostream>

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
		
		void Replace(int pos, int n, SecuenciaCaracteres otro){
			int salto=0;
			
			if(n==otro.TotalUtilizados())										//Comparamos si el numero de elementos a reemplazar tiene la misma longitud que el segundo vector
				for(int i=0;i<otro.TotalUtilizados();i++,pos++)
					vector_privado[pos]=otro.Elemento(i);						//Si es asi, solo tenemos que sustituir los valores.
			else if(n<otro.TotalUtilizados()){									//Comprobamos si el numero de elementos es menor que la longitud del segundo vector
				salto=otro.TotalUtilizados()-n;
				for(int i=total_utilizados-1;i>=pos+n;i--)
					vector_privado[i+salto]=Elemento(i);					//Si es asi, tenemos que mover los caracteres para dejar el espacio necesario para introducir
				for(int i=0;i<otro.TotalUtilizados();i++,pos++)			//los nuevos caracteres.
					vector_privado[pos]=otro.Elemento(i);
				total_utilizados+=salto;								//Finalmente aumentamos el total utilizados
			}
			else if(n>otro.TotalUtilizados()){									//Por ultimo comprobamos que el numero de elementos es mayor que la longitud del segundo vector
				salto=n-otro.TotalUtilizados();
				for(int i=pos+otro.TotalUtilizados();i<total_utilizados;i++)
					vector_privado[i]=Elemento(i+salto);					//Si es asi, eliminamos las posiciones necesarias hasta dejarlo para sustituir los caracteres
				for(int i=0;i<otro.TotalUtilizados();i++,pos++)
					vector_privado[pos]=otro.Elemento(i);
				total_utilizados-=salto;								//Restamos al total utilizados
			}
		}
};

int main(){
	
	SecuenciaCaracteres vector1, vector2;							//Creamos las variables necesarias												
	char caracter;
	int pos,n;

	cout << "Intraduce el primer vector(# para salir): ";		//Pedimos los datos del primer vector.
	caracter=cin.get();
	
	while(caracter!='#'){
	
		if(caracter!='\n'){
			
			vector1.Aniade(caracter);			//Los almacenamos en el primer vector
		}
		
		cout << "Introduce cracteres para el primer vector(# para salir): ";
		caracter=cin.get();
	}
	
	cout << "Introduce cracteres para el segundo vector(# para salir): ";			//Pedimos los datos del segundo vector
	caracter=cin.get();
	
	while(caracter!='#'){
	
		if(caracter!='\n'){
			
			vector2.Aniade(caracter);			//Los almacenamos en el segundo vector.
		}
		
		cout << "Introduce cracteres para el segundo vector(# para salir): ";
		caracter=cin.get();
	}
	
	do{
	cout << "Indica la posicion desde donde vamos a empezar a reemplazar: ";			//Indicamos la posicion
	cin >> pos;
	}while(pos<0 || pos>=vector1.TotalUtilizados());
	
	do{
	cout << "Indica el numero de elementos que se van a reemplazar: ";			//Indicamos el numero de elementos
	cin >> n;
	}while(n<0 || n>vector1.TotalUtilizados()-pos);

	vector1.Replace(pos,n,vector2);
	
	cout << "\n\n";								//Mostramos la cadena cambiada
	for(int i=0;i<vector1.TotalUtilizados();i++)
		cout << vector1.Elemento(i);
	
	cout << "\n\n";

system("pause");
}
