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

Cuboid();

Cuboid(Vector3D const (&tab)[2][4]);

Cuboid(double (&tovec)[2][4][3]);

void get_cub(Vector3D (&tab)[2][4]) const;

bool operator == (const Cuboid &cub) const;

Cuboid translation(Vector3D const &tran) const;

};

std::ostream &operator<<(std::ostream &out,  Cuboid const &Cub); //przeciazenie wyjscia