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

	cout << "Bienvenido a la Cafetería MEK" << endl << endl;
	cout << "-------------------------------------------------"<< endl;

	cout << "Menú" << endl 
	<< "1. Hacer Pedido" << endl 
	<< "2. Salir" << endl;
	cin >> opcion;

	while(opcion!=2){

		while(opcion != 1)
		{
			cout << "Dato erroneo " << endl;
			system("clear");
			cout << "Menú" << endl 
			<< "1. Hacer Pedido" << endl 
			<< "2. Salir" << endl;
			cin >> opcion;
		}

		system("clear");

		opcion_s = "00";
		cout <<"Tipo de café:" << endl 
		<< "1. Frapuchino " << endl 
		<< "2. Espresso" << endl 
		<< "3. Capuchino" << endl 
		<< "4. Mokachino" << endl;
		cin >> TipoCafe;

		while(TipoCafe != "0" and TipoCafe != "1" and TipoCafe != "2" and TipoCafe != "3")
		{
			cout << "Dato erroneo " << endl;

			cout <<"Tipo de café:" << endl 
			<< "1. Frapuchino " << endl 
			<< "2. Espresso" << endl 
			<< "3. Capuchino" << endl 
			<< "4. Mokachino" << endl;
			cin >> TipoCafe;
		}	

		if (TipoCafe== "0")
			TipoCafe="00";
		else if (TipoCafe == "1")
			TipoCafe = "01";
		else if (TipoCafe == "2")
			TipoCafe = "10";
		else 
			TipoCafe = "11";


		cout << "Cantidad: "<< endl;
		cin >> cantidad;

		while(cantidad != "0" and cantidad != "1" and cantidad != "2" and cantidad != "3")
		{
			cout << "Dato erroneo " << endl;
			cout << "Cantidad: "<< endl;
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

		opcion_s = "01";
		
		cout << "Monto a ingresar:" << endl;
		cin >> monto;

		while(monto != "0" and monto != "1" and monto != "2" and monto != "3"){
			cout << "Dato erroneo " << endl;
			cout << "Monto a ingresar:" << endl;
			cin >> monto;
		}

		if (monto == "1")
			monto= "01";
		else if (monto == "2")
			monto= "10";
		else 
			monto= "11";

		cad1= opcion_s + TipoCafe + monto;

		memoryFile << cad1 << "\n";

		cout << "¿Desea hacer otro pedido?" << endl 
		<< "1. Hacer Pedido" << endl 
		<< "2. Salir" << endl;
		cin >> opcion;
	}

	memoryFile.close();
	
	return(0);
}
