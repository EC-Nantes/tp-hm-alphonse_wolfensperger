//
#include <fstream> 
#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

#include "vehicule.hpp"

void Vehicule::mettreEnPanne(double random) {
  if (random<0.5) {
    this->etat_ = 2;
  }
  else {
    this->etat_ = 3;
  }
}


void Vehicule::demarrer() {
  this->vitesse_ = 1;
}

void Vehicule::arreter() {
  this->vitesse_ = 0;
}

void Vehicule::depanner() {
  this->etat_= 0;
}

void Vehicule::accelerer(int increment) {
  this->vitesse_ += 1;
}

void Vehicule::monter(int nbOcc) {
  this->occupants_ += nbOcc;
}

void Vehicule::descendre(int nbOcc) {
  this->occupants_ -= nbOcc;
}

string Vehicule::getEtat() {
  EtatVehicule The_etat;
  
  The_etat = EtatVehicule(this->etat_);

  printf("%s",The_etat);

  return The_etat
  
}

//Il reste à faire le string::getEtat

