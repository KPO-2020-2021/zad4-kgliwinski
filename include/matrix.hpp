#pragma once
#include "vector.hpp"
#include <iostream>
#include <cstdlib>
/*!
 * \file  matrix.hpp
 *  
 *  Plik zawiera definicję klasy reprezentujacej macierz
 *  o wymiarach SIZExSIZE
 */



/*! \class Matrix
 *  \brief Opisuje macierz SIZExSIZE
 */
template<typename type, unsigned int SIZE>
class Matrix {

private:
    type value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(type [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    ~Matrix();                              // Destruktor klasy

    Vector<type,SIZE> operator * (Vector<type,SIZE> tmp);           // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp);

    Matrix operator - (Matrix tmp);

    bool operator == (Matrix const &tmp) const;

    type  &operator () (unsigned int row, unsigned int column);
    
    const type &operator () (unsigned int row, unsigned int column) const;

    Matrix gauss() const;

    type determinant() const;

    Matrix operator*(Matrix const &mat) const;

    void rotation_matrix(const type & angle);

    Matrix rotation_matrix(const type & angle, const char &axis) const;

    Vector<type,SIZE> apply_matrix_to_rotation(const Vector<type,SIZE> &rotation) const; //3D rotation
};

template<typename type, unsigned int SIZE>
std::istream &operator>>(std::istream &in, Matrix<type,SIZE> &mat);

template<typename type, unsigned int SIZE>
std::ostream &operator<<(std::ostream &out, Matrix<type,SIZE> const &mat);



/*!
 *  \brief Konstruktor klasy Matrix.                                                
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \param[out] Matrix jednostkowa                                       
 */
template<typename type, unsigned int SIZE>
Matrix<type,SIZE>::Matrix() {
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            if (i==j)
            value[i][j] = 1.0;
            else
            value[i][j] = 0.0;
        }
    }
}


/*!
 *  \brief Konstruktor parametryczny klasy Matrix.                                  
 *  Argumenty:                                                               
 *      \param[in] tmp - dwuwymiarowa tablica z elementami typu type.                 
 *  Zwraca:                                                                  
 *      \param[out] Matrix wypelniona wartosciami podanymi w argumencie.                
 */
template<typename type, unsigned int SIZE>
Matrix<type,SIZE>::Matrix(type tmp[SIZE][SIZE]) {
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}
/*!
 *  \brief Destruktor klasy Matrix.                                                 
 *  Argumenty:                                                               
 *      Brak argumentow.                                                     
 *  Zwraca:                                                                  
 *      \post Usuwa klase                                                          
 */
template<typename type, unsigned int SIZE>
Matrix<type,SIZE>::~Matrix(){
    //std::cout<<"Deleting matrix"<<std::endl;
}

/*!
 *  \brief Realizuje mnozenie macierzy przez wektor.                                
 *  Argumenty:                                                               
 *      \param[in] this - macierz, czyli pierwszy skladnik mnozenia,                    
 *      \param[in] tmp - wektor, czyli drugi skladnik mnozenia.                           
 *  Zwraca:                                                                  
 *      \param[out] result - Iloczyn dwoch skladnikow przekazanych jako wektor.                   
 */
template<typename type, unsigned int SIZE>
Vector<type,SIZE> Matrix<type,SIZE>::operator * (Vector<type,SIZE> tmp) {
    Vector<type,SIZE> result;
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/*!
 *  \brief Funktor macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] row - numer wiersza.                                                 
 *      \param[in] column - numer kolumny.                                              
 *  Zwraca:                                                                  
 *      \param[out] value Wartosc macierzy w danym miejscu tablicy.                            
 */
template<typename type, unsigned int SIZE>
type &Matrix<type,SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/*!
 *  \brief Funktor macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] row - numer wiersza.                                                 
 *      \param[in] column - numer kolumny.                                              
 *  Zwraca:                                                                  
 *      \param[out] Wartosc macierzy w danym miejscu tablicy jako stala.                 
 */
template<typename type, unsigned int SIZE>
const type &Matrix<type,SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/*!
 *  \brief Przeciążenie dodawania macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] this - macierz, czyli pierwszy skladnik dodawania,                    
 *      \param[in] v - wektor, czyli drugi skladnik dodawania.                                              
 *  Zwraca:                                                                  
 *      \param[out] Macierz - iloczyn dwóch podanych macierzy.                 
 */
template<typename type, unsigned int SIZE>
Matrix<type,SIZE> Matrix<type,SIZE>::operator + (Matrix<type,SIZE> tmp) {
    Matrix result;
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/*!
 *  \brief Przeciążenie odejmowania macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] this - macierz, czyli pierwszy skladnik dodawania,                    
 *      \param[in] v - wektor, czyli drugi skladnik dodawania.                                              
 *  Zwraca:                                                                  
 *      \param[out] Macierz - iloczyn dwóch podanych macierzy.                 
 */
template<typename type, unsigned int SIZE>
Matrix<type,SIZE> Matrix<type,SIZE>::operator - (Matrix<type,SIZE> tmp) {
    Matrix result;
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            result(i, j) = this->value[i][j] - tmp(i, j);
        }
    }
    return result;
}

