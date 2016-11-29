/*A un trabajador le pagan según sus horas trabajadas y la tarifa está a un valor por
hora. Si la cantidad de horas trabajadas es mayor de 40 horas, la tarifa por hora se
incrementa en un 50% para las horas extras (las que haya por encima de 40). Construir
una función que dado el número total de horas trabajadas y el precio por hora,
devuelva el salario del trabajador.*/

#include <iostream>

using namespace std;

double SalarioTrabajador(int horas,int precio){

	const MAX=40;
	double salario;
	int horas_extras=0;
	
	if(horas>MAX){
		horas_extras=horas-MAX;
		horas-=horas_extras;
		
		salario=horas_extras*precio*1.5;
	}
	
	salario+=horas*precio;
	
return salario;
}

int main(){

	int precio_hora,horas;
	double salario;
	
	do{
	cout << "Introduce el precio al que es paga la hora: ";
	cin >> precio_hora;
	}while(precio_hora<0);
	do{
	cout << "Introduce el numero de horas trabajadas: ";
	cin >> horas;
	}while(horas<0);
	
	salario=SalarioTrabajador(horas,precio_hora);
	
	cout << "\nEl trabajador ha ganado: " << salario << " euros.\n\n";

system("pause");
}
