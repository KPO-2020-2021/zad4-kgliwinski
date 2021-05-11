#include <iostream>
#include <stdlib.h>
#include <fstream>
#include"cuboid.hpp"
#include"lacze_do_gnuplota.hpp"


/*!
 * \file  menu_cub.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej menu obslugi
 *         menu dla obrotow 3D
 */

/*!
 *  \class Menu_cub
 *  \brief Opisuje menu dla obrotow 3D
 */
class Menu_cub{
    private:   
/*!
 * \brief Zmienna mowiaca czy menu jest aktywne
 */
    bool open;

/*!
 * \brief Macierz obrotu, ma sluzyc do zapisu i uzycia
 *        Macierz pozostanie w pamieci, dopoki uzytkownik
 *        nie zacznie definiowac nowej (nie zacznie wpisywac
 *        osi i katow
 */
    Matrix3D rotation_matrix;

    public:
/*!
 * \brief Konstruktor bezparametryczny menu
 */
    Menu_cub();
/*!
 *  \brief Inicjuje menu
 *  Argumenty:
 *      \param[in] - tablica double 2x4x3
 */
    void init_menu(double (&tab)[2][4][3]);

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] filename - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] cub - wyswietlany prostopadloscian
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool CuboidToFile(const char *filename, Cuboid const &cub);

/*!
 * \brief Wyswietla prostopadloscian w GNUplocie
 *  Argumenty:
 *      \param[in] cub - wyswietlany prostopadloscian
 */
void Print_to_gnuplot(Cuboid const &cub);
};