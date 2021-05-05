#pragma once

#include "size.hpp"

#include <iostream>
#include <cmath>
#include <iomanip>
/*!
 * \file  vector.hh
 *  
 *  Plik zawiera definicję klasy reprezentujacej wektor
 *  o wymiarach SIZEx1
 */





/*! \class Vector
 *  \brief Opisuje wektor o n-wierszach
 */

template <typename type, unsigned int SIZE> 
class Vector {

private:

    type size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(type [SIZE]);

    ~Vector();

    Vector operator + (const Vector &v) const;

    Vector operator - (const Vector &v) const;

    Vector operator * (const type &tmp) const;

    Vector operator / (const type &tmp) const;

    bool operator == (const Vector &v) const;

    Vector rotate(const type &theta) const;

    type modulus2() const;

    type get_len() const;

    type get_slope_angle() const;

    const type &operator [] (unsigned int index) const;

    type &operator [] (unsigned int index);

};

template <typename type, unsigned int SIZE> 
std::ostream &operator << (std::ostream &out, Vector<type,SIZE> const &tmp);

template <typename type, unsigned int SIZE> 
std::istream &operator >> (std::istream &in, Vector<type,SIZE> &tmp);

#include "matrix.hpp"
/******************************************************************************
 *  Konstruktor klasy Vector.        
                                        
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \param[out] this -  Wektory wypelniony wartoscia 0.                                      
 */
template <typename type, unsigned int SIZE> 
Vector<type,SIZE>::Vector()
{
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        size[i] = 0.0;
    }
}

/******************************************************************************
 *  Konstruktor klasy Vector.                                                
 *  Argumenty:                                                               
 *      \param[in] tmp - Jednowymiarowa tablica typu zz.                            
 *  Zwraca:                                                                  
 *      \param[in] this - Tablice wypelniona wartosciami podanymi w argumencie.                
 */
template <typename type, unsigned int SIZE> 
Vector<type,SIZE>::Vector(type tmp[SIZE])
{
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        size[i] = tmp[i];
    }
}


/******************************************************************************
 *  Destruktor klasy Vector.                                                 
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \post Usuwa wektor                                                         
 */
 template <typename type, unsigned int SIZE> 
Vector<type,SIZE>::~Vector(){
    //std::cout<<"Deleting vector"<<std::endl;
}
/******************************************************************************
 *  Realizuje dodawanie dwoch wektorow.                                      
 *  Argumenty:                                                               
 *      \param[in] this - pierwszy skladnik dodawania,                                  
 *      \param[in] v - drugi skladnik dodawania.                                        
 *  Zwraca:                                                                  
 *      \param[out] result - Sume dwoch skladnikow przekazanych jako wskaznik                     
 *      na parametr.                                                         
 */
 template <typename type, unsigned int SIZE> 
Vector<type,SIZE> Vector<type,SIZE>::operator+(const Vector<type,SIZE> &v) const
{
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] + v[i];
    }
    return result;
}

/******************************************************************************
 *  Realizuje odejmowanie dwoch wektorow.                                    
 *  Argumenty:                                                               
 *      \param[in] this - pierwszy skladnik odejmowania,                                
 *      \param[in] v - drugi skladnik odejmowania.                                      
 *  Zwraca:                                                                  
 *      \param[in] result - Roznice dwoch skladnikow przekazanych jako wskaznik                  
 *      na parametr.                                                         
 */
 template <typename type, unsigned int SIZE> 
Vector<type,SIZE> Vector<type,SIZE>::operator - (const Vector<type,SIZE> &v) const
{
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] - v[i];
    }
    return result;
}

/******************************************************************************
 *  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.              
 *  Argumenty:                                                               
 *      \param[in] this - pierwszy skladnik mnozenia (wektor),                          
 *      \param[in] v - drugi skladnik mnozenia (liczba typu type).                    
 *  Zwraca:                                                                  
 *      \param[in] result - Iloczyn dwoch skladnikow przekazanych jako wskaznik                  
 *      na parametr.                                                         
 */
 template <typename type, unsigned int SIZE> 
Vector<type,SIZE> Vector<type,SIZE>::operator*(const type &tmp) const
{
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] * tmp;
    }
    return result;
}

/******************************************************************************
 *  Realizuje dzielenie dwoch wektorow.                                      
 *  Argumenty:                                                               
 *      \param[in] this - licznik dzielenia,                                            
 *      \param[in] v - mianownik dzielenia.                                             
 *  Zwraca:                                                                  
 *      \param[in] result - Iloraz dwoch skladnikow przekazanych jako wskaznik                   
 *      na parametr.                                                         
 */
 template <typename type, unsigned int SIZE> 
Vector<type,SIZE> Vector<type,SIZE>::operator/(const type &tmp) const
{
    Vector result;
    if (tmp==0){
        std::cerr << "ERROR: Nie mozna dzielic przez 0" << std::endl;
        return *this;
    }
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] / tmp;
    }

    return result;
}
/******************************************************************************
 *  Sprawdza czy wektory sa rowne                                      
 *  Argumenty:                                                               
 *      \param[in] this - l,                                            
 *      \param[in] v - r.                                             
 *  Zwraca:                                                                  
 *     \retval true - sa rowne
 *     \retval false - nie sa rowne                                                        
 */
 template <typename type, unsigned int SIZE> 
