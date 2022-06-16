#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;

class Usuario
{
    public:
        Usuario();

        virtual ~Usuario();
        bool loginUsuario();
        void menuUsuario();
        void obtenerUser(string);
        string userP;


    protected:

    private:
};

#endif // USUARIO_H
