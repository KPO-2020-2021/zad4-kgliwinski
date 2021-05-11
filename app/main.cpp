// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <stdlib.h>
#include "../include/menu.hpp"
#include "../include/lacze_do_gnuplota.hpp"
#include "matrix3D.hpp"
#include "exampleConfig.h"
#include "cuboid.hpp"


/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
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
        menu m;

       Cuboid a;
       a.check_vec_perp();


}
