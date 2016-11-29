/*
Definir la clase AlumnoFP, que almacene el nombre, el primer apellido, el DNI del
alumno y cada una de las partes consideradas en la evaluación de la asignatura: teoría,
parcial_pract1, parcial_pract2, participación_clase. La escala utilizada para evaluar
cada parte es de 0 a 10.
 Construir los constructores necesarios para poder asignar valores a los miembros
de la clase.
 Construir un método que calcule la nota final del alumno. Para ello se debe de
tener en cuenta los porcentajes de las distintas partes consideradas: 70% teoría,
5% parcial 1, 15% parcial 2 y 10% participación.
 Construir un método que calcule la nota final del alumno.
 Construir un programa que lea los datos del alumno y en caso de haber obtenido
una nota inferior a 5 en alguna de las partes que indique la nota obtenida en dicha
parte.
*/

#include <iostream>
#include <string>

using namespace std;

class AlumnoFP{
	private:
		string nombre,apellido,DNI;																//Creamos las variables de la clase
		double teoria,parcial_pract1,parcial_pract2,participacion_clase;
	public:
		AlumnoFP(string valornombre, string valorapellido, string valorDNI, double valorteoria, double valorparcial_pract1,double valorparcial_pract2,
		double valorparticipacion_clase){
																						//Creamos un constructor para metes los datos al crear el objeto
			nombre=valornombre;
			apellido=valorapellido;
			DNI=valorDNI;
			teoria=valorteoria;
			parcial_pract1=valorparcial_pract1;
			parcial_pract2=valorparcial_pract2;
			participacion_clase=valorparticipacion_clase;
		}
		AlumnoFP(){																//Creamos un constructor por defecto
		
			AlumnoFP("SN","SA","00000000A",1,1,1,1);
		
		}
		void SetNombre(string valornombre){									//Modulo para introducir el nombre
			nombre=valornombre;
		}
		string GetNombre(){														//Nos muestra el valor del nombre
			return nombre;
		}
		
		void SetApellido(string valorapellido){							//Modulo que nos deja meter el apellidos
			apellido=valorapellido;
		}
		string GetApellido(){													//Nos muestra el valor del apellido
			return apellido;
		}
		
		void SetDNI(string valorDNI){											//Introducir el valor del DNI
			DNI=valorDNI;
		}
		string GetDNI(){															//Mostrar el valor del DNI
			return DNI;
		}
		
		void SetTeoria(double valorteoria){									//Meter el valor de teoria
			teoria=valorteoria;
		}
		double GetTeoria(){														//Mostrar el valor de la variable teoria
			return teoria;
		}
		
		void SetParcial_pract1(double valorparcial_pract1){			//Meter el valor del primer parcial
			parcial_pract1=valorparcial_pract1;
		}
		double GetParcial_pract1(){											//Mostrar el valor del primer parcial
			return parcial_pract1;
		}
		
		void SetParcial_pract2(double valorparcial_pract2){			//Meter el valor del segundo parcial
			parcial_pract2=valorparcial_pract2;
		}
		double GetParcial_pract2(){											//Mostrar el valor del segundo parcial
			return parcial_pract2;
		}
		
		void SetParticipacion(double valorparticipacion_clase){		//Introducir el valor de la participacion
			participacion_clase=valorparticipacion_clase;
		}
		double GetParticipacion(){												//Mostrar el valor de la variable participacion
			return participacion_clase;
		}
		
		void SetValores(string valornombre, string valorapellido, string valorDNI, double valorteoria, double valorparcial_pract1,double valorparcial_pract2,
		double valorparticipacion_clase){
																	//Nos permite añadir todos los valores de una vez.
			
			nombre=valornombre;
			apellido=valorapellido;
			DNI=valorDNI;
			teoria=valorteoria;
			parcial_pract1=valorparcial_pract1;
			parcial_pract2=valorparcial_pract2;
			participacion_clase=valorparticipacion_clase;
			
		}
		
		double CalcTeoria(){										//Calcula el valor de la teoria sobre la nota final
			return teoria*0.7; 
		}
		
		double CalcParcial1(){									//Calcula el valor del primer parcial sobre la nota final
			return parcial_pract1*0.05;
		}
		
		double CalcParcial2(){									//Calcula el valor del segundo parcial sobre la nota final
			return parcial_pract2*0.15;
		}
		
		double CalcParticipacion(){							//Calcula el valor de la participacion sobre la nota final
			return participacion_clase*0.1;
		}
		
		double NotaFinal(){										//Calcula la nota final sumando las notas anteriores
			return CalcTeoria()+CalcParcial1()+CalcParcial2()+CalcParticipacion();
		}

};

int main(){

	static const int TAMANIO=4;								//Creamos la constante de tamaño para el vector de notas
	double notas[TAMANIO];										//Creamos el vector
	int i;									
	AlumnoFP alumno;												//Creamos el objeto
	string nombre="",apellido="",DNI="";

	cout << "Introduce tu nombre: ";							//Pedimos los datos de entrada 
	cin >> nombre;
	cout << "Introduce tu primer apellido: ";
	cin >> apellido;
	do{
	cout << "Introduce tu DNI: ";
	cin >> DNI;
	}while(DNI.size()!=9);
	cout << "\n\nAhora introduce las notas en orden: TEORIA, PARCIAL1, PARCIAL2, PARTICIPACION (de 0 a 10).\n";
	for(i=0;i<TAMANIO;i++){
	
		do{
			cout << "Introduce el " << i+1 << " valor: ";
			cin >> notas[i];
		}while(notas[i]<0 || notas[i]>10);
	
	}
	
	alumno.SetValores(nombre,apellido,DNI,notas[0],notas[1],notas[2],notas[3]);		//Metemos todos los datos a la vez

	cout << "\n\nAlumno: " << alumno.GetNombre() << " " << alumno.GetApellido() << "\nDNI: " << alumno.GetDNI() << "\n";
	cout << "La nota final del alumno es: " << alumno.NotaFinal() << ".";
	//MOSTRAMOS TODOS LOS DATOS LLAMANDO A LOS MODULOS NECESARIOS
	if(alumno.GetTeoria()<5)
		cout << "\nSuspenso en TEORIA con un " << alumno.GetTeoria() << " que para la nota final puntua con " << alumno.CalcTeoria();
	if(alumno.GetParcial_pract1()<5)
		cout << "\nSuspenso en PRACTICO 1 con un " << alumno.GetParcial_pract1() << " que para la nota final puntua con " << alumno.CalcParcial1();
	if(alumno.GetParcial_pract2()<5)
		cout << "\nSuspenso PRACTICO 2 con un " << alumno.GetParcial_pract2() << " que para la nota final puntua con " << alumno.CalcParcial2();
	if(alumno.GetParticipacion()<5)
		cout << "\nTiene en participacion un " << alumno.GetParticipacion() << " que para la nota final puntua con " << alumno.CalcParticipacion();
	cout << "\n\n";

system("pause");
}
