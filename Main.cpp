#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

double calculo1(double, double, double);
double calculo2(double, double, double);

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
			Temporal = ((B*B)-(4*A*C));
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