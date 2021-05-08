#pragma once


constexpr double PI = 3.14159265;
#include <iostream>
#include <cmath>
#include <iomanip>
/*!
 * \file  vector.hpp
 *  
 *  Plik zawiera definicję klasy reprezentujacej wektor
 *  o wymiarach SIZEx1
 */





/*! \class Vector
 *  \brief Opisuje wektor o SIZE-wierszach
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

    Vector rotate(const type &theta) const; //2D rotation

    Vector rotate(const type &roll, const type &pitch, const type &yaw) const; //3D rotation

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
/*!
 *  \brief Konstruktor klasy Vector.        
                                        
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

/*!
 *  \brief Konstruktor klasy Vector.                                                
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


/*!
 *  \brief Destruktor klasy Vector.                                                 
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \post Usuwa wektor                                                         
 */
 template <typename type, unsigned int SIZE> 
Vector<type,SIZE>::~Vector(){
    //std::cout<<"Deleting vector"<<std::endl;
}
/*!
 *  \brief Realizuje dodawanie dwoch wektorow.                                      
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

/*!
 *  \brief Realizuje odejmowanie dwoch wektorow.                                    
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

/*!
 *  \brief Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.              
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

/*!
 *  \brief Realizuje dzielenie dwoch wektorow.                                      
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
/*!
 *  \brief Sprawdza czy wektory sa rowne                                      
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

/*!
 *  \brief Funktor wektora.                                                         
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

/*!
 *  \brief Funktor wektora.                                                         
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

/*!
 *  \brief Przeciazenie operatora <<                                                
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

/*!
 *  \brief Przeciazenie operatora >>                                                
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
/*!
 * \brief Obrot wektora o kat theta wokol srodka ukladu wspolrzednych (zdefiniowano dla
 *      2D w vector2D.hpp              
 * Argumenty:                                                                
 *      \param[in] theta - kat obrotu ( w stopniach )                                   
 * Zwraca:                                                                   
 *      \param[out] rotated - zerowy wektor oraz ostrzezenie o bledzie                                                      
 */
 template <typename type, unsigned int SIZE> 
Vector<type,SIZE> Vector<type,SIZE>::rotate(const type &theta) const
{
    Vector rotated;
    std::cerr << "ERROR: Nie zdefiniowano macierzy obrotu dla przestrzeni innej niz dwu lub trojwymiarowa." << std::endl;
    return rotated;
}
/*!
 * \brief Zwraca kwadrat modulu wektora                                             
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
/*!
 * \brief Zwraca dlugosc wektora                                                    
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
    len = pow(mod2, 1.0 / 2);

    return len;
}

/*!
 * \brief Zwraca kat nachylenia wektora do osi x (zdefiniowany dla 2D w vector2D.hpp)                                    
 * Argumenty:                                                                
 *      Brak                                                                 
 * Zwraca:                                                                   
 *      \param[in] angle - kat nachylenia wektora do osi x                                                      
 */
 template <typename type, unsigned int SIZE> 
type Vector<type,SIZE>::get_slope_angle() const
{
    type angle;
    std::cerr << 
    "ERROR: Nie zdefiniowano kata nachylenia dla wektorow innych niz dwuwymiarowych."
    << std::endl;
    angle = 0;
    return angle;
}


