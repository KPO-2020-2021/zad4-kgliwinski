#include"../tests/doctest/doctest.h"
#include"cuboid.hpp"


TEST_CASE("C 1.01: konstruktor bezparametryczny prostopadloscianu i przeciazenie operatorow << >>"){
    //double tab[2][2] = {{3,1}};
    Cuboid a;
    std::ostringstream out;
    out << a; // 
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n" << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n" << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n" << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n" << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n" << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n" << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n" << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n" << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    CHECK (out.str() == out2.str());
}

TEST_CASE("C 1.01: konstruktor parametryczny prostopadloscianu i przeciazenie operatorow << >>"){
    //double tab[2][4][3] =;
    Cuboid a;
    std::ostringstream out;
    out << a; // 
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n" << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n" << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n" << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n" << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n" << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n" << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n" << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n" << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    CHECK (out.str() == out2.str());
}
