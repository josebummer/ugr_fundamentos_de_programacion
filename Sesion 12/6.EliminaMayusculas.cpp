/*
Sobre la clase SecuenciaCaracteres, añada el método EliminaMayusculas
para eliminar todas las mayúsculas. Por ejemplo, después de aplicar dicho método al
vector {'S','o','Y',' ','y','O'}, éste debe quedarse con {'o',' ','y'}.
Un primer algoritmo para resolver este problema sería el siguiente (en ejercicios posteriores
se verán métodos más eficientes):
Recorrer todas las componentes de la secuencia
Si la componente es una mayúscula, borrarla
Queremos implementarlo llamando al método Elimina (que borra un único carácter):.
La implementación de este método se ha visto en clase de teoría.
class SecuenciaCaracteres{
.........
void EliminaMayusculasError(){
for (int i=0; i<total_utilizados; i++)
if (isupper(vector_privado[i]))
Elimina(i);
}
};
El anterior código tiene un fallo. ¿Cuál? Pruébelo con cualquier secuencia que tenga
dos mayúsculas consecutivas, proponer una solución e implementarla.
*/
#include <iostream>
#include <cctype>

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
		
		void EliminaMayusculas(){
			
			for(int i=0;i<total_utilizados;i++)
				if(isupper(vector_privado[i])){
					Elimina(i);
					i--;
				}
		}
};

int main(){

	char caracter;														//Creamos las variables de entrada
	SecuenciaCaracteres vector;
	int i,posicion;
	
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

	cout << "El vector es:\n";								//Mostramos el vector
	cout << vector.Elemento(0);
	for(i=1;i<vector.TotalUtilizados();i++){
		cout << ", " << vector.Elemento(i);
	}
	cout << "\n\n";

	cout << "Elija la posicion a eliminar: ";
	cin >> posicion;
	
	vector.Elimina(posicion);
	
	cout << "El vector es:\n";								//Mostramos el vector con la posicion eliminada
	cout << vector.Elemento(0);
	for(i=1;i<vector.TotalUtilizados();i++){
		cout << ", " << vector.Elemento(i);
	}
	cout << "\n\n";

	cout << "Vamos a eliminar todas las mayusculas: ";
	
	vector.EliminaMayusculas();
	
	cout << "El vector es:\n";								//Mostramos el vector con todas las mayusculas eliminadas
	cout << vector.Elemento(0);
	for(i=1;i<vector.TotalUtilizados();i++){
		cout << ", " << vector.Elemento(i);
	}
	cout << "\n\n";
	
system("pause");
}
