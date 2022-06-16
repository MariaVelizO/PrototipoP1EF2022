#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

class Cines
{

        public:
            void menuCines();
                void NumeroId();
                void Nombre();
                void Direccion();



            virtual ~Cines();

    protected:
        private:

};

#endif // CINES_H
