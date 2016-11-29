/*(Examen Septiembre 2014) Existe un método para la clase string de C++, denominado
replace, que cambia n caracteres de una cadena cad1, empezando en
una determinada posición pos, por los caracteres presentes en una segunda cadena
cad2. La llamada al método es cad1.replace(pos, n, cad2). Ejemplos del
funcionamiento de replace son:
string cad1="Fundamental Programación";
cad1.replace(9,2,"os de la"); // "al" -> "os de la"
// Ahora cad1 tiene "Fundamentos de la Programación"
cad1.replace(12,5,"en"); // "de la" -> "en"
// Ahora cad1 tiene "Fundamentos en Programación"
Puede observar que, dependiendo de la cadena a insertar y de las posiciones especificadas,
la secuencia final puede ser más grande o más pequeña que la original.
Se quiere realizar esta tarea pero directamente en el main, trabajando sobre dos
vectores de corchetes y sin ninguna clase. Se pide construir un programa que leerá
caracteres hasta el terminador # y los almacenará en el primer vector y de nuevo leerá
caracteres hasta llegar a un segundo # y almacenará los datos en el segundo vector.
A continuación, el programa leerá dos enteros pos y n y procederá a reemplazar los
n caracteres que hay a partir de la posición pos del primer vector, con los caracteres
del segundo vector.
Restricciones para este ejercicio: No se puede utilizar la clase string en ninguna
parte del programa, debe hacerse lo más eficiente posible y no puede utilizarse un
tercer vector en el que se vaya almacenando el resultado, es decir, las modificaciones
deben hacerse directamente sobre el primer vector.
*/

#include <iostream>

using namespace std;

int main(){

	const int TAMANIO=50;															//Creamos las variables necesarias
	char vector1[TAMANIO],vector2[TAMANIO],caracter;
	int pos,n,total_util1=0,total_util2=0,salto=0;
	
	cout << "Intraduce el primer vector(# para salir): ";		//Pedimos los datos del primer vector.
	caracter=cin.get();
	
	while(caracter!='#'){
	
		if(caracter!='\n'){
			
			vector1[total_util1]=caracter;			//Los almacenamos en el primer vector
			total_util1++;
		}
		
		cout << "Introduce cracteres para el primer vector(# para salir): ";
		caracter=cin.get();
	}
	
	cout << "Introduce cracteres para el segundo vector(# para salir): ";			//Pedimos los datos del segundo vector
	caracter=cin.get();
	
	while(caracter!='#'){
	
		if(caracter!='\n'){
			
			vector2[total_util2]=caracter;			//Los almacenamos en el segundo vector.
			total_util2++;
		}
		
		cout << "Introduce cracteres para el segundo vector(# para salir): ";
		caracter=cin.get();
	}
	
	do{
	cout << "Indica la posicion desde donde vamos a empezar a reemplazar: ";			//Indicamos la posicion
	cin >> pos;
	}while(pos<=0 || pos>=total_util1);
	
	do{
	cout << "Indica el numero de elementos que se van a reemplazar: ";			//Indicamos el numero de elementos
	cin >> n;
	}while(n<0 || n>total_util1-pos);
	
	if(n==total_util2)										//Comparamos si el numero de elementos a reemplazar tiene la misma longitud que el segundo vector
		for(int i=0;i<total_util2;i++,pos++)
			vector1[pos]=vector2[i];						//Si es asi, solo tenemos que sustituir los valores.
	else if(n<total_util2){									//Comprobamos si el numero de elementos es menor que la longitud del segundo vector
		salto=total_util2-n;
		for(int i=total_util1-1;i>=pos+n;i--)
			vector1[i+salto]=vector1[i];					//Si es asi, tenemos que mover los caracteres para dejar el espacio necesario para introducir
		for(int i=0;i<total_util2;i++,pos++)			//los nuevos caracteres.
			vector1[pos]=vector2[i];
		total_util1+=salto;								//Finalmente aumentamos el total utilizados
	}
	else if(n>total_util2){									//Por ultimo comprobamos que el numero de elementos es mayor que la longitud del segundo vector
		salto=n-total_util2;
		for(int i=pos+total_util2;i<total_util1;i++)
			vector1[i]=vector1[i+salto];					//Si es asi, eliminamos las posiciones necesarias hasta dejarlo para sustituir los caracteres
		for(int i=0;i<total_util2;i++,pos++)
			vector1[pos]=vector2[i];
		total_util1-=salto;								//Restamos al total utilizados
	}
	
	cout << "\n\n";								//Mostramos la cadena cambiada
	for(int i=0;i<total_util1;i++)
		cout << vector1[i];
	
	cout << "\n\n"; 
system("pause");
}
