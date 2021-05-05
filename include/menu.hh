#pragma once

#include"rectangle.hh"
#include <iostream>


/*!
 * \file  mmenu.hh
 *  
 *  Plik zawiera definicję klasy reprezentujacej menu
 *  programu rysujacego figury 2D
 */


/*! \class Menu
 *  \brief Tworzy i obsluguje menu programu
 */
class menu{

    private:

    bool open;

    public:
    
    menu();

    void init_menu(Vector2D const (&tab)[4]);

    void show_menu();

    void switch_menu(const char &oper,Rectangle &rec);

};

