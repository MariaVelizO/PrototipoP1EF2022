#include "menu.h"
#include <iostream>
#include<conio.h>
#include "Usuario.h"
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <ctime>
#include <vector>
#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;


menu::menu()
{
    //ctor
}

menu::~menu()
{
    //dtor
}

menu::menuGeneral()
{
    menu menuG;
int choice;
	char x;
	do
    {
	system("cls");
	//Funcion que imprime Fecha  y Hora
	cout<<"\t\t\t............SISTEMA DE CINES MJ............"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Cines"<<endl;
	cout<<"\t\t\t 2. Peliculas"<<endl;
	cout<<"\t\t\t 3. Salas"<<endl;
	cout<<"\t\t\t 4. Asientos"<<endl;
    cout<<"\t\t\t 5. Clientes"<<endl;
	cout<<"\t\t\t 6. Salir"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
switch(choice)
    {
    case 1:
        menuCines ();
		break;
	case 2:
        menuPeliculas();
		break;
	case 3:
        menuSalas();
		break;
    case 4:
        menuAsientos();
		break;
    case 5:
        menuClientes();
	case 6:
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 6);
    return 0;
}



