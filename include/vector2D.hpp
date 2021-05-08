#pragma once

#include "vector.hpp"
#include "matrix2D.hpp"

typedef Vector<double, 2> Vector2D;

/*!
 * \brief Obrot wektora o kat theta wokol srodka ukladu wspolrzednych               
 * Argumenty:                                                                
 *      \param[in] theta - kat obrotu ( w stopniach )                                   
 * Zwraca:                                                                   
 *      \param[out] rotated - obrocony wektor                                                      
 */
template <>
inline Vector<double, 2> Vector<double, 2>::rotate(const double &theta) const
{
    Vector2D rotated;
    Matrix2D transformation;
    transformation.rotation_matrix(theta);
    rotated = transformation * *this;
    return rotated;
}

/*!
 * \brief Zwraca kat nachylenia wektora do osi x                                    
 * Argumenty:                                                                
 *      Brak                                                                 
 * Zwraca:                                                                   
 *      \param[in] angle - kat nachylenia wektora do osi x                                                      
 */
template <>
inline double Vector<double,2>::get_slope_angle() const
{
    double angle;
        angle = atan2(size[1], size[0]);
        angle *= 180 / PI;

    return angle;
}