/*!
 *  \brief Przeciazenie operatora >>                                                
 *  Argumenty:                                                               
 *      \param[in] in - strumien wejsciowy,                                             
 *      \param[in] mat - macierz. 
 *  Zwraca:
 *      \param[out] in - strumien wejsciowy                                                       
 */
template<typename type, unsigned int SIZE>
std::istream &operator>>(std::istream &in, Matrix<type,SIZE> &mat) {
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            in >> mat(i, j);
        }
    }
    return in;
}


/*!
 *  \brief Przeciazenie operatora <<                                                
 *  Argumenty:                                                               
 *      \param[in] out - strumien wyjsciowy,                                            
 *      \param[in] mat - macierz.     
 *  Zwraca:
 *      \param[out] out - strumien wyjsciowy                                                  
 */
template<typename type, unsigned int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<type,SIZE> &mat) {
    out.precision(10);
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            out << "| " <<std::setw(10) << std::fixed << std::setprecision(10) << mat(i, j) << " * "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}
/*!
 *  \brief Przeciążenie == macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] this - macierz, ktora porownujemy                   
 *      \param[in] tmp - macierz, z ktora porownujemy                                                          
 *  Zwraca:                                                                  
 *      \retval true - jesli sa rowne
 *      \retval false - jesli nie sa                
 */
template<typename type, unsigned int SIZE>
bool Matrix<type,SIZE>::operator == (Matrix<type,SIZE> const &tmp) const{
    unsigned int  i,j;
    for (i=0;i<SIZE;++i){
        for (j=0;j<SIZE;++j){
            if (!(abs(value[i][j]-tmp.value[i][j])<=0.000001))
                return 0;
        }
    }
    return 1;
}
/*!
 *  \brief Zwraca macierz schodkowa utworzona przez eliminacje gaussa                                                        
 *  Argumenty:                                                               
 *      \param[in] this - macierz dla ktorej chcemy przeprowadzic operacje                                                           
 *  Zwraca:                                                                  
 *      \param[out] mat - macierz schodkowa              
 */
template<typename type, unsigned int SIZE>
Matrix<type,SIZE> Matrix<type,SIZE>::gauss() const{
    Matrix mat = *this;

    unsigned int  i,j,k;
    type ratio;
    for (i=0;i<SIZE-1;i++){
        if (value[i][i] == 0)
            return 0;
        for (j=i+1; j<SIZE; j++){
            ratio = value[j][i] / value[i][i];
            for (k=0; k<SIZE; k++){
                mat.value[j][k] = (value[j][k] - ratio*value[i][k]);
            }
        }
    }
    return mat;
}
/*!
 *  \brief Zwraca wyznacznik macierzy                                                       
 *  Argumenty:                                                               
 *      \param[in] this - macierz, ktorej wyznacznik liczymy                                                             
 *  Zwraca:                                                                  
 *      \param[out] det - wyznacznik               
 */
template<typename type, unsigned int SIZE>
type Matrix<type,SIZE>::determinant() const{
    type det;
    unsigned int  i;
    Matrix tmp = this->gauss();
    det = 1;
    for (i=0;i<SIZE;++i){
        det*=tmp.value[i][i];
    }
    return det;
}

/*!
 *  \brief Zwraca wynik mnozenia dwoch macierzy                                                      
 *  Argumenty:                                                               
 *      \param[in] this - macierz 1 (L)
 *      \param mat - macierz 2 (P)                                                             
 *  Zwraca:                                                                  
 *      \param[out] res - wynik mnozenia macierzy               
 */
template<typename type, unsigned int SIZE>
Matrix<type,SIZE> Matrix<type,SIZE>::operator*(Matrix<type,SIZE> const &mat) const{
    unsigned int  i,j,k;
    Matrix res;
    for (i=0; i<SIZE; i++){
        res.value[i][i] = 0;    //zerowanie elementow macierzy ktore sa rowne 1 
                                //(z konstruktora bezparametrycznego)
    }
    for (i=0; i< SIZE; ++i){
        for (j=0; j< SIZE; ++j){
            for (k=0;k<SIZE;k++){
                res.value[i][j]+= value[i][k] * mat.value[k][j];
            }
        }
    }
    return res;
}


