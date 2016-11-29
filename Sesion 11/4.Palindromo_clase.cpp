/*
Añada los métodos EsPalindromo, Invierte y NumeroMayusculas a la clase
SecuenciaCaracteres que implementen las tareas descritas en el ejercicio 1 de
esta relación de problemas.
Incluya un programa principal de prueba similar al del ejercicio 1.
*/

#include <iostream>
#include <string>

using namespace std;

class SecuenciaCaracteres {
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
};

int main(){

	char caracter;														//Creamos las variables de entrada
	SecuenciaCaracteres vector;
	int i;
	
		cout << "Introduce la primera letra (# para salir): ";							//Pedimos los valores de entrada
		caracter=cin.get();
	
	while(caracter!='#' && vector.TotalUtilizados()<vector.Capacidad()){
		
		vector.Aniade(caracter);												//Añadimos el valor introducido al vector
		
		/* SI INTRODUCIMOS LOS DATOS POR TECLADO DESCOMENTAR LA SIGUIENTE LINEA:*/
		if(caracter=='\n')
			vector.Elimina(vector.TotalUtilizados()-1);
		
		cout << "Introduce otra letra (# para salir): ";
		caracter=cin.get();
	}
	
														
	if(vector.EsPalindromo())										//Nos devuelve si es palindromo
		cout << "\nEl vector SI es palindromo.\n\n";
	else
		cout << "\nEl vector NO es palindromo.\n\n";
	
	cout << "El vector finalmente es:\n";								//Mostramos el vector con el orden introducido
	cout << vector.Elemento(0);
	for(i=1;i<vector.TotalUtilizados();i++){
		cout << ", " << vector.Elemento(i);
	}
	cout << "\n\n";
	
	vector.Invierte();														//Invertimos el vector
	cout << "El vector invertido es:\n";								//Mostramos el vector invertido
	cout << vector.Elemento(0);
	for(i=1;i<vector.TotalUtilizados();i++){
		cout << ", " << vector.Elemento(i);
	}
	cout << "\n\n";
	
	cout << "El numero de mayusculas que hay en el vector es:\n" << vector.NumeroMayusculas() << "\n\n";			//Mostramos el numero de mausculas


system("pause");
}
