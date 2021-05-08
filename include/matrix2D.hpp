#pragma once

#include "matrix.hpp"

typedef Matrix<double, 2> Matrix2D;

/*!****
 * Utowrzenie macierzy obrotu dla obrotu w 2D - przypisanie jej do danej macierzy             
 * Argumenty:                                                                
 *      \param[in] theta_rad - kat obrotu w stopniach                                 
 * Zwraca:                                                                   
 *      \param[out] this - przypisana do podanej macierzy macierz transformacji                                                     
 */
template <>
inline void Matrix<double, 2>::rotation_matrix(const double &angle)
{
    double angle_rad = angle * PI / 180;
    double tmp[][2] = {{cos(angle_rad), -sin(angle_rad)}, {sin(angle_rad), cos(angle_rad)}};
    Matrix2D transformation(tmp);
    *this = transformation;
}
