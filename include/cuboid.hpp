#include"vector3D.hpp"
#include"matrix3D.hpp"

/*!
 * \file  cuboid.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej prostopadloscian
 *  w przestrzeni trojwymiarowej
 */


/*!
 *  \class Cuboid
 *  \brief Opisuje prostopadloscian w przestrzeni trojwymiarowej
 */
class Cuboid{
private:

Vector3D tops[2][4];

public:

/*!
 *  \brief Konstruktor bezparametryczny klasy Cuboid.                                              
 *  Argumenty:                                                                
 *      Brak argumentow.                                                      
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow                                   
 */
Cuboid();

/*!
 *  \brief Konstruktor parametryczny klasy Cuboid.                                              
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x4 typu Vector3D                                                      
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow zadanych przez program                                  
 */
Cuboid(Vector3D const (&tab)[2][4]);

/*!
 *  \brief Konstruktor parametryczny klasy Cuboid.                                              
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x4x3 typu double                                                     
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow zadanych przez program                                  
 */
Cuboid(double (&tovec)[2][4][3]);

/*!
 *  \brief Metoda zwracajaca wierzcholki prostopadloscianu do Vector3D                                              
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x4 typu Vector3D                                                     
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow przechowywanych w klasie Cuboid i przypisuje je do podanej tablicy                                  
 */
void get_cub(Vector3D (&tab)[2][4]) const;

/*!
 *  \brief Przeciazenie operatora == dla klasy Cuboid                                                
 *  Argumenty:                                                                
 *      \param[in] cub - porownywany Cuboid                                             
 *  Zwraca:
 *      \retval false - nie sa rowne, 
 *      \retval true - sa rowne                                                     
 */
bool operator == (const Cuboid &cub) const;

/*!
 *  \brief Metoda przesuwajaca prostopadloscian o zadany kat w 3D                                            
 *  Argumenty:                                                                
 *      \param[in] trans - tablica 2x4 typu Vector3D                                                     
 *  Zwraca:                                                                   
 *     \param[out] translated - prostopadloscian po operacji przesuniecia                                
 */
Cuboid translation(Vector3D const &tran) const;

};

/*!
 *  \brief Przeciazenie operatora <<                                                 
 *  Argumenty:                                                                
 *      \param[in] out - strumien wyjsciowy,                                             
 *      \param[in] Cub - prostopadloscian.                                                      
 */
std::ostream &operator<<(std::ostream &out,  Cuboid const &Cub); //przeciazenie wyjscia