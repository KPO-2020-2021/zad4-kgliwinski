#include "../tests/doctest/doctest.h"
#include "cuboid.hpp"

TEST_CASE("C 1.01: konstruktor bezparametryczny prostopadloscianu i przeciazenie operatora <<")
{
    //double tab[2][2] = {{3,1}};
    Cuboid a;
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("C 1.02: konstruktor parametryczny prostopadloscianu (przeciazenie z double) i przeciazenie operatora <<")
{
    int i, j, k;
    double tab[2][4][3];
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                tab[i][j][k] = 1.0;
            }
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("C 1.03: konstruktor parametryczny prostopadloscianu (przeciazenie z Vector3D) i przeciazenie operatora <<")
{
    int i, j;
    double tab_vec[3] = {1, 2, 3};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("C 1.03: konstruktor parametryczny prostopadloscianu (przeciazenie z Vector3D) i przeciazenie operatora << small")
{
    int i, j;
    double tab_vec[3] = {0.0000000001, 0.0000000002, 0.0000000003};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";

    CHECK(out.str() == out2.str());
}

TEST_CASE("C 1.04: konstruktor parametryczny prostopadloscianu (przeciazenie z double) i przeciazenie operatora <<")
{
    int i, j, k;
    double tab[2][4][3];
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                tab[i][j][k] = -1.0;
            }
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("C 1.05: operator == dla klasy Cuboid")
{
    Cuboid a, b;

    CHECK(a == b);
}

TEST_CASE("C 1.06: operator == dla klasy Cuboid false")
{
    Cuboid a;
    int i, j;
    double tab_vec[3] = {1, 2, 3};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid b(tab);
    CHECK(!(a == b));
}

TEST_CASE("C 2.01: Cuboid::get_cub()")
{
    int i, j;
    double tab_vec[3] = {1, 2, 3};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    Vector3D tab2[2][4];
    a.get_cub(tab2);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            CHECK(tab[i][j] == tab2[i][j]);
        }
    }
}

TEST_CASE("C 2.02: Cuboid::get_cub() small")
{
    int i, j;
    double tab_vec[3] = {0.0000000001, 0.0000000002, 0.0000000003};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    Vector3D tab2[2][4];
    a.get_cub(tab2);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            CHECK(tab[i][j] == tab2[i][j]);
        }
    }
}

TEST_CASE("C 2.03: Cuboid::get_cub() negative")
{
    int i, j;
    double tab_vec[3] = {-1, -2, -3};
    Vector3D tab[2][4];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    Vector3D tab2[2][4];
    a.get_cub(tab2);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            CHECK(tab[i][j] == tab2[i][j]);
        }
    }
}

TEST_CASE("C 3.01: Cuboid::translation(Vector3D)")
{
    Cuboid a;
    double tab[3] = {1, 2, 3};
    Vector3D tran(tab);
    Cuboid c = a.translation(tran);
    double tab2[2][4][3] = {{{1, 2, 3}, {2, 2, 3}, {2, 3, 3}, {1, 3, 3}}, {{1, 2, 4}, {2, 2, 4}, {2, 3, 4}, {1, 3, 4}}};
    Cuboid b(tab2);
    CHECK(c == b);
}

TEST_CASE("C 3.02: Cuboid::translation(Vector3D) negative")
{
    Cuboid a;
    double tab[3] = {-1, -2, -3};
    Vector3D tran(tab);
    Cuboid c = a.translation(tran);
    double tab2[2][4][3] = {{{-1, -2, -3}, {0, -2, -3}, {0, -1, -3}, {-1, -1, -3}}, {{-1, -2, -2}, {0, -2, -2}, {0, -1, -2}, {-1, -1, -2}}};
    Cuboid b(tab2);
    CHECK(c == b);
}

