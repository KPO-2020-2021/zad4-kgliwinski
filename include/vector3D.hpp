#pragma once

#include"vector.hpp"
#include"matrix3D.hpp"
typedef Vector<double, 3> Vector3D;


/******************************************************************************
 * Obrot wektora o zadane 3 katy wokol okreslonych osi (x,y,z) w 3D             
 * Argumenty:                                                                
 *      \param[in] roll - kat obrotu ( w stopniach ) wokol osi x
 *      \param[in] pitch - kat obrotu ( w stopniach ) wokol osi y
 *      \param[in] yaw - kat obrotu ( w stopniach ) wokol osi z                                   
 * Zwraca:                                                                   
 *      \param[out] rotated - obrocony wektor                                                      
 */
template <>
inline Vector<double, 3> Vector<double, 3>::rotate(const double &roll, const double &pitch, const double &yaw) const{

}