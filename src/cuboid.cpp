#include "cuboid.hpp"

Cuboid::Cuboid()
{
    int i;
    double iter[4][3] = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 1;
        tops[1][i] = Vector3D(iter[i]);
    }
}

Cuboid::Cuboid(Vector3D const (&tab)[2][4])
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
}

Cuboid::Cuboid(double (&tovec)[2][4][3])
{
    int i, j;
    Vector3D tab[2][4];
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            tab[0][i] = Vector3D(tovec[0][i]);
            tab[1][i] = Vector3D(tovec[1][i]);
        }
    }
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
}

bool Cuboid::check_cub(){
    if (!check_vec_opp() && !check_vec_perpendicular())
        return 0;
    return 1;
}

bool Cuboid::check_vec_opp(){

    return 1;
}

bool Cuboid::check_vec_perpendicular(){

    return 1;
}

std::ostream &operator<<(std::ostream &out, Cuboid const &Cub)
{
    out.precision(10);
    Vector3D vecs[2][4];
    Cub.get_cub(vecs);
    out << "Wierzcholek A: " << std::endl
        << vecs[0][0] << std::endl;
    out << "Wierzcholek B: " << std::endl
        << vecs[0][1] << std::endl;
    out << "Wierzcholek C: " << std::endl
        << vecs[0][2] << std::endl;
    out << "Wierzcholek D: " << std::endl
        << vecs[0][3] << std::endl;
    out << "Wierzcholek E: " << std::endl
        << vecs[1][0] << std::endl;
    out << "Wierzcholek F: " << std::endl
        << vecs[1][1] << std::endl;
    out << "Wierzcholek G: " << std::endl
        << vecs[1][2] << std::endl;
    out << "Wierzcholek H: " << std::endl
        << vecs[1][3] << std::endl;

    return out;
}

void Cuboid::get_cub(Vector3D (&tab)[2][4]) const
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        tab[0][i] = tops[0][i];
        tab[1][i] = tops[1][i];
    }
}

bool Cuboid::operator==(const Cuboid &cub) const
{
    int i, j;
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if (!(tops[i][j] == cub.tops[i][j]))
                return 0;
        }
    }
    return 1;
}

Cuboid Cuboid::translation(Vector3D const &tran) const
{
    int i, j;
    Cuboid translated;

    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            translated.tops[i][j] = tops[i][j] + tran;
        }
    }
    return translated;
}

Cuboid Cuboid::rotation(Matrix3D const &mat) const
{
    int i,j;
    Cuboid rotated;
    for (i=0;i<2; ++i){
        for (j=0;j<4; ++j){
            rotated.tops[i][j] = mat.apply_matrix_to_rotation(tops[i][j]);
        }
    }
    return rotated;
}