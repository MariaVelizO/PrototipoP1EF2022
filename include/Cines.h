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
            void menu();
                    void insert();
                    void display();
                    void modify();
                    void search();
                    void delet();
            Cines();
            virtual ~Cines();
    protected:
        private:
            std :: string id,name,direcc;


};


#endif // CINES_H
