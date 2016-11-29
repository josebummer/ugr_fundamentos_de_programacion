#include <iostream>

//Intercambiar variables.

using namespace std;

int main() {
	int x = 10, y = 20, z = 30,a;
	
	a = x;
	x = z;
	z = y;
	y = a;

	cout << x << " " << y << " " << z << "\n\n";
	
	system("pause");

}
