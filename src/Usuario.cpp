#include "Usuario.h"
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include <string>
//Declaracion provicional de usuario y contrase�a
#define USER "Cines"
#define PASS "1234"
using namespace std;


Usuario::Usuario()
{

}

Usuario::~Usuario()
{
    //dtor
}

//Funcion que envia el usuario a Bitacora
void Usuario::obtenerUser(string valorUsuario)
{

    userP = valorUsuario;

}

//Funcion para el login
bool Usuario::loginUsuario(){
    string Usuario, contra;
    int contador=0;
    bool ingresa=false;
    do{
        system("cls");
        cout<<"..........................."<<endl;
        cout<<" INGRESAR AL SISTEMA "<<endl;
        cout<<"..........................."<<endl;
        cout<<"Ingrese Usuario: ";
        getline(cin, Usuario);
        obtenerUser(Usuario);
        cout<<"\nContrasena: ";
        //getline(cin, contra);
        char caracter;
        caracter = getch();
        contra="";
        //En este while se trasnforma lo que ingresa el usuario en *
        while (caracter != 13) //ASCII TECLA ENTER
        {
            if (caracter != 8) //ASCII TECLA RETROCESO
            {
                contra.push_back(caracter);
                cout<<"*";
            } else
            {
                if (contra.length() > 0)
                {
                    cout<<"\b \b"; //Efecto caracter borrado en pantalla
                    contra = contra.substr(0,contra.length()-1); //Toma todos los caracteres menos el ultimo
                }
            }
            caracter = getch();
        }
        //instancia de clase USUARIOS, para consultar: primero se consulta el usuario, si existe, se consulta la contrase�a
        if (Usuario==USER && contra==PASS){
            ingresa=true;

        } else {

            cout<<"\nEl usuario y/o contrasena son incorrectos"<<endl;
            cin.get();
            contador++;

        }
        //Si se pasa de 3 fallos se detiene el ingreso y muestra error
    } while (ingresa==false && contador<3);
    if (ingresa==false){
        cout<<"\nLo siento, no puede ingresar al sistema, sus contrasenas son invalidas o agoto intentos"<<endl;
        cin.get();
    } else {

        cout<<"\n.....Bienvenido al Sistema....."<<endl;
        cout << "Presione enter para aceptar"<<endl;
        cin.get();
    }
    return ingresa;
}