bool  Vector<type,SIZE>::operator == (const Vector<type,SIZE> &v) const{
    unsigned int i;
    for (i=0;i<SIZE;i++){
        if (!((abs(size[i] - v.size[i]) <= 0.000001)))
            return 0;
    }
    return 1;
}

/******************************************************************************
 *  Funktor wektora.                                                         
 *  Argumenty:                                                               
 *      \param[in] index - index wektora.                                               
 *  Zwraca:                                                                  
 *      \param[in] size - Wartosc wektora w danym miejscu tablicy jako stala.                  
 */
 template <typename type, unsigned int SIZE> 
const type &Vector<type,SIZE>::operator[](unsigned int index) const
{
    if (index < 0 || index >= SIZE)
    {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}

/******************************************************************************
 *  Funktor wektora.                                                         
 *  Argumenty:                                                               
 *      \param[in] index - index wektora.                                               
 *  Zwraca:                                                                  
 *      \param[in] Vector - Wartosc wektora w danym miejscu tablicy.                             
 */
 template <typename type, unsigned int SIZE> 
type &Vector<type,SIZE>::operator[](unsigned int index)
{
    return const_cast<type &>(const_cast<const Vector *>(this)->operator[](index));
}

/******************************************************************************
 *  Przeciazenie operatora <<                                                
 *  Argumenty:                                                               
 *      \param[in] out - strumien wyjsciowy,                                            
 *      \param[in] tmp - wektor.   
 *  Zwraca:
 *      \param[out] out - strumien wyjsciowy                                                     
 */
 template <typename type, unsigned int SIZE> 
std::ostream &operator<<(std::ostream &out, Vector<type,SIZE> const &tmp)
{
    out.precision(10);
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        out << "[ " ;
        out << std::setw(10) << std::fixed << std::setprecision(10) << tmp[i];
        out << " ]\n";
    }
    return out;
}

/******************************************************************************
 *  Przeciazenie operatora >>                                                
 *  Argumenty:                                                               
 *      \param[in] in - strumien wejsciowy,                                             
 *      \param[in] tmp - wektor.   
 *  Zwraca:
 *      \param[out] in - strumien wejsciowy                                                     
 */
 template <typename type, unsigned int SIZE> 
std::istream &operator>>(std::istream &in, Vector<type,SIZE> &tmp)
{
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

/******************************************************************************
 * Obrot wektora o kat theta wokol srodka ukladu wspolrzednych               
 * Argumenty:                                                                
 *      \param[in] theta - kat obrotu ( w stopniach )                                   
 * Zwraca:                                                                   
 *      \param[out] rotated - obrocony wektor                                                      
 */
 template <typename type, unsigned int SIZE> 
Vector<type,SIZE> Vector<type,SIZE>::rotate(const type &theta) const
{
    Vector rotated;
    type theta_rad = theta * PI / 180;
    if (SIZE == 2)
    {
        type tmp[][SIZE] = {{cos(theta_rad), -sin(theta_rad)}, {sin(theta_rad), cos(theta_rad)}};
        Matrix<type,SIZE> transformation(tmp);
        rotated = transformation * *this;
    }
    else
    {
        std::cerr << "ERROR: Nie zdefiniowano macierzy obrotu dla przestrzeni innej niz dwuwymiarowa." << std::endl;
    }
    return rotated;
}

/******************************************************************************
 * Zwraca kwadrat modulu wektora                                             
 * Argumenty:                                                                
 *      Brak                                                                 
 * Zwraca:                                                                   
 *      \param[out] result - kwadrat modulu wektora                                               
 */
 template <typename type, unsigned int SIZE> 
type Vector<type,SIZE>::modulus2() const
{
    unsigned int i;
    type result=0;

    for (i = 0; i < SIZE; i++)
    {
        result += pow(size[i], 2);
    }
    return result;
}
/******************************************************************************
 * Zwraca dlugosc wektora                                                    
 * Argumenty:                                                                
 *      Brak                                                                 
 * Zwraca:                                                                   
 *      \param[out] len - dlugosc wektora                                                      
 */
 template <typename type, unsigned int SIZE> 
type Vector<type,SIZE>::get_len() const
{
    type len, mod2;
    Vector tmp;
    tmp = *this;
    mod2 = tmp.modulus2();
    len = pow(mod2, 1.0 / SIZE);

    return len;
}

/******************************************************************************
 * Zwraca kat nachylenia wektora do osi x                                    
 * Argumenty:                                                                
 *      Brak                                                                 
 * Zwraca:                                                                   
 *      \param[in] angle - kat nachylenia wektora do osi x                                                      
 */
 template <typename type, unsigned int SIZE> 
type Vector<type,SIZE>::get_slope_angle() const
{
    type angle;
    if (SIZE == 2)
    {
        angle = atan2(size[1], size[0]);
        angle *= 180 / PI;
    }
    else
    {
    std::cerr << 
    "ERROR: Nie zdefiniowano kata nachylenia dla wektorow innych niz dwuwymiarowych."
    << std::endl;
    angle = 0;
    }
    return angle;
}


