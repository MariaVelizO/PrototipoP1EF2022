#include "Cines.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;


Cines::Cines()
{
    string id,name,phone,college,address;
}
Cines::~Cines()
{
    //dtor
}
void Cines::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA DE CINES |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso de informacion"<<endl;
	cout<<"\t\t\t 2. Despliegue de informacion"<<endl;
	cout<<"\t\t\t 3. Modificar informacion"<<endl;
	cout<<"\t\t\t 4. Buscar informacion"<<endl;
	cout<<"\t\t\t 5. Borrar informacion"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t Agregar informacion(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		display();
		break;
	case 3:
		modify();
		break;
	case 4:
		search();
		break;
	case 5:
		delet();
		break;
	case 6:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void Cines::insert()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles de cine ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa numero ID        : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre     : ";
	cin>>name;
	cout<<"\t\t\tIngresa Direccion  : ";
	cin>>direcc;
    file.open("ParticipantRecord.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< direcc <<std::left<<std::setw(15)<< "\n";
	file.close();
}
void Cines::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles -------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		file >> id >> name >> direcc;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id : "<<id<<endl;
			cout<<"\t\t\t Nombre: "<<name<<endl;
			cout<<"\t\t\t Direccion: "<<direcc<<endl;
			file >> id >> name >> direcc;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void Cines::modify()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion de informacion-------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del cine que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> direcc;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< direcc <<std::left<<std::setw(15)<<"\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id : ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre: ";
				cin>>name;
				cout<<"\t\t\tIngrese Direccion: ";
				cin>>direcc;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< direcc <<std::left<<std::setw(15)<<"\n";
				found++;
			}
			file >> id >> name >> direcc;

		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}
void Cines::search()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de cine buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos de cine buscado------------------------"<<endl;
		cout<<"\nIngrese Id de cine que quiere buscar: ";
		cin>>participant_id;
		file >> id >> name >> direcc;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id: "<<id<<endl;
				cout<<"\t\t\t Nombre: "<<name<<endl;
				cout<<"\t\t\t Direccion: "<<direcc<<endl;
				found++;
			}
			file >> id >> name >> direcc;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Cine no encontrado...";
		}
		file.close();
	}
}
void Cines::delet()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles a Borrar-------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de cine que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> direcc;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< direcc <<std::left<<std::setw(15)<<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> name >> direcc;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}
