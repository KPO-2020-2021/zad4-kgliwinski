// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include "../include/menu_cub.hpp"
#include "exampleConfig.h"

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main()
{
  std::cout << "C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR
            << "."
            << PROJECT_VERSION_MINOR
            << "."
            << PROJECT_VERSION_PATCH
            << "."
            << PROJECT_VERSION_TWEAK
            << std::endl;

  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  int i;
  Menu_cub menu;

  double iter1[4][3] = {{0, 0, 0}, {100, 0, 0}, {0, 100, 0} , {100, 100, 0}};
  double iter2[4][3] = {{0, 100, 200}, {100, 100, 200}, {0, 0, 200} , {100, 0, 200}};

  Vector3D tops[2][4];
  for (i = 0; i < 4; ++i)
  {
    tops[0][i] = Vector3D(iter1[i]);
    tops[1][i] = Vector3D(iter2[i]);
  }
    Cuboid cub(tops);

  menu.Print_to_gnuplot(cub);

    Matrix3D a;
    a = a.rotation_matrix(90,'x');
    a = a * a.rotation_matrix(90,'y');
    a = a * a.rotation_matrix(90,'z');

    cub = cub.rotation(a);
    menu.Print_to_gnuplot(cub);
}
