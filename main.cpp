#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main(){

	int opcion;
	string opcion_s;
	string TipoCafe;
	string cantidad;
	string monto;// Monedas de 1$, 2$, 3$
	string  cad1; 


	ofstream memoryFile; 
	memoryFile.open("InstructionMemory.txt", ios::out);// ios::in | ios::out);


	//MENU
	system("clear");
	cout << "\t\t\t\t\t\t**************************************" << endl;
	cout << "\t\t\t\t\t\t**************************************" << endl;
	cout << "\t\t\t\t\t\t**                                  **" << endl;
	cout << "\t\t\t\t\t\t**   Bienvenido a la Cafetería MEK  **" << endl;
	cout << "\t\t\t\t\t\t**                                  **" << endl;
	cout << "\t\t\t\t\t\t**************************************" << endl;
	cout << "\t\t\t\t\t\t**************************************" << endl << endl;
	//cout << "\t\t\t\t\t\t\t*******************************"<< endl;

	cout << "\t\t\t\t\t\t\t\tMenú" << endl << endl
	<< "\t\t\t\t\t\t\t1. Hacer Pedido" << endl 
	<< "\t\t\t\t\t\t\t2. Salir" << endl;
	cin >> opcion;

	while(opcion!=2){

		while(opcion != 1)
		{
			cout << "Dato erroneo " << endl;
			//system("clear");
			cout << "Menú" << endl 
			<< "1. Hacer Pedido" << endl 
			<< "2. Salir" << endl;
			cin >> opcion;
		}

		//system("clear");

		opcion_s = "00";
		cout <<"\t\t\t\t\t\t\tTipo de café:" << endl 
		<< "\t\t\t\t\t\t\t1. Frapuchino " << endl 
		<< "\t\t\t\t\t\t\t2. Espresso" << endl 
		<< "\t\t\t\t\t\t\t3. Capuchino" << endl 
		<< "\t\t\t\t\t\t\t4. Mokachino" << endl;
		cin >> TipoCafe;

		while(TipoCafe != "1" and TipoCafe != "2" and TipoCafe != "3" and TipoCafe != "4")
		{
			cout << "\t\t\t\t\t\t\tDato erroneo " << endl;

			cout <<"\t\t\t\t\t\t\tTipo de café:" << endl 
			<< "\t\t\t\t\t\t\t1. Frapuchino " << endl 
			<< "\t\t\t\t\t\t\t2. Espresso" << endl 
			<< "\t\t\t\t\t\t\t3. Capuchino" << endl 
			<< "\t\t\t\t\t\t\t4. Mokachino" << endl;
			cin >> TipoCafe;
		}	

		if (TipoCafe== "1")
			TipoCafe="00";
		else if (TipoCafe == "2")
			TipoCafe = "01";
		else if (TipoCafe == "3")
			TipoCafe = "10";
		else 
			TipoCafe = "11";

		//system("clear");

		cout << "\t\t\t\t\tPuede hacer un máximo de 3 pedidos, indique cantidad: "<< endl;
		cin >> cantidad;

		while(cantidad != "1" and cantidad != "2" and cantidad != "3")// and cantidad != "4")
		{
			cout << "\t\t\t\t\t\t\tDato erroneo " << endl;
			cout << "\t\t\t\t\t\t\tCantidad: "<< endl;
			cin >> cantidad;	
		}
	
		if (cantidad == "1")
			cantidad = "01";
		else if (cantidad == "2")
			cantidad = "10";
		else if (cantidad == "3")
			cantidad = "11";

		cad1= opcion_s + TipoCafe + cantidad;

		memoryFile << cad1 << "\n";

		//system("clear");
		cout << "\t\t\t\t\t\t\t¿Desea hacer otro pedido?" << endl 
		<< "\t\t\t\t\t\t\t1. Hacer Pedido" << endl 
		<< "\t\t\t\t\t\t\t2. Salir" << endl;
		cin >> opcion;
	}

	memoryFile.close();
	
	return(0);
}
