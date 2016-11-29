/*
(Examen Febrero 2009) Sgeún un etsduio de una uivenrsdiad ignlsea, no ipmotra el
odren en el que las ltears etsan ersciats, la úicna csoa ipormtnate es que la pmrirea y
la útlima ltera etsén ecsritas en la psioción cocrrtea. El rsteo peuden estar ttaolmntee
mal y aún pordás lerelo sin pobrleams. Etso es pquore no lemeos cada ltera por sí
msima snio la paalbra cmoo un tdoo.
Diremos que dos palabras son similares si la primera letra de ambas palabras es
igual, la última letra de ambas palabras también es igual y el resto de las letras son
las mismas pero no están necesariamente en las mismas posiciones. De esta forma,
las palabras ttalomntee y totalmente son similares.
Declare en el main dos objetos de la clase SecuenciaCaracteres y asígneles
algunos caracteres de prueba. Implemente en el main un algoritmo que compruebe
si los dos objetos son similares según el criterio anterior.
Si lo necesita, puede añadir los métodos que estime oportunos a la clase
SecuenciaCaracteres.
Si le sirve de ayuda, utilice como base la descripción del siguiente algoritmo:
Usaremos una secuencia de letras ya procesadas
Comparar las primeras y últimas letras de cada palabra
Si son iguales:
Recorrer el resto de letras:
Si la letra no está en la secuencia de procesadas:
Añadirla a procesadas
Contar el número de apariciones de la letra en cada palabra
Si el número de apariciones es distinto, no son similares
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
};

int main(){

	SecuenciaCaracteres vector,vector2;							//Creamos los objetos
	bool similares=true,encontrada;								//Creamos las variables que nos ayudan a comprobar y la que nos muestra el resultado
	
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
	
	
	
	if(vector.Elemento(0)==vector2.Elemento(0) && vector.Elemento(vector.TotalUtilizados()-1)==vector2.Elemento(vector2.TotalUtilizados()-1) && vector.TotalUtilizados()==vector2.TotalUtilizados()){
		int tope=vector.TotalUtilizados()-1;
		// Comrpobamos en el if que la primera letra y la ultima son iguales y que el tamaño de los dos vectores es el mismo.
		for(int i=1;i<tope && similares;i++){				//Recorremos el vector cojiendo cada letra
			encontrada=false;
			for(int j=1;j<tope && !encontrada;j++)					
				if(vector.Elemento(i)==vector2.Elemento(j))								//Si la encuentra, salimos y pasamos a la siguiente letra
					encontrada=true;
			if(!encontrada)														//Si termina y no la ha encontrado ya tenemos que no son similares.
				similares=false;
		}
	}
	else
		similares=false;
	
	if(similares)																//Mostramo el resultado.
		cout << "\n\nEstas palabras son similares.\n\n";
	else
		cout << "\n\nEstas palabras no son similares.\n\n";
	

system("pause");
}
