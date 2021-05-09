#pragma once

#include "matrix.hpp"
#include "vector3D.hpp"
typedef Matrix<double, 3> Matrix3D;

/*!
 * Utowrzenie macierzy obrotu dla obrotu w 3D - przypisanie jej do danej macierzy             
 * Argumenty:                                                                
 *      \param[in] angle - kat obrotu w stopniach
 *      \param[in] axis - wybrana os obrotu (x,y lub z)                                
 * Zwraca:                                                                   
 *      \param[out] rotation - macierz transformacji                                                     
 */
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

/*!
 * \brief Obrot wektora o zadane 3 katy wokol okreslonych osi (x,y,z) w 3D             
 * Argumenty:                                                                
 *      \param[in] to_rot - Vector3D ktory chcemy obrocic                               
 * Zwraca:                                                                   
 *      \param[out] rotated - obrocony wektor                                                      
 */
template <>
inline Vector<double,3> Matrix<double,3>::apply_matrix_to_rotation(const Vector<double,3> &to_rot) const{
Vector3D tmp;

std::cout<<tmp<<to_rot;
return tmp;
}

