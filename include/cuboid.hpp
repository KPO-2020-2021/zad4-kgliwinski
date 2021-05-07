#include"vector3D.hpp"
#include"matrix3D.hpp"

class Cuboid{
private:

Vector3D tops[2][4];

public:

Cuboid();

Cuboid(Vector3D const (&tab)[2][4]);

void get_cub(Vector3D (&tab)[2][4]);

Cuboid translation(Vector3D const &tran) const;

Cuboid translation() const;

};