#pragma once

#include "matrix.hpp"

typedef Matrix<double, 3> Matrix3D;

/*!
 * Utowrzenie macierzy obrotu dla obrotu w 3D - przypisanie jej do danej macierzy             
 * Argumenty:                                                                
 *      \param[in] theta_rad - kat obrotu w stopniach                                 
 * Zwraca:                                                                   
 *      \param[out] this - przypisana do podanej macierzy macierz transformacji                                                     
 */
template <>
inline void Matrix<double, 3>::rotation_matrix(const double & x, const double & y, const double & z)
{
Matrix tmp;
double res = x*y*z;
std::cout<<res;
}
