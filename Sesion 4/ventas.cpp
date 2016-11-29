/*Vamos a cambiar el criterio de los descuentos. Supondremos que sólo se aplicará el
descuento del 2% (por una venta mayor de 700 euros) cuando se hayan vendido más
de 100 unidades, es decir, para ventas de menos de 100 unidades no se aplica el
descuento del 2% aunque el importe sea mayor de 700 euros.*/

#include <iostream>

using namespace std;

int main() {

	int unidades_vendidas;					// Declaramos las variables
	double euros_ventas;
	
	cout << "¿Cuantas unidades se han vendido?: ";						//Preguntamos para obtener el valor de las variables
	cin >> unidades_vendidas;
	cout << "¿Cuantos euros ha proporcionado la venta?: ";
	cin >> euros_ventas;

	if ((euros_ventas > 700) && (unidades_vendidas > 100))			// Ejecutamos la condicion que deben cumplir
		euros_ventas = euros_ventas - (euros_ventas*0.02);
		
	cout << "Los euros que finalmente tendremos son: " << euros_ventas << "\n\n";		// Mostramos el resultado
	
	system("pause");

}
