#pragma once
constexpr int SIZE = 2;
#include "vector2D.hpp"
#include "size.hpp"
#include "lacze_do_gnuplota.hpp"
#include "matrix.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>


/*!
 * \file  rectangle.hh
 *  
 *  Plik zawiera definicję klasy reprezentujacej prostokat
 *  w przestrzeni dwuwymiarowej
 */



/*! \class Rectangle
 *  \brief Opisuje prostokat w przestrzeni dwuwymiarowej
 */
class Rectangle{

Vector2D top[4]; //wierzcholki prostokata

public:
//konstruktor bezparametryczny
Rectangle(); 
//konstruktor parametryczny
Rectangle(Vector2D const (&tab)[4]); 
//destruktor bezparametrryczny
~Rectangle();   
//metoda translacji (z zadanym wektorem)
Rectangle translation(Vector2D const &tran) const; 
//metoda translacji (pyta o wektor)
Rectangle translation() const; 
//metoda obrotu (z zadanym katem)
Rectangle rotate(const double &theta) const; 
//metoda obrotu (pyta o kat)
Rectangle rotate() const;   
//zwraca prostokat
void get_rect( Vector2D ((&tab)[4])) const;   
//sprawdza dlugosci przeciwnych bokow
bool check_len_opp(Vector2D const (&vecs)[4]) const;  
 //sprawdza katy wewnetrzne
bool check_angle_rec(Vector2D const (&vecs)[4]) const;   
//sprawdza czy katy proste
bool check_angle_straight(double ang) const;    
//sprawdza katy i boki
bool check_rec() const; 
//zapisuje wierzcholki do wyjscia
void RectangleToStdout(std::ostream &StrmWy);   
//obraca n razy
Rectangle rotation_n_times();   
//zapisuje wierzcholki do pliku
bool RectangleToFile(const char *sNazwaPliku);  
//wyswietla w gnuplocie
void PrintRectangle();  

bool operator == (const Rectangle &rec) const;
};

std::ostream &operator<<(std::ostream &out,  Rectangle const &Rec); //przeciazenie wyjscia