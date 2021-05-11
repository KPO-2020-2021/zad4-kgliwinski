#include "../include/menu_cub.hpp"

Menu_cub::Menu_cub()
{
    open = 1;
}

void Menu_cub::init_menu(double (&tab)[2][4][3])
{
    Cuboid cub(tab);
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polozenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Menu_cub::CuboidToFile(const char *filename, Cuboid const &cub)
{
    std::ofstream filestrm;

    filestrm.open(filename);
    if (!filestrm.is_open())
    {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << filename << "\"" << std::endl
                  << ":(  nie powiodla sie." << std::endl;
        return false;
    }
    std::ostringstream out;
    cub.print_cuboid(filestrm);

    filestrm.close();
    return !filestrm.fail();
}

void Menu_cub::Print_to_gnuplot(Cuboid const &cub){
    PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji

       Lacze.DodajNazwePliku("../datasets/cuboid.dat", PzG::RR_Ciagly, 2);

       Lacze.DodajNazwePliku("../datasets/cuboid.dat", PzG::RR_Punktowy, 2);

       Lacze.ZmienTrybRys(PzG::TR_3D);
           cub.print_cuboid(std::cout);
       if (!this->CuboidToFile("../datasets/cuboid.dat",cub))
              std::cerr << "ERROR" << std::endl;
       Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000, '\n');
}