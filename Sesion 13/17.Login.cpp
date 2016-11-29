/*
(Examen Febrero 2013) Se est� dise�ando un sistema web que recolecta datos
personales de un usuario y, en un momento dado, debe sugerirle un nombre de
usuario (login). Dicho login estar� basado en el nombre y los apellidos; en concreto
estar� formado por los N primeros caracteres de cada nombre y apellido
(en min�sculas, unidos y sin espacios en blanco). Por ejemplo, si el nombre es
"Antonio Francisco Molina Ortega" y N=2, el nombre de usuario sugerido
ser� "anfrmoor".
Debe tener en cuenta que el n�mero de palabras que forman el nombre y los apellidos
puede ser cualquiera. Adem�s, si N es mayor que alguna de las palabras que
aparecen en el nombre, se incluir� la palabra completa. Por ejemplo, si el nombre
es "Ana CAMPOS de la Blanca" y N=4, entonces la sugerencia ser�
"anacampdelablan" (observe que se pueden utilizar varios espacios en blanco
para separar palabras).
Implemente la clase Login que tendr� como �nico dato miembro el tama�o N. Hay
que definir el m�todo Codifica que recibir� una cadena de caracteres (tipo string)
formada por el nombre y apellidos (separados por uno o m�s espacios en blanco) y
devuelva otra cadena con la sugerencia de login.
class Login{
private:
int num_caracteres_a_coger;
public:
Login (int numero_caracteres_a_coger)
:num_caracteres_a_coger(numero_caracteres_a_coger)
{ }
string Codifica(string nombre_completo){
......
}
};
Los �nicos m�todos que necesita usar de la clase string son size y push_back.
Para probar el programa lea los caracteres de la cadena uno a uno con cin.get(),
hasta que el usuario introduzca el car�cter #.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Login{
	private:
		static const int CARACTERES=5;
	public:
		string Codifica(string nombre){
		
			string usuario;
			int longitud=nombre.size(),j=0;
			
			for(int i=0;i<longitud;i++)
				if(nombre[i]!=' '){
					if(j<CARACTERES){
						usuario.push_back(tolower(nombre[i]));
						j++;
					}
				}
				else
					j=0;
					
			return usuario;
		}
};

int main(){

	Login usuario;
	string nombre;
	char caracter;

	cout << "Introduce su nombre(# para salir): ";
	caracter=cin.get();
	
	while(caracter!='#'){
	
		nombre.push_back(caracter);
		
		cout << "Introduce su nombre(# para salir): ";
		caracter=cin.get();
	}
	
	cout << "\n\nSu nombre de usuario es: " << usuario.Codifica(nombre) << "\n\n";

system("pause");
}
