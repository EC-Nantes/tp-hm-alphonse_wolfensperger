#include <iostream>
#include "vehicule.hpp"
#include <stdio.h>
using namespace std;
int main() {

  Vehicule V(0,1,0);
  V.demarrer();
  V.accelerer(-1);
  V.monter(2);
  return 0;
}