#include"../tests/doctest/doctest.h"
#include"rectangle.hpp"

TEST_CASE("R 1.01: konstruktor bezparametryczny prostokata i przeciazenie operatorow << >>"){
    //double tab[2][2] = {{3,1}};
    Rectangle a;
    Rectangle b;
    std::ostringstream out;
    out << a; // 
    std::ostringstream out2;
    out2 << b; // 

    CHECK (out.str() == out2.str());
}

TEST_CASE("R 1.02: konstruktor parametryczny prostokata i przeciazenie operatorow << >>"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector2D a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector2D(args[i]);
       } 
    Rectangle a(a1);
    Rectangle b(a1);
    std::ostringstream out;
    out << a; // 
    std::ostringstream out2;
    out2 << b; // 

    CHECK (out.str() == out2.str());
}

TEST_CASE("R 1.03: konstruktor parametryczny prostokata i przeciazenie operatorow << >>"){
    double args[4][2]= {{200.0, 300.0},{300.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector2D a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector2D(args[i]);
       } 
    Rectangle a(a1);
    Rectangle b(a1);
    std::ostringstream out;
    out << a; // 
    std::ostringstream out2;
    out2 << b; // 

    CHECK (out.str() == out2.str());
}

TEST_CASE("R 2.01: Rectangle::translate"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector2D a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector2D(args[i]);
       } 
    Rectangle a(a1);
    double args2[4][2]= {{200.0, 500.0},{200.0, 400.0},{400.0, 400.0},{400.0, 500.0}};
       Vector2D a2[4];
       for (int i=0;i<4;i++){
              a2[i]=Vector2D(args2[i]);
       } 
       Rectangle b(a2);
    double tab[2] = {100,100};
    Vector2D trans(tab);

    CHECK (a.translation(trans) == b);
}

TEST_CASE("R 2.02: Rectangle::translate neg"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector2D a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector2D(args[i]);
       } 
    Rectangle a(a1);
    double args2[4][2]= {{0, 300.0},{0, 200.0},{200.0, 200.0},{200.0, 300.0}};
       Vector2D a2[4];
       for (int i=0;i<4;i++){
              a2[i]=Vector2D(args2[i]);
       } 
       Rectangle b(a2);
    double tab[2] = {-100,-100};
    Vector2D trans(tab);

    CHECK (a.translation(trans) == b);
}

TEST_CASE("R 2.03: Rectangle::translate diff"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector2D a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector2D(args[i]);
       } 
    Rectangle a(a1);
    double args2[4][2]= {{0, 350.0},{0, 250.0},{200.0, 250.0},{200.0, 350.0}};
       Vector2D a2[4];
       for (int i=0;i<4;i++){
              a2[i]=Vector2D(args2[i]);
       } 
       Rectangle b(a2);
    double tab[2] = {-100,-50};
    Vector2D trans(tab);

    CHECK (a.translation(trans) == b);
}

TEST_CASE("R 3.01: Rectangle::rotate"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector2D a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector2D(args[i]);
       } 
    Rectangle a(a1);
    double args2[4][2]= {{-100.0, -400.0},{-100.0, -300.0},{-300.0, -300.0},{-300.0, -400.0}};
       Vector2D a2[4];
       for (int i=0;i<4;i++){
              a2[i]=Vector2D(args2[i]);
       } 
       Rectangle b(a2);
    double ang = 180;


    CHECK (a.rotate(ang) == b);
}

TEST_CASE("R 3.02: Rectangle::rotate"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector2D a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector2D(args[i]);
       } 
    Rectangle a(a1);
    double args2[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector2D a2[4];
       for (int i=0;i<4;i++){
              a2[i]=Vector2D(args2[i]);
       } 
       Rectangle b(a2);
    double ang = 360;


    CHECK (a.rotate(ang) == b);
}

TEST_CASE("R 4.01: Rectangle::check true"){
    double args[4][2]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector2D a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector2D(args[i]);
       } 
    Rectangle a(a1);
    CHECK (a.check_rec()==1);
}

TEST_CASE("R 4.02: Rectangle::check false"){
    double args[4][2]= {{000.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector2D a1[4];
       for (int i=0;i<4;i++){
              a1[i]=Vector2D(args[i]);
       } 
    Rectangle a(a1);
    CHECK (a.check_rec()==1);
}