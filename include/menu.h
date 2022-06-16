#ifndef MENU_H
#define MENU_H

class menu
{
    public:
        menu();
        virtual ~menu();
        menuGeneral();
        menuCines();
        menuPeliculas();
        menuSalas();
        menuAsientos();
        menuClientes();

        int opcion;
    protected:

    private:
};

#endif // MENUS_H