TEST_CASE("C 4.01: Cuboid::rotation(Matrix3D) 1")
{
    Cuboid a;
    double tab[3] = {-1, -2, -3};
    Vector3D tran(tab);
    Cuboid c = a.translation(tran);
    double tab2[2][4][3] = {{{-1, -2, -3}, {0, -2, -3}, {0, -1, -3}, {-1, -1, -3}}, {{-1, -2, -2}, {0, -2, -2}, {0, -1, -2}, {-1, -1, -2}}};
    Cuboid b(tab2);
    CHECK(c == b);
}

TEST_CASE("C 5.01: Cuboid:get_vec_opp i check_vec_opp")
{
    int i;
    Cuboid a;
    Vector3D opp[3][2];
    a.get_vec_opp(opp);
    double tab[3][3] = {{1, 0, 0}, {0, 0, 1}, {0, 1, 0}};
    Vector3D vec[3];
    for (i = 0; i < 3; ++i)
    {
        vec[i] = Vector3D(tab[i]);
    }
    for (i = 0; i < 3; ++i)
    {
        CHECK(opp[i][0] == opp[i][1]);
        CHECK(opp[i][1] == vec[i]);
    }
    CHECK(a.check_vec_opp());
}

TEST_CASE("C 5.02: Cuboid:get_vec_opp i check_vec_opp 2")
{
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    Vector3D opp[3][2];
    a.get_vec_opp(opp);
    double tab[3][3] = {{2, 0, 0}, {0, 0, 2}, {0, 2, 0}};
    Vector3D vec[3];
    for (i = 0; i < 3; ++i)
    {
        vec[i] = Vector3D(tab[i]);
    }
    for (i = 0; i < 3; ++i)
    {
        CHECK(opp[i][0] == opp[i][1]);
        CHECK(opp[i][1] == vec[i]);
    }
    CHECK(a.check_vec_opp());
}

TEST_CASE("C 5.03: Cuboid:get_vec_opp i check_vec_opp 3")
{
    int i;
    Vector3D tops[2][4];
    double iter[4][3] = {{-2, -2, 0}, {0, -2, 0}, {0, 0, 0}, {-2, 0, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    Vector3D opp[3][2];
    a.get_vec_opp(opp);
    double tab[3][3] = {{2, 0, 0}, {0, 0, 2}, {0, 2, 0}};
    Vector3D vec[3];
    for (i = 0; i < 3; ++i)
    {
        vec[i] = Vector3D(tab[i]);
    }
    for (i = 0; i < 3; ++i)
    {
        CHECK(opp[i][0] == opp[i][1]);
        CHECK(opp[i][1] == vec[i]);
    }
    CHECK(a.check_vec_opp());
}

TEST_CASE("C 6.01: Cuboid:get_vec_par i check_vec_par 1")
{
    int i,j;
    Vector3D tops[2][4];
    /*double iter[4][3] = {{-2, -2, 0}, {0, -2, 0}, {0, 0, 0}, {-2, 0, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);*/
    Cuboid a;
    double tab[3][3] = {{0,1,0},{0,0,1},{-1,0,0}};
    Vector3D par[2][3];
    for (i=0;i<3;++i){
        par[0][i] = Vector3D(tab[i]);
        par[1][i] = Vector3D(tab[i]);
    }

    Vector3D res[2][3];
    a.get_vec_perp(res);
    for (i=0;i<2;++i){
        for (j=0;j<3;++j){
            CHECK (res[i][j] == par[i][j]);
        }
    }

}

TEST_CASE("C 6.02: Cuboid:get_vec_par i check_vec_par 2")
{
    int i,j;
    Vector3D tops[2][4];
    double iter[4][3] = {{-2, -2, 0}, {0, -2, 0}, {0, 0, 0}, {-2, 0, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    double tab[3][3] = {{0,1,0},{0,0,1},{-1,0,0}};
    Vector3D par[2][3];
    for (i=0;i<3;++i){
        par[0][i] = Vector3D(tab[i]);
        par[1][i] = Vector3D(tab[i]);
    }

    Vector3D res[2][3];
    a.get_vec_perp(res);
    for (i=0;i<2;++i){
        for (j=0;j<3;++j){
            CHECK (res[i][j] == par[i][j]);
        }
    }

}
