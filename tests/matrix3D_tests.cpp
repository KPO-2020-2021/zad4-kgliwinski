#include"../tests/doctest/doctest.h"
#include"matrix3D.hpp"
#include"vector3D.hpp"

TEST_CASE("M 1.01: konstruktor bezparametryczny i przeciazenie operatorow << >>"){
    //double tab[3][3] = {{3,1}};
    Matrix3D a;
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 1.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 1.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 1.0000000000 * ");
}

TEST_CASE("M 1.02: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[3][3] = {{3,1,0},{3,1,0},{3,1,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 3.0000000000 * | 1.0000000000 * | 0.0000000000 * | 3.0000000000 * | 1.0000000000 * | 0.0000000000 * | 3.0000000000 * | 1.0000000000 * | 0.0000000000 * ");
}

TEST_CASE("M 1.03: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[3][3] = {{0.0003,0.0001,0},{0.0003,0.0001,0},{0.0003,0.0001,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 0.0003000000 * | 0.0001000000 * | 0.0000000000 * | 0.0003000000 * | 0.0001000000 * | 0.0000000000 * | 0.0003000000 * | 0.0001000000 * | 0.0000000000 * ");
}

TEST_CASE("M 1.04: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[3][3] = {{-0.0003,0.0001,0},{0.0003,-0.0001,0},{0,0,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| -0.0003000000 * | 0.0001000000 * | 0.0000000000 * | 0.0003000000 * | -0.0001000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * ");
}

TEST_CASE("M 1.05: konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * ");
}

TEST_CASE("M 1.06:  przeciazenie operatorow << >>"){
    double tab[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    Matrix3D a(tab);
    std::istringstream in("1 2 3 4 5 6 7 8 9");
    in >> a;
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 1.0000000000 * | 2.0000000000 * | 3.0000000000 * | 4.0000000000 * | 5.0000000000 * | 6.0000000000 * | 7.0000000000 * | 8.0000000000 * | 9.0000000000 * ");
}

TEST_CASE("M 2.01: operator * (vector)"){
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    double vec[3] = {1,2,3};
    Matrix3D a(tab);
    Vector3D b(vec);

    Vector3D c(vec);

    CHECK (c==(a*b));
}

TEST_CASE("M 2.02: operator * (vector) zero"){
    double tab[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    double vec[3] = {0,0,0};
    Matrix3D a(tab);
    Vector3D b(vec);

    Vector3D c(vec);

    CHECK (c==(a*b));
}

TEST_CASE("M 2.03: operator * (vector) neg"){
    double tab[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    double vec[3] = {1,-1,1};
    double res[3] = {2,5,8};
    Matrix3D a(tab);
    Vector3D b(vec);

    Vector3D c(res);

    CHECK (c==(a*b));
}

TEST_CASE("M 3.01: operator +"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double tab2[3][3] = {{4,3,0},{2,1,0},{0,0,0}};
    double res[3][3] = {{5,5,0},{5,5,0},{0,0,0}};

    Matrix3D a(tab);
    Matrix3D b(tab2);

    Matrix3D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("M 3.02: operator + 0"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double tab2[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    double res[3][3] = {{1,2,0},{3,4,0},{0,0,0}};

    Matrix3D a(tab);
    Matrix3D b(tab2);

    Matrix3D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("M 3.03: operator + small"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double tab2[3][3] = {{0.0000000001,0.0000000001,0},{0.0000000001,0.0000000001,0},{0,0,0}};
    double res[3][3] = {{1.0000000001,2.0000000001,0},{3.0000000001,4.0000000001,0},{0,0,0}};

    Matrix3D a(tab);
    Matrix3D b(tab2);

    Matrix3D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("M 4.01: operator ()"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double res = 1;

    Matrix3D a(tab);

    CHECK (res == a(0,0));
}

TEST_CASE("M 4.02: operator ()"){
    double tab[3][3] = {{1,0.00002,0},{3,4,0},{0,0,0}};
    double res = 0.00002;

    Matrix3D a(tab);

    CHECK (res == a(0,1));
}

TEST_CASE("M 4.03: operator ()"){
    double tab[3][3] = {{1,2,0},{-3,4,0},{0,0,0}};
    double res = -3;

    Matrix3D a(tab);

    CHECK (res == a(1,0));
}

TEST_CASE("M 4.04: operator ()"){
    double tab[3][3] = {{1,2,0},{-3,0,0},{0,0,0}};
    double res = 0;

    Matrix3D a(tab);

    CHECK (res == a(1,1));
}

TEST_CASE("Mod 1.01: Matrix3D::gauss()"){
    double tab[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    double tab2[3][3] = {{1,2,3},{0,-3,-6},{0.6,0,-0.6}};
    Matrix3D a(tab);
    Matrix3D b(tab2);

    CHECK ((a.gauss()) == b);
}

TEST_CASE("Mod 1.02: Matrix3D::gauss() 2"){
    double tab[3][3] = {{3,2},{3,4}};
    double tab2[3][3] = {{3,2},{0,2}};
    Matrix3D a(tab);
    Matrix3D b(tab2);

    CHECK ((a.gauss()) == b);
}

TEST_CASE("Mod 1.03: Matrix3D::determinant() 1"){
    double tab[3][3] = {{1,2},{3,4}};
    Matrix3D a(tab);
    double det; 
    det = 0;
    CHECK ((a.determinant()) == det);
}

TEST_CASE("Mod 1.03: Matrix3D::determinant() 2"){
    double tab[3][3] = {{3,2},{3,4}};
    Matrix3D a(tab);
    double det; 
    det = 0;
    CHECK ((a.determinant()) == det);
}

TEST_CASE("Mod 2.01: Matrix3D::multiply() 1"){
    double tab[3][3] = {{3,2},{3,4}};
    Matrix3D a(tab);  //macierz jednostkowa
    Matrix3D b;
    double tab_res[3][3] = {{3,2},{3,4}};
    Matrix3D res(tab_res);
    CHECK (a*b == res);
}

TEST_CASE("Mod 2.02: Matrix3D::multiply() 2"){
    double tab[3][3] = {{1,2},{3,4}};
    Matrix3D a(tab);  //macierz jednostkowa
    Matrix3D b(tab);
    double tab_res[3][3] = {{7,10},{15,22}};
    Matrix3D res(tab_res);
    CHECK (a*b == res);
}

TEST_CASE("Mod 2.03: Matrix3D::multiply() 3"){
    double tab[3][3] = {{-1,0},{12,4}};
    double tab2[3][3] = {{12,7},{1,5}};
    Matrix3D a(tab);  //macierz jednostkowa
    Matrix3D b(tab2);
    double tab_res[3][3] = {{-12,-7},{148,104}};
    Matrix3D res(tab_res);
    CHECK (a*b == res);
}