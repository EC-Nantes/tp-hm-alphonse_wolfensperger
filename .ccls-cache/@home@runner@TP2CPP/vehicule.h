#include <iostream>



using namespace std;


class Vehicule {
private:
  int vitesse;
  int vitesseMax;
  int nbPlaces;
  int occupants;
  int etat;

protected:
public:
  // accesseurs en lecture
  string getEtat() { return etat; } //Pb de conversion
  int getWordOcc(string word) { return words[word]; }
  int getLenWords() { return words.size(); }
  //map<string, int> getWordsMap() { return words; }

  // accesseurs en ecriture
  void demarrer() { this->vitesse = 1; }
  void arreter() { this->vitesse = 0 ; }
  void depanner() { this->vitesse = 0; 
                    this->etat = 1;
                  }

  void accelerer(int increment) { this->vitesse += 1; }

  void monter(int nbOcc) { this->occupants += 1;
                            this->nbPlaces += 1;
                          }

  void descendre(int nbOcc) { this->occupants -= 1;
                            this->nbPlaces -= 1;
                          }

  void mettreEnPanne(double Random) { this->occupants -= 1;
                          }


  // constructeurs
  Vehicule(void);
  Vehicule(string nom, string path);

  // Méthodes
  void PrintWords();
  void Export();
};