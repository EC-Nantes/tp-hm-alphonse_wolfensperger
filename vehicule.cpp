//
#include <fstream> 
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#include <stdexcept>
#include <string>

using namespace std;

#include "vehicule.hpp"

Vehicule::Vehicule(int vitesseMax, int nbPlaces, int occupants){
  this->vitesse_ = 0;
  this->vitesseMax_ = vitesseMax;
  this->nbPlaces_ = nbPlaces;
  this->occupants_ = occupants;
  this->etat_ = 0;
}

void Vehicule::mettreEnPanne(double random) {
  if (random<0.5) {
    this->etat_ = 2;
  }
  else {
    this->etat_ = 3;
  }
}


void Vehicule::demarrer() {
  //this->vitesse_ = 1;

  try
  {
    if (this->etat_ == 1) {
      throw string("Vehicule déjà en marche !");
    }
    else if (this->etat_ > 1) {
      throw string("Vehicule en panne !");
    }
    this->etat_ = 1;
  }
  catch (string const& err_msg)
  {
    cerr << "Exception: " << err_msg << endl;
  }
}

void Vehicule::arreter() {
  this->etat_ = 0;
}

void Vehicule::depanner() {
  this->etat_= 0;
}

void Vehicule::accelerer(int increment) {
  //this->vitesse_ += 1;
  
  try
  {
    this->vitesse_ += increment;
    if (this->vitesse_ > this->vitesseMax_){
      throw string("Vitesse maximale déjà atteinte !");
    }
    else if (this->vitesse_ < 0){
      throw std::string("Vehicule à l'arrêt !");
    }
  }
  catch (string const& err_msg)
  {
    cerr << "Exception: " << err_msg << endl;
  }
}

void Vehicule::monter(int nbOcc) {
  //this->occupants_ += nbOcc;

  try
  {
    this->occupants_ += nbOcc;
    if (this->occupants_ > this->nbPlaces_){
      throw string("Limite de place atteinte !");
    }
  }
  catch (string const& err_msg)
  {
    cerr << "Exception: " << err_msg << endl;
  }
}

void Vehicule::descendre(int nbOcc) {
  //this->occupants_ -= nbOcc;

  try
  {
    this->occupants_ -= nbOcc;
    if (this->occupants_ < 0){
      throw string("Descente de plus d’occupants qu’il y en a dans le véhicule !");
    }
  }
  catch (string const& err_msg)
  {
    cerr << "Exception: " << err_msg << endl;
  }
}

string Vehicule::getEtat() {
  EtatVehicule The_etat;
  //enum EtatVehicule {ARRET, MARCHE, PANNE_LEGERE, PANNE_SEVERE};
    
  //The_etat = EtatVehicule[this->etat_];

  switch(this->etat_)
  {
   case ARRET:
     return "ARRET";
     break;
   case MARCHE:
     return "MARCHE";
     break;
   case PANNE_LEGERE:
     return "PANNE_LEGERE";
     break;
   case PANNE_SEVERE:
     return "PANNE_SEVERE";
     break;
  //And so on
    default: 
      return "others";
  }
  
}


class Voiture : public Vehicule { 
  //public:void bidon() { } 
  };

class Bateau : public Vehicule { 
  //public:void bidon() { } 
  };

