#include <iostream>
#include "Usuario.h"
#include "menu.h"
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


void portadaproyec();
//Inicio de main
int main(int argc, char *argv[])
{
    menu menuG;

    //Llamado a clase Usuarios para el Login
    bool accesoUsuario;

    Usuario usuarioRegistrado;
    accesoUsuario=usuarioRegistrado.loginUsuario();
    if (accesoUsuario){menuG.menuGeneral();}
    system("cls");
    cout<<"** REGRESE PRONTO **";
    return 0;

}
