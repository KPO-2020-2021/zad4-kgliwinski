#pragma once
#include"../include/matrix3D.hpp"


template <>
inline Matrix<double,3> Matrix<double, 3>::rotation_matrix(const double & angle, const char &axis) const
{
switch (axis){
    case 'x':
    {
        double tab[3][3] = {{1,0         ,0          }, 
                            {0,cos(angle),-sin(angle)}, 
                            {0,sin(angle),cos(angle)}};
        Matrix3D rotation(tab);
        return rotation;
        break;
    }
    case 'y':
    {
        double tab[3][3] = {{cos(angle) ,0,sin(angle)},
                            {0          ,1,0         }, 
                            {-sin(angle),0,cos(angle)}};
        Matrix3D rotation(tab);
        return rotation;
        break;
    }
    case 'z':
    {
        double tab[3][3] = {{cos(angle),-sin(angle),0},
                            {sin(angle), cos(angle),0},
                            {0         ,0          ,1}};
        Matrix3D rotation(tab);
        return rotation;
        break;
    }
    default:
    {
        Matrix3D rotation; //utworzenie macierzy jednostkowej (aby nie zmieniala nic przy mnozeniu)
        return rotation;   //brak komunikatu bledu, znajdzie sie on w menu
        break;
    }
}
}

template <>
inline Vector<double,3> Matrix<double,3>::apply_matrix_to_rotation(const Vector<double,3> &to_rot) const{
Matrix3D mat = *this;
Vector3D tmp ;

tmp = mat * to_rot;

return tmp;
}