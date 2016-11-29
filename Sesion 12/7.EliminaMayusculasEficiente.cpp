/*
El algoritmo del ejercicio 6 es muy ineficiente ya que requiere trasladar muchas veces
muchas posiciones (usa dos bucles anidados). Para comprobarlo, ejecute el método
sobre el texto del Quijote, disponible en decsai. Para ello, lea los caracteres hasta
encontrar el terminador #. Para que el texto quepa en la pila, debe hacer los siguientes
cambios:
 Dentro de la clase SecuenciaCaracteres cambie el tamaño del vector privado
a 2500000 (dos millones y medio de bytes, unos 2.4 MB)
 Aumente el tamaño de la pila asignada por el sistema operativo al programa
generado por el compilador. Para ello, debe seleccionar desde DevC++:
Herramientas -> Opciones del Compilador ->
Señale la opción
Añadir los siguientes comandos al llamar al compilador
y en la caja de texto introduzca lo siguiente:
-Wl,--stack,2600000
Para resolver eficientemente este problema se propone utilizar dos variables,
posicion_lectura y posicion_escritura que nos vayan indicando, en cada
momento, la componente que se está leyendo y el sitio dónde tiene que escribirse.
Por ejemplo, supongamos que en un determinado momento la variable
posicion_lectura vale 6 y posicion_escritura 3. Si la componente en la
posición 6 es una mayúscula, simplemente avanzaremos posicion_lectura. Por
el contrario, si fuese una minúscula, la colocaremos en la posición 3 y avanzaremos
una posición ambas variables.
Implemente este algoritmo y observe la diferencia de tiempo al ejecutarlo sobre el
Quijote. Mientras que el algoritmo eficiente tarda unos 8 milisegundos, el ineficiente
puede tardar un minuto o más, dependiendo de la potencia del ordenador.
Como ampliación: si quiere saber con exactitud el tiempo de ejecución, puede utlizar
un objeto crono_mayusculas de la clase Cronometro descrita más abajo.
Antes de ejecutar el método cuyo tiempo de ejecución quiere analizar debe poner
crono_mayusculas.Reset() y justo después de que termine el método, debe ejecutar
el método crono_mayusculas.MiliSegundosTranscurridos().
#include <chrono>
class Cronometro{
private:
typedef std::chrono::time_point<std::chrono::steady_clock>
Punto_en_el_Tiempo;
typedef chrono::duration <double, nano> IntervaloTiempo;
Punto_en_el_Tiempo inicio;
Punto_en_el_Tiempo final;
public:
void Reset(){
inicio = chrono::steady_clock::now();
}
double MiliSegundosTranscurridos(){
final = chrono::steady_clock::now();
IntervaloTiempo diferencia = final - inicio;
return diferencia.count() / 1e+6;
}
};
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
			
			int posicion_lectura=0,posicion_escritura=0,tope=total_utilizados;
			
			for(int i=posicion_lectura;i<tope;i++)
				if(islower(vector_privado[i])){
					vector_privado[posicion_escritura]=vector_privado[i];
					posicion_escritura++;
				}
				else
					total_utilizados--;
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

	cout << "El vector es:\n";								//Mostramos el vector
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
