#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring> 
using std::cout;
using std::cin;
using std::endl;

double calculo1(double, double, double);
double calculo2(double, double, double);
void secuencia(int*,int);
bool unico(int* sec,int);
void convertiraCadena(char*, int*, int);
bool game(int*, int);
bool control(int*, int*, int);

int main(int argc, char *argv[])
{
	int resp =1;
	do{
		int op;
		cout << "Donde quiere acceder al ejercicio 1 o 2?: ";
		cin >> op;
		cout << endl;
		if (op == 1)
		{
			int dimension = 4;
			int* intento;
			int* adivinar;
			srand(time(NULL));
			adivinar = new int[dimension];

			secuencia(adivinar,dimension);
			if (!game(adivinar,dimension))
			{
				cout << "Usted acaba de perder Joven" << endl;
			}else{
				cout << "Usted es un genio deberia de darme puntitos extra." << endl;
			}
			
		}else{
			double A,B,C,solucion1,solucion2,Temporal;
			cout << "Se ingresara la siguiente formula Ax^2+Bx+C, para su factorizacion."<<endl;
			//Estoy siendo muy descriptivo y siendo amigable con el usuario
			cout << "Ingrese el valor de A: ";
			cin >> A;
			cout << endl;
			cout << "Ingrese el valor de B: ";
			cin >> B;
			cout << endl;
			cout << "Ingrese el valor de C: ";
			cin >> C;
			cout << endl;
			//Se almacenan lo que esta dentro del radical dentro del temporal para dejar fuera lo faltante de la ecuacion.
			Temporal = ((B*B)-(4*A*C));
			//Devolvera dos soluciones.
			solucion1 = calculo1(A,B,Temporal);
			solucion2 = calculo2(A,B,Temporal);

			cout << A << "x^2+"<<B<<"x+"<<C<<"="<< "(x+"<<solucion1<<")(x"<<solucion2<<")" << endl;
		}
		cout << "Desea continuar?\n0.Si\n1.No";
		cout << endl;
		cin >> resp;
	}while(resp != 1);
	return 0;
}

double calculo1(double a, double b, double temporal){
	double ans1;
	ans1 = (-b+sqrt(temporal))/(2*a);
	return ans1;
}

double calculo2(double a, double b, double temporal){
	double ans2;
	ans2 = (-b-sqrt(temporal))/(2*a);
	return ans2;
}

void secuencia(int* sec,int dimension){
	int numero;
	int salida[10];
	for (int i = 0; i < 10; ++i)
	{
		salida[i] = 0;
	}
	for (int i = 0; i < dimension; ++i)
	{
		numero = rand() % 9 + 1;
		while(!unico(salida, numero)){
			numero = rand() % 9 + 1;
		}
		salida[i] = numero;
		sec[i] = numero;
	}
}

bool unico(int* sec,int numero){
	for (int i = 0; i < 10; ++i)
	{
		if (sec[i] == numero)
		{
			return false;
		}
	}
	return true;
}

void convertiraCadena(char* intento, int* numeroIntento, int dimension) {
	for(int i=0; i<dimension; i++) { 
		switch(intento[i]) { 
			case '1':
				numeroIntento[i] = 1;
			break;
			case '2':
				numeroIntento[i] = 2;
			break;
			case '3':
				numeroIntento[i] = 3;
			break;
			case '4':
				numeroIntento[i] = 4;
			break;
			case '5':
				numeroIntento[i] = 5;
			break;
			case '6':
				numeroIntento[i] = 6;
			break;
			case '7':
				numeroIntento[i] = 7;
			break;
			case '8':
				numeroIntento[i] = 8;
			break;
			case '9':
				numeroIntento[i] = 9;
			break;
		}
	}
}

bool control(int* adivinar, int* intento, int dimension){
	int faltan = dimension;
	for (int i = 0; i < dimension; ++i)
	{
		if (adivinar[i] == intento[i])
		{
			cout << "1";
			faltan--;
		}else{
			cout << "0";
		}
	}
	cout << endl;
	return !faltan;
}

bool game(int* adivinar, int dimension){
	bool gane=false;
	char intento[dimension]; 
	int numeroIntento[dimension]; 
	int numIntentos=0;
	int maxIntentos=5;

	while(!gane && numIntentos < maxIntentos) { 
		cout << endl << "Ingrese el numero de " << dimension << " cifras." << endl; 
		cout << "Intento nro: " << ++numIntentos << " de " << maxIntentos << endl; 
		cin >> intento; 
		if(strlen(intento) == dimension) { 
			convertiraCadena(intento, numeroIntento, dimension); 
			gane = control(adivinar, numeroIntento, dimension); 
		}
	}
	return gane; 
}
